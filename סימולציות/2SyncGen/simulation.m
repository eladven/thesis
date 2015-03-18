close all
clear all
global Ls Lg Ltot J Rs w0 Dp mif Rl Rtot RT Tm iq0 id0 
initValues(18.8,2*50*pi,0,1);
%nonStableExample;
T = 3;
x0 = [1;2;3;4;5;6;-pi/4];

[t,x] = ode15s(@func1,[0 T],x0);
[t2,y] = ode15s(@func2,[0 T],[x0(3);x0(6);x0(7)]);

idiq = zeros(length(t2),4);
z = zeros(length(t2),7);
for index = 1:length(t2)
    idiq(index,:) = idiqFunc([y(index,1) y(index,2) y(index,3)])
    z(index,:) = [idiq(index,1:2) y(index,1) idiq(index,3:4) y(index,2:3)];
end
figure (1)
plot(t,x(:,7))
xlabel('time [sec]');
ylabel('phase [rad]');
legend('deta')
hold on 
plot(t2,y(:,3),'r')

figure (2);
plot(t,[x(:,3) x(:,6)] )
xlabel('time [sec]');
ylabel('angular velocity [rad/sec]');
legend('w1','w2')
hold on 
plot(t2,y(:,1:2),'r')

figure (3);
plot(t,[x(:,1:2) x(:,4:5)] )
xlabel('time [sec]');
ylabel('Current [Amp]');
legend('id1','iq1','id2','iq2')
hold on 
plot(t2,idiq(:,1),'y')
plot(t2,idiq(:,2),'m')

figure (4)
plot(t,x(:,4))
hold on
plot(t2,z(:,4),'r')


