#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

gcc -O3 -march=native -o BIR-izhikevich BIR-izhikevich.c -lm
gcc -O3 -march=native -o BR-izhikevich BR-izhikevich.c -lm

for i in `seq 1 100`
do
    echo "Irrelevant $i回目"
    ./BIR-izhikevich

    #save lfp data
    cp bir_lfp_v1_center_synapse.csv bir_lfp_v1_center_data_$i.csv
    cp bir_lfp_v1_left_synapse.csv bir_lfp_v1_left_data_$i.csv
    cp bir_lfp_v1_right_synapse.csv bir_lfp_v1_right_data_$i.csv

    cp bir_lfp_VHO_center_synapse.csv bir_lfp_vho_center_data_$i.csv
    cp bir_lfp_VHO_left_synapse.csv bir_lfp_vho_left_data_$i.csv
    cp bir_lfp_VHO_right_synapse.csv bir_lfp_vho_right_data_$i.csv
    #save bit data
    cp bir_bit_v1_center.csv bir_bit_v1_center_data_$i.csv
    cp bir_bit_v1_left.csv bir_bit_v1_left_data_$i.csv
    cp bir_bit_v1_right.csv bir_bit_v1_right_data_$i.csv

    cp bir_bit_VHO_center.csv bir_bit_vho_center_data_$i.csv
    cp bir_bit_VHO_left.csv bir_bit_vho_left_data_$i.csv
    cp bir_bit_VHO_right.csv bir_bit_vho_right_data_$i.csv
    #save tuning data
    cut -d " " -f 3 bir_tuning_V1_center.csv | head -n 1 > bir_tuning_V1_center_data.csv
    cut -d " " -f 3 bir_tuning_V1_center.csv > bir_tuning_V1_center_mean_analysis_data.csv
    cut -d " " -f 3 bir_tuning_V1_right.csv | head -n 1 > bir_tuning_V1_right_data.csv
    cp bir_tuning_V1_center_data.csv bir_tuning_V1_center_data_$i.csv
    cp bir_tuning_V1_center_mean_analysis_data.csv bir_tuning_V1_center_mean_analysis_data_$i.csv
    cp bir_tuning_V1_right_data.csv bir_tuning_V1_right_data_$i.csv

    cut -d " " -f 3 bir_tuning_VHO_center.csv | head -n 1 > bir_tuning_VHO_center_data.csv
    cut -d " " -f 3 bir_tuning_VHO_center.csv > bir_tuning_VHO_center_mean_analysis_data.csv
    cut -d " " -f 3 bir_tuning_VHO_right.csv | head -n 1 > bir_tuning_VHO_right_data.csv
    cp bir_tuning_VHO_center_data.csv bir_tuning_VHO_center_data_$i.csv
    cp bir_tuning_VHO_center_mean_analysis_data.csv bir_tuning_VHO_center_mean_analysis_data_$i.csv
    cp bir_tuning_VHO_right_data.csv bir_tuning_VHO_right_data_$i.csv
done

for i in `seq 1 100`
do
    echo "Relevant $i回目"
    ./BR-izhikevich

    #save lfp data
    cp br_lfp_v1_center_synapse.csv br_lfp_v1_center_data_$i.csv
    cp br_lfp_v1_left_synapse.csv br_lfp_v1_left_data_$i.csv
    cp br_lfp_v1_right_synapse.csv br_lfp_v1_right_data_$i.csv

    cp br_lfp_VHO_center_synapse.csv br_lfp_vho_center_data_$i.csv
    cp br_lfp_VHO_left_synapse.csv br_lfp_vho_left_data_$i.csv
    cp br_lfp_VHO_right_synapse.csv br_lfp_vho_right_data_$i.csv
    #save bit data
    cp br_bit_v1_center.csv br_bit_v1_center_data_$i.csv
    cp br_bit_v1_left.csv br_bit_v1_left_data_$i.csv
    cp br_bit_v1_right.csv br_bit_v1_right_data_$i.csv

    cp br_bit_VHO_center.csv br_bit_vho_center_data_$i.csv
    cp br_bit_VHO_left.csv br_bit_vho_left_data_$i.csv
    cp br_bit_VHO_right.csv br_bit_vho_right_data_$i.csv
    #save tuning data
    cut -d " " -f 3 br_tuning_V1_center.csv | head -n 1 > br_tuning_V1_center_data.csv
    cut -d " " -f 3 br_tuning_V1_center.csv > br_tuning_V1_center_mean_analysis_data.csv
    cut -d " " -f 3 br_tuning_V1_right.csv | head -n 1 > br_tuning_V1_right_data.csv
    cp br_tuning_V1_center_data.csv br_tuning_V1_center_data_$i.csv
    cp br_tuning_V1_center_mean_analysis_data.csv br_tuning_V1_center_mean_analysis_data_$i.csv
    cp br_tuning_V1_right_data.csv br_tuning_V1_right_data_$i.csv

    cut -d " " -f 3 br_tuning_VHO_center.csv | head -n 1 > br_tuning_VHO_center_data.csv
    cut -d " " -f 3 br_tuning_VHO_center.csv > br_tuning_VHO_center_mean_analysis_data.csv
    cut -d " " -f 3 br_tuning_VHO_right.csv | head -n 1 > br_tuning_VHO_right_data.csv
    cp br_tuning_VHO_center_data.csv br_tuning_VHO_center_data_$i.csv
    cp br_tuning_VHO_center_mean_analysis_data.csv br_tuning_VHO_center_mean_analysis_data_$i.csv
    cp br_tuning_VHO_right_data.csv br_tuning_VHO_right_data_$i.csv
done

#tuning analysis
./Bisection_tuning.sh

#lfp analysis
./Bisection_lfp-separate.sh

#cross correlation analysis
./Bisection_bit-separate.sh

#AI analysis
./Bisection_ai-analysis.sh

#periodogram analysis
./Bisection_periodogram-separate.sh

# PLV and phase difference analysis
./Bisection_PLV.sh

#PAC analysis
./Bisection_PAC.sh
