% Matanya Horowitz, Nikolai Matni
% Example using CVXGEN for a simple 2D estimation problem.

% Assume there are 100 beacons with known positions. Then assume we get a
% corrupted reading of their signals, with measured distance and
% orientation. The problem is solved first using CVX, and then the
% QP/CVXGEN method

addpath('./../');
