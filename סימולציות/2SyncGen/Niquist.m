close all
global Ls Lg Ltot J Rs w0 Dp mif Rl Rtot RT Tm iq0 id0 

lambda = [Ls 0 0;0 Ls 0 ;0 0 J];
lambdaA = [-Rs w0*Ls Ls*iq0;-w0*Ls -Rs -Ls*id0-mif; 0 mif -Dp];
lambdaB = [sqrt(2)*Rl*iq0;-sqrt(2)*Rl*id0;0];
C = [0 0 sqrt(2)];
s = tf('s');
G = C*((lambda*s-lambdaA)^-1)*lambdaB;
H = 1/s;
figure

subplot(2,2,1);
nyquist(G);

subplot(2,2,2);
nyquist(G);
ax = axis;
axis(ax/10);

subplot(2,2,3);
nyquist(G*H);
subplot(2,2,4);
nyquist(G*H);
ax = axis/50;
ax(3) = -(ax(2)-ax(1));
ax(4) = -ax(3)
axis(ax);

A_eig = eig(lambda^-1*lambdaA);


A_ = [lambdaA lambdaB;-C 0];
A_ = ([Ls/sqrt(2) 0 0 0;0 Ls/sqrt(2) 0 0;0 0 J/sqrt(2) 0;0 0 0 1]^-1)*A_;
close_loop_eig = eig(A_);

A = lambda^-1*lambdaA;
B = lambda^-1*lambdaB;

