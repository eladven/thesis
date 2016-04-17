function x0 = calculateEquilibriumForTheReducedSystem(Ls, J, Dp, mif, Rs, Pm, V, wg)
x0 = zeros(2,2);
w0 = wg;
lambda = asin(Pm*Ls/(V*mif));

d0=lambda;

dx = ImpSwingEq(w0, d0,...
    Ls, J, Dp, mif, Pm,V,wg);

epsilon = dx'*dx;
assert(epsilon < 10^-6,'dx is not zero at the equilibrium point')

x0(1,1) = w0;
x0(2,1) = d0;

lambda = asin(Pm*Ls/(V*mif));

d0=pi-lambda;

dx = ImpSwingEq(w0, d0,...
    Ls, J, Dp, mif, Pm,V,wg);

epsilon = dx'*dx;
assert(epsilon < 10^-6,'dx is not zero at the equilibrium point')

x0(1,2) = w0;
x0(2,2) = d0;