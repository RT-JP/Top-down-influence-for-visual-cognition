# Top-down influence for visual cognition
This repository is about the top-down influence of visual cognition. These files contains C, MATLAB, and shell script.

# How to use
$ ./BisectionVernierTaskSimulation.sh

# Model
My model consist V1 layer and HVA (or VHO) layer. V1 means a primary visual cortex. HVA means a higher visual areas. VHO means a visual high-oder and it is same as HVA.

(a) The feedforward and recurrent connections of neurons in V1 and HVA.
(b) The feedback and top-down connections.

![model](https://user-images.githubusercontent.com/81313746/112433746-068d7500-8d86-11eb-8c21-32b6810faab5.jpg)

# Results
If you succeed in the simulation, you get 26 figures. 

Tuning curves: Bisection_V1_tuning_center_mean, Bisection_VHO_tuning_center_mean, Vernier_V1_tuning_center_mean, Vernier_VHO_tuning_center_mean

Local Field Potential: Bisection_V1_LFP_separate_mean_result, Bisection_HVA_LFP_separate_mean_result, Vernier_V1_LFP_separate_mean_result, Vernier_HVA_LFP_separate_mean_result

Cross Correlation: Bisection_V1_bit_separate_mean_result, Bisection_HVA_bit_separate_mean_result, Vernier_V1_bit_separate_mean_result, Vernier_HVA_bit_separate_mean_result

Periodogram: Bisection_V1_periodogram_center_separate_mean_result, Vernier_V1_periodogram_center_separate_mean_result, Bisection_V1_periodogram_right_separate_mean_result, Vernier_V1_periodogram_top_separate_mean_result

Phase Locking Value: Bisection_V1_PLV_result, Vernier_V1_PLV_result

Phase Difference: Bisection_V1_PLV_phase_difference_result, Vernier_V1_PLV_phase_difference_result

Phase Amplitude Coupling: Bisection_V1_PAC_result_irrelevant, Bisection_V1_PAC_result_relevant, Vernier_V1_PAC_result_irrelevant, Vernier_V1_PAC_result_relevant

Attention Index: V1-AI, VHO-AI

# Requirement
gcc 5.5.0

MATLAB R2018b update 4 and the signal processing tools

gnuplot 5.0 patchlevel 3

# Licence
All files except "MT.h" are copyrighted by RT-JP 2021.
