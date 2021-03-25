% Copyright (c) 2021 RT-JP All Right Reserved

%load files
bit_result = load("Bisection_bit_time.csv");

bir_bit_v1_center_left_total = load("bir_bit_v1_center_left_separate_result_total.csv");
bir_bit_v1_center_right_total = load("bir_bit_v1_center_right_separate_result_total.csv");
br_bit_v1_center_left_total = load("br_bit_v1_center_left_separate_result_total.csv");
br_bit_v1_center_right_total = load("br_bit_v1_center_right_separate_result_total.csv");

bir_bit_vho_center_left_total = load("bir_bit_vho_center_left_separate_result_total.csv");
bir_bit_vho_center_right_total = load("bir_bit_vho_center_right_separate_result_total.csv");
br_bit_vho_center_left_total = load("br_bit_vho_center_left_separate_result_total.csv");
br_bit_vho_center_right_total = load("br_bit_vho_center_right_separate_result_total.csv");

%V1 analysis
bir_bit_v1_center_left_mean = mean(bir_bit_v1_center_left_total);
bir_bit_v1_center_left_std = std(bir_bit_v1_center_left_total);
bir_bit_v1_center_left_result = horzcat(bit_result, bir_bit_v1_center_left_mean', bir_bit_v1_center_left_std');
dlmwrite("bir_bit_v1_center_left_separate_mean_result.csv", bir_bit_v1_center_left_result);

bir_bit_v1_center_right_mean = mean(bir_bit_v1_center_right_total);
bir_bit_v1_center_right_std = std(bir_bit_v1_center_right_total);
bir_bit_v1_center_right_result = horzcat(bit_result, bir_bit_v1_center_right_mean', bir_bit_v1_center_right_std');
dlmwrite("bir_bit_v1_center_right_separate_mean_result.csv", bir_bit_v1_center_right_result);

br_bit_v1_center_left_mean = mean(br_bit_v1_center_left_total);
br_bit_v1_center_left_std = std(br_bit_v1_center_left_total);
br_bit_v1_center_left_result = horzcat(bit_result, br_bit_v1_center_left_mean', br_bit_v1_center_left_std');
dlmwrite("br_bit_v1_center_left_separate_mean_result.csv", br_bit_v1_center_left_result);

br_bit_v1_center_right_mean = mean(br_bit_v1_center_right_total);
br_bit_v1_center_right_std = std(br_bit_v1_center_right_total);
br_bit_v1_center_right_result = horzcat(bit_result, br_bit_v1_center_right_mean', br_bit_v1_center_right_std');
dlmwrite("br_bit_v1_center_right_separate_mean_result.csv", br_bit_v1_center_right_result);

%VHO analysis
bir_bit_vho_center_left_mean = mean(bir_bit_vho_center_left_total);
bir_bit_vho_center_left_std = std(bir_bit_vho_center_left_total);
bir_bit_vho_center_left_result = horzcat(bit_result, bir_bit_vho_center_left_mean', bir_bit_vho_center_left_std');
dlmwrite("bir_bit_vho_center_left_separate_mean_result.csv", bir_bit_vho_center_left_result);

bir_bit_vho_center_right_mean = mean(bir_bit_vho_center_right_total);
bir_bit_vho_center_right_std = std(bir_bit_vho_center_right_total);
bir_bit_vho_center_right_result = horzcat(bit_result, bir_bit_vho_center_right_mean', bir_bit_vho_center_right_std');
dlmwrite("bir_bit_vho_center_right_separate_mean_result.csv", bir_bit_vho_center_right_result);

br_bit_vho_center_left_mean = mean(br_bit_vho_center_left_total);
br_bit_vho_center_left_std = std(br_bit_vho_center_left_total);
br_bit_vho_center_left_result = horzcat(bit_result, br_bit_vho_center_left_mean', br_bit_vho_center_left_std');
dlmwrite("br_bit_vho_center_left_separate_mean_result.csv", br_bit_vho_center_left_result);

br_bit_vho_center_right_mean = mean(br_bit_vho_center_right_total);
br_bit_vho_center_right_std = std(br_bit_vho_center_right_total);
br_bit_vho_center_right_result = horzcat(bit_result, br_bit_vho_center_right_mean', br_bit_vho_center_right_std');
dlmwrite("br_bit_vho_center_right_separate_mean_result.csv", br_bit_vho_center_right_result);

exit()