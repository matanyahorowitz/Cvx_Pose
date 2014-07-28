%Matanya Horowitz 9/12/2013

%Do pose estimation using Orbitope Optimization on the Stanford Bunny

addpath( '../' );
%% Read in the bunny file

% Read coordinates of the vertices
fid = fopen('./bunny/bunny_vertices.txt','r');
vertex_matrix = fscanf(fid,'%f %f %f %*f %*f',[3,inf]);
fclose(fid);

n = size(vertex_matrix,2);

subsample = 20; %Pick out only one out of every (subsample) vertices

vertex_matrix = [vertex_matrix; ones(1,n)];

%% Synthesize data

%Euler angles
th_x = pi/3; th_y = pi/4; th_z = pi/2;
R_x = [1 0 0; 0 cos(th_x) -sin(th_x); 0 sin(th_x) cos(th_x)];
R_y = [cos(th_y) 0 sin(th_y); 0 1 0; -sin(th_y) 0 cos(th_y)];
R_z = [cos(th_z) -sin(th_z) 0; sin(th_z) cos(th_z) 0; 0 0 1];

R_true = R_x*R_y*R_z;
T_true = [.1 .2 .3]';
S_true = [R_true, T_true; [0 0 0], [1]];

sdev = .001;

corrupted_data = S_true*vertex_matrix + [sdev*randn(3,n); zeros(1,n)];

%% Sub-sample
nn = floor(n/subsample);
sub_model = zeros(4,nn);
sub_corrupt = zeros(4,nn);
count = 1;
for i=1:n
    if mod(i,subsample) == 0
        sub_model(:,count) = vertex_matrix(:,i);
        sub_corrupt(:,count) = corrupted_data(:,i);
        count = count + 1;
    end
end

%% Setup SDP
cons = [];

R = sdpvar(3,3);
T = sdpvar(3,1);
s = [R,T;[0 0 0], [1]];

p = eye(4);

cons_matrix = [1+R(1,1)+R(2,2)+R(3,3),      R(3,2)-R(2,3),             R(1,3)-R(3,1),             R(2,1)-R(1,2);
                        R(3,2)-R(2,3),      1+R(1,1)-R(2,2)-R(3,3),    R(2,1)+R(1,2),             R(1,3)+R(3,1);
                        R(1,3)-R(3,1),      R(2,1)+R(1,2),             1-R(1,1)+R(2,2)-R(3,3),    R(3,2)+R(2,3);
                        R(2,1)-R(1,2),      R(1,3)+R(3,1),             R(3,2)+R(2,3),             1-R(1,1)-R(2,2)+R(3,3)];
                    
cons = [cons, cons_matrix >= 0];

%% Setup features

X = sub_model(:);
Y = sub_corrupt(:);

S = kron(eye(nn),s);
P = kron(eye(nn),p);

%This is for the standard error
error = (Y - P*S*X)'*(Y - P*S*X);

%This is for P orthogonal, producing linear objective
%error = -(Y)'*(P*S*X);

%% Perform optimization

ops = sdpsettings('solver', 'sdpt3');
solvesdp(cons, error, ops);

disp('SDP Complete');
residual = double(error)

disp('Determinant of SO(3) element');
determinant = det(double(R))

%% Visualize result

S_sol = double(s);
sol_model = S_sol*vertex_matrix;

sol_pts = sol_model(1:3,:) - repmat( S_sol(1:3,4), 1, n );
obs_pts = corrupted_data(1:3,:) - repmat( S_sol(1:3,4), 1, n );

cor_pts = sub_corrupt(1:3,:) - repmat( S_sol(1:3,4), 1, nn );

% Draw the bunny using the patch command
patch('Vertices',sol_pts','Faces',face_matrix,'FaceColor','cyan');
axis off
axis equal

hold on;
% patch('Vertices',obs_pts','Faces',face_matrix,'FaceColor','cyan')
scatter3(obs_pts(1,:),obs_pts(2,:),obs_pts(3,:));
hold on;
scatter3(cor_pts(1,:),cor_pts(2,:),cor_pts(3,:),'r*');
hold off;

%% test bunny visualization

% patch('Vertices',vertex_matrix(1:3,:)','Faces',face_matrix,'FaceColor','white');
% axis off
% axis equal