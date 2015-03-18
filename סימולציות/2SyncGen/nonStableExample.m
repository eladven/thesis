close all
clear all
global Ls Lg Ltot J Rs  Dp mif Rl Rtot RT Tm


Ls =  0.01
Lg =  0
Ltot = Ls + Lg;
J = 1
Rs =  0.01
Dp = 0.2
mif = 1
Rl = 3
Rtot = Rl + Rs;
RT = Rtot + Rl;
Tm = 200

w0 = roots([Dp*Ltot^2 ,-Tm*Ltot^2, Dp*RT^2+mif^2*RT, -Tm*RT^2])
w0 = w0(3)
iq0 = (Dp*w0-Tm)/mif
id0 = (-Rtot*iq0-mif*w0-Rl*iq0)/(w0*Ltot)


syms R_ L_ w1_ mif_ Dp_ w2_ d_ Rl_ J_
A1 = [-R_ w1_*L_ 0;-w1_*L_ -R_ -mif_;0 mif_ -Dp_]
A2 = [-R_ w2_*L_ 0;-w2_*L_ -R_ -mif_;0 mif_ -Dp_]
B1 = [Rl_*cos(d_) -Rl_*sin(d_) 0;Rl_*sin(d_) Rl_*cos(d_) 0;0 0 0]
B2 = [Rl_*cos(-d_) -Rl_*sin(-d_) 0;Rl_*sin(-d_) Rl_*cos(-d_) 0;0 0 0]
lambda = [L_ 0 0 ; 0 L_ 0;0 0 J_]


syms id1_ id2_ iq1_ iq2_ Tm_
h = [A1 -B1 [0;0;0];-B2 A2 [0;0;0];[0 0 -1] [0 0 1] 0]
f = h*[id1_;iq1_;w1_;id2_;iq2_;w2_;d_]+[0;0;Tm_;0;0;Tm_;0]
f_s = subs(f,[R_ L_  mif_ Dp_  Rl_ J_ Tm_],[Rtot Ltot mif Dp Rl J Tm]);
f_s2 = subs(f_s,[iq1_ iq2_ w1_ w2_],[iq0 iq0 w0 w0])

eq1 = double(subs(f_s2,[d_ id1_ id2_],[0,id0,id0]))

%%%%%%%%%%%%%%%
RT = Rtot - Rl;
w02 = roots([Dp*Ltot^2 ,-Tm*Ltot^2, Dp*RT^2+mif^2*RT, -Tm*RT^2])
w02 = w02(1)
iq02 = (Dp*w02-Tm)/mif
id02 = (-Rtot*iq02-mif*w02+Rl*iq02)/(w02*Ltot)
 
f_s2 = subs(f_s,[iq1_ iq2_ w1_ w2_],[iq02 iq02 w02 w02])
eq2 = double(subs(f_s2,[d_ id1_ id2_],[pi,id02,id02]))


%%%%% Jacobian
T = jacobian([lambda zeros(3,4);zeros(3,3) lambda [0;0;0];0 0 0 0 0 0 1]^-1*f,[id1_;iq1_;w1_;id2_;iq2_;w2_;d_])
T1 = subs(T,[R_ L_  mif_ Dp_  Rl_ J_ Tm_],[Rtot Ltot mif Dp Rl J Tm]);
T2 = subs(T1 ,[id1_ iq1_ w1_  id2_ iq2_ w2_ d_],[id0 iq0 w0 id0 iq0 w0 0]);
eig(double(T2))

T3 = subs(T1 ,[id1_ iq1_ w1_  id2_ iq2_ w2_ d_],[id02 iq02 w02 id02 iq02 w02 pi]);
eig(double(T3))