syms R_s L_s D_p J mif V T_m W_g;
syms i_d i_q W d;

A = [-R_s/L_s    W      0      0;
     -W      -R_s/L_s -mif/L_s 0;
     0         mif/J   -D_p/J  0;
     0           0      1      0];
B = [V*sin(d)/L_s;V*cos(d)/L_s; T_m/J; -W_g];
x = [i_d;i_q;W;d];

A_linaer = jacobian(A*x+B, x);

charPolyCoeficents = charpoly(A_linaer);

% calculate the equalibrium point
eq = A*x + B;

W_0 = solve(eq(4) == 0); 
i_q0 = solve(eq(3) == 0,i_q);
i_q0 = subs(i_q0,W,W_0);
i_d0 = solve(eq(2) == 0,i_d);
i_d0 = subs(i_d0,{W,i_q},{W_0,i_q0});
i_d0t = solve(eq(1) == 0,i_d);
i_d0t = subs(i_d0t,{W,i_q},{W_0,i_q0});
d0 = solve(i_d0t ==i_d0, d);
i_d0 = simplify(i_d0t);

display('calculating constrains for stability');
a0 = simplify(subs(charPolyCoeficents(5-0),{W,i_q,i_d},{W_0,i_q0,i_d0}));
a1 = simplify(subs(charPolyCoeficents(5-1),{W,i_q,i_d},{W_0,i_q0,i_d0}));
a2 = simplify(subs(charPolyCoeficents(5-2),{W,i_q,i_d},{W_0,i_q0,i_d0}));
a3 = simplify(subs(charPolyCoeficents(5-3),{W,i_q,i_d},{W_0,i_q0,i_d0}));

T_m_1 = simplify(solve(a2==0,T_m));
T_m_2 = simplify(solve(a1==0,T_m));

constraint_1 = simplify(a3*a2-a1);
T_m_c1 = solve(constraint_1 == 0, T_m);

constraint_2 = simplify(a3*a2*a1-a3^2*a0-a1^2)

%my params
D_p0 =1;
J0 = 3;
R_s0 = 0.0001;
M_f = 0.5e-6;
L_s0 = 1e-6;
m = sqrt(3/2)*M_f;
i_f = -10;
W_g0 = 50*2*pi;
V0 = 220;
mif0 = m*i_f;
T_m0 = 100;
%calculate T_m range
delta = -atan((W_g0 * L_s0) / R_s0);
T_m1 = W_g0*D_p0 + mif0*(V0*sin(delta)*W_g0*L_s0-V0*cos(delta)*R_s0+mif0*W_g0*R_s0)/(W_g0^2*L_s0^2+R_s0^2);
delta = delta + pi;
T_m2 = W_g0*D_p0 + mif0*(V0*sin(delta)*W_g0*L_s0-V0*cos(delta)*R_s0+mif0*W_g0*R_s0)/(W_g0^2*L_s0^2+R_s0^2);

T_m0 = max(T_m1,T_m2)

a = subs(constraint_2,{D_p,J,R_s,L_s,mif,W_g,V,T_m},{D_p0,J0,R_s0,L_s0,mif0,W_g0,V0,T_m0})
dmin = atan(R_s0/(W_g0*L_s0))-pi/2
dmax = atan(R_s0/(W_g0*L_s0))+pi/2
ab = zeros(0,1);
dd = zeros(0,1);
for d0 = dmin:0.05:dmax
  dd = [dd d0];
  ab = [ab subs(a,d,d0)];
end
figure(1)
plot(dd,ab)


