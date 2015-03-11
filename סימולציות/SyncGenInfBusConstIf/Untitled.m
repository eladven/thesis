syms R w1 d1 w2 Rl mif d2 L
A = [-R w1*L Rl*cos(d1) -Rl*sin(d1);
     -w1*L -R Rl*sin(d1) Rl*cos(d1);
     Rl*cos(d1) Rl*sin(d1) -R w2*L ;
     -Rl*sin(d1) Rl*cos(d1) -w2*L -R ]
 
 B = [0;mif*w1;0;mif*w2]

 z = simplify(A^-1*B)
 
 iq1 = simplify(z(2))
 
 iq_ = simplify(subs(iq1,Rl,R))