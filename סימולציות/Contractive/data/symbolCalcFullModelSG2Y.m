clear all
close all

syms id iq y d;
syms R Rl L mif J Dp D K


A = [(-R-Rl*cos(d))/L y/2-(Dp+2*D)*d/(4*J)-(Rl/L)*sin(d) 0 0;
    -y/2+(Dp+2*D)*d/(4*J)+(Rl/L)*sin(d) (-R-Rl*cos(d))/L -mif/L 0;
    0 2*mif/J -(Dp+2*D)/(2*J) (Dp+2*D)^2/(4*J^2)+(2*K)/J;
    0 0 1 -(Dp+2*D)/(2*J)]
z_hat = [id;iq;y;d]
f = A*z_hat
J = jacobian(f,[id;iq;y;d])
simplify(J)

