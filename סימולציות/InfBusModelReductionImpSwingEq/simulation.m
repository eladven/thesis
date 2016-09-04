clear all
close all
clc;

w = warning ('off','all');
rmpath('folderthatisnotonpath')
warning(w)

global Ls J Dp mif Rs Pm V wg
initValues5KWSG;
%initValues1MWSG;
%initValuesReduceNonStableExample;
%initValuesNonStableExample;

global x0;


[t,x] = ode15s(@modelDynamics,[0 T],x0);
[t_hat,x_hat] = ode15s(@reducedModelDynamics,[0 T],[x0(3),x0(4)]);


iq_hat = zeros(1,length(t_hat));
id_hat = zeros(1,length(t_hat));
for i=1:length(iq_hat)
    iq_hat(i) =  - (V*sin(x_hat(i,2)))/(Ls*x_hat(i,1));
    id_hat(i) =    - (mif*x_hat(i,1) - V*cos(x_hat(i,2)))/(Ls*x_hat(i,1));
end
figure (1)
subplot(3,1,1)
hold on;
plot(t,x(:,1:2))
plot(t_hat,id_hat,'g');
plot(t_hat,iq_hat,'r');
xlabel('time [sec]');
ylabel('current [A]');
legend({'$i_d$','$i_q$','$\hat{i_d}$','$\hat{i_q}$'},'Interpreter','latex','Position', [0.93,0.78,0.01,0.1])
subplot(3,1,2)
hold on
plot(t,x(:,3))
plot(t_hat,x_hat(:,1),'r')
xlabel('time [sec]');
ylabel('freq [rad/sec]');
legend({'$\omega$','$\hat{\omega}$'},'Interpreter','latex','Position', [0.93,0.528,0.01,0.1])
subplot(3,1,3)
hold on
plot(t,x(:,4))
plot(t_hat,x_hat(:,2),'r')
xlabel('time [sec]');
ylabel('phase [rad]');
legend({'$\delta$','$\hat{\delta}$'},'Interpreter','latex','Position', [0.93,0.225,0.01,0.1])


%%

x0 = calculateEquilibrium(Ls, J, Dp, mif, Rs, Pm, V, wg);
eig_ = calculateEigOfJacobianOfEqPointForOrigSys(Ls, J, Dp, mif, Rs, Pm, V, wg,x0(1,1), x0(2,1), x0(3,1), x0(4,1));
display('The detailed system (1) is localy ');
if (max(real(eig_)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end
% display('The eig of system 1 is:');
% display(eig_);

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
% display('The eig of system 1 is:');
% display(eig_);


eig_ = calculateEigOfJacobianOfEqPointForReducedSys(Ls, J, Dp, mif, Rs, Pm, V, wg,x0_hat(1,2), x0_hat(2,2));
display('The reduced system (2) is localy ');
if (max(real(eig_)) >0)
    display('UNSTABLE');
else
    display('STABLE');
end