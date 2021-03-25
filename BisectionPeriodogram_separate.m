% Copyright (c) 2021 RT-JP All Right Reserved.

N = 5;

%load files
for i = 1:N
    bir_periodogram_v1_center_total_name = sprintf("bir_periodogram_v1_center_separate_total_%d.csv", i);
    bir_periodogram_v1_center_total{i} = importdata(bir_periodogram_v1_center_total_name);
    
    bir_periodogram_v1_right_total_name = sprintf("bir_periodogram_v1_right_separate_total_%d.csv", i);
    bir_periodogram_v1_right_total{i} = importdata(bir_periodogram_v1_right_total_name);
    
    br_periodogram_v1_center_total_name = sprintf("br_periodogram_v1_center_separate_total_%d.csv", i);
    br_periodogram_v1_center_total{i} = importdata(br_periodogram_v1_center_total_name);
    
    br_periodogram_v1_right_total_name = sprintf("br_periodogram_v1_right_separate_total_%d.csv", i);
    br_periodogram_v1_right_total{i} = importdata(br_periodogram_v1_right_total_name);

    %V1 analysis
    bir_periodogram_v1_center_mean{i} = mean(bir_periodogram_v1_center_total{i});
    fileID_name = sprintf("bir_periodogram_v1_center_separate_result_%d.csv", i);
    dlmwrite(fileID_name, bir_periodogram_v1_center_mean{i});
    
    bir_periodogram_v1_right_mean{i} = mean(bir_periodogram_v1_right_total{i});
    fileID_name = sprintf("bir_periodogram_v1_right_separate_result_%d.csv", i);
    dlmwrite(fileID_name, bir_periodogram_v1_right_mean{i});
    
    br_periodogram_v1_center_mean{i} = mean(br_periodogram_v1_center_total{i});
    fileID_name = sprintf("br_periodogram_v1_center_separate_result_%d.csv", i);
    dlmwrite(fileID_name, br_periodogram_v1_center_mean{i});
    
    br_periodogram_v1_right_mean{i} = mean(br_periodogram_v1_right_total{i});
    fileID_name = sprintf("br_periodogram_v1_right_separate_result_%d.csv", i);
    dlmwrite(fileID_name, br_periodogram_v1_right_mean{i});
end

exit()