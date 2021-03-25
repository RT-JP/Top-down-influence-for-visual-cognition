% Copyright (c) 2021 RT-JP All Right Reserved.

%load files
bit_result = load("Vernier_bit_time.csv");

vir_bit_v1_center_top_total = load("vir_bit_v1_center_top_separate_result_total.csv");
vr_bit_v1_center_top_total = load("vr_bit_v1_center_top_separate_result_total.csv");

vir_bit_vho_center_top_total = load("vir_bit_vho_center_top_separate_result_total.csv");
vr_bit_vho_center_top_total = load("vr_bit_vho_center_top_separate_result_total.csv");

%V1 analysis
vir_bit_v1_center_top_mean = mean(vir_bit_v1_center_top_total);
vir_bit_v1_center_top_std = std(vir_bit_v1_center_top_total);
vir_bit_v1_center_top_result = horzcat(bit_result, vir_bit_v1_center_top_mean', vir_bit_v1_center_top_std');
dlmwrite("vir_bit_v1_center_top_separate_mean_result.csv", vir_bit_v1_center_top_result);

vr_bit_v1_center_top_mean = mean(vr_bit_v1_center_top_total);
vr_bit_v1_center_top_std = std(vr_bit_v1_center_top_total);
vr_bit_v1_center_top_result = horzcat(bit_result, vr_bit_v1_center_top_mean', vr_bit_v1_center_top_std');
dlmwrite("vr_bit_v1_center_top_separate_mean_result.csv", vr_bit_v1_center_top_result);

%VHO analysis
vir_bit_vho_center_top_mean = mean(vir_bit_vho_center_top_total);
vir_bit_vho_center_top_std = std(vir_bit_vho_center_top_total);
vir_bit_vho_center_top_result = horzcat(bit_result, vir_bit_vho_center_top_mean', vir_bit_vho_center_top_std');
dlmwrite("vir_bit_vho_center_top_separate_mean_result.csv", vir_bit_vho_center_top_result);

vr_bit_vho_center_top_mean = mean(vr_bit_vho_center_top_total);
vr_bit_vho_center_top_std = std(vr_bit_vho_center_top_total);
vr_bit_vho_center_top_result = horzcat(bit_result, vr_bit_vho_center_top_mean', vr_bit_vho_center_top_std');
dlmwrite("vr_bit_vho_center_top_separate_mean_result.csv", vr_bit_vho_center_top_result);

exit()