Ls = 27.5*10^-3; %[H] -
Lg = 0;
Ltot = Lg+Ls;
J = 20; % [kg*Sec]  - Eitan
Rs = 1.08; %0.152 [ohm] - Eitan

Dp = 1.7; %1.7[J*Sec] - Eitan
mif = -33.11;
Rl = 300;
Rtot = Rl + Rs;
RT = Rl + Rtot;

w0 = 50*2*pi; % [rad/sec]
Tm = w0*(Dp*(Ltot^2*w0^2+RT^2)+mif^2*RT)/(Ltot^2*w0^2+RT^2);
