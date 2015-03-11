function eps = RunModel(modelName, isPrintGraph)

%simulate the system
sim(modelName);

%plot the results
if (isPrintGraph ~= 0)
    figure(1)
    subplot(2,1,1);
    plot(omega.Data,delta.Data);
    st1 = sprintf('D_p = %f ',3); 
    title({st1,'line 2','line3'});
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