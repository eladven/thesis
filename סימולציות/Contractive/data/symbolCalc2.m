clear all
close all

syms alpha x y K D;

f = [-((alpha+2*D)/2)*x+y;(((alpha+2*D)^2)/4)*x-sin(x)-((alpha+2*D)/2)*y-2*K*x]

J = jacobian(f,[x y])
J_s = (J+J.')/2
lambda = eig(J_s)
lambda = subs(lambda,D,0)
lambda = subs(lambda,K,2.5)


figure(1);
ezcontour(lambda(1), [0, 4, -pi, pi])
figure(2);
ezcontour(lambda(2), [0, 4, -pi, pi])
eigmin = 0;
alpha_opt = 0;
for alpha_num = 0:0.05:4
    local_max_eig = max(double(subs(lambda,[alpha,x],[alpha_num,0])));
    if (local_max_eig < eigmin)
        eigmin = local_max_eig;
        alpha_opt = alpha_num;
    end
end
eigmin
alpha_opt

lambda_opt = subs(lambda,alpha,alpha_opt)
x_vect = [];
local_max_eig = [];
for x_=-pi:0.05:pi
    x_vect = [x_vect x_];
    local_max_eig = [local_max_eig max(double(subs(lambda_opt,x,x_)))];
end
figure(3);
plot(x_vect,local_max_eig);
xlabel('x');
ylabel('max(lambda)');
title( strcat('max lambde vs x for optimal alpha+2D = ',num2str(alpha_opt),', K=2.5'));


