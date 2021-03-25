% Copyright (c) 2021 RT-JP All Right Reserved.

t = -1000:3:1000;
N = 100;

for i = 1:N
    %Create File Name
    vir_bit_v1_center_data_name = sprintf('vir_bit_v1_center_data_%d.csv',i);
    vir_bit_v1_top_data_name = sprintf('vir_bit_v1_top_data_%d.csv',i);
    vr_bit_v1_center_data_name = sprintf('vr_bit_v1_center_data_%d.csv',i);
    vr_bit_v1_top_data_name = sprintf('vr_bit_v1_top_data_%d.csv',i);
    %Input File
    vir_bit_v1_center_data = importdata(vir_bit_v1_center_data_name);
    vir_bit_v1_top_data = importdata(vir_bit_v1_top_data_name);
    vr_bit_v1_center_data = importdata(vr_bit_v1_center_data_name);
    vr_bit_v1_top_data = importdata(vr_bit_v1_top_data_name);
    %Irrelevant bit Output File
    vir_bit_v1_center_top = xcorr(vir_bit_v1_center_data, vir_bit_v1_top_data, 'coeff');
    vir_bit_v1_center_top_output_name = 'vir_bit_v1_center_top_%d.csv';
    vir_bit_v1_center_top_output = sprintf(vir_bit_v1_center_top_output_name,i);
    dlmwrite(vir_bit_v1_center_top_output, vir_bit_v1_center_top);
    
    %Relevant bit Output File
    vr_bit_v1_center_top = xcorr(vr_bit_v1_center_data, vr_bit_v1_top_data, 'coeff');
    vr_bit_v1_center_top_output_name = 'vr_bit_v1_center_top_%d.csv';
    vr_bit_v1_center_top_output = sprintf(vr_bit_v1_center_top_output_name,i);
    dlmwrite(vr_bit_v1_center_top_output, vr_bit_v1_center_top);
    
    %Create File Name
    vir_bit_vho_center_data_name = sprintf('vir_bit_vho_center_data_%d.csv',i);
    vir_bit_vho_top_data_name = sprintf('vir_bit_vho_top_data_%d.csv',i);
    vr_bit_vho_center_data_name = sprintf('vr_bit_vho_center_data_%d.csv',i);
    vr_bit_vho_top_data_name = sprintf('vr_bit_vho_top_data_%d.csv',i);
    %Input File
    vir_bit_vho_center_data = importdata(vir_bit_vho_center_data_name);
    vir_bit_vho_top_data = importdata(vir_bit_vho_top_data_name);
    vr_bit_vho_center_data = importdata(vr_bit_vho_center_data_name);
    vr_bit_vho_top_data = importdata(vr_bit_vho_top_data_name);
    %Irrelevant bit Output File
    vir_bit_vho_center_top = xcorr(vir_bit_vho_center_data, vir_bit_vho_top_data, 'coeff');
    vir_bit_vho_center_top_output_name = 'vir_bit_vho_center_top_%d.csv';
    vir_bit_vho_center_top_output = sprintf(vir_bit_vho_center_top_output_name,i);
    dlmwrite(vir_bit_vho_center_top_output, vir_bit_vho_center_top);
    
    %Relevant bit Output File
    vr_bit_vho_center_top = xcorr(vr_bit_vho_center_data, vr_bit_vho_top_data, 'coeff');
    vr_bit_vho_center_top_output_name = 'vr_bit_vho_center_top_%d.csv';
    vr_bit_vho_center_top_output = sprintf(vr_bit_vho_center_top_output_name,i);
    dlmwrite(vr_bit_vho_center_top_output, vr_bit_vho_center_top);
    
    %Irrelevant V1 VHO bit Output File
    vir_bit_v1_vho_center = xcorr(vir_bit_v1_center_data, vir_bit_vho_center_data, 'coeff');
    vir_bit_v1_vho_center_output_name = 'vir_bit_v1_vho_center_%d.csv';
    vir_bit_v1_vho_center_output = sprintf(vir_bit_v1_vho_center_output_name,i);
    dlmwrite(vir_bit_v1_vho_center_output, vir_bit_v1_vho_center);

    vir_bit_v1_vho_top = xcorr(vir_bit_v1_top_data, vir_bit_vho_top_data, 'coeff');
    vir_bit_v1_vho_top_output_name = 'vir_bit_v1_vho_top_%d.csv';
    vir_bit_v1_vho_top_output = sprintf(vir_bit_v1_vho_top_output_name,i);
    dlmwrite(vir_bit_v1_vho_top_output, vir_bit_v1_vho_top);

    %Relevant V1 VHO bit Output File
    vr_bit_v1_vho_center = xcorr(vr_bit_v1_center_data, vr_bit_vho_center_data, 'coeff');
    vr_bit_v1_vho_center_output_name = 'vr_bit_v1_vho_center_%d.csv';
    vr_bit_v1_vho_center_output = sprintf(vr_bit_v1_vho_center_output_name,i);
    dlmwrite(vr_bit_v1_vho_center_output, vr_bit_v1_vho_center);

    vr_bit_v1_vho_top = xcorr(vr_bit_v1_top_data, vr_bit_vho_top_data, 'coeff');
    vr_bit_v1_vho_top_output_name = 'vr_bit_v1_vho_top_%d.csv';
    vr_bit_v1_vho_top_output = sprintf(vr_bit_v1_vho_top_output_name,i);
    dlmwrite(vr_bit_v1_vho_top_output, vr_bit_v1_vho_top);
end

fileID_bit_time = fopen('Vernier_bit_time.csv', 'w');
fprintf(fileID_bit_time, '%6d\n', t);
fclose(fileID_bit_time);

exit()