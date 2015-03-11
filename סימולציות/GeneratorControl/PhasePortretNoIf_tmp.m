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

%calculate T_m range
delta = -atan((omega_g * L_s) / R_s);
T_m1 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);
delta = delta + pi;
T_m2 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);


T_m_min = min(T_m1,T_m2)
T_m_max = max(T_m1,T_m2)

r = R_s/L_s;
mif = m*i_f;

T_minimum = J*r*(omega_g+r^2/omega_g) + (2*r^2*D_p)/omega_g+omega_g*D_p+(mif/(omega_g*L_s))*(1+mif*r);

T = zeros(1,0);
eps = zeros(1,0);

for T_m = T_m_min-1:0.2:T_m_max+1
    %initial conditions
    i_q0= 100*rand - 50;
    i_d0 = 100*rand - 50;
    omega0 = 2*omega_g*rand;
    delta0 = 500*rand;
    T = [T T_m];
    eps = [eps RunModel('syncGenInfBusNoIfSimulink',0)];
end

eps_min  = eps;
eps_max  = eps;

for index=1:35
    index
    for index2 = 1:length(eps)
        %initial conditions
        i_q0= 100*rand - 50;
        i_d0 = 100*rand - 50;
        omega0 = 2*omega_g*rand;
        delta0 = 500*rand;
        T_m = T(index2);
        temp_eps = RunModel('syncGenInfBusNoIfSimulink',0);
        eps_min(index2) = min(temp_eps,eps_min(index2));
        eps_max(index2) = max(temp_eps,eps_max(index2));
    end
    
end

figure(2);
hold on;
plot(T,eps_min,'r');
plot(T,eps_max,'b');
plot(T,eps,'g');

figure(1)
RunModel('syncGenInfBusNoIfSimulink',1)
