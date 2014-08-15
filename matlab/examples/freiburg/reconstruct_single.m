%Matanya Horowitz August 14, 2014

%Do pose estimation using Orbitope Optimization on the Stanford Bunny

addpath( '../../' );
addpath( '../../icp_standard/' );
%% Read in the bunny file

% Read coordinates of the vertices
model_img = imread('rgbd_dataset_freiburg1_xyz/depth/1305031102.160407.png','png');

obs_img = imread('rgbd_dataset_freiburg1_xyz/depth/1305031102.194330.png','png');

model = depthToPC( model_img );
obs = depthToPC( obs_img );

model = subsample_pc(model,1500);
obs = subsample_pc(obs,1500);

%Center both
%obs_bar = mean(obs,2);
%model_bar = mean(model,2);

%obs = obs - repmat(obs_bar,1,size(obs,2));
%model = model - repmat(model_bar,1,size(model,2));

n = size(model,2);
n
%% Perform optimization
% [R,T, residual] = EstPose3DL1( obs, model, 0, 10000 );
% [R,T, residual] = EstPose3D( obs, model, 0 );

% [R, T, ER, TI] = ISE3(obs,model, 12, 'Lambda', 1000, 'Matching', 'kDtree', 'Minimize', 'point');
[R, T, ER, TI] = ISE3(obs,model, 6, 'Lambda', 2, 'Matching', 'kDtree', 'Minimize', 'plane');
% [R, T, ER, TI] = icp(obs,model,'Matching', 'kDtree');
%[R, T, ER, TI] = icp(obs,model, 6, 'Matching', 'kDtree', 'Minimize', 'plane');

%% Visualize result
% match = R*model;
match = R*model + repmat(T,1,size(model,2));
subplot(2,2,1);
title('Before');
hold on;
scatter3(obs(1,:),obs(2,:),obs(3,:));
hold on;
scatter3(model(1,:),model(2,:),model(3,:),'r*');
hold off;

% obs = obs + repmat(T,1,size(obs,2));
subplot(2,2,3);
title('After');
hold on;
scatter3(obs(1,:),obs(2,:),obs(3,:));
hold on;
scatter3(match(1,:),match(2,:),match(3,:),'r*');
hold off;

subplot(2,2,2);
title('Error');
plot(ER);

subplot(2,2,4);
title('Ti');
plot(TI);