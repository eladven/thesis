function dxdt = osc(t,x)
global alpha;
 dxdt = [x(2)
 -alpha*x(2) - sin(x(1))];
end