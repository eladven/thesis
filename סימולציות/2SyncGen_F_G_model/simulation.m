 TwoSyncGenSymbolicDynamics;

global Ls Lg Ltot J Rs w0 Dp mif Rl Rtot RT Tm iq0 id0 
initValuesVivek(300,2*20*pi,0,1);

T = 5;
x0 = [19;-35;0;19;-32;0;0.5];

[t,x] = ode15s(@modelDynamics,[0 T],x0);


figure (1)
plot(t,x(:,7))
st = sprintf('Parameters: Ltot=%f, J=%f, Rs=%f, Dp=%f, mif=%f, Rl Rtot RT Tm', ...
   Ltot,J,Rs,Dp,mif)
title(st);
xlabel('time [sec]');
ylabel('phase [rad]');
hold on 
legend('delta','delta-hat')

figure (2);
plot(t,[x(:,3) x(:,6)] )
xlabel('time [sec]');
ylabel('angular velocity [rad/sec]');
hold on 
legend('w1','w2','w1-hat','w2-hat')

figure (3);
plot(t,x(:,1:2))
xlabel('time [sec]');
ylabel('Current [Amp]');
legend('id1','iq1','id2','iq2')
hold on 
legend('id1','iq1','id1-hat','iq1-hat')

