function eps = CheckStabilityForParams(L_s,R_s,D_p,T_m,W_g,V,m,i_f,J)
syms i_d i_q W d;
mif = m*i_f;
A = [-R_s/L_s    W      0      0;
    -W      -R_s/L_s -mif/L_s 0;
    0         mif/J   -D_p/J  0;
    0           0      1      0];
B = [V*sin(d)/L_s;V*cos(d)/L_s; T_m/J; -W_g];
x = [i_d;i_q;W;d];

A_linaer = jacobian(A*x+B, x);
eq = A*x + B;
W_0 = solve(eq(4) == 0);
i_q0 = solve(eq(3) == 0,i_q);
i_q0 = subs(i_q0,W,W_0);
i_d0 = solve(eq(1) == 0,i_d);
i_d0 = subs(i_d0,{W,i_q},{W_0,i_q0});

charPolyCoeficents = charpoly(A_linaer);
charPolyCoeficents = subs(charPolyCoeficents,{W,i_q,i_d},{W_0,i_q0,i_d0});

dmin = atan(R_s/(W_g*L_s))-pi/2;
dmax = dmin+pi;
ab = zeros(0,1);
dd = zeros(0,1);
for d0 = dmin:0.05:dmax
    a
    +
    if ((subs(charPolyCoeficents(1),d,d0) <= 0) || (subs(charPolyCoeficents(2),d,d0) <= 0) ||...
        (subs(charPolyCoeficents(3),d,d0) <= 0) || (subs(charPolyCoeficents(4),d,d0) <= 0) ||...
        (subs(charPolyCoeficents(5),d,d0) <= 0) )
        elad = 18
    end
    %dd = [dd d0];
    %ab = [ab subs(a,d,d0)];
end
subs(charPolyCoeficents,d,d0)
figure(1)
plot(dd,ab)
