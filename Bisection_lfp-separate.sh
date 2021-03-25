#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

matlab -nodisplay -r BisectionLFPizhikevich_synapse

for i in `seq 1 20`
do
    paste -s bir_lfp_v1_center_left_synapse_$i.csv >> bir_lfp_v1_center_left_separate_total_1.csv
    paste -s bir_lfp_v1_center_right_synapse_$i.csv >> bir_lfp_v1_center_right_separate_total_1.csv
    paste -s br_lfp_v1_center_left_synapse_$i.csv >> br_lfp_v1_center_left_separate_total_1.csv
    paste -s br_lfp_v1_center_right_synapse_$i.csv >> br_lfp_v1_center_right_separate_total_1.csv

    paste -s bir_lfp_vho_center_left_synapse_$i.csv >> bir_lfp_vho_center_left_separate_total_1.csv
    paste -s bir_lfp_vho_center_right_synapse_$i.csv >> bir_lfp_vho_center_right_separate_total_1.csv
    paste -s br_lfp_vho_center_left_synapse_$i.csv >> br_lfp_vho_center_left_separate_total_1.csv
    paste -s br_lfp_vho_center_right_synapse_$i.csv >> br_lfp_vho_center_right_separate_total_1.csv
done

for i in `seq 21 40`
do
    paste -s bir_lfp_v1_center_left_synapse_$i.csv >> bir_lfp_v1_center_left_separate_total_2.csv
    paste -s bir_lfp_v1_center_right_synapse_$i.csv >> bir_lfp_v1_center_right_separate_total_2.csv
    paste -s br_lfp_v1_center_left_synapse_$i.csv >> br_lfp_v1_center_left_separate_total_2.csv
    paste -s br_lfp_v1_center_right_synapse_$i.csv >> br_lfp_v1_center_right_separate_total_2.csv

    paste -s bir_lfp_vho_center_left_synapse_$i.csv >> bir_lfp_vho_center_left_separate_total_2.csv
    paste -s bir_lfp_vho_center_right_synapse_$i.csv >> bir_lfp_vho_center_right_separate_total_2.csv
    paste -s br_lfp_vho_center_left_synapse_$i.csv >> br_lfp_vho_center_left_separate_total_2.csv
    paste -s br_lfp_vho_center_right_synapse_$i.csv >> br_lfp_vho_center_right_separate_total_2.csv
done

for i in `seq 41 60`
do
    paste -s bir_lfp_v1_center_left_synapse_$i.csv >> bir_lfp_v1_center_left_separate_total_3.csv
    paste -s bir_lfp_v1_center_right_synapse_$i.csv >> bir_lfp_v1_center_right_separate_total_3.csv
    paste -s br_lfp_v1_center_left_synapse_$i.csv >> br_lfp_v1_center_left_separate_total_3.csv
    paste -s br_lfp_v1_center_right_synapse_$i.csv >> br_lfp_v1_center_right_separate_total_3.csv

    paste -s bir_lfp_vho_center_left_synapse_$i.csv >> bir_lfp_vho_center_left_separate_total_3.csv
    paste -s bir_lfp_vho_center_right_synapse_$i.csv >> bir_lfp_vho_center_right_separate_total_3.csv
    paste -s br_lfp_vho_center_left_synapse_$i.csv >> br_lfp_vho_center_left_separate_total_3.csv
    paste -s br_lfp_vho_center_right_synapse_$i.csv >> br_lfp_vho_center_right_separate_total_3.csv
done

for i in `seq 61 80`
do
    paste -s bir_lfp_v1_center_left_synapse_$i.csv >> bir_lfp_v1_center_left_separate_total_4.csv
    paste -s bir_lfp_v1_center_right_synapse_$i.csv >> bir_lfp_v1_center_right_separate_total_4.csv
    paste -s br_lfp_v1_center_left_synapse_$i.csv >> br_lfp_v1_center_left_separate_total_4.csv
    paste -s br_lfp_v1_center_right_synapse_$i.csv >> br_lfp_v1_center_right_separate_total_4.csv

    paste -s bir_lfp_vho_center_left_synapse_$i.csv >> bir_lfp_vho_center_left_separate_total_4.csv
    paste -s bir_lfp_vho_center_right_synapse_$i.csv >> bir_lfp_vho_center_right_separate_total_4.csv
    paste -s br_lfp_vho_center_left_synapse_$i.csv >> br_lfp_vho_center_left_separate_total_4.csv
    paste -s br_lfp_vho_center_right_synapse_$i.csv >> br_lfp_vho_center_right_separate_total_4.csv
done

for i in `seq 81 100`
do
    paste -s bir_lfp_v1_center_left_synapse_$i.csv >> bir_lfp_v1_center_left_separate_total_5.csv
    paste -s bir_lfp_v1_center_right_synapse_$i.csv >> bir_lfp_v1_center_right_separate_total_5.csv
    paste -s br_lfp_v1_center_left_synapse_$i.csv >> br_lfp_v1_center_left_separate_total_5.csv
    paste -s br_lfp_v1_center_right_synapse_$i.csv >> br_lfp_v1_center_right_separate_total_5.csv

    paste -s bir_lfp_vho_center_left_synapse_$i.csv >> bir_lfp_vho_center_left_separate_total_5.csv
    paste -s bir_lfp_vho_center_right_synapse_$i.csv >> bir_lfp_vho_center_right_separate_total_5.csv
    paste -s br_lfp_vho_center_left_synapse_$i.csv >> br_lfp_vho_center_left_separate_total_5.csv
    paste -s br_lfp_vho_center_right_synapse_$i.csv >> br_lfp_vho_center_right_separate_total_5.csv
done

matlab -nodisplay -r BisectionLFPizhikevich_separate

for i in `seq 1 5`
do
    paste -s bir_lfp_v1_center_left_separate_result_$i.csv >> bir_lfp_v1_center_left_separate_result_total.csv
    paste -s bir_lfp_v1_center_right_separate_result_$i.csv >> bir_lfp_v1_center_right_separate_result_total.csv
    paste -s br_lfp_v1_center_left_separate_result_$i.csv >> br_lfp_v1_center_left_separate_result_total.csv
    paste -s br_lfp_v1_center_right_separate_result_$i.csv >> br_lfp_v1_center_right_separate_result_total.csv

    paste -s bir_lfp_vho_center_left_separate_result_$i.csv >> bir_lfp_vho_center_left_separate_result_total.csv
    paste -s bir_lfp_vho_center_right_separate_result_$i.csv >> bir_lfp_vho_center_right_separate_result_total.csv
    paste -s br_lfp_vho_center_left_separate_result_$i.csv >> br_lfp_vho_center_left_separate_result_total.csv
    paste -s br_lfp_vho_center_right_separate_result_$i.csv >> br_lfp_vho_center_right_separate_result_total.csv
done

matlab -nodisplay -r BisectionLFPizhikevich_mean_separate

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_V1_LFP_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[0:100]
 set yrange[0:1]
 set multiplot layout 1,2
 plot "bir_lfp_v1_center_left_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "bir_lfp_v1_center_left_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "br_lfp_v1_center_left_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "br_lfp_v1_center_left_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
 plot "bir_lfp_v1_center_right_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "bir_lfp_v1_center_right_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "br_lfp_v1_center_right_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "br_lfp_v1_center_right_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Bisection_V1_LFP_separate_mean_result.eps Bisection_V1_LFP_separate_mean_result.jpg

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_HVA_LFP_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[0:100]
 set yrange[0:1]
 set multiplot layout 1,2
 plot "bir_lfp_vho_center_left_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "bir_lfp_vho_center_left_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "br_lfp_vho_center_left_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "br_lfp_vho_center_left_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
 plot "bir_lfp_vho_center_right_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "bir_lfp_vho_center_right_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "br_lfp_vho_center_right_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "br_lfp_vho_center_right_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Bisection_HVA_LFP_separate_mean_result.eps Bisection_HVA_LFP_separate_mean_result.jpg