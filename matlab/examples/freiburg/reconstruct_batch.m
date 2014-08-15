%Matanya Horowitz August 14, 2014

addpath( '../../' );
addpath( '../../icp_standard/' );

%%
scan_limit = 4;

files = dir('rgbd_dataset_freiburg1_xyz/depth/*.png');

num_files = length(files);

rots = cell(1,num_files);
trans = cell(1,num_files);

count = 1;
for file = files'
    if count == scan_limit+1
        break;
    end
    fprintf( '--Matching image %d--\n', count );
    
    if count == 1
        last_file = file;
        rots{count} = eye(3);
        trans{count} = zeros(3,1);
        
        display('First scan set to origin');
    else
        model_img = imread(['rgbd_dataset_freiburg1_xyz/depth/', last_file.name], 'png');

        obs_img = imread(['rgbd_dataset_freiburg1_xyz/depth/', file.name],'png');

        model = depthToPC( model_img );
        obs = depthToPC( obs_img );

        model = subsample_pc(model,1200);
        obs = subsample_pc(obs,1200);

        n = size(model,2);

        [R, T, ER, TI] = ISE3(obs,model, 3, 'Lambda', 2, 'Matching', 'kDtree', 'Minimize', 'plane');
        %[R, T, ER, TI] = icp(obs,model, 6, 'Matching', 'kDtree', 'Minimize', 'plane');
        
        rots{count} = R*rots{count-1};
        trans{count} = -T + trans{count-1};
        
        display('Rotation: ');
        display(R);
        
        display('Translation: ');
        display(-T);
    end

    count = count + 1;
end

%% Assemble different scans

for i=1:scan_limit
    model_img = imread(['rgbd_dataset_freiburg1_xyz/depth/', files(i).name], 'png');
    model = depthToPC( model_img );
    model = subsample_pc(model,1200);
    
    model = rots{i}*model + repmat(trans{i},1,size(model,2));
    scatter3(model(1,:),model(2,:),model(3,:));
    hold all;
end