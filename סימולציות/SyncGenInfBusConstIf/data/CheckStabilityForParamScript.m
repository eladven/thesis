clear all
close all


%my params
D_p =0.2;
J = 0.1;
R_s = 0.2;
R_f = 0.02;
M_f = 0.5e-2;
L_f = 1e-2;
L_s = 1e-2;
m = sqrt(3/2)*M_f;
i_f = -10;
omega_g = 50*2*pi;
V = 220;

%calculate T_m range
delta = -atan((omega_g * L_s) / R_s);
T_m1 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);
delta = delta + pi;
T_m2 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);


T_m_min = min(T_m1,T_m2);
T_m_max = max(T_m1,T_m2);
T_m = T_m_min +1;
W_g = omega_g;
CheckStabilityForParams(L_s,R_s,D_p,T_m,W_g,V,m,i_f,J)