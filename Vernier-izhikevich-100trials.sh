#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

gcc -O3 -march=native -o VIR-izhikevich VIR-izhikevich.c -lm
gcc -O3 -march=native -o VR-izhikevich VR-izhikevich.c -lm

for i in `seq 1 100`
do
    echo "Irrelevant $i回目"
    ./VIR-izhikevich

    #save lfp data
    cp vir_lfp_v1_center_synapse.csv vir_lfp_v1_center_data_$i.csv
    cp vir_lfp_v1_top_synapse.csv vir_lfp_v1_top_data_$i.csv
    cp vir_lfp_v1_bottom_synapse.csv vir_lfp_v1_bottom_data_$i.csv
    
    cp vir_lfp_vho_center_synapse.csv vir_lfp_vho_center_data_$i.csv
    cp vir_lfp_vho_top_synapse.csv vir_lfp_vho_top_data_$i.csv
    cp vir_lfp_vho_bottom_synapse.csv vir_lfp_vho_bottom_data_$i.csv
    #save bit data
    cp vir_bit_v1_center.csv vir_bit_v1_center_data_$i.csv
    cp vir_bit_v1_top.csv vir_bit_v1_top_data_$i.csv
    cp vir_bit_v1_bottom.csv vir_bit_v1_bottom_data_$i.csv

    cp vir_bit_vho_center.csv vir_bit_vho_center_data_$i.csv
    cp vir_bit_vho_top.csv vir_bit_vho_top_data_$i.csv
    cp vir_bit_vho_bottom.csv vir_bit_vho_bottom_data_$i.csv
    #save tuning data
    cut -d " " -f 3 vir_tuning_V1_center.csv | head -n 1 > vir_tuning_V1_center_data.csv
    cut -d " " -f 3 vir_tuning_V1_center.csv > vir_tuning_V1_center_mean_analysis_data.csv
    cut -d " " -f 3 vir_tuning_V1_top.csv | head -n 1 > vir_tuning_V1_top_data.csv
    cp vir_tuning_V1_center_data.csv vir_tuning_V1_center_data_$i.csv
    cp vir_tuning_V1_center_mean_analysis_data.csv vir_tuning_V1_center_mean_analysis_data_$i.csv
    cp vir_tuning_V1_top_data.csv vir_tuning_V1_top_data_$i.csv

    cut -d " " -f 3 vir_tuning_VHO_center.csv | head -n 1 > vir_tuning_VHO_center_data.csv
    cut -d " " -f 3 vir_tuning_VHO_center.csv > vir_tuning_VHO_center_mean_analysis_data.csv
    cut -d " " -f 3 vir_tuning_VHO_top.csv | head -n 1 > vir_tuning_VHO_top_data.csv
    cp vir_tuning_VHO_center_data.csv vir_tuning_VHO_center_data_$i.csv
    cp vir_tuning_VHO_center_mean_analysis_data.csv vir_tuning_VHO_center_mean_analysis_data_$i.csv
    cp vir_tuning_VHO_top_data.csv vir_tuning_VHO_top_data_$i.csv
done

for i in `seq 1 100`
do
    echo "Relevant $i回目"
    ./VR-izhikevich

    #save lfp data
    cp vr_lfp_v1_center_synapse.csv vr_lfp_v1_center_data_$i.csv
    cp vr_lfp_v1_top_synapse.csv vr_lfp_v1_top_data_$i.csv
    cp vr_lfp_v1_bottom_synapse.csv vr_lfp_v1_bottom_data_$i.csv
    
    cp vr_lfp_vho_center_synapse.csv vr_lfp_vho_center_data_$i.csv
    cp vr_lfp_vho_top_synapse.csv vr_lfp_vho_top_data_$i.csv
    cp vr_lfp_vho_bottom_synapse.csv vr_lfp_vho_bottom_data_$i.csv
    #save bit data
    cp vr_bit_v1_center.csv vr_bit_v1_center_data_$i.csv
    cp vr_bit_v1_top.csv vr_bit_v1_top_data_$i.csv
    cp vr_bit_v1_bottom.csv vr_bit_v1_bottom_data_$i.csv
    
    cp vr_bit_vho_center.csv vr_bit_vho_center_data_$i.csv
    cp vr_bit_vho_top.csv vr_bit_vho_top_data_$i.csv
    cp vr_bit_vho_bottom.csv vr_bit_vho_bottom_data_$i.csv
    #save tuning data
    cut -d " " -f 3 vr_tuning_V1_center.csv | head -n 1 > vr_tuning_V1_center_data.csv
    cut -d " " -f 3 vr_tuning_V1_center.csv > vr_tuning_V1_center_mean_analysis_data.csv
    cut -d " " -f 3 vr_tuning_V1_top.csv | head -n 1 > vr_tuning_V1_top_data.csv
    cp vr_tuning_V1_center_data.csv vr_tuning_V1_center_data_$i.csv
    cp vr_tuning_V1_center_mean_analysis_data.csv vr_tuning_V1_center_mean_analysis_data_$i.csv
    cp vr_tuning_V1_top_data.csv vr_tuning_V1_top_data_$i.csv

    cut -d " " -f 3 vr_tuning_VHO_center.csv | head -n 1 > vr_tuning_VHO_center_data.csv
    cut -d " " -f 3 vr_tuning_VHO_center.csv > vr_tuning_VHO_center_mean_analysis_data.csv
    cut -d " " -f 3 vr_tuning_VHO_top.csv | head -n 1 > vr_tuning_VHO_top_data.csv
    cp vr_tuning_VHO_center_data.csv vr_tuning_VHO_center_data_$i.csv
    cp vr_tuning_VHO_center_mean_analysis_data.csv vr_tuning_VHO_center_mean_analysis_data_$i.csv
    cp vr_tuning_VHO_top_data.csv vr_tuning_VHO_top_data_$i.csv
done

#tuning analysis
./Vernier_tuning.sh

#lfp analysis
./Vernier_lfp-separate.sh

#cross correlation analysis
./Vernier_bit-separate.sh

#AI analysis
./Vernier_ai-analysis.sh

#periodogram analysis
./Vernier_periodogram-separate.sh

# PLV and phase difference analysis
./Vernier_PLV.sh

#PAC analysis
./Vernier_PAC.sh
