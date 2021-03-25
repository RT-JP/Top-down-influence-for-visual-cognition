% Copyright (c) 2021 RT-JP All Right Reserved.

%load files
lfp_result = load("Vernier_lfp_freq.csv");

vir_lfp_v1_center_top_total = load("vir_lfp_v1_center_top_separate_result_total.csv");
vir_lfp_v1_top_bottom_total = load("vir_lfp_v1_top_bottom_separate_result_total.csv");
vr_lfp_v1_center_top_total = load("vr_lfp_v1_center_top_separate_result_total.csv");
vr_lfp_v1_top_bottom_total = load("vr_lfp_v1_top_bottom_separate_result_total.csv");

vir_lfp_vho_center_top_total = load("vir_lfp_vho_center_top_separate_result_total.csv");
vir_lfp_vho_top_bottom_total = load("vir_lfp_vho_top_bottom_separate_result_total.csv");
vr_lfp_vho_center_top_total = load("vr_lfp_vho_center_top_separate_result_total.csv");
vr_lfp_vho_top_bottom_total = load("vr_lfp_vho_top_bottom_separate_result_total.csv");

%V1 analysis
vir_lfp_v1_center_top_mean = mean(vir_lfp_v1_center_top_total);
vir_lfp_v1_center_top_std = std(vir_lfp_v1_center_top_total);
vir_lfp_v1_center_top_result = horzcat(lfp_result, vir_lfp_v1_center_top_mean', vir_lfp_v1_center_top_std');
dlmwrite("vir_lfp_v1_center_top_separate_mean_result.csv", vir_lfp_v1_center_top_result);

vir_lfp_v1_top_bottom_mean = mean(vir_lfp_v1_top_bottom_total);
vir_lfp_v1_top_bottom_std = std(vir_lfp_v1_top_bottom_total);
vir_lfp_v1_top_bottom_result = horzcat(lfp_result, vir_lfp_v1_top_bottom_mean', vir_lfp_v1_top_bottom_std');
dlmwrite("vir_lfp_v1_top_bottom_separate_mean_result.csv", vir_lfp_v1_top_bottom_result);

vr_lfp_v1_center_top_mean = mean(vr_lfp_v1_center_top_total);
vr_lfp_v1_center_top_std = std(vr_lfp_v1_center_top_total);
vr_lfp_v1_center_top_result = horzcat(lfp_result, vr_lfp_v1_center_top_mean', vr_lfp_v1_center_top_std');
dlmwrite("vr_lfp_v1_center_top_separate_mean_result.csv", vr_lfp_v1_center_top_result);

vr_lfp_v1_top_bottom_mean = mean(vr_lfp_v1_top_bottom_total);
vr_lfp_v1_top_bottom_std = std(vr_lfp_v1_top_bottom_total);
vr_lfp_v1_top_bottom_result = horzcat(lfp_result, vr_lfp_v1_top_bottom_mean', vr_lfp_v1_top_bottom_std');
dlmwrite("vr_lfp_v1_top_bottom_separate_mean_result.csv", vr_lfp_v1_top_bottom_result);

%VHO analysis
vir_lfp_vho_center_top_mean = mean(vir_lfp_vho_center_top_total);
vir_lfp_vho_center_top_std = std(vir_lfp_vho_center_top_total);
vir_lfp_vho_center_top_result = horzcat(lfp_result, vir_lfp_vho_center_top_mean', vir_lfp_vho_center_top_std');
dlmwrite("vir_lfp_vho_center_top_separate_mean_result.csv", vir_lfp_vho_center_top_result);

vir_lfp_vho_top_bottom_mean = mean(vir_lfp_vho_top_bottom_total);
vir_lfp_vho_top_bottom_std = std(vir_lfp_vho_top_bottom_total);
vir_lfp_vho_top_bottom_result = horzcat(lfp_result, vir_lfp_vho_top_bottom_mean', vir_lfp_vho_top_bottom_std');
dlmwrite("vir_lfp_vho_top_bottom_separate_mean_result.csv", vir_lfp_vho_top_bottom_result);

vr_lfp_vho_center_top_mean = mean(vr_lfp_vho_center_top_total);
vr_lfp_vho_center_top_std = std(vr_lfp_vho_center_top_total);
vr_lfp_vho_center_top_result = horzcat(lfp_result, vr_lfp_vho_center_top_mean', vr_lfp_vho_center_top_std');
dlmwrite("vr_lfp_vho_center_top_separate_mean_result.csv", vr_lfp_vho_center_top_result);

vr_lfp_vho_top_bottom_mean = mean(vr_lfp_vho_top_bottom_total);
vr_lfp_vho_top_bottom_std = std(vr_lfp_vho_top_bottom_total);
vr_lfp_vho_top_bottom_result = horzcat(lfp_result, vr_lfp_vho_top_bottom_mean', vr_lfp_vho_top_bottom_std');
dlmwrite("vr_lfp_vho_top_bottom_separate_mean_result.csv", vr_lfp_vho_top_bottom_result);

exit()