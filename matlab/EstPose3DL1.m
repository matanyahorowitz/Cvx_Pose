function [Rs,Ts,residual] = EstPose3DL1(obs, model, weights, lambda)
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
cvx_begin sdp quiet
cvx_solver sdpt3

variable R(3,3);
variable T(3,1);
variable z(3,n);


%X = [model; ones(1,n)];
%Y = [obs; ones(1,n)];
%Z = [z; zeros(1,n)];

cons_matrix = [1+R(1,1)+R(2,2)+R(3,3),      R(3,2)-R(2,3),             R(1,3)-R(3,1),             R(2,1)-R(1,2);
                        R(3,2)-R(2,3),      1+R(1,1)-R(2,2)-R(3,3),    R(2,1)+R(1,2),             R(1,3)+R(3,1);
                        R(1,3)-R(3,1),      R(2,1)+R(1,2),             1-R(1,1)+R(2,2)-R(3,3),    R(3,2)+R(2,3);
                        R(2,1)-R(1,2),      R(1,3)+R(3,1),             R(3,2)+R(2,3),             1-R(1,1)-R(2,2)+R(3,3)];

%s = [R,   T;
%    [0 0 0], [1]];

%objective = norm((Y-s*X) - Z,'fro') + lambda*norm(Z,1);
objective = 0;
for i=1:n
    objective = objective + norm( (R*model(:,i)) - (obs(:,i) + T) + z(:,i), 2 );
end

objective = objective + lambda*norm(z,1);

minimize(objective);
subject to
cons_matrix >= 0;
cvx_end

residual = double(objective);
r = double(R);
t = double(T);

disp('Det(R)');
det(r)

[u,s,v] = svd(r);
r = u*v';

Rs = r;
Ts = t;
