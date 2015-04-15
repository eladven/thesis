function [dy] = func2(t,y)
w1 = y(1);
w2 = y(2);
d = y(3);
global Ltot J Dp mif Rl Rtot Tm
t
A1 = [-Rtot w1*Ltot 0;-w1*Ltot -Rtot -mif;0 mif -Dp];
A2 = [-Rtot w2*Ltot 0;-w2*Ltot -Rtot -mif;0 mif -Dp];
B1 = [Rl*cos(d) -Rl*sin(d) 0;Rl*sin(d) Rl*cos(d) 0;0 0 0];
B2 = [Rl*cos(-d) -Rl*sin(-d) 0;Rl*sin(-d) Rl*cos(-d) 0;0 0 0];
lambda = [Ltot 0 0 ; 0 Ltot 0;0 0 J];

h = [lambda^-1*[A1 -B1 [0;0;0]];lambda^-1*[-B2 A2 [0;0;0]];[0 0 -1] [0 0 1] 0];
Asys = [h(1:2,1:2) h(1:2,4:5);h(4:5,1:2) h(4:5,4:5)];
Bsys = [-h(1:2,3)*w1-h(1:2,6)*w2-h(1:2,7)*d;-h(4:5,3)*w1-h(4:5,6)*w2-h(4:5,7)*d];
idiq = (Asys^-1)*Bsys

x = [idiq(1);idiq(2);w1;idiq(3);idiq(4);w2;d];
dx =  h*x+[0;0;Tm/J;0;0;Tm/J;0];
dy = [dx(3);dx(6);dx(7)];