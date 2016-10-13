%% The basic values are 5 kW SG vaslues
%  Form the thesis of Eytan Brawn

Ls = 18.0*10^-3; %[H] - Eitan  %% The value for getting unstability 0.1*10^-3;
Lg = 0;
Ltot = Lg+Ls;
J = 40.05; % [kg*Sec]  - Eitan
Rs = 0.4*10^-3; %0.152 [ohm] - Eitan

Dp = 337; %1.7[J*Sec] - Eitan
mif = 1.79; %Vivek Mf 0.0052 [H]
Rl = 10; %P = sqrt(3)*V^2/R - > R = sqrt(3)V^2/P = sqrt(3)330^2 / (2*5*10^3)
Rtot = Rl + Rs;
RT = Rl + Rtot;

w0 = 50*2*pi; % [rad/sec]
Tm = 700;
