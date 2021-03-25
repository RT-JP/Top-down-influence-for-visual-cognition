% Copyright (c) 2021 RT-JP All Right Reserved.

N = 5;

%load files
for i = 1:N
    vir_lfp_v1_center_top_total_name = sprintf("vir_lfp_v1_center_top_separate_total_%d.csv", i);
    vir_lfp_v1_center_top_total{i} = importdata(vir_lfp_v1_center_top_total_name);

    vir_lfp_v1_top_bottom_total_name = sprintf("vir_lfp_v1_top_bottom_separate_total_%d.csv", i);
    vir_lfp_v1_top_bottom_total{i} = importdata(vir_lfp_v1_top_bottom_total_name);

    vr_lfp_v1_center_top_total_name = sprintf("vr_lfp_v1_center_top_separate_total_%d.csv", i);
    vr_lfp_v1_center_top_total{i} = importdata(vr_lfp_v1_center_top_total_name);

    vr_lfp_v1_top_bottom_total_name = sprintf("vr_lfp_v1_top_bottom_separate_total_%d.csv", i);
    vr_lfp_v1_top_bottom_total{i} = importdata(vr_lfp_v1_top_bottom_total_name);

    vir_lfp_vho_center_top_total_name = sprintf("vir_lfp_vho_center_top_separate_total_%d.csv", i);
    vir_lfp_vho_center_top_total{i} = importdata(vir_lfp_vho_center_top_total_name);

    vir_lfp_vho_top_bottom_total_name = sprintf("vir_lfp_vho_top_bottom_separate_total_%d.csv", i);
    vir_lfp_vho_top_bottom_total{i} = importdata(vir_lfp_vho_top_bottom_total_name);

    vr_lfp_vho_center_top_total_name = sprintf("vr_lfp_vho_center_top_separate_total_%d.csv", i);
    vr_lfp_vho_center_top_total{i} = importdata(vr_lfp_vho_center_top_total_name);

    vr_lfp_vho_top_bottom_total_name = sprintf("vr_lfp_vho_top_bottom_separate_total_%d.csv", i);
    vr_lfp_vho_top_bottom_total{i} = importdata(vr_lfp_vho_top_bottom_total_name);

    %V1 analysis
    vir_lfp_v1_center_top_mean{i} = mean(vir_lfp_v1_center_top_total{i});
    fileID_name = sprintf("vir_lfp_v1_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_lfp_v1_center_top_mean{i});

    vir_lfp_v1_top_bottom_mean{i} = mean(vir_lfp_v1_top_bottom_total{i});
    fileID_name = sprintf("vir_lfp_v1_top_bottom_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_lfp_v1_top_bottom_mean{i});

    vr_lfp_v1_center_top_mean{i} = mean(vr_lfp_v1_center_top_total{i});
    fileID_name = sprintf("vr_lfp_v1_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_lfp_v1_center_top_mean{i});

    vr_lfp_v1_top_bottom_mean{i} = mean(vr_lfp_v1_top_bottom_total{i});
    fileID_name = sprintf("vr_lfp_v1_top_bottom_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_lfp_v1_top_bottom_mean{i});

    %VHO analysis
    vir_lfp_vho_center_top_mean{i} = mean(vir_lfp_vho_center_top_total{i});
    fileID_name = sprintf("vir_lfp_vho_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_lfp_vho_center_top_mean{i});

    vir_lfp_vho_top_bottom_mean{i} = mean(vir_lfp_vho_top_bottom_total{i});
    fileID_name = sprintf("vir_lfp_vho_top_bottom_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vir_lfp_vho_top_bottom_mean{i});

    vr_lfp_vho_center_top_mean{i} = mean(vr_lfp_vho_center_top_total{i});
    fileID_name = sprintf("vr_lfp_vho_center_top_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_lfp_vho_center_top_mean{i});

    vr_lfp_vho_top_bottom_mean{i} = mean(vr_lfp_vho_top_bottom_total{i});
    fileID_name = sprintf("vr_lfp_vho_top_bottom_separate_result_%d.csv", i);
    dlmwrite(fileID_name, vr_lfp_vho_top_bottom_mean{i});
end

exit()