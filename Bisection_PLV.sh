#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

#PLV
matlab -nodisplay -r BisectionPLVV1

paste -s Bisection_IrrelevantResult-bin10Hz-range1Hz-*.csv > Bisection_IrrelevantResult-bin10Hz-range1Hz-total.csv
paste -s Bisection_RelevantResult-bin10Hz-range1Hz-*.csv > Bisection_RelevantResult-bin10Hz-range1Hz-total.csv

matlab -nodisplay -r BisectionPLVV1_mean

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_V1_PLV_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set yrange[0:1]
 plot "Bisection_IrrelevantResult-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "Bisection_IrrelevantResult-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "Bisection_RelevantResult-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "red" notitle, "Bisection_RelevantResult-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Bisection_V1_PLV_result.eps Bisection_V1_PLV_result.jpg

#PLV phase-difference

matlab -nodisplay -r Bisection_phase_difference

paste -s Bisection_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-*.csv > Bisection_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-total.csv
paste -s Bisection_Relevant-phase-difference-Result-bin10Hz-range1Hz-*.csv > Bisection_Relevant-phase-difference-Result-bin10Hz-range1Hz-total.csv

matlab -nodisplay -r Bisection_phase_difference_mean

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Bisection_V1_PLV_phase_difference_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set yrange[0:3.5]
 plot "Bisection_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "Bisection_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "Bisection_Relevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "red" notitle, "Bisection_Relevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Bisection_V1_PLV_phase_difference_result.eps Bisection_V1_PLV_phase_difference_result.jpg
