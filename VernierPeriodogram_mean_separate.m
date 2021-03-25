% Copyright (c) 2021 RT-JP All Right Reserved.

%load files
periodogram_result = load("Vernier_periodogram_freq.csv");

vir_periodogram_v1_center_total = load("vir_periodogram_v1_center_separate_result_total.csv");
vir_periodogram_v1_top_total = load("vir_periodogram_v1_top_separate_result_total.csv");
vr_periodogram_v1_center_total = load("vr_periodogram_v1_center_separate_result_total.csv");
vr_periodogram_v1_top_total = load("vr_periodogram_v1_top_separate_result_total.csv");

%V1 analysis
vir_periodogram_v1_center_mean = mean(vir_periodogram_v1_center_total);
vir_periodogram_v1_center_std = std(vir_periodogram_v1_center_total);
vir_periodogram_v1_center_result = horzcat(periodogram_result, vir_periodogram_v1_center_mean', vir_periodogram_v1_center_std');
dlmwrite("vir_periodogram_v1_center_separate_mean_result.csv", vir_periodogram_v1_center_result);

vir_periodogram_v1_top_mean = mean(vir_periodogram_v1_top_total);
vir_periodogram_v1_top_std = std(vir_periodogram_v1_top_total);
vir_periodogram_v1_top_result = horzcat(periodogram_result, vir_periodogram_v1_top_mean', vir_periodogram_v1_top_std');
dlmwrite("vir_periodogram_v1_top_separate_mean_result.csv", vir_periodogram_v1_top_result);

vr_periodogram_v1_center_mean = mean(vr_periodogram_v1_center_total);
vr_periodogram_v1_center_std = std(vr_periodogram_v1_center_total);
vr_periodogram_v1_center_result = horzcat(periodogram_result, vr_periodogram_v1_center_mean', vr_periodogram_v1_center_std');
dlmwrite("vr_periodogram_v1_center_separate_mean_result.csv", vr_periodogram_v1_center_result);

vr_periodogram_v1_top_mean = mean(vr_periodogram_v1_top_total);
vr_periodogram_v1_top_std = std(vr_periodogram_v1_top_total);
vr_periodogram_v1_top_result = horzcat(periodogram_result, vr_periodogram_v1_top_mean', vr_periodogram_v1_top_std');
dlmwrite("vr_periodogram_v1_top_separate_mean_result.csv", vr_periodogram_v1_top_result);

exit()