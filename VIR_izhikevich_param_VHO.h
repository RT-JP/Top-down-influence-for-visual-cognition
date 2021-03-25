/* Copyright (c) 2021 RT-JP All Right Reserved. */

//Simulation settings
const double th_VHO = 30.0; //membrane threshold

//VHO Pyr neuron
const double tau_XVHO = 60.0; //Time constant for output
const double x_lambda_VHO = 180.0; //lambda for output
const int VHO_X_RANGE = 20; //VHO X range
const int VHO_Y_RANGE = 3; //VHO Y range

//VHO PV neuron
const double tau_XVHO_PV = 40.0; //Time constant for output
const double x_lambda_VHO_PV = 120.0; //lambda for output

//VHO SOM neuron
const double tau_XVHO_SOM = 40.0; //Time constant for output
const double x_lambda_VHO_SOM = 120.0; //lambda for output

//Neuron connection
const double w_ex_VHO = 4.0; //Weight for PC -> PC

const double w_ex_VHO_PV = 8.0; //Weight for PC -> PV
const double w_inh_VHO_PV_PC = 6.0; //Weight for PV -> PC

const double w_ex_VHO_SOM_local = 1.5; //Weight for PC -> SOM (local)
const double w_ex_VHO_SOM_global = 1.5; //Weight for PC -> SOM (global)
const double w_inh_VHO_SOM_PC = 12.0; //Weight for SOM -> PC 

//V1 < - > VHO connection
const double w_BOT_V1_VHO = 10.0; //V1 -> VHO bottomup
const double w_TOP_VHO_V1 = 10.0; //VHO -> V1 Topdown