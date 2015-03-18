function h = initValues(Rl_param,w0_param,Tm_param,useW0param)

% Eitan one generator with nominal power of 5kW V = 330 [v] (phase to
% ground)
global Ls Lg Ltot J Rs w0 Dp mif Rl Rtot RT Tm iq0 id0 
Ls = 0.4*10^-3; % 2.2*10^-3[H] - Eitan
Lg = 0;
Ltot = Lg+Ls;
J = 0.2; % [kg*Sec]  - Eitan
Rs = 0.011; % [ohm] - Eitan

Dp = 1.7; %1.7[J*Sec] - Eitan
mif = -1.38; %Vivek Mf 0.0052 [H]
Rl = Rl_param; %18.86200; %P = sqrt(3)*V^2/R - > R = sqrt(3)V^2/P = sqrt(3)330^2 / (2*5*10^3)
Rtot = Rl + Rs;
RT = Rl + Rtot;

if (useW0param ~= 0)
    w0 = w0_param; % 50*2*pi; % [rad/sec] 
    Tm = w0*(Dp*(Ltot^2*w0^2+RT^2)+mif^2*RT)/(Ltot^2*w0^2+RT^2);
else
    Tm = Tm_param;
    w0 = roots([Dp*Ltot^2 ,-Tm*Ltot^2, Dp*RT^2+mif^2*RT, -Tm*RT^2]);
    for k=1:length(w0)
        if isreal(w0(k))
            w0 = w0(k);
            break;
        end
    end
end



iq0 = (Dp*w0-Tm)/mif;
id0 = -(mif*w0+iq0*RT)/(w0*Ltot);

%% Validate that z0 is indeed equalibrium point

syms R_ L_ w1_ mif_ Dp_ w2_ d_ Rl_ J_
A1 = [-R_ w1_*L_ 0;-w1_*L_ -R_ -mif_;0 mif_ -Dp_];
A2 = [-R_ w2_*L_ 0;-w2_*L_ -R_ -mif_;0 mif_ -Dp_];
B1 = [Rl_*cos(d_) -Rl_*sin(d_) 0;Rl_*sin(d_) Rl_*cos(d_) 0;0 0 0];
B2 = [Rl_*cos(-d_) -Rl_*sin(-d_) 0;Rl_*sin(-d_) Rl_*cos(-d_) 0;0 0 0];
lambda = [L_ 0 0 ; 0 L_ 0;0 0 J_];

h = [lambda^-1*[A1 -B1 [0;0;0]];lambda^-1*[-B2 A2 [0;0;0]];[0 0 -1] [0 0 1] 0];

syms id1_ iq1_ id2_ iq2_;
z1 = [id1_;iq1_;w1_];
z2 = [id2_;iq2_;w2_];
z= [z1;z2;d_];

h_ = h*z+[0;0;Tm/J;0;0;Tm/J;0];
hn = subs(h_,[R_ L_ mif_ Dp_ Rl_ J_],[Rtot Ltot mif Dp Rl J]);
hn = subs(hn,[id1_ iq1_ w1_ id2_ iq2_ w2_ d_],[id0 iq0 w0 id0 iq0 w0 0]);
epsilon = double(hn);
if (epsilon > 10^-4)
    msgID = 'MYFUN:NonEqualPoint';
    msg = 'z0 is not equalibrium point.';
    baseException = MException(msgID,msg);
    throw(baseException)

end
