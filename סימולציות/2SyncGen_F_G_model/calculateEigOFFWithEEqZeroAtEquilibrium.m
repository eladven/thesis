function [eig_] = calculateEigOFFWithEEqZeroAtEquilibrium(x1,x2,x3,Ltot,J,Dp,mif,Rl,Rtot)
syms e1 e2 e3 e4
de = eSymbolicDynamics(e1, e2, e3, e4,x1,x2,x3,Ltot, J, Dp, mif, Rl, Rtot);

FJacobian = jacobian(de,[e1;e2;e3;e4]);
T = subs(FJacobian,e4,0);
eig_ = eig(double(T));