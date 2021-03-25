/* Copyright (c) 2021 RT-JP All Right Reserved. */

//izhikevich parameters
const double a_RS = 0.02;
const double b_RS = 0.2;
const double c_RS = -65.0;
const double d_RS = 8.0;

const double a_FS = 0.1;
const double b_FS = 0.2;
const double c_FS = -65.0;
const double d_FS = 2.0;

const double a_CH = 0.02;
const double b_CH = 0.2;
const double c_CH = -50.0;
const double d_CH = 2.0;

const double a_LTS = 0.02;
const double b_LTS = 0.25;
const double c_LTS = -65.0;
const double d_LTS = 2.0;

//Simulation settings
const double dt = 0.1; //Step width
const double th_V1 = 30.0; //membrane threshold
const double V_first_param = -80.0;
const double TASK_TIME = 400.0; //time of one stimulus
const double REST_TIME = 0.0; //Task interval
const int Train_Task_Total = 1; //Train num

//V1 Pyr neuron
const double tau_XV1 = 30.0; //Time constant for output
const double x_lambda_V1 = 90.0; //lambda for output
const int V1_X_RANGE = 20; //V1 X range
const int V1_Y_RANGE = 20; //V1 Y range

//V1 PV neuron
const double tau_XV1_PV = 30.0; //Time constant for output
const double x_lambda_V1_PV = 90.0; //lambda for output

//SOM neuron
const double tau_XV1_SOM = 30.0; //Time constant for output
const double x_lambda_V1_SOM = 90.0; //lambda for output

//Input
const double tau_Input = 30.0; //Time constant for input
const double x_lambda_Input = 90.0; //lambda for output
const double firingrate_Input_V1 = 100.0; //Firing rate for poisson spike train
const double firingrate_Input_dt = 0.0001; //Step width for poisson spike train
const double Input_weight_V1 = 10.0; //Weight for poisson spike train

//Neuron connection
const double dist_sigma_E = 5.0; //Sigma for gaussian distribution (Excitory) 
const double dist_sigma_I = 7.0; //Sigma for gaussian distribution (Inhibitory)

const double w_ex_V1 = 3.0; //Weight for PC -> PC

const double w_ex_V1_PV = 4.0; //Weight for PC -> PV
const double w_inh_V1_PV_PC = 5.0; //Weight for PV -> PC
const double w_inh_V1_PV_PC_Relevant = 5.0;

const double w_ex_V1_SOM_local = 1.5; //Weight for PC -> SOM (local)
const double w_ex_V1_SOM_global = 1.5; //Weight for PC -> SOM (global)
const double w_inh_V1_SOM_PC = 5.0; //Weight for SOM -> PC 
const double w_inh_V1_SOM_PC_Relevant = 8.0;

//Cross correlation
const double BIT_FIRE = 1.0; //Bit value for neuron firing
const int T_BIT = 30; //Binning value for cross correlation

//LFP
const int T_LFP = 10.0; //Binning value for LFP