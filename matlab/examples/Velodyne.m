%Matanya Horowitz 9/12/2013

%Do pose estimation using Orbitope Optimization on the Stanford Bunny

addpath( '../' );
addpath( '../icp_standard/' );
%% Read in the bunny file

% Read coordinates of the vertices
model = import_csv_pc('../../examples/data/velodyne/velodyne_scan_00200.csv');

obs = import_csv_pc('../../examples/data/velodyne/velodyne_scan_00220.csv');

model = model';
obs = obs';

model = subsample_pc(model,30);
obs = subsample_pc(obs,30);

n = size(model,2);

%% Perform optimization
[R,T, residual] = EstPose3DL1( obs, model, 0, 1000 );
%[TR, TT, ER, TI] = ISE3(obs,model,100);
% [TR, TT, ER, TI] = icp(obs,model,'Matching', 'kDtree');

%% Visualize result
match = R*model + repmat(T,1,n);

figure;
title('Before');
hold on;
scatter3(obs(1,:),obs(2,:),obs(3,:));
hold on;
scatter3(model(1,:),model(2,:),model(3,:),'r*');
hold off;

figure;
title('After');
hold on;
scatter3(obs(1,:),obs(2,:),obs(3,:));
hold on;
scatter3(match(1,:),match(2,:),match(3,:),'r*');
hold off;

figure;
title('Error');
plot(ER);

figure;
title('Ti');
plot(TI);