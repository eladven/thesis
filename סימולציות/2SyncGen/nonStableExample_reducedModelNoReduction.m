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
w0 =  314.1592 %w0(3)
iq0 = (Dp*w0-Tm)/mif
id0 = (-Rtot*iq0-mif*w0-Rl*iq0)/(w0*Ltot)

syms R_ L_ w1_ mif_ Dp_ w2_ d_ Rl_ J_ Tm_;
A = [-Dp_/J_*w1_;-Dp_ / J_*w2_;w2_-w1_]
B = [-mif_^2*(Rl_*w2_*(-R_^2+Rl_^2+L_^2*w1_*w2_)*cos(d_)+R_*(w1_*(R_^2-Rl_^2+L_^2*w2_^2)-L_*Rl_*w2_*(w1_+w2_)*sin(d_))) / (J_*(R_^4+(Rl_^2+L_^2*w1_*w2_)^2+R_^2*(-2*Rl_^2+L_^2*(w1_^2+w2_^2))))+Tm_/J_;...
     -mif_^2*(Rl_*w1_*(-R_^2+Rl_^2+L_^2*w2_*w1_)*cos(d_)+R_*(w2_*(R_^2-Rl_^2+L_^2*w1_^2)-L_*Rl_*w1_*(w2_+w1_)*sin(d_))) / (J_*(R_^4+(Rl_^2+L_^2*w1_*w2_)^2+R_^2*(-2*Rl_^2+L_^2*(w1_^2+w2_^2))))+Tm_/J_;...
     0]
f = A+B
y=[w1_;w2_;d_];
f_s = subs(f,[R_ L_  mif_ Dp_  Rl_ J_ Tm_],[Rtot Ltot mif Dp Rl J Tm])
f_s2 = double(subs(f_s,[w1_ w2_ d_],[w0 w0 0]))

%%%%% Jacobian
T = simplify(jacobian(f,y))
T1 = subs(T,[R_ L_  mif_ Dp_  Rl_ J_ Tm_],[Rtot Ltot mif Dp Rl J Tm]);
T2 = subs(T1 ,[w1_  w2_ d_],[w0 w0 0])
eig_eq_d_zero = eig(double(T2))
