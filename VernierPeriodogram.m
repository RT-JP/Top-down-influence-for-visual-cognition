% Copyright (c) 2021 RT-JP All Right Reserved.

N = 100;

for i = 1:N
    %V1data Input
    vir_synapse_v1_center_data_name = sprintf('vir_lfp_v1_center_data_%d.csv',i);
    vir_synapse_v1_top_data_name = sprintf('vir_lfp_v1_top_data_%d.csv',i);
    vir_synapse_v1_bottom_data_name = sprintf('vir_lfp_v1_bottom_data_%d.csv',i);
    
    vr_synapse_v1_center_data_name = sprintf('vr_lfp_v1_center_data_%d.csv',i);
    vr_synapse_v1_top_data_name = sprintf('vr_lfp_v1_top_data_%d.csv',i);
    vr_synapse_v1_bottom_data_name = sprintf('vr_lfp_v1_bottom_data_%d.csv',i);
    
    vir_synapse_v1_center_data = importdata(vir_synapse_v1_center_data_name);
    vir_synapse_v1_top_data = importdata(vir_synapse_v1_top_data_name);
    vir_synapse_v1_bottom_data = importdata(vir_synapse_v1_bottom_data_name);
    
    vr_synapse_v1_center_data = importdata(vr_synapse_v1_center_data_name);
    vr_synapse_v1_top_data = importdata(vr_synapse_v1_top_data_name);
    vr_synapse_v1_bottom_data = importdata(vr_synapse_v1_bottom_data_name);
    
    %V1 LFP
    fs = 1000;
    [vir_periodogram_v1_center, periodogram_fs] = periodogram(vir_synapse_v1_center_data,rectwin(length(vir_synapse_v1_center_data)),length(vir_synapse_v1_center_data),fs);
    vir_periodogram_v1_center_output_name = 'vir_periodogram_v1_center_%d.csv';
    vir_periodogram_v1_center_output = sprintf(vir_periodogram_v1_center_output_name,i);
    dlmwrite(vir_periodogram_v1_center_output, 10*log10(vir_periodogram_v1_center));

    fs = 1000;
    [vir_periodogram_v1_top, periodogram_fs] = periodogram(vir_synapse_v1_top_data,rectwin(length(vir_synapse_v1_top_data)),length(vir_synapse_v1_top_data),fs);
    vir_periodogram_v1_top_output_name = 'vir_periodogram_v1_top_%d.csv';
    vir_periodogram_v1_top_output = sprintf(vir_periodogram_v1_top_output_name,i);
    dlmwrite(vir_periodogram_v1_top_output, 10*log10(vir_periodogram_v1_top));

    fs = 1000;
    [vir_periodogram_v1_bottom, periodogram_fs] = periodogram(vir_synapse_v1_bottom_data,rectwin(length(vir_synapse_v1_bottom_data)),length(vir_synapse_v1_bottom_data),fs);
    vir_periodogram_v1_bottom_output_name = 'vir_periodogram_v1_bottom_%d.csv';
    vir_periodogram_v1_bottom_output = sprintf(vir_periodogram_v1_bottom_output_name,i);
    dlmwrite(vir_periodogram_v1_bottom_output, 10*log10(vir_periodogram_v1_bottom));
    
    fs = 1000;
    [vr_periodogram_v1_center, periodogram_fs] = periodogram(vr_synapse_v1_center_data,rectwin(length(vr_synapse_v1_center_data)),length(vr_synapse_v1_center_data),fs);
    vr_periodogram_v1_center_output_name = 'vr_periodogram_v1_center_%d.csv';
    vr_periodogram_v1_center_output = sprintf(vr_periodogram_v1_center_output_name,i);
    dlmwrite(vr_periodogram_v1_center_output, 10*log10(vr_periodogram_v1_center));

    fs = 1000;
    [vr_periodogram_v1_top, periodogram_fs] = periodogram(vr_synapse_v1_top_data,rectwin(length(vr_synapse_v1_top_data)),length(vr_synapse_v1_top_data),fs);
    vr_periodogram_v1_top_output_name = 'vr_periodogram_v1_top_%d.csv';
    vr_periodogram_v1_top_output = sprintf(vr_periodogram_v1_top_output_name,i);
    dlmwrite(vr_periodogram_v1_top_output, 10*log10(vr_periodogram_v1_top));

    fs = 1000;
    [vr_periodogram_v1_bottom, periodogram_fs] = periodogram(vr_synapse_v1_bottom_data,rectwin(length(vr_synapse_v1_bottom_data)),length(vr_synapse_v1_bottom_data),fs);
    vr_periodogram_v1_bottom_output_name = 'vr_periodogram_v1_bottom_%d.csv';
    vr_periodogram_v1_bottom_output = sprintf(vr_periodogram_v1_bottom_output_name,i);
    dlmwrite(vr_periodogram_v1_bottom_output, 10*log10(vr_periodogram_v1_bottom));

    %VHOdata Input
    vir_synapse_vho_center_data_name = sprintf('vir_lfp_vho_center_data_%d.csv',i);
    vir_synapse_vho_top_data_name = sprintf('vir_lfp_vho_top_data_%d.csv',i);
    vir_synapse_vho_bottom_data_name = sprintf('vir_lfp_vho_bottom_data_%d.csv',i);
    
    vr_synapse_vho_center_data_name = sprintf('vr_lfp_vho_center_data_%d.csv',i);
    vr_synapse_vho_top_data_name = sprintf('vr_lfp_vho_top_data_%d.csv',i);
    vr_synapse_vho_bottom_data_name = sprintf('vr_lfp_vho_bottom_data_%d.csv',i);
    
    vir_synapse_vho_center_data = importdata(vir_synapse_vho_center_data_name);
    vir_synapse_vho_top_data = importdata(vir_synapse_vho_top_data_name);
    vir_synapse_vho_bottom_data = importdata(vir_synapse_vho_bottom_data_name);
    
    vr_synapse_vho_center_data = importdata(vr_synapse_vho_center_data_name);
    vr_synapse_vho_top_data = importdata(vr_synapse_vho_top_data_name);
    vr_synapse_vho_bottom_data = importdata(vr_synapse_vho_bottom_data_name);
    
    %VHO LFP
    fs = 1000;
    [vir_periodogram_vho_center, periodogram_fs] = periodogram(vir_synapse_vho_center_data,rectwin(length(vir_synapse_vho_center_data)),length(vir_synapse_vho_center_data),fs);
    vir_periodogram_vho_center_output_name = 'vir_periodogram_hva_center_%d.csv';
    vir_periodogram_vho_center_output = sprintf(vir_periodogram_vho_center_output_name,i);
    dlmwrite(vir_periodogram_vho_center_output, 10*log10(vir_periodogram_vho_center));

    fs = 1000;
    [vir_periodogram_vho_top, periodogram_fs] = periodogram(vir_synapse_vho_top_data,rectwin(length(vir_synapse_vho_top_data)),length(vir_synapse_vho_top_data),fs);
    vir_periodogram_vho_top_output_name = 'vir_periodogram_hva_top_%d.csv';
    vir_periodogram_vho_top_output = sprintf(vir_periodogram_vho_top_output_name,i);
    dlmwrite(vir_periodogram_vho_top_output, 10*log10(vir_periodogram_vho_top));

    fs = 1000;
    [vir_periodogram_vho_bottom, periodogram_fs] = periodogram(vir_synapse_vho_bottom_data,rectwin(length(vir_synapse_vho_bottom_data)),length(vir_synapse_vho_bottom_data),fs);
    vir_periodogram_vho_bottom_output_name = 'vir_periodogram_hva_bottom_%d.csv';
    vir_periodogram_vho_bottom_output = sprintf(vir_periodogram_vho_bottom_output_name,i);
    dlmwrite(vir_periodogram_vho_bottom_output, 10*log10(vir_periodogram_vho_bottom));
    
    fs = 1000;
    [vr_periodogram_vho_center, periodogram_fs] = periodogram(vr_synapse_vho_center_data,rectwin(length(vr_synapse_vho_center_data)),length(vr_synapse_vho_center_data),fs);
    vr_periodogram_vho_center_output_name = 'vr_periodogram_hva_center_%d.csv';
    vr_periodogram_vho_center_output = sprintf(vr_periodogram_vho_center_output_name,i);
    dlmwrite(vr_periodogram_vho_center_output, 10*log10(vr_periodogram_vho_center));

    fs = 1000;
    [vr_periodogram_vho_top, periodogram_fs] = periodogram(vr_synapse_vho_top_data,rectwin(length(vr_synapse_vho_top_data)),length(vr_synapse_vho_top_data),fs);
    vr_periodogram_vho_top_output_name = 'vr_periodogram_hva_top_%d.csv';
    vr_periodogram_vho_top_output = sprintf(vr_periodogram_vho_top_output_name,i);
    dlmwrite(vr_periodogram_vho_top_output, 10*log10(vr_periodogram_vho_top));

    fs = 1000;
    [vr_periodogram_vho_bottom, periodogram_fs] = periodogram(vr_synapse_vho_bottom_data,rectwin(length(vr_synapse_vho_bottom_data)),length(vr_synapse_vho_bottom_data),fs);
    vr_periodogram_vho_bottom_output_name = 'vr_periodogram_hva_bottom_%d.csv';
    vr_periodogram_vho_bottom_output = sprintf(vr_periodogram_vho_bottom_output_name,i);
    dlmwrite(vr_periodogram_vho_bottom_output, 10*log10(vr_periodogram_vho_bottom));
end

periodogram_freq = [periodogram_fs];
fileID_periodogram_freq = fopen('Vernier_periodogram_freq.csv', 'w');
fprintf(fileID_periodogram_freq, '%6d\n', periodogram_freq);
fclose(fileID_periodogram_freq);

exit()