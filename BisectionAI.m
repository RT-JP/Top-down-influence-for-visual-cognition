% Copyright (c) 2021 RT-JP All Right Reserved.

N = 100;

%AI(R)
bir_V1_center = load("bir_tuning_V1_center_data_total.csv");
bir_V1_side = load("bir_tuning_V1_right_data_total.csv");
bir_V1_R = (bir_V1_center + bir_V1_side) / 2;

br_V1_center = load("br_tuning_V1_center_data_total.csv");
br_V1_side = load("br_tuning_V1_right_data_total.csv");
br_V1_R = (br_V1_center + br_V1_side) / 2;

V1_AI_R = (br_V1_R - bir_V1_R) ./ (br_V1_R + bir_V1_R);

fileID_V1_AI_R = fopen('Bisection_V1_AI_R.csv', 'w');
fprintf(fileID_V1_AI_R, '%6f\n', V1_AI_R);
fclose(fileID_V1_AI_R);

bir_VHO_center = load("bir_tuning_VHO_center_data_total.csv");
bir_VHO_side = load("bir_tuning_VHO_right_data_total.csv");
bir_VHO_R = (bir_VHO_center + bir_VHO_side) / 2;

br_VHO_center = load("br_tuning_VHO_center_data_total.csv");
br_VHO_side = load("br_tuning_VHO_right_data_total.csv");
br_VHO_R = (br_VHO_center + bir_VHO_side) / 2;

VHO_AI_R = (br_VHO_R - bir_VHO_R) ./ (br_VHO_R + bir_VHO_R);

fileID_VHO_AI_R = fopen('Bisection_VHO_AI_R.csv', 'w');
fprintf(fileID_VHO_AI_R, '%6f\n', VHO_AI_R);
fclose(fileID_VHO_AI_R);

%AI(LFP beta)
for i = 1:N
    %V1 LFP beta Input
    bir_lfp_v1_center_right_beta_data_name = sprintf('bir_lfp_v1_center_right_beta_%d.csv',i);
    br_lfp_v1_center_right_beta_data_name = sprintf('br_lfp_v1_center_right_beta_%d.csv',i);
    %VHO LFP beta Input
    bir_lfp_vho_center_right_beta_data_name = sprintf('bir_lfp_vho_center_right_beta_%d.csv',i);
    br_lfp_vho_center_right_beta_data_name = sprintf('br_lfp_vho_center_right_beta_%d.csv',i);
    
    %load data
    bir_lfp_v1_center_right_beta_data = importdata(bir_lfp_v1_center_right_beta_data_name);
    br_lfp_v1_center_right_beta_data = importdata(br_lfp_v1_center_right_beta_data_name);
    
    bir_lfp_vho_center_right_beta_data = importdata(bir_lfp_vho_center_right_beta_data_name);
    br_lfp_vho_center_right_beta_data = importdata(br_lfp_vho_center_right_beta_data_name);
    
    %trapz
    bir_lfp_v1_center_right_beta_result = trapz(bir_lfp_v1_center_right_beta_data);
    br_lfp_v1_center_right_beta_result = trapz(br_lfp_v1_center_right_beta_data);
    
    bir_lfp_vho_center_right_beta_result = trapz(bir_lfp_vho_center_right_beta_data);
    br_lfp_vho_center_right_beta_result = trapz(br_lfp_vho_center_right_beta_data);

    %AI_beta
    V1_AI_beta = (br_lfp_v1_center_right_beta_result - bir_lfp_v1_center_right_beta_result) / (br_lfp_v1_center_right_beta_result + bir_lfp_v1_center_right_beta_result);
    VHO_AI_beta = (br_lfp_vho_center_right_beta_result - bir_lfp_vho_center_right_beta_result) / (br_lfp_vho_center_right_beta_result + bir_lfp_vho_center_right_beta_result);
    
    %output
    V1_AI_beta_output_name = 'Bisection_V1_AI_beta_result_%d.csv';
    V1_AI_beta_output = sprintf(V1_AI_beta_output_name,i);
    
    VHO_AI_beta_output_name = 'Bisection_VHO_AI_beta_result_%d.csv';
    VHO_AI_beta_output = sprintf(VHO_AI_beta_output_name,i);
    
    fileID_V1_AI_beta = fopen(V1_AI_beta_output, 'w');
    fprintf(fileID_V1_AI_beta, '%6f\n', V1_AI_beta);
    fclose(fileID_V1_AI_beta);

    fileID_VHO_AI_beta = fopen(VHO_AI_beta_output, 'w');
    fprintf(fileID_VHO_AI_beta, '%6f\n', VHO_AI_beta);
    fclose(fileID_VHO_AI_beta);
end

%AI(LFP gamma)
for i = 1:N
    %V1 LFP gamma Input
    bir_lfp_v1_center_right_gamma_data_name = sprintf('bir_lfp_v1_center_right_gamma_%d.csv',i);
    br_lfp_v1_center_right_gamma_data_name = sprintf('br_lfp_v1_center_right_gamma_%d.csv',i);
    %VHO LFP gamma Input
    bir_lfp_vho_center_right_gamma_data_name = sprintf('bir_lfp_vho_center_right_gamma_%d.csv',i);
    br_lfp_vho_center_right_gamma_data_name = sprintf('br_lfp_vho_center_right_gamma_%d.csv',i);
    
    %load data
    bir_lfp_v1_center_right_gamma_data = importdata(bir_lfp_v1_center_right_gamma_data_name);
    br_lfp_v1_center_right_gamma_data = importdata(br_lfp_v1_center_right_gamma_data_name);
    
    bir_lfp_vho_center_right_gamma_data = importdata(bir_lfp_vho_center_right_gamma_data_name);
    br_lfp_vho_center_right_gamma_data = importdata(br_lfp_vho_center_right_gamma_data_name);
    
    %trapz
    bir_lfp_v1_center_right_gamma_result = trapz(bir_lfp_v1_center_right_gamma_data);
    br_lfp_v1_center_right_gamma_result = trapz(br_lfp_v1_center_right_gamma_data);
    
    bir_lfp_vho_center_right_gamma_result = trapz(bir_lfp_vho_center_right_gamma_data);
    br_lfp_vho_center_right_gamma_result = trapz(br_lfp_vho_center_right_gamma_data);
    
    %AI_gamma
    V1_AI_gamma = (br_lfp_v1_center_right_gamma_result - bir_lfp_v1_center_right_gamma_result) / (br_lfp_v1_center_right_gamma_result + bir_lfp_v1_center_right_gamma_result);
    VHO_AI_gamma = (br_lfp_vho_center_right_gamma_result - bir_lfp_vho_center_right_gamma_result) / (br_lfp_vho_center_right_gamma_result + bir_lfp_vho_center_right_gamma_result);
    
    %output
    V1_AI_gamma_output_name = 'Bisection_V1_AI_gamma_result_%d.csv';
    V1_AI_gamma_output = sprintf(V1_AI_gamma_output_name,i);
    
    VHO_AI_gamma_output_name = 'Bisection_VHO_AI_gamma_result_%d.csv';
    VHO_AI_gamma_output = sprintf(VHO_AI_gamma_output_name,i);
    
    fileID_V1_AI_gamma = fopen(V1_AI_gamma_output, 'w');
    fprintf(fileID_V1_AI_gamma, '%6f\n', V1_AI_gamma);
    fclose(fileID_V1_AI_gamma);

    fileID_VHO_AI_gamma = fopen(VHO_AI_gamma_output, 'w');
    fprintf(fileID_VHO_AI_gamma, '%6f\n', VHO_AI_gamma);
    fclose(fileID_VHO_AI_gamma);
end

exit()
