function [TR, TT, ER, TI] = ISE3(obs,model,lambda)
% Matanya Horowitz, Nikolai Matni
% 10/22/2013
%
% Borrows heavily from the ICP Matlab package. We thank those authors at:
% http://www.mathworks.com/matlabcentral/fileexchange/27804-iterative-closest-point
%
% 3D Estimation software. Takes a collection of 3D points obs and finds the
% pose in SE(3) that best aligns the model points to the obs. This method
% iteratively performs correspondence and then estimation.
%
%Inputs:
% obs - An 3xn list of observed points
% model - An 3xn list of corresponding points on the model
% lambda - An L1 penalty. This feature is disabled if lambda=0
%
%Outputs:
% TT - The estimated translation
% TR - The estimated rotation
% ER - The residual at each iterate
% TI - The time for each iterate

%%

iter = 5;
matching = 'kDtree';
minimize = 'point';

% Allocate vector for RMS of errors in every iteration.
TI = zeros(iter+1,1); 

% Start timer
tic;

% Transformed data point cloud
p = model;
q = obs;
pt = p;

Np = size(p,2);

% Allocate vector for RMS of errors in every iteration.
ER = zeros(iter+1,1); 

% Initialize temporary transform vector and matrix.
T = zeros(3,1);
R = eye(3,3);

% Initialize total transform vector(s) and rotation matric(es).
TT = zeros(3,1, iter+1);
TR = repmat(eye(3,3), [1,1, iter+1]);

switch matching
    case 'bruteForce'
        
    case 'Delaunay'
        DT = DelaunayTri(transpose(q));
    case 'kDtree'
        kdOBJ = KDTreeSearcher(transpose(q));
end

TI(1) = toc;

% Go into main iteration loop
for k=1:iter
    fprintf('Iterate %d of main iteration\n', k);
    % Do matching
    switch matching
        case 'bruteForce'
            [match mindist] = match_bruteForce(q,pt);
        case 'Delaunay'
            [match mindist] = match_Delaunay(q,pt,DT);
        case 'kDtree'
            [match mindist] = match_kDtree(q,pt,kdOBJ);
    end
    
    p_idx = true(1, Np);
    q_idx = match;
    
    if k == 1
        ER(k) = sqrt(sum(mindist.^2)/length(mindist));
    end
    
    q_proc = q(:,q_idx);
    p_proc = pt(:,p_idx);
    
%     q_proc = [q_proc; ones(1,length(q_proc))];
%     p_proc = [p_proc; ones(1,length(p_proc))];
%     
    tic;
    [SE3, res] = EstPose3D(q_proc,p_proc);
    TI(k+1) = toc;
    
    R = SE3(1:3, 1:3);
    T = SE3(1:3, 4);
    
    % Add to the total transformation
    TR(:,:,k+1) = R*TR(:,:,k);
    TT(:,:,k+1) = R*TT(:,:,k)+T;

    % Apply last transformation
    pt = TR(:,:,k+1) * p + repmat(TT(:,:,k+1), 1, Np);
    
    % Root mean of objective function 
    ER(k+1) = rms_error(q(:,q_idx), pt(:,p_idx));
end

TR = TR(:,:,end);
TT = TT(:,:,end);

%%%
%Functions taken from ICP code

function [match mindist] = match_bruteForce(q, p)
    m = size(p,2);
    n = size(q,2);    
    match = zeros(1,m);
    mindist = zeros(1,m);
    for ki=1:m
        d=zeros(1,n);
        for ti=1:3
            d=d+(q(ti,:)-p(ti,ki)).^2;
        end
        [mindist(ki),match(ki)]=min(d);
    end
    
    mindist = sqrt(mindist);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [match mindist] = match_Delaunay(q, p, DT)
	match = transpose(nearestNeighbor(DT, transpose(p)));
	mindist = sqrt(sum((p-q(:,match)).^2,1));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

function [match mindist] = match_kDtree(~, p, kdOBJ)
	[match mindist] = knnsearch(kdOBJ,transpose(p));
    match = transpose(match);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Extrapolation in quaternion space. Details are found in:
%
% Besl, P., & McKay, N. (1992). A method for registration of 3-D shapes. 
% IEEE Transactions on pattern analysis and machine intelligence, 239?256.

function [dv] = extrapolate(v,d,vmax)

p1 = polyfit(v,d,1); % linear fit
p2 = polyfit(v,d,2); % parabolic fit
v1 = -p1(2)/p1(1); % linear zero crossing
v2 = -p2(2)/(2*p2(1)); % polynomial top point

if issorted([0 v2 v1 vmax]) || issorted([0 v2 vmax v1])
    disp('Parabolic update!');
    dv = v2;
elseif issorted([0 v1 v2 vmax]) || issorted([0 v1 vmax v2])...
        || (v2 < 0 && issorted([0 v1 vmax]))
    disp('Line based update!');
    dv = v1;
elseif v1 > vmax && v2 > vmax
    disp('Maximum update!');
    dv = vmax;
else
    disp('No extrapolation!');
    dv = 0;
end


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Determine the RMS error between two point equally sized point clouds with
% point correspondance.
% ER = rms_error(p1,p2) where p1 and p2 are 3xn matrices.

function ER = rms_error(p1,p2)
dsq = sum(power(p1 - p2, 2),1);
ER = sqrt(mean(dsq));

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Converts (orthogonal) rotation matrices R to (unit) quaternion
% representations
% 
% Input: A 3x3xn matrix of rotation matrices
% Output: A 4xn matrix of n corresponding quaternions
%
% http://en.wikipedia.org/wiki/Rotation_matrix#Quaternion

function quaternion = rmat2quat(R)

Qxx = R(1,1,:);
Qxy = R(1,2,:);
Qxz = R(1,3,:);
Qyx = R(2,1,:);
Qyy = R(2,2,:);
Qyz = R(2,3,:);
Qzx = R(3,1,:);
Qzy = R(3,2,:);
Qzz = R(3,3,:);

w = 0.5 * sqrt(1+Qxx+Qyy+Qzz);
x = 0.5 * sign(Qzy-Qyz) .* sqrt(1+Qxx-Qyy-Qzz);
y = 0.5 * sign(Qxz-Qzx) .* sqrt(1-Qxx+Qyy-Qzz);
z = 0.5 * sign(Qyx-Qxy) .* sqrt(1-Qxx-Qyy+Qzz);

quaternion = reshape([w;x;y;z],4,[]);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Converts (unit) quaternion representations to (orthogonal) rotation matrices R
% 
% Input: A 4xn matrix of n quaternions
% Output: A 3x3xn matrix of corresponding rotation matrices
%
% http://en.wikipedia.org/wiki/Quaternions_and_spatial_rotation#From_a_quaternion_to_an_orthogonal_matrix

function R = quat2rmat(quaternion)
q0(1,1,:) = quaternion(1,:);
qx(1,1,:) = quaternion(2,:);
qy(1,1,:) = quaternion(3,:);
qz(1,1,:) = quaternion(4,:);

R = [q0.^2+qx.^2-qy.^2-qz.^2 2*qx.*qy-2*q0.*qz 2*qx.*qz+2*q0.*qy;
     2*qx.*qy+2*q0.*qz q0.^2-qx.^2+qy.^2-qz.^2 2*qy.*qz-2*q0.*qx;
     2*qx.*qz-2*q0.*qy 2*qy.*qz+2*q0.*qx q0.^2-qx.^2-qy.^2+qz.^2];
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Least squares normal estimation from point clouds using PCA
%
% H. Hoppe, T. DeRose, T. Duchamp, J. McDonald, and W. Stuetzle. 
% Surface reconstruction from unorganized points. 
% In Proceedings of ACM Siggraph, pages 71:78, 1992.
%
% p should be a matrix containing the horizontally concatenated column
% vectors with points. k is a scalar indicating how many neighbors the
% normal estimation is based upon.
%
% Note that for large point sets, the function performs significantly
% faster if Statistics Toolbox >= v. 7.3 is installed.
%
% Jakob Wilm 2010

function n = lsqnormest(p, k)
m = size(p,2);
n = zeros(3,m);

v = ver('stats');
if str2double(v.Version) >= 7.5 
    neighbors = transpose(knnsearch(transpose(p), transpose(p), 'k', k+1));
else
    neighbors = k_nearest_neighbors(p, p, k+1);
end

for i = 1:m
    x = p(:,neighbors(2:end, i));
    p_bar = 1/k * sum(x,2);
    
    P = (x - repmat(p_bar,1,k)) * transpose(x - repmat(p_bar,1,k)); %spd matrix P
    %P = 2*cov(x);
    
    [V,D] = eig(P);
    
    [~, idx] = min(diag(D)); % choses the smallest eigenvalue
    
    n(:,i) = V(:,idx);   % returns the corresponding eigenvector    
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Program to find the k - nearest neighbors (kNN) within a set of points. 
% Distance metric used: Euclidean distance
%
% Note that this function makes repetitive use of min(), which seems to be
% more efficient than sort() for k < 30.

function [neighborIds neighborDistances] = k_nearest_neighbors(dataMatrix, queryMatrix, k)

numDataPoints = size(dataMatrix,2);
numQueryPoints = size(queryMatrix,2);

neighborIds = zeros(k,numQueryPoints);
neighborDistances = zeros(k,numQueryPoints);

D = size(dataMatrix, 1); %dimensionality of points

for i=1:numQueryPoints
    d=zeros(1,numDataPoints);
    for t=1:D % this is to avoid slow repmat()
        d=d+(dataMatrix(t,:)-queryMatrix(t,i)).^2;
    end
    for j=1:k
        [s,t] = min(d);
        neighborIds(j,i)=t;
        neighborDistances(j,i)=sqrt(s);
        d(t) = NaN; % remove found number from d
    end
end

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Boundary point determination. Given a set of 3D points and a
% corresponding triangle representation, returns those point indices that
% define the border/edge of the surface.

function bound = find_bound(pts, poly)

%Correcting polygon indices and converting datatype 
poly = double(poly);
pts = double(pts);

%Calculating freeboundary points:
TR = TriRep(poly, pts(1,:)', pts(2,:)', pts(3,:)');
FF = freeBoundary(TR);

%Output
bound = FF(:,1);
 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
