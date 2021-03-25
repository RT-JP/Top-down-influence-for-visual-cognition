% Copyright (c) 2021 RT-JP All Right Reserved.

N = 5;

%load files
for i = 1:N
    bir_bit_v1_center_left_total_name = sprintf("bir_bit_v1_center_left_separate_total_%d.csv", i);
    bir_bit_v1_center_left_total{i} = importdata(bir_bit_v1_center_left_total_name);

    bir_bit_v1_center_right_total_name = sprintf("bir_bit_v1_center_right_separate_total_%d.csv", i);
    bir_bit_v1_center_right_total{i} = importdata(bir_bit_v1_center_right_total_name);

    br_bit_v1_center_left_total_name = sprintf("br_bit_v1_center_left_separate_total_%d.csv", i);
    br_bit_v1_center_left_total{i} = importdata(br_bit_v1_center_left_total_name);

    br_bit_v1_center_right_total_name = sprintf("br_bit_v1_center_right_separate_total_%d.csv", i);
    br_bit_v1_center_right_total{i} = importdata(br_bit_v1_center_right_total_name);

    bir_bit_vho_center_left_total_name = sprintf("bir_bit_vho_center_left_separate_total_%d.csv", i);
    bir_bit_vho_center_left_total{i} = importdata(bir_bit_vho_center_left_total_name);

    bir_bit_vho_center_right_total_name = sprintf("bir_bit_vho_center_right_separate_total_%d.csv", i);
    bir_bit_vho_center_right_total{i} = importdata(bir_bit_vho_center_right_total_name);

    br_bit_vho_center_left_total_name = sprintf("br_bit_vho_center_left_separate_total_%d.csv", i);
    br_bit_vho_center_left_total{i} = importdata(br_bit_vho_center_left_total_name);

    br_bit_vho_center_right_total_name = sprintf("br_bit_vho_center_right_separate_total_%d.csv", i);
    br_bit_vho_center_right_total{i} = importdata(br_bit_vho_center_right_total_name);

    %V1 analysis
    bir_bit_v1_center_left_mean{i} = mean(bir_bit_v1_center_left_total{i});
    fileID_name = sprintf("bir_bit_v1_center_left_separate_result_%d.csv", i);
    dlmwrite(fileID_name, bir_bit_v1_center_left_mean{i});

    bir_bit_v1_center_right_mean{i} = mean(bir_bit_v1_center_right_total{i});
    fileID_name = sprintf("bir_bit_v1_center_right_separate_result_%d.csv", i);
    dlmwrite(fileID_name, bir_bit_v1_center_right_mean{i});

    br_bit_v1_center_left_mean{i} = mean(br_bit_v1_center_left_total{i});
    fileID_name = sprintf("br_bit_v1_center_left_separate_result_%d.csv", i);
    dlmwrite(fileID_name, br_bit_v1_center_left_mean{i});

    br_bit_v1_center_right_mean{i} = mean(br_bit_v1_center_right_total{i});
    fileID_name = sprintf("br_bit_v1_center_right_separate_result_%d.csv", i);
    dlmwrite(fileID_name, br_bit_v1_center_right_mean{i});

    %VHO analysis
    bir_bit_vho_center_left_mean{i} = mean(bir_bit_vho_center_left_total{i});
    fileID_name = sprintf("bir_bit_vho_center_left_separate_result_%d.csv", i);
    dlmwrite(fileID_name, bir_bit_vho_center_left_mean{i});

    bir_bit_vho_center_right_mean{i} = mean(bir_bit_vho_center_right_total{i});
    fileID_name = sprintf("bir_bit_vho_center_right_separate_result_%d.csv", i);
    dlmwrite(fileID_name, bir_bit_vho_center_right_mean{i});

    br_bit_vho_center_left_mean{i} = mean(br_bit_vho_center_left_total{i});
    fileID_name = sprintf("br_bit_vho_center_left_separate_result_%d.csv", i);
    dlmwrite(fileID_name, br_bit_vho_center_left_mean{i});

    br_bit_vho_center_right_mean{i} = mean(br_bit_vho_center_right_total{i});
    fileID_name = sprintf("br_bit_vho_center_right_separate_result_%d.csv", i);
    dlmwrite(fileID_name, br_bit_vho_center_right_mean{i});
end

exit()