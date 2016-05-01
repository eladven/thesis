function x0 = calculateEquilibrium(Ls, J, Dp, mif, Rs, Pm, V, wg)
x0 = zeros(4,2);
w0 = wg;
Tm = Pm/wg+wg*Dp;
iq0 = (Dp*wg-Tm) / mif;
p = Rs/Ls;
psi = asin(wg/sqrt(p^2 + wg^2));
lambda = acos((Dp*wg-Tm)*Ls*sqrt(p^2+wg^2)/(mif*V)+mif*wg*p/(V*sqrt(p^2+wg^2)));

d0 = lambda-psi;
id0 = (V*cos(d0)-mif*wg-Rs*iq0)/(wg*Ls);

dx = InfBusTmVarDynamics(...
   id0, iq0, w0, d0,...
    Ls, J, Dp, mif, Rs, Pm,V,wg);

epsilon = dx'*dx;
assert(epsilon < 10^-6,sprintf('dx is not zero at the equilibrium point. epsilon: %f',epsilon))

x0(1,1) = id0; 
x0(2,1) = iq0;
x0(3,1) = w0; 
x0(4,1) = d0; 



d0 = -lambda-psi;
id0 = (V*cos(d0)-mif*wg-Rs*iq0)/(wg*Ls);


dx = InfBusTmVarDynamics(...
   id0, iq0, w0, d0,...
    Ls, J, Dp, mif, Rs, Pm,V,wg);

epsilon = dx'*dx;
assert(epsilon < 10^-6,'dx is not zero at the equilibrium point')

x0(1,2) = id0; 
x0(2,2) = iq0;
x0(3,2) = w0; 
x0(4,2) = d0; 