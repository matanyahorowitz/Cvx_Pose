% Matanya Horowitz, Nikolai Matni 10/22/2013
% ICP example on a sinusoidal, corrupted surface

addpath('../icp/');

addpath( '../parallel' );
addpath( '../' );

%% Setup problem
m = 10; % width of grid
n = m^2; % number of points

[X,Y] = meshgrid(linspace(-2,2,m), linspace(-2,2,m));

X = reshape(X,1,[]);
Y = reshape(Y,1,[]);

Z = sin(X).*cos(Y);

% Create the data point-matrix
D = [X; Y; Z];

% Translation values (a.u.):
Tx = 0.5;
Ty = -0.3;
Tz = 0.2;

% Translation vector
T = [Tx; Ty; Tz];

% Rotation values (rad.):
rx = 0.3;
ry = -0.2;
rz = 0.05;

Rx = [1 0 0;
      0 cos(rx) -sin(rx);
      0 sin(rx) cos(rx)];
  
Ry = [cos(ry) 0 sin(ry);
      0 1 0;
      -sin(ry) 0 cos(ry)];
  
Rz = [cos(rz) -sin(rz) 0;
      sin(rz) cos(rz) 0;
      0 0 1];

% Rotation matrix
R = Rx*Ry*Rz;

% Transform data-matrix plus noise into model-matrix 
M = R * D + repmat(T, 1, n);

% Add noise to model and data
rng(2912673);
M = M + .05*randn(3,n);
D = D + .05*randn(3,n);

%% Run Co(SE3)
[Rse3 Tse3 ERse3 tse3] = ISE3(M, D, 0);

% Transform data-matrix using ICP result
Dse3 = Rse3 * D + repmat(Tse3, 1, n);

% Plot model points blue and transformed points red
figure;
subplot(2,2,1);
plot3(M(1,:),M(2,:),M(3,:),'bo',D(1,:),D(2,:),D(3,:),'r.');
axis equal;
xlabel('x'); ylabel('y'); zlabel('z');
title('Red: z=sin(x)*cos(y), blue: transformed point cloud');

% Plot the results
subplot(2,2,2);
plot3(M(1,:),M(2,:),M(3,:),'bo',Dse3(1,:),Dse3(2,:),Dse3(3,:),'r.');
axis equal;
xlabel('x'); ylabel('y'); zlabel('z');
title('ISE3 result');

% Plot RMS curve
subplot(2,2,[3 4]);
plot(0:5,ERse3,'--x');
xlabel('iteration#');
ylabel('d_{RMS}');
legend('bruteForce matching');
title(['Total elapsed time: ' num2str(tse3(end),2) ' s']);

%% Run ICP
[Ricp Ticp ERicp ticp] = icp(M, D, 5, 'Matching', 'kDtree', 'Extrapolation', false, 'Minimize', 'point');

% Transform data-matrix using ICP result
Dicp = Ricp * D + repmat(Ticp, 1, n);

% Plot model points blue and transformed points red
figure;
subplot(2,2,1);
plot3(M(1,:),M(2,:),M(3,:),'bo',D(1,:),D(2,:),D(3,:),'r.');
axis equal;
xlabel('x'); ylabel('y'); zlabel('z');
title('Red: z=sin(x)*cos(y), blue: transformed point cloud');

% Plot the results
subplot(2,2,2);
plot3(M(1,:),M(2,:),M(3,:),'bo',Dicp(1,:),Dicp(2,:),Dicp(3,:),'r.');
axis equal;
xlabel('x'); ylabel('y'); zlabel('z');
title('ICP result');

% Plot RMS curve
subplot(2,2,[3 4]);
plot(0:5,ERicp,'--x');
xlabel('iteration#');
ylabel('d_{RMS}');
legend('bruteForce matching');
title(['Total elapsed time: ' num2str(ticp(end),2) ' s']);

%%
figure;
plot(0:5,ERicp,'r--x', 0:5,ERse3,'b--x');
xlabel('iteration#');
ylabel('d_{RMS}');
legend('ICP matching', 'Co(SE3) matching');
title(['ICP vs CO(SE3)']);