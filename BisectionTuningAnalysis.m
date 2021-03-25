% Copyright (c) 2021 RT-JP All Right Reserved

bar = -2:1:2;

%V1
bir_V1 = load("bir_tuning_V1_center_mean_analysis_data_total.csv");
br_V1 = load("br_tuning_V1_center_mean_analysis_data_total.csv");

bir_V1_mean = mean(bir_V1);
br_V1_mean = mean(br_V1);

bir_V1_std = std(bir_V1);
br_V1_std = std(br_V1);

bir_V1_connect = horzcat(bar', bir_V1_mean', bir_V1_std');
br_V1_connect = horzcat(bar', br_V1_mean', br_V1_std');

dlmwrite("bir_tuning_V1_center_mean_result.csv", bir_V1_connect);
dlmwrite("br_tuning_V1_center_mean_result.csv", br_V1_connect);

%VHO
bir_VHO = load("bir_tuning_VHO_center_mean_analysis_data_total.csv");
br_VHO = load("br_tuning_VHO_center_mean_analysis_data_total.csv");

bir_VHO_mean = mean(bir_VHO);
br_VHO_mean = mean(br_VHO);

bir_VHO_std = std(bir_VHO);
br_VHO_std = std(br_VHO);

bir_VHO_connect = horzcat(bar', bir_VHO_mean', bir_VHO_std');
br_VHO_connect = horzcat(bar', br_VHO_mean', br_VHO_std');

dlmwrite("bir_tuning_VHO_center_mean_result.csv", bir_VHO_connect);
dlmwrite("br_tuning_VHO_center_mean_result.csv", br_VHO_connect);

exit()