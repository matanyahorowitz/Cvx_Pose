function [SE,residual] = EstPose3DL1(obs, model, lambda)
% Matanya Horowitz, Nikolai Matni
% 10/21/2013
%
% 3D Estimation software. Takes a collection of 3D points obs and finds the
% pose in SE(3) that best aligns the model points to the obs. The obs and
% model points are assumed to be of the same length.
%
%Inputs:
% obs - An 4xn list of observed points
% model - An 4xn list of corresponding points on the model
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

% Setup SDP
cvx_begin sdp
cvx_solver sdpt3

variable R(3,3);
variable t(3,1);
variable z(4,n);

Z = z(:);

X = [model; ones(1,n)];
Y = [obs; ones(1,n)];
X = X(:);
Y = Y(:);


cons_matrix = [1+R(1,1)+R(2,2)+R(3,3),      R(3,2)-R(2,3),             R(1,3)-R(3,1),             R(2,1)-R(1,2);
                        R(3,2)-R(2,3),      1+R(1,1)-R(2,2)-R(3,3),    R(2,1)+R(1,2),             R(1,3)+R(3,1);
                        R(1,3)-R(3,1),      R(2,1)+R(1,2),             1-R(1,1)+R(2,2)-R(3,3),    R(3,2)+R(2,3);
                        R(2,1)-R(1,2),      R(1,3)+R(3,1),             R(3,2)+R(2,3),             1-R(1,1)-R(2,2)+R(3,3)];


s = [R,   t;
    [0 0 0], [1]];

S = kron(eye(n),s);

% objective = ((Y-S*X) - Z)'*((Y-S*X) - Z) + lambda*norm(Z,1);
objective = -Y'*S*X;

minimize(objective);
subject to
cons_matrix > 0;
cvx_end

residual = double(objective);
SE = double(s);
