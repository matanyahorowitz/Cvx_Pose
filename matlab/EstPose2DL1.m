function [SE,residual] = EstPose2D(obs, model,lambda)
% Matanya Horowitz, Nikolai Matni
% 10/21/2013
%
% 3D Estimation software. Takes a collection of 3D points obs and finds the
% pose in SE(3) that best aligns the model points to the obs. The obs and
% model points are assumed to be of the same length.
%
%Inputs:
% obs - An 3xn list of observed points
% model - An 3xn list of corresponding points on the model
% lambda - An L1 penalty. This feature is disabled if lambda=0
%
%Outputs:
% trans - The estimated translation
% rot - The estimated rotation
% residual - The residual

n = length(obs);
m = length(model);

if n ~= m
    display('Point lists must be of equal length');
    return;
end

%% Compute centroid
centroid_obs = mean(obs);
centroid_model = mean(model);

trans = centorid_obs - centroid_model;
obs = obs - repmat(centroid_obs,1,n);
model = model - repmat(centroid_model,1,n);

%% Setup SDP
cvx_begin
cvx_solver sdpt3

variable R(2,2);
variable t(2,1);
variable z(2,n);

%% Setup features and objective

X = obs(:);
Y = model(:);
Z = z(:);

s = [R,   t;
    [0 0 0], [1]];

S = kron(eye(n),s);

objective = ((Y-S*X) - Z)'*((Y-S*X) - Z) + lambda*norm(Z,1);

minimize(objective);

subject to

    norm([R(1,1), R(2,1)]) <= 1;
    R(1,1) == R(2,2);
    R(1,2) == -R(2,1);

cvx_end

residual = double(objective);
SE = double(s);
