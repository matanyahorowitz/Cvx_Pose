%Matanya Horowitz August 14, 2014

%Do pose estimation using Orbitope Optimization on the Stanford Bunny

addpath( '../../' );
addpath( '../../icp_standard/' );
addpath( '../../../examples/data/bunny/');
%% Read in the bunny file

files = dir('../../../examples/data/bunny/*.ply');
%%
num_files = size(files,1);
count_limit = 3;
R_list = cell(1,num_files);
T_list = cell(1,num_files);
er_list = cell(1,num_files);
ti_list = cell(1,num_files);
subs = 100;

count = 1;
for file = files'
    if count > count_limit
        break;
    end
    
    fprintf( 'Reconstructing with point cloud #%d, %s\n', count, file.name);
    if count == 1
        model = import_bunny_ply(file.name,25,inf)';
        
        model = subsample_pc(model,subs);
        bar = mean(model,2);
        model = model - repmat(bar,1,size(model,2));
        
        fprintf('number of points used=%d \n', size(model,2));
        R = eye(3);
        T = zeros(3,1);
        
        R_list{count} = R;
        T_list{count} = T;
        
        count = count + 1;
        continue;
    end
    
    obs = import_bunny_ply(file.name,25,inf)';
    
    obs = subsample_pc(obs,subs);
    bar = mean(obs,2);
    obs = obs - repmat(bar,1,size(obs,2));
    
%     [R, T, ER, TI] = icp(model,obs, 6, 'Matching', 'kDtree', 'Minimize', 'plane');
    [R, T, ER, TI] = ISE3(model,obs, 6, 'Lambda', 2, 'Matching', 'kDtree', 'Minimize', 'plane');
    R_list{count} = R;
    T_list{count} = T;
    er_list{count} = ER;
    ti_list{count} = TI;
    
    count = count + 1;
    model = obs;
end


%% Visualize result

figure;
hold all;
count = 1;
R = eye(3);
T = zeros(3,1);

for file = files'
    if count > count_limit
        break;
    end
    fprintf( 'Visualizing with point cloud #%d, %s\n', count, file.name);
    
    model = import_bunny_ply(file.name,25,inf)';
    
    model = subsample_pc(model,subs);
    bar = mean(model,2);
    model = model - repmat(bar,1,size(model,2));
    
    R = R_list{count} * R;
    T = T + T_list{count};
    
    match = R*model + repmat(T,1,size(model,2));
%     match = model;
    scatter3(match(1,:),match(2,:),match(3,:));
    count = count + 1;
end
hold off;