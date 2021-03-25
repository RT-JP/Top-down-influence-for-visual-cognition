#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

#PLV
matlab -nodisplay -r VernierPLVV1

paste -s Vernier_IrrelevantResult-bin10Hz-range1Hz-*.csv > Vernier_IrrelevantResult-bin10Hz-range1Hz-total.csv
paste -s Vernier_RelevantResult-bin10Hz-range1Hz-*.csv > Vernier_RelevantResult-bin10Hz-range1Hz-total.csv

matlab -nodisplay -r VernierPLVV1_mean

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_PLV_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set yrange[0:1]
 plot "Vernier_IrrelevantResult-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "Vernier_IrrelevantResult-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "Vernier_RelevantResult-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "red" notitle, "Vernier_RelevantResult-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Vernier_V1_PLV_result.eps Vernier_V1_PLV_result.jpg

#PLV phase-difference

matlab -nodisplay -r Vernier_phase_difference

paste -s Vernier_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-*.csv > Vernier_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-total.csv
paste -s Vernier_Relevant-phase-difference-Result-bin10Hz-range1Hz-*.csv > Vernier_Relevant-phase-difference-Result-bin10Hz-range1Hz-total.csv

matlab -nodisplay -r Vernier_phase_difference_mean

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_PLV_phase_difference_result.eps"
 set tics font "Times New Roman, 30"
 set xlabel font "Times New Roman, 30"
 set ylabel font "Times New Roman, 30"
 set datafile separator ","
 set yrange[0:3.5]
 plot "Vernier_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "blue" dt (5,5) notitle, "Vernier_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "blue" dt (5,5) notitle, "Vernier_Relevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" w e lw 3 lc rgb "red" notitle, "Vernier_Relevant-phase-difference-Result-bin10Hz-range1Hz-total-result.csv" u 1:2 w l lw 3 lc rgb "red" notitle
EOF

convert -density 300 Vernier_V1_PLV_phase_difference_result.eps Vernier_V1_PLV_phase_difference_result.jpg
