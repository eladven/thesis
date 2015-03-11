close all
clear all
x = 0.9;
alpha =-1:0.05:5;
y = alpha.^2/8-alpha/2-cos(x)/2+0.5;
figure(1)
plot(alpha,y)

hold on
plot(zeros(length(alpha)),alpha);
plot(alpha,zeros(length(alpha)));
axis([-1,5,-cos(x)/2-0.2,0.9])
plot(2, -cos(x)/2, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
    'LineWidth', 2, 'MarkerSize', 6);
text(2.1,  -cos(x)/2-0.05, '$(2,-\frac{1}{2}cos(x))$','Interpreter','latex','FontSize',16);
plot(2+2*sqrt(cos(x)), 0, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
    'LineWidth', 2, 'MarkerSize', 6);
plot(2-2*sqrt(cos(x)), 0, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
    'LineWidth', 2, 'MarkerSize', 6);
text(2+2*sqrt(cos(x))-0.5,0.1, '$2+2 \sqrt{cos(x)}$','Interpreter','latex','FontSize',16);
text(2-2*sqrt(cos(x))-0.5,0.1, '$2-2 \sqrt{cos(x)}$','Interpreter','latex','FontSize',16);


%%%%%%%%%%%%%%%%%%%%%%%5

x = -pi:0.05:pi;
alpha =3;
D = 2;
K = 6.3;

y1 = (alpha+2*D).^2/8-(alpha+2*D)/2-cos(x)/2+0.5-K;
y2 = -(alpha+2*D).^2/8-(alpha+2*D)/2+cos(x)/2-0.5+K;

figure(2)
hold on
plot(x,y1,'b')
plot(x,y2,'b')


hold on
ax = -10:0.1:10
plot(zeros(length(ax)),ax);
plot(ax,zeros(length(ax)));
maxi = max(max(y1),max(y2));
mini = min(min(y1),min(y2));
axis([-pi,pi,mini,max(maxi,0)+1])
% plot(2, -cos(x)/2, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
%     'LineWidth', 2, 'MarkerSize', 6);
% text(2.1,  -cos(x)/2-0.05, '$(2,-\frac{1}{2}cos(x))$','Interpreter','latex','FontSize',16);
% plot(2+2*sqrt(cos(x)), 0, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
%     'LineWidth', 2, 'MarkerSize', 6);
% plot(2-2*sqrt(cos(x)), 0, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
%     'LineWidth', 2, 'MarkerSize', 6);
% text(2+2*sqrt(cos(x))-0.5,0.1, '$2+2 \sqrt{cos(x)}$','Interpreter','latex','FontSize',16);
% text(2-2*sqrt(cos(x))-0.5,0.1, '$2-2 \sqrt{cos(x)}$','Interpreter','latex','FontSize',16);
% 
% 

%%%%%%%%%%%%%%%%%%%%%%%5
max_alpha = 5;
x = 0;
alpha_plus_2D =-0.1:0.05:max_alpha;
K = 2.5;

y1 = (alpha_plus_2D).^2/8-(alpha_plus_2D*D)/2-cos(x)/2+0.5-K;
y2 = -(alpha_plus_2D).^2/8-(alpha_plus_2D*D)/2+cos(x)/2-0.5+K;

figure(3)
hold on
plot(alpha_plus_2D,y1,'b')
plot(alpha_plus_2D,y2,'b')


hold on
ax = -10:0.1:10
plot(zeros(length(ax)),ax);
plot(ax,zeros(length(ax)));
maxi = max(max(y1),max(y2));
mini = min(min(y1),min(y2));
axis([-0.1,max_alpha,mini,max(maxi,0)+1])
% plot(2, -cos(x)/2, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
%     'LineWidth', 2, 'MarkerSize', 6);
% text(2.1,  -cos(x)/2-0.05, '$(2,-\frac{1}{2}cos(x))$','Interpreter','latex','FontSize',16);
% plot(2+2*sqrt(cos(x)), 0, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
%     'LineWidth', 2, 'MarkerSize', 6);
% plot(2-2*sqrt(cos(x)), 0, 'o', 'MarkerFaceColor', 'k', 'MarkerEdgeColor','k', ...
%     'LineWidth', 2, 'MarkerSize', 6);
% text(2+2*sqrt(cos(x))-0.5,0.1, '$2+2 \sqrt{cos(x)}$','Interpreter','latex','FontSize',16);
% text(2-2*sqrt(cos(x))-0.5,0.1, '$2-2 \sqrt{cos(x)}$','Interpreter','latex','FontSize',16);
% 
% 

%axis off