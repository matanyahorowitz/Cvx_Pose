function res = z2so(Z, A)
    n = size(A,1);
    
    res = zeros(n,n);
    
    for i=1:n
        for j=1:n
            res(i,j) = trace(A{i,j}'*Z);
        end
    end
end