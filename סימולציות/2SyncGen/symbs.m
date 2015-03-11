syms R_ L_ w1_ mif_ Dp_ w2_ d_ Rl_ J_
A1 = [-R_ w1_*L_ 0;-w1_*L_ -R_ -mif_;0 mif_ -Dp_]
A2 = [-R_ w2_*L_ 0;-w2_*L_ -R_ -mif_;0 mif_ -Dp_]
B1 = [Rl_*cos(d_) -Rl_*sin(d_) 0;Rl_*sin(d_) Rl_*cos(d_) 0;0 0 0]
B2 = [Rl_*cos(-d_) -Rl_*sin(-d_) 0;Rl_*sin(-d_) Rl_*cos(-d_) 0;0 0 0]
lambda = [L_ 0 0 ; 0 L_ 0;0 0 J_]

h = [lambda^-1*[A1 -B1 [0;0;0]];lambda^-1*[-B2 A2 [0;0;0]];[0 0 -1] [0 0 1] 0]

syms id1_ iq1_ id2_ iq2_
z1 = [id1_;iq1_;w1_]
z2 = [id2_;iq2_;w2_]
z= [z1;z2;d_]


global Ltot J w0 Dp mif Rl Rtot iq0 id0;


h_ = h*z+[0;0;Tm/J;0;0;Tm/J;0]
hn = subs(h_,[R_ L_ mif_ Dp_ Rl_ J_],[Rtot Ltot mif Dp Rl J]);
hn = subs(hn,[id1_ iq1_ w1_ id2_ iq2_ w2_ d_],[id0 iq0 w0 id0 iq0 w0 0]);
double(hn)

T = jacobian(h_,z)
syms id0_ iq0_ w0_
T1 = subs(T,[id1_ iq1_ w1_ id2_ iq2_ w2_ d_],[id0_ iq0_ w0_ id0_ iq0_ w0_ 0])
T2 = subs(T1,[R_ L_ mif_ Dp_ Rl_ J_],[Rtot Ltot mif Dp Rl J]);
T3 = subs(T2,[id0_ iq0_ w0_ ],[id0 iq0 w0]);
eig(double(T3))