#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

matlab -nodisplay -r BisectionPeriodogram

for i in `seq 1 20`
do
    paste -s bir_periodogram_v1_center_$i.csv >> bir_periodogram_v1_center_separate_total_1.csv
    paste -s bir_periodogram_v1_right_$i.csv >> bir_periodogram_v1_right_separate_total_1.csv

    paste -s br_periodogram_v1_center_$i.csv >> br_periodogram_v1_center_separate_total_1.csv
    paste -s br_periodogram_v1_right_$i.csv >> br_periodogram_v1_right_separate_total_1.csv
done

for i in `seq 21 40`
do
    paste -s bir_periodogram_v1_center_$i.csv >> bir_periodogram_v1_center_separate_total_2.csv
    paste -s bir_periodogram_v1_right_$i.csv >> bir_periodogram_v1_right_separate_total_2.csv

    paste -s br_periodogram_v1_center_$i.csv >> br_periodogram_v1_center_separate_total_2.csv
    paste -s br_periodogram_v1_right_$i.csv >> br_periodogram_v1_right_separate_total_2.csv
done

for i in `seq 41 60`
do
    paste -s bir_periodogram_v1_center_$i.csv >> bir_periodogram_v1_center_separate_total_3.csv
    paste -s bir_periodogram_v1_right_$i.csv >> bir_periodogram_v1_right_separate_total_3.csv

    paste -s br_periodogram_v1_center_$i.csv >> br_periodogram_v1_center_separate_total_3.csv
    paste -s br_periodogram_v1_right_$i.csv >> br_periodogram_v1_right_separate_total_3.csv
done

for i in `seq 61 80`
do
    paste -s bir_periodogram_v1_center_$i.csv >> bir_periodogram_v1_center_separate_total_4.csv
    paste -s bir_periodogram_v1_right_$i.csv >> bir_periodogram_v1_right_separate_total_4.csv

    paste -s br_periodogram_v1_center_$i.csv >> br_periodogram_v1_center_separate_total_4.csv
    paste -s br_periodogram_v1_right_$i.csv >> br_periodogram_v1_right_separate_total_4.csv
done

for i in `seq 81 100`
do
    paste -s bir_periodogram_v1_center_$i.csv >> bir_periodogram_v1_center_separate_total_5.csv
    paste -s bir_periodogram_v1_right_$i.csv >> bir_periodogram_v1_right_separate_total_5.csv

    paste -s br_periodogram_v1_center_$i.csv >> br_periodogram_v1_center_separate_total_5.csv
    paste -s br_periodogram_v1_right_$i.csv >> br_periodogram_v1_right_separate_total_5.csv
done

matlab -nodisplay -r BisectionPeriodogram_separate

for i in `seq 1 5`
do
    paste -s bir_periodogram_v1_center_separate_result_$i.csv >> bir_periodogram_v1_center_separate_result_total.csv
    paste -s bir_periodogram_v1_right_separate_result_$i.csv >> bir_periodogram_v1_right_separate_result_total.csv

    paste -s br_periodogram_v1_center_separate_result_$i.csv >> br_periodogram_v1_center_separate_result_total.csv
    paste -s br_periodogram_v1_right_separate_result_$i.csv >> br_periodogram_v1_right_separate_result_total.csv
done

matlab -nodisplay -r BisectionPeriodogram_mean_separate

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_V1_periodogram_center_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[0:100]
 set multiplot layout 2,1
 plot "bir_periodogram_v1_center_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "bir_periodogram_v1_center_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle
 plot "br_periodogram_v1_center_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "br_periodogram_v1_center_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" dt (5,5) notitle
EOF

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_V1_periodogram_right_separate_mean_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[0:100]
 set multiplot layout 2,1
 plot "bir_periodogram_v1_right_separate_mean_result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "bir_periodogram_v1_right_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle
 plot "br_periodogram_v1_right_separate_mean_result.csv" w e lw 3 lc rgb "red" notitle, "br_periodogram_v1_right_separate_mean_result.csv" u 1:2 w l lw 3 lc rgb "red" dt (5,5) notitle
EOF

convert -density 300 Bisection_V1_periodogram_center_separate_mean_result.eps Bisection_V1_periodogram_center_separate_mean_result.jpg
convert -density 300 Bisection_V1_periodogram_right_separate_mean_result.eps Bisection_V1_periodogram_right_separate_mean_result.jpg
