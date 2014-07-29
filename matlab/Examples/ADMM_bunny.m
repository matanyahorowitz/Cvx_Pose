% Matanya Horowitz and Nikolai Matni
% July 3, 2014
% For "A Convex Approach to Consensus on SO(n)" by Matni and Horowitz in
% Allerton, 2014.

% Suppose we solving a pose estimation problem, where we split the point
% correspondences into N sets for semi-independent processors. 
addpath( '../parallel' );
addpath( '../' );

%% Settings

%For convergence plots
iters = 50; %Number of ADMM iterations
alpha = 2; %ADMM dual descent weight parameter
N = 10; %For plots

%For bunny time implosion time lapse
% N = 200; % Data is split into 200 for the bunny time lapse
% iters = 50; %Number of ADMM iterations
% alpha = 2; %ADMM dual descent weight parameter


%% Read in the bunny file
% Read data of vertices connecting each face or triangle
fid = fopen('./bunny/bunny_faces.txt','r');
face_matrix = fscanf(fid,'%*f %f %f %f',[3,inf]);
face_matrix = face_matrix';
fclose(fid);

% The face data is indexed starting with 0, increment every vertex numbering by 1
[r,c] = size(face_matrix);
face_matrix = face_matrix + ones(r,c);

% Read coordinates of the vertices
fid = fopen('./bunny/bunny_vertices.txt','r');
vertex_matrix = fscanf(fid,'%f %f %f %*f %*f',[3,inf]);
fclose(fid);

vertex_matrix = vertex_matrix / max(max(vertex_matrix));
n = size(vertex_matrix,2);

subsample = 2; %Pick out only one out of every (subsample) vertices

%% Center bunny

centroid = mean(vertex_matrix')';
vertex_matrix = vertex_matrix - repmat( centroid, 1, n );

%% Synthesize data

% randn('seed',0);
%Euler angles
th_x = randn(); th_y = randn(); th_z = pi/3;
% th_x = 0; th_y = 0; th_z = 0;

R_x = [1 0         0; 
       0 cos(th_x) -sin(th_x); 
       0 sin(th_x) cos(th_x)];

R_y = [cos(th_y)  0 sin(th_y); 
       0          1 0; 
       -sin(th_y) 0 cos(th_y)];

R_z = [cos(th_z) -sin(th_z) 0; 
       sin(th_z) cos(th_z)  0; 
       0         0          1 ];

R_true = R_x*R_y*R_z;

sdev = .05;

delta = sdev*randn(3,n);

A_total = R_true*vertex_matrix + delta; 
B_total = vertex_matrix;

%% Split data


Ad = cell(N,1);
Bd = cell(N,1);
for i=1:N
    Ad{i} = zeros(3,ceil(n/N));
    Bd{i} = zeros(3,ceil(n/N));
end

% Points are split throughout model

% for i=0:n-1
%     bin_num = mod(i,N) + 1;
%     bin_ind = floor(i/N)+1;
%     
%     Ad{bin_num}(:,bin_ind) = A_total(:,i+1);
%     Bd{bin_num}(:,bin_ind) = B_total(:,i+1);
% end

% Points are split sequentially 

pt_set = 1:floor(n/N):n;

for i=1:N
    if i==N
        Ad{i} = A_total(:,pt_set(i):n);
        Bd{i} = B_total(:,pt_set(i):n);
    else
        Ad{i} = A_total(:,pt_set(i):pt_set(i+1)-1);
        Bd{i} = B_total(:,pt_set(i):pt_set(i+1)-1);
    end
end

D = cell(N,1);
for i=1:N
    D{i} = Ad{i}*Bd{i}';
end

%% Initialization of SO(n) data
n = 3;

%dimension 8 x 4
Pa = [1, 0; 0, -1];
for i=2:n-1
    Pa = kron(Pa, [1, 0; 0, -1]);
end
Peven = .5 * [eye(2^(n-1)) + Pa;
              eye(2^(n-1)) - Pa];
          
A = cell(n,n);
lambda = cell(n,1);
rho = cell(n,1);

for i=1:n
    la = 1; pa = 1;
    
    for j=1:i-1
        la = kron(la, [1, 0; 0, -1]);
        pa = kron(pa, eye(2));
    end
    
    la = kron(la,[0, -1; 1, 0]);
    pa = kron(pa,[0, -1; 1, 0]);
    
    for j=1:n-i
        la = kron(la, eye(2));
        pa = kron(pa, [1, 0; 0, -1]);
    end
    
    lambda{i} = la;
    rho{i} = pa;
end

for i=1:n
    for j=1:n
        A{i,j} = -Peven'*lambda{i}*rho{j}*Peven;
    end
end

%% Problem data

D_adj = cell(N,1);
for i=1:N
    D_adj{i} = adjoint_so(D{i},A);
end

%% ADMM

% Initialize data


Y = cell(iters+1,N);
Z = cell(iters+1,N);
Z0 = cell(iters+1,1);

dim = 2^(n-1);
for i=1:N
    Z{1,i} = zeros(dim);
    Y{1,i} = zeros(dim);
end
Z0{1} = zeros(dim);

tic()
for t=1:iters    
    Q0 = zeros(dim);

    for i=1:N
        Qi = (1/alpha) * (D_adj{i} - Y{t,i}) + Z0{t};
        
        [U,u] = eig(Qi);
        eigvals = diag(u);
        uproj = projsplx(eigvals);
        
        Z{t+1,i} = U*diag(uproj)*U';
        
        Q0 = Q0 + (1/alpha) * Y{t,i} + Z{t+1,i};
    end
    
    [U,u] = eig(Q0);
    eigvals = diag(u);
    uproj = projsplx(eigvals);
    Z0{t+1} = U*diag(uproj)*U';
    
    for i=1:N
        Y{t+1,i} = Y{t,i} + alpha*(Z{t+1,i} - Z0{t+1});
%         Y{t+1,i} = Y{t,i} + (1/t)*(Z{t+1,i} - Z0{t+1});
    end
    
end
toc()

%Recover R matrices from Z matrices
R0_final = z2so(Z0{t+1},A);

R0 = cell(iters+1,1);
R = cell(iters+1,N);

for t=1:iters+1
    R0{t} = z2so(Z0{t},A);
    for i=1:N
        R{t,i} = z2so(Z{t,i},A);
    end
end
%% Visualize results

% Distance from node one

results = zeros(iters-1,N);
for t=2:iters
    for i=1:N
        results(t-1,i) = norm(Z0{t} - Z{t,i},'fro');
    end
end
plot(results);
title('Distance from Z0', 'FontSize', 14);
set(gca, 'FontSize', 14);
%%
% Distance from true value
results = zeros(iters-1,N);
for t=2:iters
    for i=1:N
        results(t-1,i) = norm(R_true - R{t,i},'fro');
    end
end
figure;
plot(results);
title('Distance from R_{true}', 'FontSize', 14);
set(gca,'FontSize',14)
%%
% Converged Rotation
sol_data = R0_final*B_total;

figure;
scatter3(sol_data(1,:),sol_data(2,:), sol_data(3,:),'r*')
axis off;
hold on;
scatter3(A_total(1,:),A_total(2,:), A_total(3,:),'b.')

R_true
det(R_true)

R0_final
det(R0_final)

% Some example rotations as they converge
% figure;
% for t=1:10:31
%     for i=1:N
%         subplot(N,4,1);
%         
%     end
% end
%%
% figure;
% count = 1;
% seq = [2 3 4 8 20 iters];
% while count <= 6
% %     subplot(2,3,count);
%     t = seq(count);
%     figure;
%     for i=1:N
%         cur_result = R{t,i}*Bd{i};
%         scatter3(cur_result(1,:),cur_result(2,:), cur_result(3,:),'b.')
%         hold on;
%     end
%     hold off;
%     title(sprintf('t = %d',t), 'FontSize', 16);
%     set(gca,'FontSize',16)
%     axis([-.5, .5, -.5, .5, -.5, .5])
% %     axis off;
%     count = count + 1;
% end
%%

