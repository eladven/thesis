close all;
global R Rl mif J Dp L Tm
R = 130;
Rl = 110;
J = 3;
Dp = 0.3;
mif = 10^-1;
L = 10^-3;
Tm = 100;

tspan = [0:0.05:200];
delta0 = 1;
x1_0 = [-2;6;347.9;delta0]*0.06;
x2_0 = [1;4;348.2;-delta0]*0.06;
[T,X] = ode23s(@two_SG,tspan,[x1_0; x2_0]);
X1 = X(:,1:4);
X2 = X(:,5:8);

x1_hat_0 = x1_0(3:4);
x2_hat_0 = x1_0(3:4);
[T,X_hat] = ode23s(@two_SG_hat,tspan,[x1_hat_0; x2_hat_0]);
X1_hat = X_hat(:,1:2);
X2_hat = X_hat(:,3:4);

figure(1)
subplot(2,2,1);
plot(T,X1(:,3))
hold on
plot(T,X2(:,3),'r')
plot(T,X1_hat(:,1),'g')
plot(T,X2_hat(:,1),'y')


subplot(2,2,2);
plot(T,X1(:,4))
hold on
plot(T,X2(:,4),'r')

subplot(2,2,3);
plot(T,X1(:,1))
hold on
plot(T,X2(:,1),'r')


subplot(2,2,4);
plot(T,X1(:,2))
hold on
plot(T,X2(:,2),'r')

dx = X1 - X2;
ainfNorm = arrayfun(@(idx) norm(dx(idx,:),inf), 1:size(dx,1));
a1Norm = arrayfun(@(idx) norm(dx(idx,:),1), 1:size(dx,1));
a2Norm = arrayfun(@(idx) norm(dx(idx,:),2), 1:size(dx,1));

figure(2)

plot (T,ainfNorm,'b');
hold on 
plot (T,a1Norm,'r');
plot (T,a2Norm,'g');









