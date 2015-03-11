clear all
close all
global Ltot J Rtot Tm iq0 id0 w0 mif Dp Rl
syms Ltot_ J_ Rtot_ Tm_ iq0_ id0_ w0_ mif_ Dp_ Rl_ s
initValues(18.8620,2*pi*50,0,1);
lambda = [Ltot_ 0 0;0 Ltot_ 0 ;0 0 J_]/sqrt(2);
lambdaA = [-Rtot_ w0_*Ltot_ Ltot_*iq0_;-w0_*Ltot_ -Rtot_ -Ltot_*id0_-mif_; 0 mif_ -Dp_];
lambdaB = [sqrt(2)*Rl_*iq0_;-sqrt(2)*Rl_*id0_;0];
C = [0 0 sqrt(2)];

A_ = [lambda,[0;0;0];[0,0,0],1]^-1*[lambdaA lambdaB;-C 0]

chp = charpoly(A_)
eig(double(subs(A_,[Ltot_ J_ Rtot_ Tm_ iq0_ id0_ w0_ mif_ Dp_ Rl_],[Ltot J Rtot Tm iq0 id0 w0 mif Dp Rl])))
double(subs(chp,[Ltot_ J_ Rtot_ Tm_ iq0_ id0_ w0_ mif_ Dp_ Rl_],[Ltot J Rtot Tm iq0 id0 w0 mif Dp Rl]))

for ii=1:10000
    ii
    Ltot = rand*100^rand;
    J = rand*100^rand;
    Tm = rand*100^rand;
    mif = rand*100^rand;
    Dp = rand*100^rand;
    Rl = rand*100^rand;
    Rs = rand*100^rand;
    Rtot = Rs+Rl;
    RT= Rtot+Rl;
    w0 = roots([Dp*Ltot^2 ,-Tm*Ltot^2, Dp*RT^2+mif^2*RT, -Tm*RT^2]);
    for k=1:length(w0)
        if isreal(w0(k))
            w0 = w0(k);
            break;
        end
    end
    
    iq0 = (Dp*w0-Tm)/mif;
    id0 = -(mif*w0+iq0*RT)/(w0*Ltot);
    z = [Ltot J Rtot Tm mif Dp Rl iq0 id0 w0];
    eg = eig(double(subs(A_,[Ltot_ J_ Rtot_ Tm_ mif_ Dp_ Rl_ iq0_ id0_ w0_],z)));
    if (max(real(eg)) > 0 )
        z
        eg
        Ltot
        J
        Rtot
        Tm
        mif
        Dp
        Rl
        Rs
        Rtot
        RT
        w0
        iq0
        id0
        break
    end
    
end;