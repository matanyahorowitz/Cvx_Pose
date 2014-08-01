%Matanya Horowitz 9/12/2013

%Do pose estimation using Orbitope Optimization on the Stanford Bunny

addpath( '../' );
%% Read in the bunny file

% Read coordinates of the vertices
model = import_csv_pc('../../examples/data/velodyne/velodyne_scan_00200.csv');

obs = import_csv_pc('../../examples/data/velodyne/velodyne_scan_00220.csv');

model = model';
obs = obs';

n = size(model,2);

%% Perform optimization
%[SE3, residual] = EstPose3DL1( obs, model, 1 );
[TR, TT, ER, TI] = ISE3(obs,model,1);

%% Visualize result
%match = SE3(1:3,1:3)*model + repmat(SE3(1:3,4),1,n);
match = TR*model + repmat(TT,1,n);

figure;
title('Before');
hold on;
scatter3(obs(1,:),pbs(2,:),obs(3,:));
hold on;
scatter3(model(1,:),model(2,:),model(3,:),'r*');
hold off;

figure;
title('After');
scatter3(obs(1,:),pbs(2,:),obs(3,:));
hold on;
scatter3(match(1,:),match(2,:),match(3,:),'r*');
hold off;

%% test bunny visualization

% patch('Vertices',vertex_matrix(1:3,:)','Faces',face_matrix,'FaceColor','white');
% axis off
% axis equal