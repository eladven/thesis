clear all

syms Dp_ Rtot_ Rl_ mif_ Ltot_ D_ y_ J_ K_ d_
H = [(-Rl_*cos(d_)-Rtot_)/Ltot_ y_/2-d_*(Dp_+2*D_)/(2*J_)-Rl_/Ltot_*sin(d_) 0 0;
    -y_/2+d_*(Dp_+2*D_)/(2*J_)+Rl_/Ltot_*sin(d_) (-Rl_*cos(d_)-Rtot_)/Ltot_ -mif_/Ltot_ 0;
    0 mif_/J_ -(Dp_+2*D_)/(2*J_) (Dp_+2*D_)^2/(4*J_^2)-2*K_/J_;
    0 0 1 -(Dp_+2*D_)/(2*J_)]
syms id_ iq_
z = [id_;iq_;y_;d_]

Jac = simplify(jacobian(H*z,z))

global Dp Rtot Rl mif Ltot k J
initValues(18.8,50*2*pi,0,1);
Jac = subs(Jac,[Dp_ Rtot_ Rl_ mif_ Ltot_ J_],[Dp Rtot Rl mif Ltot J])

JacPlus = ((Jac)+(Jac'))/2
eig(JacPlus)