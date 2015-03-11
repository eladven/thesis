
global Ls Lg Ltot J Rs w0 Dp mif Rl Rtot RT Tm iq0 id0 delta0
delta0 = 0
A_tilda()
B_tilda()
A_ = [A_tilda() -B_tilda();-B_tilda() A_tilda()]
eig(A_)
A_*[id0;iq0;w0;id0;iq0;w0]+[0;0;Tm;0;0;Tm]

z = Dp*Ltot^2*w0^3-Tm*Ltot^2*w0^2+(Dp*RT^2+mif^2*RT)*w0-Tm*RT^2