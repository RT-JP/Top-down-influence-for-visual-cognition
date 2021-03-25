#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

paste -s bir_tuning_V1_center_data_*.csv > bir_tuning_V1_center_data_total.csv
paste -s bir_tuning_V1_right_data_*.csv > bir_tuning_V1_right_data_total.csv
paste -s br_tuning_V1_center_data_*.csv > br_tuning_V1_center_data_total.csv
paste -s br_tuning_V1_right_data_*.csv > br_tuning_V1_right_data_total.csv

paste -s bir_tuning_VHO_center_data_*.csv > bir_tuning_VHO_center_data_total.csv
paste -s bir_tuning_VHO_right_data_*.csv > bir_tuning_VHO_right_data_total.csv
paste -s br_tuning_VHO_center_data_*.csv > br_tuning_VHO_center_data_total.csv
paste -s br_tuning_VHO_right_data_*.csv > br_tuning_VHO_right_data_total.csv

for i in `seq 1 100`
do
    #Beta region data(10-30Hz)
    sed -n -e 3,7p bir_lfp_v1_center_right_synapse_$i.csv > bir_lfp_v1_center_right_beta_$i.csv
    sed -n -e 3,7p bir_lfp_vho_center_right_synapse_$i.csv > bir_lfp_vho_center_right_beta_$i.csv
    sed -n -e 3,7p br_lfp_v1_center_right_synapse_$i.csv > br_lfp_v1_center_right_beta_$i.csv
    sed -n -e 3,7p br_lfp_vho_center_right_synapse_$i.csv > br_lfp_vho_center_right_beta_$i.csv

    #Gamma region data(30-60Hz)
    sed -n -e 8,15p bir_lfp_v1_center_right_synapse_$i.csv > bir_lfp_v1_center_right_gamma_$i.csv
    sed -n -e 8,15p bir_lfp_vho_center_right_synapse_$i.csv > bir_lfp_vho_center_right_gamma_$i.csv
    sed -n -e 8,15p br_lfp_v1_center_right_synapse_$i.csv > br_lfp_v1_center_right_gamma_$i.csv
    sed -n -e 8,15p br_lfp_vho_center_right_synapse_$i.csv > br_lfp_vho_center_right_gamma_$i.csv
done

matlab -nodisplay -r BisectionAI

#AI result
paste -s Bisection_V1_AI_beta_result_*.csv > Bisection_V1_AI_beta.csv
paste -s Bisection_V1_AI_gamma_result_*.csv > Bisection_V1_AI_gamma.csv

paste -s Bisection_VHO_AI_beta_result_*.csv > Bisection_VHO_AI_beta.csv
paste -s Bisection_VHO_AI_gamma_result_*.csv > Bisection_VHO_AI_gamma.csv

paste Bisection_V1_AI_R.csv Bisection_V1_AI_beta.csv > Bisection_V1_AI_R_beta.csv
paste Bisection_VHO_AI_R.csv Bisection_VHO_AI_beta.csv > Bisection_VHO_AI_R_beta.csv

paste Bisection_V1_AI_R.csv Bisection_V1_AI_gamma.csv > Bisection_V1_AI_R_gamma.csv
paste Bisection_VHO_AI_R.csv Bisection_VHO_AI_gamma.csv > Bisection_VHO_AI_R_gamma.csv
