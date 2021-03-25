#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

matlab -nodisplay -r VernierBITizhikevich

for i in `seq 1 20`
do
    paste -s vir_bit_v1_center_top_$i.csv >> vir_bit_v1_center_top_separate_total_1.csv
    paste -s vr_bit_v1_center_top_$i.csv >> vr_bit_v1_center_top_separate_total_1.csv

    paste -s vir_bit_vho_center_top_$i.csv >> vir_bit_vho_center_top_separate_total_1.csv
    paste -s vr_bit_vho_center_top_$i.csv >> vr_bit_vho_center_top_separate_total_1.csv
done

for i in `seq 21 40`
do
    paste -s vir_bit_v1_center_top_$i.csv >> vir_bit_v1_center_top_separate_total_2.csv
    paste -s vr_bit_v1_center_top_$i.csv >> vr_bit_v1_center_top_separate_total_2.csv

    paste -s vir_bit_vho_center_top_$i.csv >> vir_bit_vho_center_top_separate_total_2.csv
    paste -s vr_bit_vho_center_top_$i.csv >> vr_bit_vho_center_top_separate_total_2.csv
done

for i in `seq 41 60`
do
    paste -s vir_bit_v1_center_top_$i.csv >> vir_bit_v1_center_top_separate_total_3.csv
    paste -s vr_bit_v1_center_top_$i.csv >> vr_bit_v1_center_top_separate_total_3.csv

    paste -s vir_bit_vho_center_top_$i.csv >> vir_bit_vho_center_top_separate_total_3.csv
    paste -s vr_bit_vho_center_top_$i.csv >> vr_bit_vho_center_top_separate_total_3.csv
done

for i in `seq 61 80`
do
    paste -s vir_bit_v1_center_top_$i.csv >> vir_bit_v1_center_top_separate_total_4.csv
    paste -s vr_bit_v1_center_top_$i.csv >> vr_bit_v1_center_top_separate_total_4.csv

    paste -s vir_bit_vho_center_top_$i.csv >> vir_bit_vho_center_top_separate_total_4.csv
    paste -s vr_bit_vho_center_top_$i.csv >> vr_bit_vho_center_top_separate_total_4.csv
done

for i in `seq 81 100`
do
    paste -s vir_bit_v1_center_top_$i.csv >> vir_bit_v1_center_top_separate_total_5.csv
    paste -s vr_bit_v1_center_top_$i.csv >> vr_bit_v1_center_top_separate_total_5.csv

    paste -s vir_bit_vho_center_top_$i.csv >> vir_bit_vho_center_top_separate_total_5.csv
    paste -s vr_bit_vho_center_top_$i.csv >> vr_bit_vho_center_top_separate_total_5.csv
done

matlab -nodisplay -r VernierBIT_separate

for i in `seq 1 5`
do
    paste -s vir_bit_v1_center_top_separate_result_$i.csv >> vir_bit_v1_center_top_separate_result_total.csv
    paste -s vr_bit_v1_center_top_separate_result_$i.csv >> vr_bit_v1_center_top_separate_result_total.csv

    paste -s vir_bit_vho_center_top_separate_result_$i.csv >> vir_bit_vho_center_top_separate_result_total.csv
    paste -s vr_bit_vho_center_top_separate_result_$i.csv >> vr_bit_vho_center_top_separate_result_total.csv
done

matlab -nodisplay -r VernierBIT_mean_separate

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_bit_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[-100:100]
 set yrange[0:0.5]
 plot "vir_bit_v1_center_top_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "vir_bit_v1_center_top_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "vr_bit_v1_center_top_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "vr_bit_v1_center_top_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Vernier_V1_bit_separate_mean_result.eps Vernier_V1_bit_separate_mean_result.jpg

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_HVA_bit_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[-100:100]
 set yrange[0:0.5]
 plot "vir_bit_vho_center_top_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "vir_bit_vho_center_top_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "vr_bit_vho_center_top_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "vr_bit_vho_center_top_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Vernier_HVA_bit_separate_mean_result.eps Vernier_HVA_bit_separate_mean_result.jpg