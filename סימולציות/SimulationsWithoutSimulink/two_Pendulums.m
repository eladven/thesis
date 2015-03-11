function dxdt = two_SG(t,x)
global D K
x1 = x(1:2);
x2 = x(3:4);
dxdt1 = A_Pnd(x1(1))*x1+[0; D*(x2(2)-x1(2))+K*(x2(1)-x1(1))];
dxdt2 = A_Pnd(x2(1))*x2+[0; D*(x1(2)-x2(2))+K*(x1(1)-x2(1))];
dxdt = [dxdt1 ; dxdt2];
end