function eps = RunModel(modelName, isPrintGraph)
global D_p J R_s L_s m i_f omega_g V T_m
%simulate the system
sim(modelName);
global omegaModel deltaModel i_dModel i_qModel
%plot the results
if (isPrintGraph ~= 0)
    title({sprintf('D_p is %f J is %f R_s is %f L_s is %f',D_p,J,R_s,L_s),...
    sprintf('m*i_f is %f  W_g is %f V is %f T_m is %f',m*i_f,omega_g,V,T_m)});
    subplot(2,1,1);
    plot(omega.Data,delta.Data);
    xlabel('Omega');
    ylabel('Delta');
    subplot(2,1,2);
    
    plot(i_d.Data,i_q.Data);
    xlabel('i_q');
    ylabel('i_d');
end

len = length(omega.Data);
omega_no_bias = omega.Data(len-100:len) -sum(omega.Data(len-100:len))/101;
delta_no_bias = delta.Data(len-100:len) -sum(delta.Data(len-100:len))/101;
id_no_bias = i_d.Data(len-100:len) -sum(i_d.Data(len-100:len))/101;
iq_no_bias = i_q.Data(len-100:len) -sum(i_q.Data(len-100:len))/101;
eps_vec = [max(omega_no_bias) max(delta_no_bias) max(id_no_bias) max(iq_no_bias)];
eps  = max(eps_vec);
i_dModel = i_d;
i_qModel = i_q;
omegaModel = omega;
deltaModel = delta
