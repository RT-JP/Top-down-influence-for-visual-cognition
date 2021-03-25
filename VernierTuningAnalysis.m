% Copyright (c) 2021 RT-JP All Right Reserved.

bar = -2:1:2;

%V1
vir_V1 = load("vir_tuning_V1_center_mean_analysis_data_total.csv");
vr_V1 = load("vr_tuning_V1_center_mean_analysis_data_total.csv");

vir_V1_mean = mean(vir_V1);
vr_V1_mean = mean(vr_V1);

vir_V1_std = std(vir_V1);
vr_V1_std = std(vr_V1);

vir_V1_connect = horzcat(bar', vir_V1_mean', vir_V1_std');
vr_V1_connect = horzcat(bar', vr_V1_mean', vr_V1_std');

dlmwrite("vir_tuning_V1_center_mean_result.csv", vir_V1_connect);
dlmwrite("vr_tuning_V1_center_mean_result.csv", vr_V1_connect);

%VHO
vir_VHO = load("vir_tuning_VHO_center_mean_analysis_data_total.csv");
vr_VHO = load("vr_tuning_VHO_center_mean_analysis_data_total.csv");

vir_VHO_mean = mean(vir_VHO);
vr_VHO_mean = mean(vr_VHO);

vir_VHO_std = std(vir_VHO);
vr_VHO_std = std(vr_VHO);

vir_VHO_connect = horzcat(bar', vir_VHO_mean', vir_VHO_std');
vr_VHO_connect = horzcat(bar', vr_VHO_mean', vr_VHO_std');

dlmwrite("vir_tuning_VHO_center_mean_result.csv", vir_VHO_connect);
dlmwrite("vr_tuning_VHO_center_mean_result.csv", vr_VHO_connect);

exit()