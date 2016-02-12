function [dy] = reducedModelDynamicsSmallL2(t,y)
w1 = y(1);
w2 = y(2);
d = y(3);
global Ltot J Dp mif Rl Rtot Tm
L = Ltot;
R = Rtot;

A = [-Dp/J - R*mif^2/(J*(R^2-Rl^2)), Rl*mif^2*cos(d)/(J*(R^2-Rl^2))+L*Rl*R*mif^2*(w1+w2)*sin(d)/(J*(R^2-Rl^2)^2),0;
    +Rl*mif^2*cos(d)/(J*(R^2-Rl^2))-L*mif^2*Rl*R*(w1+w2)*sin(d)/(J*(R^2-Rl^2)^2),-Dp/J - R*mif^2/(J*(R^2-Rl^2)),0;
      -1,1,0];
B = [Tm/J;Tm/J;0];
y=[w1;w2;d];
dy = A*y+B;
