% Copyright (c) 2021 RT-JP All Right Reserved.

N = 5;

%load files
for i = 1:N
    vir_periodogram_v1_center_total_name = sprintf("vir_periodogram_v1_center_separate_total_%d.csv", i);
    vir_periodogram_v1_center_total{i} = importdata(vir_periodogram_v1_center_total_name);
    
    vir_periodogram_v1_top_total_name = sprintf("vir_periodogram_v1_top_separate_total_%d.csv", i);
    vir_periodogram_v1_top_total{i} = importdata(vir_periodogram_v1_top_total_name);
    
    vr_periodogram_v1_center_total_name = sprintf("vr_periodogram_v1_center_separate_total_%d.csv", i);
    vr_periodogram_v1_center_total{i} = importdata(vr_periodogram_v1_center_total_name);
    
    vr_periodogram_v1_top_total_name = sprintf("vr_periodogram_v1_top_separate_total_%d.csv", i);
    vr_periodogram_v1_top_total{i} = importdata(vr_periodogram_v1_top_total_name);

    %V1 analysis
    vir_periodogram_v1_center_mean{i} = mean(vir_periodogram_v1_center_total{i});
    fileID_name = sprintf("vir_periodogram_v1_center_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_periodogram_v1_center_mean{i});
    
    vir_periodogram_v1_top_mean{i} = mean(vir_periodogram_v1_top_total{i});
    fileID_name = sprintf("vir_periodogram_v1_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_periodogram_v1_top_mean{i});
    
    vr_periodogram_v1_center_mean{i} = mean(vr_periodogram_v1_center_total{i});
    fileID_name = sprintf("vr_periodogram_v1_center_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_periodogram_v1_center_mean{i});
    
    vr_periodogram_v1_top_mean{i} = mean(vr_periodogram_v1_top_total{i});
    fileID_name = sprintf("vr_periodogram_v1_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_periodogram_v1_top_mean{i});
end

exit()