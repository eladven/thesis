

Ls = 4.4*10^-5;
wg =  60*2*pi; 
J = 0.2; % 
Rs = 0.15;

Dp = 1.7; 
mif = 1.05; 

Pm =  10000;
V = 630;


x_eq = calculateEquilibrium(Ls, J, Dp, mif, Rs, Pm, V, wg);
x0 = [x_eq(1,1)+5;x_eq(2,1)-5;x_eq(3,1)-10;x_eq(4,1)];