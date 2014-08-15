%Matanya Horowitz 9/12/2013

%Do pose estimation using Orbitope Optimization on the Stanford Bunny

addpath( '../../examples/data/bunny' );
clc; clear;
%% Read in the bunny file

% Read coordinates of the vertices
fid = fopen('bunny_vertices.txt','r');
vertex_matrix = fscanf(fid,'%f %f %f %*f %*f',[3,inf]);
fclose(fid);

n = size(vertex_matrix,2);

subsample = 5; %Pick out only one out of every (subsample) vertices

%% Synthesize data

%Euler angles
th_x = pi/3; th_y = pi/4; th_z = pi/2;
R_x = [1 0 0; 0 cos(th_x) -sin(th_x); 0 sin(th_x) cos(th_x)];
R_y = [cos(th_y) 0 sin(th_y); 0 1 0; -sin(th_y) 0 cos(th_y)];
R_z = [cos(th_z) -sin(th_z) 0; sin(th_z) cos(th_z) 0; 0 0 1];

R_true = R_x*R_y*R_z;

sdev = .0;

corrupted_data = R_true*vertex_matrix + sdev*randn(3,n);

%% Sub-sample
nn = floor(n/subsample);
model = zeros(3,nn);
obs = zeros(3,nn);
count = 1;
for i=1:n
    if mod(i,subsample) == 0
        model(:,count) = vertex_matrix(:,i);
        obs(:,count) = corrupted_data(:,i);
        count = count + 1;
    end
end
nn = count-1;

%% Compute centroid
centroid_obs = mean(obs')';
centroid_model = mean(model')';

trans = centroid_obs - centroid_model;
obs = obs - repmat(centroid_obs,1,nn);
model = model - repmat(centroid_model,1,nn);

obs = obs * .5;

A = init_z2so(3);

%% Setup SDP
cvx_begin sdp
cvx_solver sdpt3

variable Z(4,4);

%R = z2so(Z,A);

for i=1:3
    for j=1:3
        R(i,j) = trace(A{i,j}'*Z);
    end
end

%% Setup features and objective
objective = norm(obs - R*model,'fro') - 100*trace(Z);

minimize(objective);
subject to
Z >= 0;
trace(Z) <= 100;
cvx_end

%% Perform optimization

disp('Determinant of SO(3) element');
determinant = det(double(R))

%% Visualize result

R_sol = double(R);
sol_model = R_sol*model;

% patch('Vertices',obs_pts','Faces',face_matrix,'FaceColor','cyan')
scatter3(sol_model(1,:),sol_model(2,:),sol_model(3,:));
hold on;
scatter3(obs(1,:),obs(2,:),obs(3,:),'r*');
hold off;

%% test bunny visualization

% patch('Vertices',vertex_matrix(1:3,:)','Faces',face_matrix,'FaceColor','white');
% axis off
% axis equal