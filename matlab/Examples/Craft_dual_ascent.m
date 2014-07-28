% Matanya Horowitz and Nikolai Matni
% July 3, 2014
% For "A Convex Approach to Consensus on SO(n)" by Matni and Horowitz in
% Allerton, 2014.

% Suppose we have a constellation of satellites, and we wish to have them
% synchronize their orientation. We want to find the average, in the sense
% of (1).

addpath( '../parallel' );
addpath( '../' );

%% Initialization of SO(n) data
n = 3;

%dimension 8 x 4
Pa = [1, 0; 0, -1];
for i=2:n-1
    Pa = kron(Pa, [1, 0; 0, -1]);
end
Peven = .5 * [eye(2^(n-1)) + Pa;
              eye(2^(n-1)) - Pa];
          
A = cell(n,n);
lambda = cell(n,1);
rho = cell(n,1);

for i=1:n
    la = 1; pa = 1;
    
    for j=1:i-1
        la = kron(la, [1, 0; 0, -1]);
        pa = kron(pa, eye(2));
    end
    
    la = kron(la,[0, -1; 1, 0]);
    pa = kron(pa,[0, -1; 1, 0]);
    
    for j=1:n-i
        la = kron(la, eye(2));
        pa = kron(pa, [1, 0; 0, -1]);
    end
    
    lambda{i} = la;
    rho{i} = pa;
end

for i=1:n
    for j=1:n
        A{i,j} = -Peven'*lambda{i}*rho{j}*Peven;
    end
end

%% Problem data

%Data matrices
N = 12;

% This is the rotation averaging case, so B{i} = I, A{i} = R{i}_0, so
% D{i} = R{i}_0

D = cell(N,1);
D_adj = cell(N,1);
for i=1:N
    d = randn(3,3);
    [U,S,V] = svd(d);
    D{i} = U*V';
    if det(D{i}) < 0
        D{i} = - D{i};
    end
    D_adj{i} = adjoint_so(D{i},A);
end

%% Dual ascent

% We will assume a ring topology
% Initialize data
iters = 100;
alpha = 5;

Y = cell(iters+1,N,N);
Z = cell(iters+1,N);

dim = 2^(n-1);
for i=1:N
    Z{1,i} = zeros(dim);
    for j=1:N
        Y{1,i,j} = zeros(dim);
    end
end
tic()
for t=1:iters
    
    for i=1:N
        obj_data = D_adj{i};
        
        %Specific to ring topology. Change the following section for
        %different topologies.
        prev = i-1; if( prev == 0 ), prev = N; end;
        next = i+1; if( next == N+1 ), next = 1; end;
%         obj_data = obj_data - (Y{t,i,mod(prev-2,N)+1}+ Y{t,i,prev} + Y{t,i,next}+Y{t,i,mod(next+2,N)+1});
        obj_data = obj_data - (Y{t,i,prev} + Y{t,i,next});
        
        [E,e] = eig(obj_data);
        [maxv,maxi] = max(diag(e));
        mu = E(:,maxi);
        z = mu*mu';
        
%         cvx_begin sdp
%             variable z(dim,dim) symmetric;
%             
%             minimize( trace(obj_data'*z) );
%             subject to
%                 z >= 0;
%                 trace(z) == 1;
%         cvx_end
        Z{t+1,i} = z;
    end


    for i=1:N
        for j=1:N
%             Y{t+1,i,j} = Y{t,i,j} + alpha*(Z{t+1,i} - Z{t+1,j});
            Y{t+1,i,j} = Y{t,i,j} + alpha*(1/(1+.5*t))*(Z{t+1,i} - Z{t+1,j});
        end
    end


    
end
toc()
%% Visualize results

%Distance from node one

results = zeros(iters-1,N);
sample_path = zeros(4,iters-1);
for t=2:iters
    for i=1:N
        results(t-1,i) = norm(Z{t,1} - Z{t,i},'fro');
    end
    [u,v] = eigs(Z{t,1});
    [maxu,maxi]=max(diag(v));
    sample_path(:,t-1)=u(:,maxi);
end

close all
figure
plot(results);

title('Distance from Z_{1}', 'FontSize', 14);
set(gca,'FontSize',14)
xlabel('Iteration','FontSize',14)
ylabel('|| \cdot ||_{F}','FontSize',14)

% figure
% plot(sample_path');