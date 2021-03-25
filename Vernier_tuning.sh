#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

paste -s vir_tuning_V1_center_mean_analysis_data_*.csv > vir_tuning_V1_center_mean_analysis_data_total.csv
paste -s vr_tuning_V1_center_mean_analysis_data_*.csv > vr_tuning_V1_center_mean_analysis_data_total.csv
paste -s vir_tuning_VHO_center_mean_analysis_data_*.csv > vir_tuning_VHO_center_mean_analysis_data_total.csv
paste -s vr_tuning_VHO_center_mean_analysis_data_*.csv > vr_tuning_VHO_center_mean_analysis_data_total.csv

matlab -nodisplay -r VernierTuningAnalysis

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_tuning_center_mean.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[-2.5:2.5]
 set yrange[0:80]
 plot "vir_tuning_V1_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "blue" dt (5,5) notitle, "vir_tuning_V1_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "blue" dt (5,5) notitle, "vr_tuning_V1_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "red" notitle, "vr_tuning_V1_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "red" notitle
EOF

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_VHO_tuning_center_mean.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[-2.5:2.5]
 set yrange[0:80]
 plot "vir_tuning_VHO_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "blue" dt (5,5) notitle, "vir_tuning_VHO_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "blue" dt (5,5) notitle, "vr_tuning_VHO_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "red" notitle, "vr_tuning_VHO_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "red" notitle
EOF

convert -density 300 Vernier_V1_tuning_center_mean.eps Vernier_V1_tuning_center_mean.jpg
convert -density 300 Vernier_VHO_tuning_center_mean.eps Vernier_VHO_tuning_center_mean.jpg