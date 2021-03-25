% Copyright (c) 2021 RT-JP All Right Reserved.

%load files
plv_result = load("Bisection_PLV-freq-1.csv");

irrelevant_plv = load("Bisection_IrrelevantResult-bin10Hz-range1Hz-total.csv");
relevant_plv = load("Bisection_RelevantResult-bin10Hz-range1Hz-total.csv");

%V1 analysis
irrelevant_plv_mean = mean(irrelevant_plv);
irrelevant_plv_std = std(irrelevant_plv);
irrelevant_plv_result = horzcat(plv_result, irrelevant_plv_mean', irrelevant_plv_std');
dlmwrite("Bisection_IrrelevantResult-bin10Hz-range1Hz-total-result.csv", irrelevant_plv_result);

relevant_plv_mean = mean(relevant_plv);
relevant_plv_std = std(relevant_plv);
relevant_plv_result = horzcat(plv_result, relevant_plv_mean', relevant_plv_std');
dlmwrite("Bisection_RelevantResult-bin10Hz-range1Hz-total-result.csv", relevant_plv_result);

exit()