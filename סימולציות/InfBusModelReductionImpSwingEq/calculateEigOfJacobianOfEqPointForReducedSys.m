function [eige] = calculateEigOfJacobianOfEqPointForReducedSys(Ls, J, Dp, mif, Rs, Pm, V, wg,...
    w0, d0)
syms w_ d_

F = ImpSwingEq(w_, d_,...
    Ls, J, Dp, mif, Pm,V,wg);

FJacobian = jacobian(F,[w_;d_]);
T = subs(FJacobian ,[w_ d_],[w0 d0]);
eige = eig(double(T));