function [eige] = calculateEigOfJacobianOfEqPointForOrigSys(Ltot,J,Dp,mif,Rl,Rtot,Tm,...
    id0, iq0, w0, d0)
syms id1_ iq1_ w1_ id2_ iq2_ w2_ d_ 
syms Ltot_ J_ Dp_ mif_ Rl_ Rtot_ Tm_
dx = TwoSyncGenSymbolicDynamics(id1_, iq1_, w1_, id2_, iq2_, w2_, d_,...
    Ltot_, J_, Dp_, mif_, Rl_, Rtot_, Tm_);
FJacobian = jacobian(dx,[id1_;iq1_;w1_;id2_;iq2_;w2_;d_]);
T1 = subs(FJacobian,[Rtot_ Ltot_  mif_ Dp_  Rl_ J_ Tm_],[Rtot Ltot mif Dp Rl J Tm]);
T2 = subs(T1 ,[id1_ iq1_ w1_  id2_ iq2_ w2_ d_],[id0 iq0 w0 id0 iq0 w0 0]);
eige = eig(double(T2));