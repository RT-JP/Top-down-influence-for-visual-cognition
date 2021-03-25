% Copyright (c) 2021 RT-JP All Right Reserved.

N = 100;

for i = 1:N
    %V1data Input
    bir_synapse_v1_center_data_name = sprintf('bir_lfp_v1_center_data_%d.csv',i);
    bir_synapse_v1_left_data_name = sprintf('bir_lfp_v1_left_data_%d.csv',i);
    bir_synapse_v1_right_data_name = sprintf('bir_lfp_v1_right_data_%d.csv',i);
    
    br_synapse_v1_center_data_name = sprintf('br_lfp_v1_center_data_%d.csv',i);
    br_synapse_v1_left_data_name = sprintf('br_lfp_v1_left_data_%d.csv',i);
    br_synapse_v1_right_data_name = sprintf('br_lfp_v1_right_data_%d.csv',i);
    
    bir_synapse_v1_center_data = importdata(bir_synapse_v1_center_data_name);
    bir_synapse_v1_left_data = importdata(bir_synapse_v1_left_data_name);
    bir_synapse_v1_right_data = importdata(bir_synapse_v1_right_data_name);
    
    br_synapse_v1_center_data = importdata(br_synapse_v1_center_data_name);
    br_synapse_v1_left_data = importdata(br_synapse_v1_left_data_name);
    br_synapse_v1_right_data = importdata(br_synapse_v1_right_data_name);
    
    %V1 LFP
    fs = 1000;
    [bir_periodogram_v1_center, periodogram_fs] = periodogram(bir_synapse_v1_center_data,hamming(length(bir_synapse_v1_center_data)),500,fs);
    bir_periodogram_v1_center_output_name = 'bir_periodogram_v1_center_%d.csv';
    bir_periodogram_v1_center_output = sprintf(bir_periodogram_v1_center_output_name,i);
    dlmwrite(bir_periodogram_v1_center_output, 10*log10(bir_periodogram_v1_center));

    fs = 1000;
    [bir_periodogram_v1_left, periodogram_fs] = periodogram(bir_synapse_v1_left_data,hamming(length(bir_synapse_v1_left_data)),500,fs);
    bir_periodogram_v1_left_output_name = 'bir_periodogram_v1_left_%d.csv';
    bir_periodogram_v1_left_output = sprintf(bir_periodogram_v1_left_output_name,i);
    dlmwrite(bir_periodogram_v1_left_output, 10*log10(bir_periodogram_v1_left));

    fs = 1000;
    [bir_periodogram_v1_right, periodogram_fs] = periodogram(bir_synapse_v1_right_data,hamming(length(bir_synapse_v1_right_data)),500,fs);
    bir_periodogram_v1_right_output_name = 'bir_periodogram_v1_right_%d.csv';
    bir_periodogram_v1_right_output = sprintf(bir_periodogram_v1_right_output_name,i);
    dlmwrite(bir_periodogram_v1_right_output, 10*log10(bir_periodogram_v1_right));
    
    fs = 1000;
    [br_periodogram_v1_center, periodogram_fs] = periodogram(br_synapse_v1_center_data,hamming(length(br_synapse_v1_center_data)),500,fs);
    br_periodogram_v1_center_output_name = 'br_periodogram_v1_center_%d.csv';
    br_periodogram_v1_center_output = sprintf(br_periodogram_v1_center_output_name,i);
    dlmwrite(br_periodogram_v1_center_output, 10*log10(br_periodogram_v1_center));

    fs = 1000;
    [br_periodogram_v1_left, periodogram_fs] = periodogram(br_synapse_v1_left_data,hamming(length(br_synapse_v1_left_data)),500,fs);
    br_periodogram_v1_left_output_name = 'br_periodogram_v1_left_%d.csv';
    br_periodogram_v1_left_output = sprintf(br_periodogram_v1_left_output_name,i);
    dlmwrite(br_periodogram_v1_left_output, 10*log10(br_periodogram_v1_left));

    fs = 1000;
    [br_periodogram_v1_right, periodogram_fs] = periodogram(br_synapse_v1_right_data,hamming(length(br_synapse_v1_right_data)),500,fs);
    br_periodogram_v1_right_output_name = 'br_periodogram_v1_right_%d.csv';
    br_periodogram_v1_right_output = sprintf(br_periodogram_v1_right_output_name,i);
    dlmwrite(br_periodogram_v1_right_output, 10*log10(br_periodogram_v1_right));

    %VHOdata Input
    bir_synapse_vho_center_data_name = sprintf('bir_lfp_vho_center_data_%d.csv',i);
    bir_synapse_vho_left_data_name = sprintf('bir_lfp_vho_left_data_%d.csv',i);
    bir_synapse_vho_right_data_name = sprintf('bir_lfp_vho_right_data_%d.csv',i);
    
    br_synapse_vho_center_data_name = sprintf('br_lfp_vho_center_data_%d.csv',i);
    br_synapse_vho_left_data_name = sprintf('br_lfp_vho_left_data_%d.csv',i);
    br_synapse_vho_right_data_name = sprintf('br_lfp_vho_right_data_%d.csv',i);
    
    bir_synapse_vho_center_data = importdata(bir_synapse_vho_center_data_name);
    bir_synapse_vho_left_data = importdata(bir_synapse_vho_left_data_name);
    bir_synapse_vho_right_data = importdata(bir_synapse_vho_right_data_name);
    
    br_synapse_vho_center_data = importdata(br_synapse_vho_center_data_name);
    br_synapse_vho_left_data = importdata(br_synapse_vho_left_data_name);
    br_synapse_vho_right_data = importdata(br_synapse_vho_right_data_name);
    
    %VHO LFP
    fs = 1000;
    [bir_periodogram_vho_center, periodogram_fs] = periodogram(bir_synapse_vho_center_data,hamming(length(bir_synapse_vho_center_data)),500,fs);
    bir_periodogram_vho_center_output_name = 'bir_periodogram_hva_center_%d.csv';
    bir_periodogram_vho_center_output = sprintf(bir_periodogram_vho_center_output_name,i);
    dlmwrite(bir_periodogram_vho_center_output, 10*log10(bir_periodogram_vho_center));

    fs = 1000;
    [bir_periodogram_vho_left, periodogram_fs] = periodogram(bir_synapse_vho_left_data,hamming(length(bir_synapse_vho_left_data)),500,fs);
    bir_periodogram_vho_left_output_name = 'bir_periodogram_hva_left_%d.csv';
    bir_periodogram_vho_left_output = sprintf(bir_periodogram_vho_left_output_name,i);
    dlmwrite(bir_periodogram_vho_left_output, 10*log10(bir_periodogram_vho_left));

    fs = 1000;
    [bir_periodogram_vho_right, periodogram_fs] = periodogram(bir_synapse_vho_right_data,hamming(length(bir_synapse_vho_right_data)),500,fs);
    bir_periodogram_vho_right_output_name = 'bir_periodogram_hva_right_%d.csv';
    bir_periodogram_vho_right_output = sprintf(bir_periodogram_vho_right_output_name,i);
    dlmwrite(bir_periodogram_vho_right_output, 10*log10(bir_periodogram_vho_right));
    
    fs = 1000;
    [br_periodogram_vho_center, periodogram_fs] = periodogram(br_synapse_vho_center_data,hamming(length(br_synapse_vho_center_data)),500,fs);
    br_periodogram_vho_center_output_name = 'br_periodogram_hva_center_%d.csv';
    br_periodogram_vho_center_output = sprintf(br_periodogram_vho_center_output_name,i);
    dlmwrite(br_periodogram_vho_center_output, 10*log10(br_periodogram_vho_center));

    fs = 1000;
    [br_periodogram_vho_left, periodogram_fs] = periodogram(br_synapse_vho_left_data,hamming(length(br_synapse_vho_left_data)),500,fs);
    br_periodogram_vho_left_output_name = 'br_periodogram_hva_left_%d.csv';
    br_periodogram_vho_left_output = sprintf(br_periodogram_vho_left_output_name,i);
    dlmwrite(br_periodogram_vho_left_output, 10*log10(br_periodogram_vho_left));

    fs = 1000;
    [br_periodogram_vho_right, periodogram_fs] = periodogram(br_synapse_vho_right_data,hamming(length(br_synapse_vho_right_data)),500,fs);
    br_periodogram_vho_right_output_name = 'br_periodogram_hva_right_%d.csv';
    br_periodogram_vho_right_output = sprintf(br_periodogram_vho_right_output_name,i);
    dlmwrite(br_periodogram_vho_right_output, 10*log10(br_periodogram_vho_right));
end

periodogram_freq = [periodogram_fs];
fileID_periodogram_freq = fopen('Bisection_periodogram_freq.csv', 'w');
fprintf(fileID_periodogram_freq, '%6d\n', periodogram_freq);
fclose(fileID_periodogram_freq);

exit()