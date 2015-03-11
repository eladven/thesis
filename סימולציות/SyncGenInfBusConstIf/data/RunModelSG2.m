clear all;
close all;

global D_p J R_s L_s mif omega_g T_m R L R_l

D_p = 16e3;
J = 1822;
R_s = 0.2;
L_s = 4e-6;
mif = 1.79;
omega_g = 2*pi*50;
T_m = 10000000;
R_g = 6;
R_l = 100;
L_g = 0.15;
R = R_g + R_s +R_l;
L = L_g +L_s;

global i_q01 i_d01 omega_01 delta_01 i_q02 i_d02 omega_02 delta_02
i_q01 = 0;
i_d01 =0;
omega_01=3;
delta_01 = 0.002;
i_q02 = 0;
i_d02 =0;
omega_02 =0;
delta_02 = -delta_01;

%simulate the system
sim('SG2');

subplot(2,1,1);
hold on
plot(omega1.Time,i_d1.Data);
plot(omega2.Time,i_d2.Data,'r');
xlabel('i_d');
ylabel('time');
subplot(2,1,2);

hold on;
plot(omega1.Time,i_q1.Data)
plot(omega1.Time,i_q2.Data,'r');
xlabel('i_q');
ylabel('time');

figure(2)
subplot(2,1,1);
hold on
plot(omega1.Time,omega1.Data);
plot(omega2.Time,omega2.Data,'r');
xlabel('omega');
ylabel('time');


subplot(2,1,2);
hold on
plot(delta1.Time,delta1.Data)
plot(delta2.Time,delta2.Data,'r')
xlabel('delta');
ylabel('time');


