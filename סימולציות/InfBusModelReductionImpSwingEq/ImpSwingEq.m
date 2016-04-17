function [F_dynamic_] = ImpSwingEq(...
    w_, d_,...
    Ls_, J_, Dp_, mif_, Pm_,V_,wg_)


dw = (-Dp_/J_)*(w_-wg_)+Pm_/(J_*w_) -V_*mif_*sin(d_)/(Ls_*J_*w_);
dd = w_ - wg_;

F_dynamic_ = [dw;dd];