#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

paste -s bir_tuning_V1_center_mean_analysis_data_*.csv > bir_tuning_V1_center_mean_analysis_data_total.csv
paste -s br_tuning_V1_center_mean_analysis_data_*.csv > br_tuning_V1_center_mean_analysis_data_total.csv
paste -s bir_tuning_VHO_center_mean_analysis_data_*.csv > bir_tuning_VHO_center_mean_analysis_data_total.csv
paste -s br_tuning_VHO_center_mean_analysis_data_*.csv > br_tuning_VHO_center_mean_analysis_data_total.csv

matlab -nodisplay -r BisectionTuningAnalysis

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_V1_tuning_center_mean.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[-2.5:2.5]
 set yrange[0:80]
 plot "bir_tuning_V1_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "blue" dt (5,5) notitle, "bir_tuning_V1_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "blue" dt (5,5) notitle, "br_tuning_V1_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "red" notitle, "br_tuning_V1_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "red" notitle
EOF

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_VHO_tuning_center_mean.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set xrange[-2.5:2.5]
 set yrange[0:80]
 plot "bir_tuning_VHO_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "blue" dt (5,5) notitle, "bir_tuning_VHO_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "blue" dt (5,5) notitle, "br_tuning_VHO_center_mean_result.csv" using 1:2:3 with yerrorbars lw 5 pt 7 ps 1 lc rgb "red" notitle, "br_tuning_VHO_center_mean_result.csv" using 1:2 w l lw 5 lc rgb "red" notitle
EOF

convert -density 300 Bisection_V1_tuning_center_mean.eps Bisection_V1_tuning_center_mean.jpg
convert -density 300 Bisection_VHO_tuning_center_mean.eps Bisection_VHO_tuning_center_mean.jpg