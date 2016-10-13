close all
w = warning ('off','all');
rmpath('folderthatisnotonpath')
warning(w)

global Ltot J Dp mif Rl Rtot Tm T x0
initValues5KWSG
initValuesLIMITCaseInROA
initValuesLIMITCaseOutROA
initValuesNonStableExample

displayParameters(Ltot,J,Dp,mif,Rl,Rtot,Tm);

[t,x] = ode15s(@modelDynamics,[0 T],x0);

plotXGraphs(x,t);

[id0, iq0, w0, d0] = calculateEquilibrium(Ltot,J,Dp,mif,Rl,Rtot,Tm);
eig = calculateEigOfJacobianOfEqPointForOrigSys(Ltot,J,Dp,mif,Rl,Rtot,Tm,id0, iq0, w0, d0);
display('This system is localy ');
if (max(real(eig)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end

display('G~(x) is ');
if (calculateStabilityConditionOFGTilda(Rtot,Rl,Dp,Ltot,id0,iq0))
    display('STABLE');
else
    display('UNSTABLE');
end

eig = calculateEigOFFWithEEqZeroAtEquilibrium(2*id0,2*iq0,2*w0,Ltot,J,Dp,mif,Rl,Rtot);
display('The linearization of e dynamic with x = x0 and d=0 is');
if (max(real(eig)) >0)
    display('Not Hurwitz');
else
    display('Hurwitz');
end
%searchStabilityOnTmMif(10,4000,-1,-15,15);

