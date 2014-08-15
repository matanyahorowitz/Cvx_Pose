function A = init_z2so(n)

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

end