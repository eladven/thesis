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

%random initial conditions
i_d0 = rand * 100 - 50;
i_q0= rand * 100 - 50;
omega0 = rand * 600;
delta0 = rand  * 100 - 50;

%calculate T_m range
delta = -atan((omega_g * L_s) / R_s);
T_m1 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);
delta = delta + pi;
T_m2 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);


T_m_min = min(T_m1,T_m2);
T_m_max = max(T_m1,T_m2);

%random T_m value
T_m = T_m_min + (T_m_max - T_m_min)*rand

%simulate the system 
sim('syncGenInfBusNoIfSimulink');

%plot the results
figure(1)
subplot(2,1,1);
plot(omega.Data,delta.Data);
subplot(2,1,2);
plot(i_d.Data,i_q.Data);
