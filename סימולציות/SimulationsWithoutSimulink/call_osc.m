close all;
global alpha
alpha = 100000
 tspan = [0:0.05:50];
 x1_0 = -2;
 x2_0 = 2;
 [T,X] = ode15s(@osc,tspan,[x1_0 x2_0]);
 figure(1)
 plot(T,X(:,1))
 hold on
 plot(T,X(:,2),'r')
 figure(2)
  plot(X(:,1),X(:,2))