function [pc] = depthToPC( depth_image )
% Converts a depth image to a point cloud for a kinect. Calibration
% parameters are obtained from
% http://vision.in.tum.de/data/datasets/rgbd-dataset/file_formats

fx = 525.0;  % focal length x
fy = 525.0;  % focal length y
cx = 319.5;  % optical center x
cy = 239.5;  % optical center y

%factor = 5000.; % for the 16-bit PNG files
% OR: factor = 1. # for the 32-bit float images in the ROS bag files

factor = 5000.;

pc = zeros(3,size(depth_image,1)*size(depth_image,2));

counter = 1;

for v = 1:size(depth_image,1) %height
  for u = 1:size(depth_image,2) % width
    Z = double(depth_image(v,u)) / factor;
    X = (u - cx - 1) * Z / fx;
    Y = (v - cy - 1) * Z / fy;
    
    pc(:,counter) = [X; Y; Z];
    
    counter = counter + 1;
  end
end

end