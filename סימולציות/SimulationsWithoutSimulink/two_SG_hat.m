function dxdt = two_SG_hat(t,x)
global Tm J
x1 = x(1:2);
x2 = x(3:4);
delta1 = x1(2);
delta2 = x2(2);
dxdt1 = A_hat()*x1+B_hat(delta1)*x2 + [Tm/J;0];
dxdt2 = A_hat()*x2+B_hat(delta2)*x1 + [Tm/J;0];
dxdt = [dxdt1 ; dxdt2];
end