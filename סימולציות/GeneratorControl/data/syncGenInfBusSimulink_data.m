clear all
syms m Ls Lf J m Ls Lf J Rs w If Dp Rf;
L = [Ls 0 m 0 0;0 Ls 0 0 0;m 0 Lf 0 0;0 0 0 J 0 ;0 0 0 0 1]
LA = [-Rs w*Ls 0 0 0;-w*Ls -Rs 0 -m*If 0; 0 0 -Rf 0 0; 0 m*If 0 -Dp 0; 0 0 0 1 0]
L1 = L^-1
A = L1*LA
clear all

T_m = 50;
V_f = 300;
D_p =0.2;
J = 0.1;
R_s = 0.2;
R_l = 2000;
R_f = 0.02;
M_f = 0.5e-2;
L_f = 1e-2;
L_s = 1e-2;
m = sqrt(3/2)*M_f;
gamma = 1/(m^2-L_s*L_f);

omega_g = 50*2*pi;
V = 220;

