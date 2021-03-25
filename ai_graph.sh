#!/bin/sh

# Copyright (c) 2021 RT-JP All Right Reserved.

gnuplot << EOF
 set terminal jpeg
 set output "V1-AI.jpg"
 set tics font "Times New Roman, 15"
 set xlabel font "Times New Roman, 15"
 set ylabel font "Times New Roman, 15"
 unset border; set xtics axis; set ytics axis; set zeroaxis ls -1;
 set xrange[-0.4:0.4]
 set yrange[-1:1]
 set multiplot layout 1,2
 set title "AI(beta) vs AI(R)"
 plot "Bisection_V1_AI_R_beta.csv" notitle, "Vernier_V1_AI_R_beta.csv" notitle
 set title "AI(gamma) vs AI(R)"
 plot "Bisection_V1_AI_R_gamma.csv" notitle, "Vernier_V1_AI_R_gamma.csv" notitle
EOF

gnuplot << EOF
 set terminal jpeg
 set output "VHO-AI.jpg"
 set tics font "Times New Roman, 15"
 set xlabel font "Times New Roman, 15"
 set ylabel font "Times New Roman, 15"
 unset border; set xtics axis; set ytics axis; set zeroaxis ls -1;
 set xrange[-0.4:0.4]
 set yrange[-1:1]
 set multiplot layout 1,2
 set title "AI(beta) vs AI(R)"
 plot "Bisection_VHO_AI_R_beta.csv" notitle, "Vernier_VHO_AI_R_beta.csv" notitle
 set title "AI(gamma) vs AI(R)"
 plot "Bisection_VHO_AI_R_gamma.csv" notitle, "Vernier_VHO_AI_R_gamma.csv" notitle
EOF
