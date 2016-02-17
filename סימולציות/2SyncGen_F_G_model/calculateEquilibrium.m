function [id0, iq0, w0, d0] = calculateEquilibrium(Ltot,J,Dp,mif,Rl,Rtot,Tm)
RT = Rtot + Rl;
w0 = roots([Dp*Ltot^2 ,-Tm*Ltot^2, Dp*RT^2+mif^2*RT,...
    -Tm*RT^2]);
w0 = w0(imag(w0)==0);
iq0 = (Dp*w0-Tm)/mif;
id0 = (-Rtot*iq0-mif*w0-Rl*iq0)/(w0*Ltot);
d0 = 0;

dx = TwoSyncGenSymbolicDynamics(...
    id0, iq0, w0, id0, iq0, w0, 0,...
    Ltot, J, Dp, mif, Rl, Rtot, Tm);
epsilon = dx'*dx;
assert(epsilon < 10^-6,'dx is not zero at the equilibrium point')