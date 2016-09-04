function [F_dynamic_] = ImpSwingEqConstTm(...
    w_, d_,...
    Ls_, J_, Dp_, mif_, Tm_,V_,wg_)


dw = (-Dp_/J_)*w_+Tm_/J_ -V_*mif_*sin(d_)/(Ls_*J_*w_);
dd = w_ - wg_;

F_dynamic_ = [dw;dd]; 