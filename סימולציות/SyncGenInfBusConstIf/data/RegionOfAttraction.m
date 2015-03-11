function eps = RegionOfAttraction(numOfIterations)
global D_p J R_s M_f L_s omega_g V i_f;
m = sqrt(3/2)*M_f;

%calculate T_m range
delta = -atan((omega_g * L_s) / R_s);
T_m1 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);
delta = delta + pi;
T_m2 = omega_g*D_p + m*i_f*(V*sin(delta)*omega_g*L_s-V*cos(delta)*R_s+m*i_f*omega_g*R_s)/(omega_g^2*L_s^2+R_s^2);

T_m_min = min(T_m1,T_m2)
T_m_max = max(T_m1,T_m2)

T = zeros(1,0);
eps = zeros(1,0);
global T_m;
global i_q0 i_d0 omega0 delta0
for T_m = T_m_min-1:(T_m_max-T_m_min)/20:T_m_max+1
    %initial conditions
    i_q0= 100*rand - 50;
    i_d0 = 100*rand - 50;
    omega0 = 2*omega_g*rand;
    delta0 = 500*rand;
    T = [T T_m];
    eps = [eps RunModel('syncGenInfBusNoIfSimulink',0)];
end

eps_min  = eps;
eps_max  = eps;
for index=1:numOfIterations-1
    index
    for index2 = 1:length(eps)
        %initial conditions
        i_q0= 100*rand - 50;
        i_d0 = 100*rand - 50;
        omega0 = 2*omega_g*rand;
        delta0 = 500*rand;
        T_m = T(index2);
        temp_eps = RunModel('syncGenInfBusNoIfSimulink',0);
        eps_min(index2) = min(temp_eps,eps_min(index2));
        eps_max(index2) = max(temp_eps,eps_max(index2));
    end
    
end

hold on;
plot(T,eps_min,'r');
plot(T,eps_max,'b');
plot(T,eps,'g');
xlabel('T_m');
ylabel('eps');
hold off;

title({sprintf('D_p is %f J is %f R_s is %f L_s is %f',D_p,J,R_s,L_s),...
    sprintf('m*i_f is %f  W_g is %f V is %f',m*i_f,omega_g,V)});

