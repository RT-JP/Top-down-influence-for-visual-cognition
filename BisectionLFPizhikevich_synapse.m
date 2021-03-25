% Copyright (c) 2021 RT-JP All Right Reserved.

N = 100;

for i = 1:N
    %V1data Input
    bir_lfp_v1_center_data_name = sprintf('bir_lfp_v1_center_data_%d.csv',i);
    bir_lfp_v1_left_data_name = sprintf('bir_lfp_v1_left_data_%d.csv',i);
    bir_lfp_v1_right_data_name = sprintf('bir_lfp_v1_right_data_%d.csv',i);
    br_lfp_v1_center_data_name = sprintf('br_lfp_v1_center_data_%d.csv',i);
    br_lfp_v1_left_data_name = sprintf('br_lfp_v1_left_data_%d.csv',i);
    br_lfp_v1_right_data_name = sprintf('br_lfp_v1_right_data_%d.csv',i);
    
    bir_lfp_v1_center_data = importdata(bir_lfp_v1_center_data_name);
    bir_lfp_v1_left_data = importdata(bir_lfp_v1_left_data_name);
    bir_lfp_v1_right_data = importdata(bir_lfp_v1_right_data_name);
    br_lfp_v1_center_data = importdata(br_lfp_v1_center_data_name);
    br_lfp_v1_left_data = importdata(br_lfp_v1_left_data_name);
    br_lfp_v1_right_data = importdata(br_lfp_v1_right_data_name);
    
    %V1 LFP
    fs = 1000;
    [bir_lfp_v1_center_left, lfp_fs] = mscohere(bir_lfp_v1_center_data,bir_lfp_v1_left_data,hamming(200),100,257,fs);
    bir_lfp_v1_center_left_result = [bir_lfp_v1_center_left];
    bir_lfp_v1_center_left_output_name = 'bir_lfp_v1_center_left_synapse_%d.csv';
    bir_lfp_v1_center_left_output = sprintf(bir_lfp_v1_center_left_output_name,i);
    dlmwrite(bir_lfp_v1_center_left_output, bir_lfp_v1_center_left_result);
    
    fs = 1000;
    [bir_lfp_v1_center_right, lfp_fs] = mscohere(bir_lfp_v1_center_data,bir_lfp_v1_right_data,hamming(200),100,257,fs);
    bir_lfp_v1_center_right_result = [bir_lfp_v1_center_right];
    bir_lfp_v1_center_right_output_name = 'bir_lfp_v1_center_right_synapse_%d.csv';
    bir_lfp_v1_center_right_output = sprintf(bir_lfp_v1_center_right_output_name,i);
    dlmwrite(bir_lfp_v1_center_right_output, bir_lfp_v1_center_right_result);
    
    fs = 1000;
    [br_lfp_v1_center_left, lfp_fs] = mscohere(br_lfp_v1_center_data,br_lfp_v1_left_data,hamming(200),100,257,fs);
    br_lfp_v1_center_left_result = [br_lfp_v1_center_left];
    br_lfp_v1_center_left_output_name = 'br_lfp_v1_center_left_synapse_%d.csv';
    br_lfp_v1_center_left_output = sprintf(br_lfp_v1_center_left_output_name,i);
    dlmwrite(br_lfp_v1_center_left_output, br_lfp_v1_center_left_result);
    
    fs = 1000;
    [br_lfp_v1_center_right, lfp_fs] = mscohere(br_lfp_v1_center_data,br_lfp_v1_right_data,hamming(200),100,257,fs);
    br_lfp_v1_center_right_result = [br_lfp_v1_center_right];
    br_lfp_v1_center_right_output_name = 'br_lfp_v1_center_right_synapse_%d.csv';
    br_lfp_v1_center_right_output = sprintf(br_lfp_v1_center_right_output_name,i);
    dlmwrite(br_lfp_v1_center_right_output, br_lfp_v1_center_right_result);
end

for i = 1:N
    %VHOdata Input
    bir_lfp_vho_center_data_name = sprintf('bir_lfp_vho_center_data_%d.csv',i);
    bir_lfp_vho_left_data_name = sprintf('bir_lfp_vho_left_data_%d.csv',i);
    bir_lfp_vho_right_data_name = sprintf('bir_lfp_vho_right_data_%d.csv',i);
    br_lfp_vho_center_data_name = sprintf('br_lfp_vho_center_data_%d.csv',i);
    br_lfp_vho_left_data_name = sprintf('br_lfp_vho_left_data_%d.csv',i);
    br_lfp_vho_right_data_name = sprintf('br_lfp_vho_right_data_%d.csv',i);
    
    bir_lfp_vho_center_data = importdata(bir_lfp_vho_center_data_name);
    bir_lfp_vho_left_data = importdata(bir_lfp_vho_left_data_name);
    bir_lfp_vho_right_data = importdata(bir_lfp_vho_right_data_name);
    br_lfp_vho_center_data = importdata(br_lfp_vho_center_data_name);
    br_lfp_vho_left_data = importdata(br_lfp_vho_left_data_name);
    br_lfp_vho_right_data = importdata(br_lfp_vho_right_data_name);
    
    %VHO LFP
    fs = 1000;
    [bir_lfp_vho_center_left, lfp_fs] = mscohere(bir_lfp_vho_center_data,bir_lfp_vho_left_data,hamming(200),100,257,fs);
    bir_lfp_vho_center_left_result = [bir_lfp_vho_center_left];
    bir_lfp_vho_center_left_output_name = 'bir_lfp_vho_center_left_synapse_%d.csv';
    bir_lfp_vho_center_left_output = sprintf(bir_lfp_vho_center_left_output_name,i);
    dlmwrite(bir_lfp_vho_center_left_output, bir_lfp_vho_center_left_result);
    
    fs = 1000;
    [bir_lfp_vho_center_right, lfp_fs] = mscohere(bir_lfp_vho_center_data,bir_lfp_vho_right_data,hamming(200),100,257,fs);
    bir_lfp_vho_center_right_result = [bir_lfp_vho_center_right];
    bir_lfp_vho_center_right_output_name = 'bir_lfp_vho_center_right_synapse_%d.csv';
    bir_lfp_vho_center_right_output = sprintf(bir_lfp_vho_center_right_output_name,i);
    dlmwrite(bir_lfp_vho_center_right_output, bir_lfp_vho_center_right_result);
    
    fs = 1000;
    [br_lfp_vho_center_left, lfp_fs] = mscohere(br_lfp_vho_center_data,br_lfp_vho_left_data,hamming(200),100,257,fs);
    br_lfp_vho_center_left_result = [br_lfp_vho_center_left];
    br_lfp_vho_center_left_output_name = 'br_lfp_vho_center_left_synapse_%d.csv';
    br_lfp_vho_center_left_output = sprintf(br_lfp_vho_center_left_output_name,i);
    dlmwrite(br_lfp_vho_center_left_output, br_lfp_vho_center_left_result);
    
    fs = 1000;
    [br_lfp_vho_center_right, lfp_fs] = mscohere(br_lfp_vho_center_data,br_lfp_vho_right_data,hamming(200),100,257,fs);
    br_lfp_vho_center_right_result = [br_lfp_vho_center_right];
    br_lfp_vho_center_right_output_name = 'br_lfp_vho_center_right_synapse_%d.csv';
    br_lfp_vho_center_right_output = sprintf(br_lfp_vho_center_right_output_name,i);
    dlmwrite(br_lfp_vho_center_right_output, br_lfp_vho_center_right_result);
end

lfp_freq = [lfp_fs];
fileID_lfp_freq = fopen('Bisection_lfp_freq.csv', 'w');
fprintf(fileID_lfp_freq, '%6d\n', lfp_freq);
fclose(fileID_lfp_freq);

exit()