clear all;
close all;

%% Vivik params
% Rs=0.152;
% Ls=4.4e-3;
% wg=2*pi*50;
% J=0.02;
% mif=-1.38;
% Dp=10.14;
% Tm=10+Dp*wg;
% V=230*sqrt(3);

%my params
global D_p J R_s M_f L_s omega_g V i_f T_m;
global i_q0 i_d0 omega0 delta0
D_p = 0.2;
J = 0.2;
R_s = 0.2; 
R_f = 0.02;
M_f = 0.5e-2;
L_f = 1e-2;
L_s = 1e-2;
m = sqrt(3/2)*M_f;
i_f = -10;
omega_g = 50*2*pi;
V = 220;

figure(1)
RegionOfAttraction(10);

