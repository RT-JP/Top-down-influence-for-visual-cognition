#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

paste -s vir_tuning_V1_center_data_*.csv > vir_tuning_V1_center_data_total.csv
paste -s vir_tuning_V1_top_data_*.csv > vir_tuning_V1_top_data_total.csv
paste -s vir_tuning_VHO_center_data_*.csv > vir_tuning_VHO_center_data_total.csv
paste -s vir_tuning_VHO_top_data_*.csv > vir_tuning_VHO_top_data_total.csv

paste -s vr_tuning_V1_center_data_*.csv > vr_tuning_V1_center_data_total.csv
paste -s vr_tuning_V1_top_data_*.csv > vr_tuning_V1_top_data_total.csv
paste -s vr_tuning_VHO_center_data_*.csv > vr_tuning_VHO_center_data_total.csv
paste -s vr_tuning_VHO_top_data_*.csv > vr_tuning_VHO_top_data_total.csv

for i in `seq 1 100`
do
    #Beta region data(10-30Hz)
    sed -n -e 3,7p vir_lfp_v1_center_top_$i.csv > vir_lfp_v1_center_top_beta_$i.csv
    sed -n -e 3,7p vir_lfp_vho_center_top_$i.csv > vir_lfp_vho_center_top_beta_$i.csv
    sed -n -e 3,7p vr_lfp_v1_center_top_$i.csv > vr_lfp_v1_center_top_beta_$i.csv
    sed -n -e 3,7p vr_lfp_vho_center_top_$i.csv > vr_lfp_vho_center_top_beta_$i.csv

    #Gamma region data(30-60Hz)
    sed -n -e 8,15p vir_lfp_v1_center_top_$i.csv > vir_lfp_v1_center_top_gamma_$i.csv
    sed -n -e 8,15p vir_lfp_vho_center_top_$i.csv > vir_lfp_vho_center_top_gamma_$i.csv
    sed -n -e 8,15p vr_lfp_v1_center_top_$i.csv > vr_lfp_v1_center_top_gamma_$i.csv
    sed -n -e 8,15p vr_lfp_vho_center_top_$i.csv > vr_lfp_vho_center_top_gamma_$i.csv
done

matlab -nodisplay -r VernierAI

#AI result
paste -s Vernier_V1_AI_beta_result_*.csv > Vernier_V1_AI_beta.csv
paste -s Vernier_V1_AI_gamma_result_*.csv > Vernier_V1_AI_gamma.csv

paste -s Vernier_VHO_AI_beta_result_*.csv > Vernier_VHO_AI_beta.csv
paste -s Vernier_VHO_AI_gamma_result_*.csv > Vernier_VHO_AI_gamma.csv

paste Vernier_V1_AI_R.csv Vernier_V1_AI_beta.csv > Vernier_V1_AI_R_beta.csv
paste Vernier_VHO_AI_R.csv Vernier_VHO_AI_beta.csv > Vernier_VHO_AI_R_beta.csv

paste Vernier_V1_AI_R.csv Vernier_V1_AI_gamma.csv > Vernier_V1_AI_R_gamma.csv
paste Vernier_VHO_AI_R.csv Vernier_VHO_AI_gamma.csv > Vernier_VHO_AI_R_gamma.csv