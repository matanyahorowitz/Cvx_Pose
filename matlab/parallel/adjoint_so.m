function res = adjoint_so(Y,A)
n = size(A,1);
res = zeros(2^(n-1));

for i=1:n
    for j=1:n
        res = res + Y(i,j)*A{i,j};
    end
end