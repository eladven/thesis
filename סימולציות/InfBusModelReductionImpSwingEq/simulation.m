close all
clc;

w = warning ('off','all');
rmpath('folderthatisnotonpath')
warning(w)

global Ls J Dp mif Rs Pm V wg
%initValues5KWSG;
initValues1MWSG;
%initValuesReduceNonStableExample;
%initValuesNonStableExample;

T = 3;
global x0;


[t,x] = ode15s(@modelDynamics,[0 T],x0);
[t_hat,x_hat] = ode15s(@reducedModelDynamics,[0 T],[x0(3),x0(4)]);


iq_hat = zeros(1,length(t));
id_hat = zeros(1,length(t));
for i=1:length(iq_hat)
    iq_hat(i) =  - (V*sin(x(i,4)))/(Ls*x(i,3));
    id_hat(i) =    - (mif*x(i,3) - V*cos(x(i,4)))/(Ls*x(i,3));
end
figure (1)
hold on;
plot(t,x(:,1:2))
plot(t,iq_hat,'r');
plot(t,id_hat,'g');
figure (2)
hold on
plot(t,x(:,3))
plot(t_hat,x_hat(:,1),'r')
xlabel('time [sec]');
ylabel('freq [rad/sec]');
figure (3)
hold on
plot(t,x(:,4))
plot(t_hat,x_hat(:,2),'r')
xlabel('time [sec]');
ylabel('phase [rad]');


%%

x0 = calculateEquilibrium(Ls, J, Dp, mif, Rs, Pm, V, wg);
eig_ = calculateEigOfJacobianOfEqPointForOrigSys(Ls, J, Dp, mif, Rs, Pm, V, wg,x0(1,1), x0(2,1), x0(3,1), x0(4,1));
display('The detailed system (1) is localy ');
if (max(real(eig_)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end

eig_ = calculateEigOfJacobianOfEqPointForOrigSys(Ls, J, Dp, mif, Rs, Pm, V, wg,x0(1,2), x0(2,2), x0(3,2), x0(4,2));
display('The detailed system (2) is localy ');
if (max(real(eig_)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end



x0_hat = calculateEquilibriumForTheReducedSystem(Ls, J, Dp, mif, Rs, Pm, V, wg);
eig_ = calculateEigOfJacobianOfEqPointForReducedSys(Ls, J, Dp, mif, Rs, Pm, V, wg,x0_hat(1,1), x0_hat(2,1));
display('The reduced system (1) is localy ');
if (max(real(eig_)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end

eig_ = calculateEigOfJacobianOfEqPointForReducedSys(Ls, J, Dp, mif, Rs, Pm, V, wg,x0_hat(1,2), x0_hat(2,2));
display('The reduced system (2) is localy ');
if (max(real(eig_)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end