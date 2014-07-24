function projected = proj_spectra(Q)
    [U,u] = eig(Q);
    eigvals = diag(u);
    uproj = projsplx(eigvals);
    projected = U*diag(uproj)*U';
end