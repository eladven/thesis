close all
clear all
global Ls Lg Ltot J Rs  Dp mif Rl Rtot RT Tm


Ls =  10^-4;
Lg =  0;
Ltot = Ls + Lg;
J = 0.2;
Rs =  0.011;
Dp = 1.7;
mif = -1.38
Rl = 18.8;
Rtot = Rl + Rs;
RT = Rtot + Rl;
Tm = 549.9779

w0 = roots([Dp*Ltot^2 ,-Tm*Ltot^2, Dp*RT^2+mif^2*RT, -Tm*RT^2])
w0 = w0(3)
iq0 = (Dp*w0-Tm)/mif
id0 = (-Rtot*iq0-mif*w0-Rl*iq0)/(w0*Ltot)

syms R_ L_ w1_ mif_ Dp_ w2_ d_ Rl_ J_ Tm_;
A = [-Dp_/J_ + R_*mif_^2/(J_*(R_^2-Rl_^2)),-Rl_*mif_^2*cos(d_)/(J_*(R_^2-Rl_^2)),0;
    -Rl_*mif_^2*cos(d_)/(J_*(R_^2-Rl_^2)),-Dp_/J_ + R_*mif_^2/(J_*(R_^2-Rl_^2)),0;
      -1,1,0]
B = [Tm_/J_;Tm_/J_;0]
y=[w1_;w2_;d_]
f = A*y+B
f_s = subs(f,[R_ L_  mif_ Dp_  Rl_ J_ Tm_],[Rtot Ltot mif Dp Rl J Tm])
f_s2 = double(subs(f_s,[w1_ w2_ d_],[w0 w0 0]))
