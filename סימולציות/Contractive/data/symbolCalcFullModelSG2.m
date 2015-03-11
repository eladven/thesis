clear all
close all

syms id iq w d;
syms R Rl L mif J Dp D K
 
 f = [(-R-Rl*cos(d))/L w-(Rl/L)*sin(d) 0 0;
        -w+(Rl/L)*sin(d) (-R-Rl*cos(d))/L -mif/L 0;
        0 mif/J -(Dp+2*D)/J K/J;
        0 0 2 0]*[id;iq;w;d]
 
 J = jacobian(f,[id;iq;w;d])
 J_s = (J+J.')/2

