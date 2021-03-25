% Copyright (c) 2021 RT-JP All Right Reserved.

N = 100;

%AI(R)
vir_V1_center = load("vir_tuning_V1_center_data_total.csv");
vir_V1_side = load("vir_tuning_V1_top_data_total.csv");
vir_V1_R = (vir_V1_center + vir_V1_side) / 2;

vr_V1_center = load("vr_tuning_V1_center_data_total.csv");
vr_V1_side = load("vr_tuning_V1_top_data_total.csv");
vr_V1_R = (vr_V1_center + vr_V1_side) / 2;

V1_AI_R = (vr_V1_R - vir_V1_R) ./ (vr_V1_R + vir_V1_R);

fileID_V1_AI_R = fopen('Vernier_V1_AI_R.csv', 'w');
fprintf(fileID_V1_AI_R, '%6f\n', V1_AI_R);
fclose(fileID_V1_AI_R);

vir_VHO_center = load("vir_tuning_VHO_center_data_total.csv");
vir_VHO_side = load("vir_tuning_VHO_top_data_total.csv");
vir_VHO_R = (vir_VHO_center + vir_VHO_side) / 2;

vr_VHO_center = load("vr_tuning_VHO_center_data_total.csv");
vr_VHO_side = load("vr_tuning_VHO_top_data_total.csv");
vr_VHO_R = (vr_VHO_center + vir_VHO_side) / 2;

VHO_AI_R = (vr_VHO_R - vir_VHO_R) ./ (vr_VHO_R + vir_VHO_R);

fileID_VHO_AI_R = fopen('Vernier_VHO_AI_R.csv', 'w');
fprintf(fileID_VHO_AI_R, '%6f\n', VHO_AI_R);
fclose(fileID_VHO_AI_R);

%AI(LFP beta)
for i = 1:N
    %V1 LFP beta Input
    vir_lfp_v1_center_top_beta_data_name = sprintf('vir_lfp_v1_center_top_beta_%d.csv',i);
    vr_lfp_v1_center_top_beta_data_name = sprintf('vr_lfp_v1_center_top_beta_%d.csv',i);
    %VHO LFP beta Input
    vir_lfp_vho_center_top_beta_data_name = sprintf('vir_lfp_vho_center_top_beta_%d.csv',i);
    vr_lfp_vho_center_top_beta_data_name = sprintf('vr_lfp_vho_center_top_beta_%d.csv',i);
    
    %load data
    vir_lfp_v1_center_top_beta_data = importdata(vir_lfp_v1_center_top_beta_data_name);
    vr_lfp_v1_center_top_beta_data = importdata(vr_lfp_v1_center_top_beta_data_name);
    
    vir_lfp_vho_center_top_beta_data = importdata(vir_lfp_vho_center_top_beta_data_name);
    vr_lfp_vho_center_top_beta_data = importdata(vr_lfp_vho_center_top_beta_data_name);
    
    %trapz
    vir_lfp_v1_center_top_beta_result = trapz(vir_lfp_v1_center_top_beta_data);
    vr_lfp_v1_center_top_beta_result = trapz(vr_lfp_v1_center_top_beta_data);
    
    vir_lfp_vho_center_top_beta_result = trapz(vir_lfp_vho_center_top_beta_data);
    vr_lfp_vho_center_top_beta_result = trapz(vr_lfp_vho_center_top_beta_data);

    %AI_beta
    V1_AI_beta = (vr_lfp_v1_center_top_beta_result - vir_lfp_v1_center_top_beta_result) / (vr_lfp_v1_center_top_beta_result + vir_lfp_v1_center_top_beta_result);
    VHO_AI_beta = (vr_lfp_vho_center_top_beta_result - vir_lfp_vho_center_top_beta_result) / (vr_lfp_vho_center_top_beta_result + vir_lfp_vho_center_top_beta_result);
    
    %output
    V1_AI_beta_output_name = 'Vernier_V1_AI_beta_result_%d.csv';
    V1_AI_beta_output = sprintf(V1_AI_beta_output_name,i);
    
    VHO_AI_beta_output_name = 'Vernier_VHO_AI_beta_result_%d.csv';
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
    vir_lfp_v1_center_top_gamma_data_name = sprintf('vir_lfp_v1_center_top_gamma_%d.csv',i);
    vr_lfp_v1_center_top_gamma_data_name = sprintf('vr_lfp_v1_center_top_gamma_%d.csv',i);
    %VHO LFP gamma Input
    vir_lfp_vho_center_top_gamma_data_name = sprintf('vir_lfp_vho_center_top_gamma_%d.csv',i);
    vr_lfp_vho_center_top_gamma_data_name = sprintf('vr_lfp_vho_center_top_gamma_%d.csv',i);
    
    %load data
    vir_lfp_v1_center_top_gamma_data = importdata(vir_lfp_v1_center_top_gamma_data_name);
    vr_lfp_v1_center_top_gamma_data = importdata(vr_lfp_v1_center_top_gamma_data_name);
    
    vir_lfp_vho_center_top_gamma_data = importdata(vir_lfp_vho_center_top_gamma_data_name);
    vr_lfp_vho_center_top_gamma_data = importdata(vr_lfp_vho_center_top_gamma_data_name);
    
    %trapz
    vir_lfp_v1_center_top_gamma_result = trapz(vir_lfp_v1_center_top_gamma_data);
    vr_lfp_v1_center_top_gamma_result = trapz(vr_lfp_v1_center_top_gamma_data);
    
    vir_lfp_vho_center_top_gamma_result = trapz(vir_lfp_vho_center_top_gamma_data);
    vr_lfp_vho_center_top_gamma_result = trapz(vr_lfp_vho_center_top_gamma_data);
    
    %AI_gamma
    V1_AI_gamma = (vr_lfp_v1_center_top_gamma_result - vir_lfp_v1_center_top_gamma_result) / (vr_lfp_v1_center_top_gamma_result + vir_lfp_v1_center_top_gamma_result);
    VHO_AI_gamma = (vr_lfp_vho_center_top_gamma_result - vir_lfp_vho_center_top_gamma_result) / (vr_lfp_vho_center_top_gamma_result + vir_lfp_vho_center_top_gamma_result);
    
    %output
    V1_AI_gamma_output_name = 'Vernier_V1_AI_gamma_result_%d.csv';
    V1_AI_gamma_output = sprintf(V1_AI_gamma_output_name,i);
    
    VHO_AI_gamma_output_name = 'Vernier_VHO_AI_gamma_result_%d.csv';
    VHO_AI_gamma_output = sprintf(VHO_AI_gamma_output_name,i);
    
    fileID_V1_AI_gamma = fopen(V1_AI_gamma_output, 'w');
    fprintf(fileID_V1_AI_gamma, '%6f\n', V1_AI_gamma);
    fclose(fileID_V1_AI_gamma);

    fileID_VHO_AI_gamma = fopen(VHO_AI_gamma_output, 'w');
    fprintf(fileID_VHO_AI_gamma, '%6f\n', VHO_AI_gamma);
    fclose(fileID_VHO_AI_gamma);
end

exit()
