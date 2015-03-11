close all;
global alpha D K
alpha = 4;
D = 0;
K = 0;

tspan = [0:0.05:30];
x1_0 = [rand-0.5;rand-0.5];
x2_0 = [rand-0.5;rand-0.5];
[T,X] = ode23(@two_Pendulums,tspan,[x1_0; x2_0]);
X1 = X(:,1:2);
X2 = X(:,3:4);

figure(1)
subplot(2,1,1);
plot(T,X1(:,1))
hold on
plot(T,X2(:,1),'r')

subplot(2,1,2);
plot(T,X1(:,2))
hold on
plot(T,X2(:,2),'r')



dx = X1 - X2;
ainfNorm = arrayfun(@(idx) norm(dx(idx,:),inf), 1:size(dx,1));
a1Norm = arrayfun(@(idx) norm(dx(idx,:),1), 1:size(dx,1));
a2Norm = arrayfun(@(idx) norm(dx(idx,:),2), 1:size(dx,1));

figure(2)

plot (T,ainfNorm,'b');
hold on 
plot (T,a1Norm,'r');
plot (T,a2Norm,'g');

figure(3)
Z1 = zeros(2,size(X1,1));
Z2 = zeros(2,size(X1,1));
for index=1:size(X1,1)
    X1_ = X1(index,:)';
    X2_ = X2(index,:)';    
    P1 = [cos(X1_(1)) + (alpha^2)/2,alpha/2;alpha/2 1];
    P2 = [cos(X2_(1)) + (alpha^2)/2,alpha/2;alpha/2 1];
    Z1(:,index) = P1*X1_;
    Z2(:,index) = P2*X2_;
end

dz = Z1' - Z2';
ainfNorm = arrayfun(@(idx) norm(dz(idx,:),inf), 1:size(dz,1));
a1Norm = arrayfun(@(idx) norm(dz(idx,:),1), 1:size(dz,1));
a2Norm = arrayfun(@(idx) norm(dz(idx,:),2), 1:size(dz,1));

figure(3)

plot (T,ainfNorm,'b');
hold on 
plot (T,a1Norm,'r');
plot (T,a2Norm,'g');


