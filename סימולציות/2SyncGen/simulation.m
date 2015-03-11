close all
clear all
initValues(18.8,2*50*pi,0,1);


x0 = [1;2;3;4;5;6;-pi/4];

[t,x] = ode15s(@func1,[0 10],x0);
figure (1)
plot(t,x(:,7))
xlabel('time [sec]');
ylabel('phase [rad]');
legend('deta')
axis([0,3000,330,365]);

figure (2);
plot(t,[x(:,3) x(:,6)] )
xlabel('time [sec]');
ylabel('angular velocity [rad/sec]');
legend('w1','w2')
axis([0,3000,0.5,5]);

figure (3);
plot(t,[x(:,1:2) x(:,4:5)] )
xlabel('time [sec]');
ylabel('Current [Amp]');
legend('id1','iq1','id2','iq2')
axis([0,3000,-0.2,1]);

