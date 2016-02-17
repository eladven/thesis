function [F_dynamic_] = eSymbolicDynamics(...
    e1, e2, e3, e4,...
    x1_,x2_,x3_,...
    Ltot_, J_, Dp_, mif_, Rl_, Rtot_)
e_ = [e1; e2; e3; e4];
d_ = e4;
A_ = [-Rtot_+Rl_*cos(d_) (Ltot_/2)*x3_         (Ltot_/2)*x2_       0;...
       -(Ltot_/2)*x3_      -Rtot_+Rl_*cos(d_)  -(Ltot_/2)*x1_-mif_  0;...
         0                 mif_                  -Dp_                0;...
         0                 0                    -1                 0];

lambda_ = [Ltot_ 0 0 0; 0 Ltot_ 0 0;0 0 J_ 0;0 0 0 1];

B_ = [Rl_*sin(d_)*x2_;-Rl_*sin(d_)*x1_;0;0];
F_dynamic_ = lambda_^-1*(A_*e_ + B_);