#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

matlab -nodisplay -r VernierPeriodogram

for i in `seq 1 20`
do
    paste -s vir_periodogram_v1_center_$i.csv >> vir_periodogram_v1_center_separate_total_1.csv
    paste -s vir_periodogram_v1_top_$i.csv >> vir_periodogram_v1_top_separate_total_1.csv

    paste -s vr_periodogram_v1_center_$i.csv >> vr_periodogram_v1_center_separate_total_1.csv
    paste -s vr_periodogram_v1_top_$i.csv >> vr_periodogram_v1_top_separate_total_1.csv
done

for i in `seq 21 40`
do
    paste -s vir_periodogram_v1_center_$i.csv >> vir_periodogram_v1_center_separate_total_2.csv
    paste -s vir_periodogram_v1_top_$i.csv >> vir_periodogram_v1_top_separate_total_2.csv

    paste -s vr_periodogram_v1_center_$i.csv >> vr_periodogram_v1_center_separate_total_2.csv
    paste -s vr_periodogram_v1_top_$i.csv >> vr_periodogram_v1_top_separate_total_2.csv
done

for i in `seq 41 60`
do
    paste -s vir_periodogram_v1_center_$i.csv >> vir_periodogram_v1_center_separate_total_3.csv
    paste -s vir_periodogram_v1_top_$i.csv >> vir_periodogram_v1_top_separate_total_3.csv

    paste -s vr_periodogram_v1_center_$i.csv >> vr_periodogram_v1_center_separate_total_3.csv
    paste -s vr_periodogram_v1_top_$i.csv >> vr_periodogram_v1_top_separate_total_3.csv
done

for i in `seq 61 80`
do
    paste -s vir_periodogram_v1_center_$i.csv >> vir_periodogram_v1_center_separate_total_4.csv
    paste -s vir_periodogram_v1_top_$i.csv >> vir_periodogram_v1_top_separate_total_4.csv

    paste -s vr_periodogram_v1_center_$i.csv >> vr_periodogram_v1_center_separate_total_4.csv
    paste -s vr_periodogram_v1_top_$i.csv >> vr_periodogram_v1_top_separate_total_4.csv
done

for i in `seq 81 100`
do
    paste -s vir_periodogram_v1_center_$i.csv >> vir_periodogram_v1_center_separate_total_5.csv
    paste -s vir_periodogram_v1_top_$i.csv >> vir_periodogram_v1_top_separate_total_5.csv

    paste -s vr_periodogram_v1_center_$i.csv >> vr_periodogram_v1_center_separate_total_5.csv
    paste -s vr_periodogram_v1_top_$i.csv >> vr_periodogram_v1_top_separate_total_5.csv
done

matlab -nodisplay -r VernierPeriodogram_separate

for i in `seq 1 5`
do
    paste -s vir_periodogram_v1_center_separate_result_$i.csv >> vir_periodogram_v1_center_separate_result_total.csv
    paste -s vir_periodogram_v1_top_separate_result_$i.csv >> vir_periodogram_v1_top_separate_result_total.csv

    paste -s vr_periodogram_v1_center_separate_result_$i.csv >> vr_periodogram_v1_center_separate_result_total.csv
    paste -s vr_periodogram_v1_top_separate_result_$i.csv >> vr_periodogram_v1_top_separate_result_total.csv
done

matlab -nodisplay -r VernierPeriodogram_mean_separate

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_periodogram_center_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[0:100]
 set multiplot layout 2,1
 plot "vir_periodogram_v1_center_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "vir_periodogram_v1_center_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle
 plot "vr_periodogram_v1_center_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "vr_periodogram_v1_center_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" dt (5,5) notitle
EOF

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_periodogram_top_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[0:100]
 set multiplot layout 2,1
 plot "vir_periodogram_v1_top_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "vir_periodogram_v1_top_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle
 plot "vr_periodogram_v1_top_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "vr_periodogram_v1_top_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" dt (5,5) notitle
EOF

convert -density 300 Vernier_V1_periodogram_center_separate_mean_result.eps Vernier_V1_periodogram_center_separate_mean_result.jpg
convert -density 300 Vernier_V1_periodogram_top_separate_mean_result.eps Vernier_V1_periodogram_top_separate_mean_result.jpg