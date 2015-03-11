close all;
global D alpha psi1_0 psi2_0 psi1_dot_0 psi2_dot_0

D = 10;
alpha = 0.3;
psi1_0 = rand*pi-pi/2;
psi2_0 = rand*pi-pi/2;
psi1_dot_0 = rand*4 - 2;
psi2_dot_0 = rand*4 - 2;

%simulate the system
sim('CupeledPendelums');

figure(1);
subplot(4,1,1);
hold on;
plot(psi1.data,psi1_dot.data,'b');
plot(psi2.data,psi2_dot.data,'r');
subplot(4,1,2);
hold on;
plot(psi1.time,psi1_dot.data-psi2_dot.data,'b');
subplot(4,1,3);
hold on;
plot(psi1.time,psi1.data-psi2.data,'b');
subplot(4,1,4);
hold on;
norm = sqrt(psi1.data.^2+psi1_dot.data.^2+psi2.data.^2+psi2_dot.data.^2);
plot(psi1.time,norm,'b');

D = 0;

%simulate the system
sim('CupeledPendelums');

figure(1);
subplot(4,1,1);
hold on;
plot(psi1.data,psi1_dot.data,'g');
plot(psi2.data,psi2_dot.data,'y');
xlabel('angle');
ylabel('angular velocity');
legend('x1 with coupling','x2 with coupling','x1 without coupling','x2 without coupling');
subplot(4,1,2);
hold on;
plot(psi1.time,psi1_dot.data-psi2_dot.data,'r');
xlabel('time');
ylabel('dpsi1/dt-dpsi2/dt');
legend('with coupling','without coupling');
subplot(4,1,3);
hold on;
plot(psi1.time,psi1.data-psi2.data,'r');
xlabel('time');
ylabel('psi1-psi2');
legend('with coupling','without coupling');
subplot(4,1,4);
hold on;
norm = sqrt(psi1.data.^2+psi1_dot.data.^2+psi2.data.^2+psi2_dot.data.^2);
plot(psi1.time,norm,'r');
xlabel('time');
ylabel('vector norm');
legend('with coupling','without coupling');

