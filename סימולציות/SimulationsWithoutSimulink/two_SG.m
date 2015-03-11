function dxdt = two_SG(t,x)
global Tm J
x1 = x(1:4);
x2 = x(5:8);
omega1 = x1(3);
omega2 = x2(3);
delta1 = x1(4);
delta2 = x2(4);
dxdt1 = A(omega1)*x1+B(delta1)*x2 + [0;0;Tm/J;0];
dxdt2 = A(omega2)*x2+B(delta2)*x1 + [0;0;Tm/J;0];
dxdt = [dxdt1 ; dxdt2];
end