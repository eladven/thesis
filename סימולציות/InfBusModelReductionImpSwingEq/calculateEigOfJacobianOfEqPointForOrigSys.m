function [eige] = calculateEigOfJacobianOfEqPointForOrigSys(Ls, J, Dp, mif, Rs, Pm, V, wg,...
    id0, iq0, w0, d0)
syms id_ iq_ w_ d_

F = InfBusTmVarDynamics(...
    id_, iq_, w_, d_,...
    Ls, J, Dp, mif, Rs, Pm,V,wg);

FJacobian = jacobian(F,[id_;iq_;w_;d_]);
T = subs(FJacobian ,[id_ iq_ w_ d_],[id0 iq0 w0 d0]);
eige = eig(double(T));