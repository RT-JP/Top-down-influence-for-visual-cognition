#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

matlab -nodisplay -r VernierPAC_V1_BetaPhaseGammaAmp

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_PAC_result_irrelevant.eps"
 set tics font "Times New Roman, 10"
 set xlabel font "Times New Roman, 10"
 set ylabel font "Times New Roman, 10"
 set xtics 0, 20, 100
 set ytics 0, 20, 100
 set pm3d
 set pm3d map
 set cbrange[0:1]
 splot "Vernier_Irrelevant-BetaPhase-GammaAmp-Result-V1.csv" notitle
EOF

convert -density 300 Vernier_V1_PAC_result_irrelevant.eps Vernier_V1_PAC_result_irrelevant.jpg

gnuplot << EOF
 set terminal postscript eps enhanced color
 set output "Vernier_V1_PAC_result_relevant.eps"
 set tics font "Times New Roman, 10"
 set xlabel font "Times New Roman, 10"
 set ylabel font "Times New Roman, 10"
 set xtics 0, 20, 100
 set ytics 0, 20, 100
 set pm3d
 set pm3d map
 set cbrange[0:1]
 splot "Vernier_Relevant-BetaPhase-GammaAmp-Result-V1.csv" notitle
EOF

convert -density 300 Vernier_V1_PAC_result_relevant.eps Vernier_V1_PAC_result_relevant.jpg
