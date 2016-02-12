%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% This script calculate the symbolic model synamics.
% 
% Our convention is that varable with _ suffix is 
% symbolic, while variable without this suffix is numeric.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

syms id1_ iq1_ w1_ id2_ iq2_ w2_ d_
syms Ltot_ J_ Dp_ mif_ Rl_ Rtot_ Tm_
x_ = [id1_; iq1_; w1_; id2_; iq2_; w2_; delta_];
A1_ = [-Rtot_ w1_*Ltot_ 0;-w1_*Ltot_ -Rtot_ -mif_;0 mif_ -Dp_];
A2_ = [-Rtot_ w2_*Ltot_ 0;-w2_*Ltot_ -Rtot_ -mif_;0 mif_ -Dp_];
B1_ = [Rl_*cos(d_) -Rl_*sin(d_) 0;Rl_*sin(d_) Rl_*cos(d_) 0;0 0 0];
B2_ = [Rl_*cos(-d_) -Rl_*sin(-d_) 0;Rl_*sin(-d_) Rl_*cos(-d_) 0;0 0 0];
lambda_ = [Ltot_ 0 0 ; 0 Ltot_ 0;0 0 J_];

h_ = [lambda_^-1*[A1_ -B1_ [0;0;0]];lambda_^-1*[-B2_ A2_ [0;0;0]];[0 0 -1] [0 0 1] 0];
F_dynamic_ = h_*x_+[0;0;Tm_/J_;0;0;Tm_/J_;0];