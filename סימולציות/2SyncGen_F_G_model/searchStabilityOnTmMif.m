function [] = searchStabilityOnTmMif(fromTm,toTm,fromMif,toMif,N)

if nargin > 5 || nargin < 4
    error('searchStabilityOnTmMif: requires at most 4 or 5 inputs');
end

if nargin == 4
    N = 30;
end
dTm = (toTm - fromTm) / N;
dMif = (toMif - fromMif) / N;


global Ltot J Dp mif Rl Rtot Tm

syms id1_ iq1_ w1_ id2_ iq2_ w2_ d_
syms Ltot_ J_ Dp_ mif_ Rl_ Rtot_ Tm_
dx = TwoSyncGenSymbolicDynamics(id1_, iq1_, w1_, id2_, iq2_, w2_, d_,...
    Ltot_, J_, Dp_, mif_, Rl_, Rtot_, Tm_);
FJacobian = jacobian(dx,[id1_;iq1_;w1_;id2_;iq2_;w2_;d_]);

stabiltyByEig = ones(N,N);
stabiltyByF_G = ones(N,N);

for TmIndex = 1:N
    for mifIndex = 1:N
        [id0, iq0, w0, d0] = calculateEquilibrium(Ltot,J,Dp,fromMif+mifIndex*dMif,...
            Rl,Rtot,fromTm+TmIndex*dTm);
        T1 = subs(FJacobian,[Rtot_ Ltot_  mif_ Dp_  Rl_ J_ Tm_],...
            [Rtot Ltot (fromMif+mifIndex*dMif) Dp Rl J (fromTm+TmIndex*dTm)]);
        T2 = subs(T1 ,[id1_ iq1_ w1_  id2_ iq2_ w2_ d_],[id0 iq0 w0 id0 iq0 w0 0]);
        eige = eig(double(T2));
        stabiltyByEig(TmIndex,mifIndex) = 60*(max(real(eige)) >0);
        
        eig_ = calculateEigOFFWithEEqZeroAtEquilibrium(2*id0,2*iq0,2*w0,Ltot,J,Dp,(fromMif+mifIndex*dMif),Rl,Rtot);
        stabiltyByF_G(TmIndex,mifIndex) = 60 * (calculateStabilityConditionOFGTilda(Rtot,Rl,Dp,Ltot,id0,iq0)...
            && (max(real(eig_)) >0));

    end
end

figure;
image(stabiltyByEig);
colorbar
set(gca,'YTickMode','manual');
set(gca,'YTick',1:N/10:N);
set(gca,'YtickLabels',fromTm:(toTm-fromTm)/10:toTm);

set(gca,'XTickMode','manual');
set(gca,'XTick',1:N/10:N);
set(gca,'XtickLabels',fromMif:(toMif-fromMif)/10:toMif);
title('local stability by eig of Jacobian at eq point');
xlabel('MI_f')
ylabel('Tm')

figure;
image(stabiltyByF_G);
colorbar
set(gca,'YTickMode','manual');
set(gca,'YTick',1:N/10:N);
set(gca,'YtickLabels',fromTm:(toTm-fromTm)/10:toTm);

set(gca,'XTickMode','manual');
set(gca,'XTick',1:N/10:N);
set(gca,'XtickLabels',fromMif:(toMif-fromMif)/10:toMif);
title('Stabilty of the linearized F and G');
xlabel('MI_f')
ylabel('Tm')