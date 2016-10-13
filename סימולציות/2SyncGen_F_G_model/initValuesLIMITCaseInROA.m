%%%%%%%%%%%%%%%%%%%%
% -- LIMIT CASE -- 
%%%%%%%%%%%%%%%%%%%%

Ls = 0.41*10^-3; %[H] - Eitan  %% The value for getting unstability 0.1*10^-3;
Lg = 0;
Ltot = Lg+Ls;
J = 0.19; % [kg*Sec]  - Eitan
Rs = 0.011; %0.152 [ohm] - Eitan

Dp = 1.7; %1.7[J*Sec] - Eitan
mif = -1.38; %Vivek Mf 0.0052 [H]
Rl = 18.86200; %P = sqrt(3)*V^2/R - > R = sqrt(3)V^2/P = sqrt(3)330^2 / (2*5*10^3)
Rtot = Rl + Rs;
RT = Rl + Rtot;

w0 =  50*2*pi; % [rad/sec]
Tm =  w0*(Dp*(Ltot^2*w0^2+RT^2)+mif^2*RT)/(Ltot^2*w0^2+RT^2);

x0 = [40;-20;70;40;-20;65;0];
T=10;
