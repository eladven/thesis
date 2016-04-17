close all
w = warning ('off','all');
rmpath('folderthatisnotonpath')
warning(w)

global Ls J Dp mif Rs Pm V wg
initValuesNonStableExample;

T = 3;
x0 = [10;10;50*2*pi;0];


[t,x] = ode15s(@modelDynamics,[0 T],x0);
figure (1)
plot(t,x(:,1:2))
figure (2)
plot(t,x(:,3))
figure (3)
plot(t,x(:,4))


[t,x] = ode15s(@reducedModelDynamics,[0 T],[x0(3),x0(4)]);
figure (4)
plot(t,x(:,1))
figure (5)
plot(t,x(:,2))


%%
%%%%%%%%%%%%%%%%%%%%%%%%%%

% [id0, iq0, w0, d0] = calculateEquilibrium(Ltot,J,Dp,mif,Rl,Rtot,Tm);
% eig = calculateEigOfJacobianOfEqPointForOrigSys(Ltot,J,Dp,mif,Rl,Rtot,Tm,id0, iq0, w0, d0);
% display('This system is localy ');
% if (max(real(eig)) >0)
%     display('UNSTABLE');
% else
%     display('STABLE');
% end
% 
% display('G~(x) is ');
% if (calculateStabilityConditionOFGTilda(Rtot,Rl,Dp,Ltot,id0,iq0))
%     display('STABLE');
% else
%     display('UNSTABLE');
% end
% 
% eig = calculateEigOFFWithEEqZeroAtEquilibrium(2*id0,2*iq0,2*w0,Ltot,J,Dp,mif,Rl,Rtot);
% display('The linearization of e dynamic with x = x0 and d=0 is');
% if (max(real(eig)) >0)
%     display('Not Hurwitz');
% else
%     display('Hurwitz');
% end
% 
% searchStabilityOnTmMif(10,4000,-1,-15,15);
% 
