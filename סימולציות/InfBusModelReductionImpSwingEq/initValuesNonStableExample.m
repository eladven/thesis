

Ls = 4.4*10^-3;
wg =  60*2*pi; 
J = 0.2; % 
Rs = 0;

Dp = 1.7; 
mif = 1.05; 

Pm =  75000;
V = 330;


x_eq = calculateEquilibrium(Ls, J, Dp, mif, Rs, Pm, V, wg);
x0 = [x_eq(1,1)+5;x_eq(2,1)-5;x_eq(3,1)-10;x_eq(4,1)];