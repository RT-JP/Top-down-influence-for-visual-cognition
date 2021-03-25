% Copyright (c) 2021 RT-JP All Right Reserved.

t = -1000:3:1000;
N = 100;

for i = 1:N
    %Create File Name
    bir_bit_v1_center_data_name = sprintf('bir_bit_v1_center_data_%d.csv',i);
    bir_bit_v1_left_data_name = sprintf('bir_bit_v1_left_data_%d.csv',i);
    bir_bit_v1_right_data_name = sprintf('bir_bit_v1_right_data_%d.csv',i);
    br_bit_v1_center_data_name = sprintf('br_bit_v1_center_data_%d.csv',i);
    br_bit_v1_left_data_name = sprintf('br_bit_v1_left_data_%d.csv',i);
    br_bit_v1_right_data_name = sprintf('br_bit_v1_right_data_%d.csv',i);
    %Input File
    bir_bit_v1_center_data = importdata(bir_bit_v1_center_data_name);
    bir_bit_v1_left_data = importdata(bir_bit_v1_left_data_name);
    bir_bit_v1_right_data = importdata(bir_bit_v1_right_data_name);
    br_bit_v1_center_data = importdata(br_bit_v1_center_data_name);
    br_bit_v1_left_data = importdata(br_bit_v1_left_data_name);
    br_bit_v1_right_data = importdata(br_bit_v1_right_data_name);
    %Irrelevant bit Output File
    bir_bit_v1_center_left = xcorr(bir_bit_v1_center_data, bir_bit_v1_left_data, 'coeff');
    bir_bit_v1_center_left_output_name = 'bir_bit_v1_center_left_%d.csv';
    bir_bit_v1_center_left_output = sprintf(bir_bit_v1_center_left_output_name,i);
    dlmwrite(bir_bit_v1_center_left_output, bir_bit_v1_center_left);
    
    bir_bit_v1_center_right = xcorr(bir_bit_v1_center_data, bir_bit_v1_right_data, 'coeff');
    bir_bit_v1_center_right_output_name = 'bir_bit_v1_center_right_%d.csv';
    bir_bit_v1_center_right_output = sprintf(bir_bit_v1_center_right_output_name,i);
    dlmwrite(bir_bit_v1_center_right_output, bir_bit_v1_center_right);

    %Relevant bit Output File
    br_bit_v1_center_left = xcorr(br_bit_v1_center_data, br_bit_v1_left_data, 'coeff');
    br_bit_v1_center_left_output_name = 'br_bit_v1_center_left_%d.csv';
    br_bit_v1_center_left_output = sprintf(br_bit_v1_center_left_output_name,i);
    dlmwrite(br_bit_v1_center_left_output, br_bit_v1_center_left);
    
    br_bit_v1_center_right = xcorr(br_bit_v1_center_data, br_bit_v1_right_data, 'coeff');
    br_bit_v1_center_right_output_name = 'br_bit_v1_center_right_%d.csv';
    br_bit_v1_center_right_output = sprintf(br_bit_v1_center_right_output_name,i);
    dlmwrite(br_bit_v1_center_right_output, br_bit_v1_center_right);
end

for i = 1:N
    %Create File Name
    bir_bit_vho_center_data_name = sprintf('bir_bit_vho_center_data_%d.csv',i);
    bir_bit_vho_left_data_name = sprintf('bir_bit_vho_left_data_%d.csv',i);
    bir_bit_vho_right_data_name = sprintf('bir_bit_vho_right_data_%d.csv',i);
    br_bit_vho_center_data_name = sprintf('br_bit_vho_center_data_%d.csv',i);
    br_bit_vho_left_data_name = sprintf('br_bit_vho_left_data_%d.csv',i);
    br_bit_vho_right_data_name = sprintf('br_bit_vho_right_data_%d.csv',i);
    %Input File
    bir_bit_vho_center_data = importdata(bir_bit_vho_center_data_name);
    bir_bit_vho_left_data = importdata(bir_bit_vho_left_data_name);
    bir_bit_vho_right_data = importdata(bir_bit_vho_right_data_name);
    br_bit_vho_center_data = importdata(br_bit_vho_center_data_name);
    br_bit_vho_left_data = importdata(br_bit_vho_left_data_name);
    br_bit_vho_right_data = importdata(br_bit_vho_right_data_name);
    %Irrelevant bit Output File
    bir_bit_vho_center_left = xcorr(bir_bit_vho_center_data, bir_bit_vho_left_data, 'coeff');
    bir_bit_vho_center_left_output_name = 'bir_bit_vho_center_left_%d.csv';
    bir_bit_vho_center_left_output = sprintf(bir_bit_vho_center_left_output_name,i);
    dlmwrite(bir_bit_vho_center_left_output, bir_bit_vho_center_left);
    
    bir_bit_vho_center_right = xcorr(bir_bit_vho_center_data, bir_bit_vho_right_data, 'coeff');
    bir_bit_vho_center_right_output_name = 'bir_bit_vho_center_right_%d.csv';
    bir_bit_vho_center_right_output = sprintf(bir_bit_vho_center_right_output_name,i);
    dlmwrite(bir_bit_vho_center_right_output, bir_bit_vho_center_right);

    %Relevant bit Output File
    br_bit_vho_center_left = xcorr(br_bit_vho_center_data, br_bit_vho_left_data, 'coeff');
    br_bit_vho_center_left_output_name = 'br_bit_vho_center_left_%d.csv';
    br_bit_vho_center_left_output = sprintf(br_bit_vho_center_left_output_name,i);
    dlmwrite(br_bit_vho_center_left_output, br_bit_vho_center_left);
    
    br_bit_vho_center_right = xcorr(br_bit_vho_center_data, br_bit_vho_right_data, 'coeff');
    br_bit_vho_center_right_output_name = 'br_bit_vho_center_right_%d.csv';
    br_bit_vho_center_right_output = sprintf(br_bit_vho_center_right_output_name,i);
    dlmwrite(br_bit_vho_center_right_output, br_bit_vho_center_right);
end

fileID_bit_time = fopen('Bisection_bit_time.csv', 'w');
fprintf(fileID_bit_time, '%6d\n', t);
fclose(fileID_bit_time);

exit()