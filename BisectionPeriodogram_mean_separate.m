% Copyright (c) 2021 RT-JP All Right Reserved.

%load files
periodogram_result = load("Bisection_periodogram_freq.csv");

bir_periodogram_v1_center_total = load("bir_periodogram_v1_center_separate_result_total.csv");
bir_periodogram_v1_right_total = load("bir_periodogram_v1_right_separate_result_total.csv");
br_periodogram_v1_center_total = load("br_periodogram_v1_center_separate_result_total.csv");
br_periodogram_v1_right_total = load("br_periodogram_v1_right_separate_result_total.csv");

%V1 analysis
bir_periodogram_v1_center_mean = mean(bir_periodogram_v1_center_total);
bir_periodogram_v1_center_std = std(bir_periodogram_v1_center_total);
bir_periodogram_v1_center_result = horzcat(periodogram_result, bir_periodogram_v1_center_mean', bir_periodogram_v1_center_std');
dlmwrite("bir_periodogram_v1_center_separate_mean_result.csv", bir_periodogram_v1_center_result);

bir_periodogram_v1_right_mean = mean(bir_periodogram_v1_right_total);
bir_periodogram_v1_right_std = std(bir_periodogram_v1_right_total);
bir_periodogram_v1_right_result = horzcat(periodogram_result, bir_periodogram_v1_right_mean', bir_periodogram_v1_right_std');
dlmwrite("bir_periodogram_v1_right_separate_mean_result.csv", bir_periodogram_v1_right_result);

br_periodogram_v1_center_mean = mean(br_periodogram_v1_center_total);
br_periodogram_v1_center_std = std(br_periodogram_v1_center_total);
br_periodogram_v1_center_result = horzcat(periodogram_result, br_periodogram_v1_center_mean', br_periodogram_v1_center_std');
dlmwrite("br_periodogram_v1_center_separate_mean_result.csv", br_periodogram_v1_center_result);

br_periodogram_v1_right_mean = mean(br_periodogram_v1_right_total);
br_periodogram_v1_right_std = std(br_periodogram_v1_right_total);
br_periodogram_v1_right_result = horzcat(periodogram_result, br_periodogram_v1_right_mean', br_periodogram_v1_right_std');
dlmwrite("br_periodogram_v1_right_separate_mean_result.csv", br_periodogram_v1_right_result);

exit()