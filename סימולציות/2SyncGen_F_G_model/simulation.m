close all
w = warning ('off','all');
rmpath('folderthatisnotonpath')
warning(w)

global Ltot J Dp mif Rl Rtot Tm
initValuesEitan;
%initValuesVivek;
%initValuesNonStableExample;

T = 5;
x0 = [19;-35;0;19;-32;0;0.5];


[t,x] = ode15s(@modelDynamics,[0 T],x0);
plotXGraphs(x,t);

[id0, iq0, w0, d0] = calculateEquilibrium(Ltot,J,Dp,mif,Rl,Rtot,Tm);
eig = calculateEigOfJacobianOfEqPointForOrigSys(Ltot,J,Dp,mif,Rl,Rtot,Tm,id0, iq0, w0, d0);
display('This system is ');
if (max(real(eig)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end

%calculateStabilityConditionOFGTilda
%calculateEigOFFWithEEqZeroAtEquilibrium

searchStabilityOnTmMif(10,4000,-1,-15,20);

