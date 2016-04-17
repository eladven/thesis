function [F_dynamic_] = InfBusTmVarDynamics(...
    id_, iq_, w_, d_,...
    Ls_, J_, Dp_, mif_, Rs_, Pm_,V_,wg_)
x_ = [id_; iq_; w_; d_];
A_ = [-Rs_ w_*Ls_ 0 0;-w_*Ls_ -Rs_ -mif_ 0;0 mif_ -Dp_ 0;0 0 1 0];
B_ = [V_*sin(d_); V_*cos(d_); Pm_/w_+wg_*Dp_;-wg_];
lambda_ = diag([Ls_ Ls_ J_ 1]);

F_dynamic_ = (lambda_^-1)*(A_*x_+ B_);