close all;
clear all;
global alpha psi1_0 psi2_0 psi1_dot_0 psi2_dot_0 K D

alpha = rand*2;
D = (4-alpha)/2;  %% alpha+2D = 4 -> D = (4-alpha)/2
K = 2.5;

psi1_0 = 2*rand-1;
psi2_0 = 2*rand-1;
psi1_dot_0 = 2*rand-1;
psi2_dot_0 = 2*rand-1;

%simulate the system
sim('CupeledPendelums_simple_D_K');

figure(1);
subplot(2,1,1);
hold on;
plot(psi1.time,psi1.data,'b');
plot(psi1.time,psi2.data,'r');
xlabel('time');
ylabel('phase');
legend('x_1','x_2','Interpreter','latex');
subplot(2,1,2);
hold on;
plot(psi1.time,psi1_dot.data,'b');
plot(psi1.time,psi2_dot.data,'r');
xlabel('time');
ylabel('velocity');
h = legend('$\frac{dx_1}{dt}$','$\frac{dx_2}{dt}$');
set(h,'Interpreter','latex','FontSize',16)

%% Calculate the exponential bound:

syms alpha_sim x y K_sim D_sim;

f = [-((alpha_sim+2*D_sim)/2)*x+y;(((alpha_sim+2*D_sim)^2)/4)*x-sin(x)-((alpha_sim+2*D_sim)/2)*y-2*K_sim*x];

J = jacobian(f,[x y]);
J_s = (J+J.')/2;
lambda = eig(J_s)
lambda = subs(lambda,[alpha_sim D_sim K_sim],[alpha D K])

eigmax = -10000;
xmin = min(min(x1.data),min(x2.data));
xmax = max(max(x1.data),max(x2.data));
for x_num = xmin:(xmax - xmin)/100:xmax
    local_max_eig = max(double(subs(lambda, x, x_num)));
    if (local_max_eig > eigmax)
        eigmax = local_max_eig;
    end
end
eigmax

x_vect =[];
local_max_eig =[];
local_max_eig = [];
for x_=xmin:(xmax - xmin)/100:xmax
    x_vect = [x_vect x_];
    local_max_eig = [local_max_eig max(double(subs(lambda,x,x_)))];
end
figure(4);
plot(x_vect,local_max_eig);
xlabel('x');
h = ylabel('$max(\lambda)$');
set(h,'Interpreter','latex','FontSize',16)
title('max lambda vs x over trajectory');

%% plot the results

norm = sqrt((psi2.data-psi1.data).^2+(psi2_dot.data-psi1_dot.data).^2);
expo = norm(1)*exp(eigmax*psi1.time); 
figure(2)
hold on

plot(psi1.time,norm);
plot(psi1.time,expo,'r');
xlabel('time');
ylabel('L_2 norm');
h = legend('$|x_1(t) - x_2(t)|$','$e^{\lambda_{max} t}|x_1(0) - x_2(0)|$');
set(h,'Interpreter','latex','FontSize',16)

norm2 = sqrt((x2.data-x1.data).^2+(y2.data-y1.data).^2);
expo2 = norm2(1)*exp(eigmax*psi1.time); 
figure(3)
hold on

plot(psi1.time,norm2);
plot(psi1.time,expo2,'r');
xlabel('time');
ylabel('L_2 norm');
h =legend('$|z_1(t) - z_2(t)|$','$e^{\lambda_{max} t}|z_1(0) - z_2(0)|$');
set(h,'Interpreter','latex','FontSize',16)

