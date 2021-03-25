% Copyright (c) 2021 RT-JP All Right Reserved.

N = 100;

for i = 1:N
    %V1data Input
    vir_lfp_v1_center_data_name = sprintf('vir_lfp_v1_center_data_%d.csv',i);
    vir_lfp_v1_top_data_name = sprintf('vir_lfp_v1_top_data_%d.csv',i);
    vir_lfp_v1_bottom_data_name = sprintf('vir_lfp_v1_bottom_data_%d.csv',i);
    vr_lfp_v1_center_data_name = sprintf('vr_lfp_v1_center_data_%d.csv',i);
    vr_lfp_v1_top_data_name = sprintf('vr_lfp_v1_top_data_%d.csv',i);
    vr_lfp_v1_bottom_data_name = sprintf('vr_lfp_v1_bottom_data_%d.csv',i);
    
    vir_lfp_v1_center_data = importdata(vir_lfp_v1_center_data_name);
    vir_lfp_v1_top_data = importdata(vir_lfp_v1_top_data_name);
    vir_lfp_v1_bottom_data = importdata(vir_lfp_v1_bottom_data_name);
    vr_lfp_v1_center_data = importdata(vr_lfp_v1_center_data_name);
    vr_lfp_v1_top_data = importdata(vr_lfp_v1_top_data_name);
    vr_lfp_v1_bottom_data = importdata(vr_lfp_v1_bottom_data_name);
    
    %V1 LFP
    fs = 1000;
    [vir_lfp_v1_center_top, lfp_fs] = mscohere(vir_lfp_v1_center_data,vir_lfp_v1_top_data,hamming(200),100,257,fs);
    vir_lfp_v1_center_top_result = [vir_lfp_v1_center_top];
    vir_lfp_v1_center_top_output_name = 'vir_lfp_v1_center_top_%d.csv';
    vir_lfp_v1_center_top_output = sprintf(vir_lfp_v1_center_top_output_name,i);
    dlmwrite(vir_lfp_v1_center_top_output, vir_lfp_v1_center_top_result);
    
    fs = 1000;
    [vr_lfp_v1_center_top, lfp_fs] = mscohere(vr_lfp_v1_center_data,vr_lfp_v1_top_data,hamming(200),100,257,fs);
    vr_lfp_v1_center_top_result = [vr_lfp_v1_center_top];
    vr_lfp_v1_center_top_output_name = 'vr_lfp_v1_center_top_%d.csv';
    vr_lfp_v1_center_top_output = sprintf(vr_lfp_v1_center_top_output_name,i);
    dlmwrite(vr_lfp_v1_center_top_output, vr_lfp_v1_center_top_result);

    fs = 1000;
    [vir_lfp_v1_top_bottom, lfp_fs] = mscohere(vir_lfp_v1_top_data,vir_lfp_v1_bottom_data,hamming(200),100,257,fs);
    vir_lfp_v1_top_bottom_result = [vir_lfp_v1_top_bottom];
    vir_lfp_v1_top_bottom_output_name = 'vir_lfp_v1_top_bottom_%d.csv';
    vir_lfp_v1_top_bottom_output = sprintf(vir_lfp_v1_top_bottom_output_name,i);
    dlmwrite(vir_lfp_v1_top_bottom_output, vir_lfp_v1_top_bottom_result);

    fs = 1000;
    [vr_lfp_v1_top_bottom, lfp_fs] = mscohere(vr_lfp_v1_top_data,vr_lfp_v1_bottom_data,hamming(200),100,257,fs);
    vr_lfp_v1_top_bottom_result = [vr_lfp_v1_top_bottom];
    vr_lfp_v1_top_bottom_output_name = 'vr_lfp_v1_top_bottom_%d.csv';
    vr_lfp_v1_top_bottom_output = sprintf(vr_lfp_v1_top_bottom_output_name,i);
    dlmwrite(vr_lfp_v1_top_bottom_output, vr_lfp_v1_top_bottom_result);

    %VHOdata Input
    vir_lfp_vho_center_data_name = sprintf('vir_lfp_vho_center_data_%d.csv',i);
    vir_lfp_vho_top_data_name = sprintf('vir_lfp_vho_top_data_%d.csv',i);
    vir_lfp_vho_bottom_data_name = sprintf('vir_lfp_vho_bottom_data_%d.csv',i);
    vr_lfp_vho_center_data_name = sprintf('vr_lfp_vho_center_data_%d.csv',i);
    vr_lfp_vho_top_data_name = sprintf('vr_lfp_vho_top_data_%d.csv',i);
    vr_lfp_vho_bottom_data_name = sprintf('vr_lfp_vho_bottom_data_%d.csv',i);
    
    vir_lfp_vho_center_data = importdata(vir_lfp_vho_center_data_name);
    vir_lfp_vho_top_data = importdata(vir_lfp_vho_top_data_name);
    vir_lfp_vho_bottom_data = importdata(vir_lfp_vho_bottom_data_name);
    vr_lfp_vho_center_data = importdata(vr_lfp_vho_center_data_name);
    vr_lfp_vho_top_data = importdata(vr_lfp_vho_top_data_name);
    vr_lfp_vho_bottom_data = importdata(vr_lfp_vho_bottom_data_name);
    
    %VHO LFP
    fs = 1000;
    [vir_lfp_vho_center_top, lfp_fs] = mscohere(vir_lfp_vho_center_data,vir_lfp_vho_top_data,hamming(200),100,257,fs);
    vir_lfp_vho_center_top_result = [vir_lfp_vho_center_top];
    vir_lfp_vho_center_top_output_name = 'vir_lfp_vho_center_top_%d.csv';
    vir_lfp_vho_center_top_output = sprintf(vir_lfp_vho_center_top_output_name,i);
    dlmwrite(vir_lfp_vho_center_top_output, vir_lfp_vho_center_top_result);
    
    fs = 1000;
    [vr_lfp_vho_center_top, lfp_fs] = mscohere(vr_lfp_vho_center_data,vr_lfp_vho_top_data,hamming(200),100,257,fs);
    vr_lfp_vho_center_top_result = [vr_lfp_vho_center_top];
    vr_lfp_vho_center_top_output_name = 'vr_lfp_vho_center_top_%d.csv';
    vr_lfp_vho_center_top_output = sprintf(vr_lfp_vho_center_top_output_name,i);
    dlmwrite(vr_lfp_vho_center_top_output, vr_lfp_vho_center_top_result);

    fs = 1000;
    [vir_lfp_vho_top_bottom, lfp_fs] = mscohere(vir_lfp_vho_top_data,vir_lfp_vho_bottom_data,hamming(200),100,257,fs);
    vir_lfp_vho_top_bottom_result = [vir_lfp_vho_top_bottom];
    vir_lfp_vho_top_bottom_output_name = 'vir_lfp_vho_top_bottom_%d.csv';
    vir_lfp_vho_top_bottom_output = sprintf(vir_lfp_vho_top_bottom_output_name,i);
    dlmwrite(vir_lfp_vho_top_bottom_output, vir_lfp_vho_top_bottom_result);

    fs = 1000;
    [vr_lfp_vho_top_bottom, lfp_fs] = mscohere(vr_lfp_vho_top_data,vr_lfp_vho_bottom_data,hamming(200),100,257,fs);
    vr_lfp_vho_top_bottom_result = [vr_lfp_vho_top_bottom];
    vr_lfp_vho_top_bottom_output_name = 'vr_lfp_vho_top_bottom_%d.csv';
    vr_lfp_vho_top_bottom_output = sprintf(vr_lfp_vho_top_bottom_output_name,i);
    dlmwrite(vr_lfp_vho_top_bottom_output, vr_lfp_vho_top_bottom_result);
    
    %V1 VHO LFP
    fs = 1000;
    [vir_lfp_v1_vho_center, lfp_fs] = mscohere(vir_lfp_v1_center_data,vir_lfp_vho_center_data,hamming(200),100,257,fs);
    vir_lfp_v1_vho_center_result = [vir_lfp_v1_vho_center];
    vir_lfp_v1_vho_center_output_name = 'vir_lfp_v1_vho_center_%d.csv';
    vir_lfp_v1_vho_center_output = sprintf(vir_lfp_v1_vho_center_output_name,i);
    dlmwrite(vir_lfp_v1_vho_center_output, vir_lfp_v1_vho_center_result);

    fs = 1000;
    [vir_lfp_v1_vho_top, lfp_fs] = mscohere(vir_lfp_v1_top_data,vir_lfp_vho_top_data,hamming(200),100,257,fs);
    vir_lfp_v1_vho_top_result = [vir_lfp_v1_vho_top];
    vir_lfp_v1_vho_top_output_name = 'vir_lfp_v1_vho_top_%d.csv';
    vir_lfp_v1_vho_top_output = sprintf(vir_lfp_v1_vho_top_output_name,i);
    dlmwrite(vir_lfp_v1_vho_top_output, vir_lfp_v1_vho_top_result);

    fs = 1000;
    [vr_lfp_v1_vho_center, lfp_fs] = mscohere(vr_lfp_v1_center_data,vr_lfp_vho_center_data,hamming(200),100,257,fs);
    vr_lfp_v1_vho_center_result = [vr_lfp_v1_vho_center];
    vr_lfp_v1_vho_center_output_name = 'vr_lfp_v1_vho_center_%d.csv';
    vr_lfp_v1_vho_center_output = sprintf(vr_lfp_v1_vho_center_output_name,i);
    dlmwrite(vr_lfp_v1_vho_center_output, vr_lfp_v1_vho_center_result);

    fs = 1000;
    [vr_lfp_v1_vho_top, lfp_fs] = mscohere(vr_lfp_v1_top_data,vr_lfp_vho_top_data,hamming(200),100,257,fs);
    vr_lfp_v1_vho_top_result = [vr_lfp_v1_vho_top];
    vr_lfp_v1_vho_top_output_name = 'vr_lfp_v1_vho_top_%d.csv';
    vr_lfp_v1_vho_top_output = sprintf(vr_lfp_v1_vho_top_output_name,i);
    dlmwrite(vr_lfp_v1_vho_top_output, vr_lfp_v1_vho_top_result);
end

lfp_freq = [lfp_fs];
fileID_lfp_freq = fopen('Vernier_lfp_freq.csv', 'w');
fprintf(fileID_lfp_freq, '%6d\n', lfp_freq);
fclose(fileID_lfp_freq);

exit()