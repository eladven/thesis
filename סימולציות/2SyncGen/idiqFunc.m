function [idiq] = idiqFunc(y)
w1 = y(1);
w2 = y(2);
d = y(3);
global Ltot Dp mif Rl Rtot;
A1 = [-Rtot w1*Ltot 0;-w1*Ltot -Rtot -mif;0 mif -Dp];
A2 = [-Rtot w2*Ltot 0;-w2*Ltot -Rtot -mif;0 mif -Dp];
B1 = [Rl*cos(d) -Rl*sin(d) 0;Rl*sin(d) Rl*cos(d) 0;0 0 0];
B2 = [Rl*cos(-d) -Rl*sin(-d) 0;Rl*sin(-d) Rl*cos(-d) 0;0 0 0];

h = [A1 -B1 [0;0;0];-B2 A2 [0;0;0];[0 0 -1] [0 0 1] 0];

Asys = [h(1:2,1:2) h(1:2,4:5);h(4:5,1:2) h(4:5,4:5)];
Bsys = [-h(1:2,3)*w1-h(1:2,6)*w2-h(1:2,7)*d;-h(4:5,3)*w1-h(4:5,6)*w2-h(4:5,7)*d];
idiq = (Asys^-1)*Bsys;