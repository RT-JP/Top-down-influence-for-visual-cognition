% Copyright (c) 2021 RT-JP Right Reserved.

%load files
lfp_result = load("Bisection_lfp_freq.csv");

bir_lfp_v1_center_left_total = load("bir_lfp_v1_center_left_separate_result_total.csv");
bir_lfp_v1_center_right_total = load("bir_lfp_v1_center_right_separate_result_total.csv");
br_lfp_v1_center_left_total = load("br_lfp_v1_center_left_separate_result_total.csv");
br_lfp_v1_center_right_total = load("br_lfp_v1_center_right_separate_result_total.csv");

bir_lfp_vho_center_left_total = load("bir_lfp_vho_center_left_separate_result_total.csv");
bir_lfp_vho_center_right_total = load("bir_lfp_vho_center_right_separate_result_total.csv");
br_lfp_vho_center_left_total = load("br_lfp_vho_center_left_separate_result_total.csv");
br_lfp_vho_center_right_total = load("br_lfp_vho_center_right_separate_result_total.csv");

%V1 analysis
bir_lfp_v1_center_left_mean = mean(bir_lfp_v1_center_left_total);
bir_lfp_v1_center_left_std = std(bir_lfp_v1_center_left_total);
bir_lfp_v1_center_left_result = horzcat(lfp_result, bir_lfp_v1_center_left_mean', bir_lfp_v1_center_left_std');
dlmwrite("bir_lfp_v1_center_left_separate_mean_result.csv", bir_lfp_v1_center_left_result);

bir_lfp_v1_center_right_mean = mean(bir_lfp_v1_center_right_total);
bir_lfp_v1_center_right_std = std(bir_lfp_v1_center_right_total);
bir_lfp_v1_center_right_result = horzcat(lfp_result, bir_lfp_v1_center_right_mean', bir_lfp_v1_center_right_std');
dlmwrite("bir_lfp_v1_center_right_separate_mean_result.csv", bir_lfp_v1_center_right_result);

br_lfp_v1_center_left_mean = mean(br_lfp_v1_center_left_total);
br_lfp_v1_center_left_std = std(br_lfp_v1_center_left_total);
br_lfp_v1_center_left_result = horzcat(lfp_result, br_lfp_v1_center_left_mean', br_lfp_v1_center_left_std');
dlmwrite("br_lfp_v1_center_left_separate_mean_result.csv", br_lfp_v1_center_left_result);

br_lfp_v1_center_right_mean = mean(br_lfp_v1_center_right_total);
br_lfp_v1_center_right_std = std(br_lfp_v1_center_right_total);
br_lfp_v1_center_right_result = horzcat(lfp_result, br_lfp_v1_center_right_mean', br_lfp_v1_center_right_std');
dlmwrite("br_lfp_v1_center_right_separate_mean_result.csv", br_lfp_v1_center_right_result);

%VHO analysis
bir_lfp_vho_center_left_mean = mean(bir_lfp_vho_center_left_total);
bir_lfp_vho_center_left_std = std(bir_lfp_vho_center_left_total);
bir_lfp_vho_center_left_result = horzcat(lfp_result, bir_lfp_vho_center_left_mean', bir_lfp_vho_center_left_std');
dlmwrite("bir_lfp_vho_center_left_separate_mean_result.csv", bir_lfp_vho_center_left_result);

bir_lfp_vho_center_right_mean = mean(bir_lfp_vho_center_right_total);
bir_lfp_vho_center_right_std = std(bir_lfp_vho_center_right_total);
bir_lfp_vho_center_right_result = horzcat(lfp_result, bir_lfp_vho_center_right_mean', bir_lfp_vho_center_right_std');
dlmwrite("bir_lfp_vho_center_right_separate_mean_result.csv", bir_lfp_vho_center_right_result);

br_lfp_vho_center_left_mean = mean(br_lfp_vho_center_left_total);
br_lfp_vho_center_left_std = std(br_lfp_vho_center_left_total);
br_lfp_vho_center_left_result = horzcat(lfp_result, br_lfp_vho_center_left_mean', br_lfp_vho_center_left_std');
dlmwrite("br_lfp_vho_center_left_separate_mean_result.csv", br_lfp_vho_center_left_result);

br_lfp_vho_center_right_mean = mean(br_lfp_vho_center_right_total);
br_lfp_vho_center_right_std = std(br_lfp_vho_center_right_total);
br_lfp_vho_center_right_result = horzcat(lfp_result, br_lfp_vho_center_right_mean', br_lfp_vho_center_right_std');
dlmwrite("br_lfp_vho_center_right_separate_mean_result.csv", br_lfp_vho_center_right_result);

exit()