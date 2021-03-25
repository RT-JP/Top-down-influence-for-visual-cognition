% Copyright (c) 2021 RT-JP All Right Reserved.

N = 5;

%load files
for i = 1:N
    vir_bit_v1_center_top_total_name = sprintf("vir_bit_v1_center_top_separate_total_%d.csv", i);
    vir_bit_v1_center_top_total{i} = importdata(vir_bit_v1_center_top_total_name);

    vr_bit_v1_center_top_total_name = sprintf("vr_bit_v1_center_top_separate_total_%d.csv", i);
    vr_bit_v1_center_top_total{i} = importdata(vr_bit_v1_center_top_total_name);

    vir_bit_vho_center_top_total_name = sprintf("vir_bit_vho_center_top_separate_total_%d.csv", i);
    vir_bit_vho_center_top_total{i} = importdata(vir_bit_vho_center_top_total_name);

    vr_bit_vho_center_top_total_name = sprintf("vr_bit_vho_center_top_separate_total_%d.csv", i);
    vr_bit_vho_center_top_total{i} = importdata(vr_bit_vho_center_top_total_name);

    %V1 analysis
    vir_bit_v1_center_top_mean{i} = mean(vir_bit_v1_center_top_total{i});
    fileID_name = sprintf("vir_bit_v1_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_bit_v1_center_top_mean{i});

    vr_bit_v1_center_top_mean{i} = mean(vr_bit_v1_center_top_total{i});
    fileID_name = sprintf("vr_bit_v1_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_bit_v1_center_top_mean{i});

    %VHO analysis
    vir_bit_vho_center_top_mean{i} = mean(vir_bit_vho_center_top_total{i});
    fileID_name = sprintf("vir_bit_vho_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_bit_vho_center_top_mean{i});

    vr_bit_vho_center_top_mean{i} = mean(vr_bit_vho_center_top_total{i});
    fileID_name = sprintf("vr_bit_vho_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_bit_vho_center_top_mean{i});
end

exit()