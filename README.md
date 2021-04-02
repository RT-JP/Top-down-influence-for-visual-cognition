# About repository
This repository is about the top-down influence of visual cognition. I consider two types of perceptual tasks. The one is bisection task, the other is vernier task. (A) In bisection task, monkeys had to determine which side bars was closer to the centralbar. (B) In vernier task, they were required to determine to which side the central bar was displaced relative to a collinear line of end bars. The more details of the tasks are described in [Li et al. (2004)](https://www.ncbi.nlm.nih.gov/pmc/articles/PMC1440483/).

![tasks](https://user-images.githubusercontent.com/81313746/113378909-20950c00-93b3-11eb-9e56-9f29f1685ada.jpg)

# Model
My model consists of V1 layer and HVA (or VHO) layer. V1 means a primary visual cortex. HVA means a higher visual areas. VHO is same as HVA.

The V1 model has 20 × 20 units. Each units constains a pyramidal (Pyr) neuron, a parvalbumin (PV)-expressing interneuron and a somatostatin (SOM)-expressing interneuron. The HVA model has the structure similar to the V1 model. It has 20 × 3 units. (a) The feedforward and recurrent connections of neurons in V1 and HVA. (b) The feedback and top-down connections. I used the izhikevich neuron model.

![model](https://user-images.githubusercontent.com/81313746/112433746-068d7500-8d86-11eb-8c21-32b6810faab5.jpg)

# Files
These files contains C, MATLAB, and shell script. The main files are four types.

(I) "BIR": Bisection Irrelevant. This is about the bisection task without top-down.

(II) "BR": Bisection Relevant. This is about the bisection task with top-down.

(III) "VIR": Vernier Irrelevant. This is about the vernier task without top-down.

(IV) "VR": Vernier Relevant. This is about the vernier task with top-down.

"XXX-izhikevich.c" is a main program (XXX = BIR, BR, VIR, VR). Please refer to the "Bisection-izhikevich-100trials.sh" of "Vernier-izhikevich-100trials.sh" file for the flow from program execution to analysis.

# How to use
$ ./BisectionVernierTaskSimulation.sh

If you want to change the parameters, see the header file that contains the name "param".

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
