function dxdt = two_SG(t,x)
 A = [-R/L    1     0       0;
      -1    -R/L  -mif/L    0;
       0    mif/J -Dp/J     0;
       0      0     1       0]

B = [(-R-Rl*cos(d))/L y/2-(Dp+2*D)*d/(4*J)-(Rl/L)*sin(d) 0 0;
    -y/2+(Dp+2*D)*d/(4*J)+(Rl/L)*sin(d) (-R-Rl*cos(d))/L -mif/L 0;
    0 2*mif/J -(Dp+2*D)/(2*J) (Dp+2*D)^2/(4*J^2)+(2*K)/J;
    0 0 1 -(Dp+2*D)/(2*J)]
 dxdt = [x(2)
 -alpha*x(2) - sin(x(1))];
end