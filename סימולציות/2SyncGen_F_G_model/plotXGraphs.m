function [] = plotXGraphs(x,t)
figure (1)
plot(t,x(:,7))
xlabel('time [sec]');
ylabel('phase [rad]');
legend('delta')
 
figure (2);
plot(t,[x(:,3) x(:,6)] )
xlabel('time [sec]');
ylabel('angular velocity [rad/sec]');
legend('w1','w2')
 
figure (3);
plot(t,[x(:,1:2) x(:,4:5)])
xlabel('time [sec]');
ylabel('Current [Amp]');
legend('id1','iq1','id2','iq2')
