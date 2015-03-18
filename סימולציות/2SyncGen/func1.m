function [dx] = func1(t,x)
w1 = x(3);
w2 = x(6);
d = x(7);
global Ltot J Dp mif Rl Rtot Tm
A1 = [-Rtot w1*Ltot 0;-w1*Ltot -Rtot -mif;0 mif -Dp];
A2 = [-Rtot w2*Ltot 0;-w2*Ltot -Rtot -mif;0 mif -Dp];
B1 = [Rl*cos(d) -Rl*sin(d) 0;Rl*sin(d) Rl*cos(d) 0;0 0 0];
B2 = [Rl*cos(-d) -Rl*sin(-d) 0;Rl*sin(-d) Rl*cos(-d) 0;0 0 0];
lambda = [Ltot 0 0 ; 0 Ltot 0;0 0 J];

h = [lambda^-1*[A1 -B1 [0;0;0]];lambda^-1*[-B2 A2 [0;0;0]];[0 0 -1] [0 0 1] 0];

dx = h*x+[0;0;Tm/J;0;0;Tm/J;0];