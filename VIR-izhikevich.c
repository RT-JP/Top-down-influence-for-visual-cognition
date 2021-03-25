/* Copyright (c) 2021 RT-JP All Right Reserved. */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "VIR_izhikevich_param_V1.h" //Reading header file of V1 parameters
#include "VIR_izhikevich_param_VHO.h" //Reading header file of VHO parameters
#include "VIR_izhikevich_resultfile_V1.h" //Reading header file of V1 resultfiles
#include "VIR_izhikevich_resultfile_VHO.h" //Reading header file of VHO resultfiles
#include "kansuu-izhikevich.h" //Reading header file of functions
#include "MT.h" //Reading header file of mersenne twister by Takuji Nishimura and Makoto Matsumoto (see the lisence of "MT.h").

int main(){
	FileOpenV1(); //File open of V1
	FileOpenVHO(); //File open of VHO

	init_genrand((unsigned)time(NULL)); //Reset random

    /*Start to define of variable*/
	int h, i, j, k, m, n, l;
	double t = 0.0, URN_V1_LGN = 0.0; //URN = Uniform Random Numbers 
	int train_count = 0; //Train counter
	double train_time_start = 0.0, train_time_end = 0.0, train_time_total = 0.0; //Task time
	int train_bisection = 0, train_vernier = 0; //Five bars position of bisection and vernier task
	int t_bit = 0; //Data binning for firing bit
	int t_lfp = 0; //Data binning for LFP
	//Tuning curves of V1
	double pattern_V1_center = 0.0;
	double pattern_V1_left = 0.0;
	double pattern_V1_right = 0.0;
	double pattern_V1_top = 0.0;
	double pattern_V1_bottom = 0.0;
	//Tuning curves of VHO
	double pattern_VHO_center = 0.0; 
	double pattern_VHO_left = 0.0;
	double pattern_VHO_right = 0.0;
	double pattern_VHO_top = 0.0;
	double pattern_VHO_bottom = 0.0;

	int tuning_count = 0;
    /*End to define of variable*/

    /*Start to define of array*/
    //V1 Pyr neuron
	double train_V_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr membrane potential
	double train_U_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr recovery variable
	double train_I_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr total input
	double train_X_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr output
	double train_Delta_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 delta function for Pyr output
	double train_S_ex_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr -> Pyr excitatory connection
	double train_S_inh_from_pv_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 PV -> Pyr inhibitory connection
	double train_S_inh_from_som_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 SOM -> Pyr inhibitory connection
	double train_S_inh_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 total inhibitory connection
	double train_LGN_V1[V1_X_RANGE][V1_Y_RANGE]; //Input from LGN to V1
	double train_TOP_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 topdown signal
	
	double train_LGN_Input_Switch[V1_X_RANGE][V1_Y_RANGE]; //Input switch of LGN
	double train_V1_synapse[V1_X_RANGE][V1_Y_RANGE]; //V1 total synapse input 
	double train_X_Input_V1[V1_X_RANGE][V1_Y_RANGE]; //LGN output
	double train_Delta_Input_V1[V1_X_RANGE][V1_Y_RANGE]; //LGN delta function for output
	//V1 PV neuron
	double train_V1_PV_V[V1_X_RANGE][V1_Y_RANGE]; //V1 PV membrane potential
	double train_V1_PV_U[V1_X_RANGE][V1_Y_RANGE]; //V1 PV recovery variable
	double train_V1_PV_I[V1_X_RANGE][V1_Y_RANGE]; //V1 PV total input
	double train_V1_PV_X[V1_X_RANGE][V1_Y_RANGE]; //V1 PV output
	double train_V1_PV_Delta[V1_X_RANGE][V1_Y_RANGE]; //V1 delta function for PV output
	double train_V1_PV_S_ex[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr -> PV excitatory connection
	//V1 SOM neuron
	double train_V1_SOM_V[V1_X_RANGE][V1_Y_RANGE]; //V1 SOM membrane potential
	double train_V1_SOM_U[V1_X_RANGE][V1_Y_RANGE]; //V1 SOM recovery variable
	double train_V1_SOM_I[V1_X_RANGE][V1_Y_RANGE]; //V1 SOM total input
	double train_V1_SOM_X[V1_X_RANGE][V1_Y_RANGE]; //V1 SOM output
	double train_V1_SOM_Delta[V1_X_RANGE][V1_Y_RANGE]; //V1 delta function for SOM output
	double train_V1_SOM_S_ex[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr -> SOM excitatory connection
    //V1 Cross correlation
	double BIT_V1[V1_X_RANGE][V1_Y_RANGE]; //For bit data generation
	double BIT_COUNT_V1[V1_X_RANGE][V1_Y_RANGE]; //For bit data count
	double LINE_BIT_V1[5]; //For bit data of five bars
	//V1 LFP coherence
	double LFP_V1_synapse[V1_X_RANGE][V1_Y_RANGE]; //For LFP data generation
	double LFP_synapse_V1[5]; //For LFP data of five bars
	//V1 Tuning curve
	double spike_count_V1[V1_X_RANGE][V1_Y_RANGE]; //V1 Pyr spike count

	//VHO Pyr neuron (same as V1 Pyr neuron) 
	double train_V_VHO[VHO_X_RANGE][VHO_Y_RANGE]; 
	double train_U_VHO[VHO_X_RANGE][VHO_Y_RANGE];
	double train_I_VHO[VHO_X_RANGE][VHO_Y_RANGE]; 
	double train_X_VHO[VHO_X_RANGE][VHO_Y_RANGE];
	double train_Delta_VHO[VHO_X_RANGE][VHO_Y_RANGE]; 
	double train_S_ex_VHO[VHO_X_RANGE][VHO_Y_RANGE]; 
	double train_S_inh_from_pv_VHO[VHO_X_RANGE][VHO_Y_RANGE];
	double train_S_inh_from_som_VHO[VHO_X_RANGE][VHO_Y_RANGE];
	double train_S_inh_VHO[VHO_X_RANGE][VHO_Y_RANGE];
	double train_BOT_VHO[VHO_X_RANGE][VHO_Y_RANGE]; //Feedforward from V1 Pyr neuron
	double train_TOP_VHO[VHO_X_RANGE][VHO_Y_RANGE]; //Topdown input 
	
	double train_VHO_synapse[VHO_X_RANGE][VHO_Y_RANGE]; //VHO total synapse input 
	//VHO PV neuron (same as V1 PV neuron) 
	double train_VHO_PV_V[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_PV_U[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_PV_I[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_PV_X[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_PV_Delta[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_PV_S_ex[VHO_X_RANGE][VHO_Y_RANGE];
	//VHO SOM neuron (same as V1 SOM neuron) 
	double train_VHO_SOM_V[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_SOM_U[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_SOM_I[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_SOM_X[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_SOM_Delta[VHO_X_RANGE][VHO_Y_RANGE];
	double train_VHO_SOM_S_ex[VHO_X_RANGE][VHO_Y_RANGE];
	//VHO Cross correlation
	double BIT_VHO[VHO_X_RANGE][VHO_Y_RANGE];
	double BIT_COUNT_VHO[VHO_X_RANGE][VHO_Y_RANGE];
	double LINE_BIT_VHO[5];
	//VHO LFP coherence
	double LFP_VHO_synapse[VHO_X_RANGE][VHO_Y_RANGE];
	//VHO Tuning curve
	double spike_count_VHO[VHO_X_RANGE][VHO_Y_RANGE];
    
	//VHO LFP
	double LFP_synapse_VHO[5];
    /*End to define of array*/

    /*Start to initialize of array*/
    //V1
	for(i = 0; i < V1_X_RANGE; i++){
		for(j = 0; j < V1_Y_RANGE; j++){
			train_V_V1[i][j] = V_first_param; 
			train_U_V1[i][j] = 0.0;
			train_I_V1[i][j] = 0.0; 
			train_X_V1[i][j] = 0.0; 
			train_Delta_V1[i][j] = 0.0; 
			train_S_ex_V1[i][j] = 0.0;
			train_S_inh_from_pv_V1[i][j] = 0.0;
			train_S_inh_from_som_V1[i][j] = 0.0;
			train_S_inh_V1[i][j] = 0.0;
			train_LGN_V1[i][j] = 0.0;
			train_TOP_V1[i][j] = 0.0;
			train_LGN_Input_Switch[i][j] = 0.0;
			train_V1_synapse[i][j] = 0.0;
			train_X_Input_V1[i][j] = 0.0; 
			train_Delta_Input_V1[i][j] = 0.0;

			BIT_V1[i][j] = 0.0;
			BIT_COUNT_V1[i][j] = 0.0;
			spike_count_V1[i][j] = 0.0;
			LFP_V1_synapse[i][j] = 0.0;

			train_V1_PV_V[i][j] = 0.0;
			train_V1_PV_U[i][j] = 0.0;
			train_V1_PV_I[i][j] = 0.0;;
			train_V1_PV_X[i][j] = 0.0;
			train_V1_PV_Delta[i][j] = 0.0;
			train_V1_PV_S_ex[i][j] = 0.0;

			train_V1_SOM_V[i][j] = 0.0;
			train_V1_SOM_U[i][j] = 0.0;
			train_V1_SOM_I[i][j] = 0.0;;
			train_V1_SOM_X[i][j] = 0.0;
			train_V1_SOM_Delta[i][j] = 0.0;
			train_V1_SOM_S_ex[i][j] = 0.0;
        }
    }
	//VHO
	for(i = 0; i < VHO_X_RANGE; i++){
		for(j = 0; j < VHO_Y_RANGE; j++){
			train_V_VHO[i][j] = V_first_param; 
			train_U_VHO[i][j] = 0.0;
			train_I_VHO[i][j] = 0.0; 
			train_X_VHO[i][j] = 0.0; 
			train_Delta_VHO[i][j] = 0.0; 
			train_S_ex_VHO[i][j] = 0.0;
			train_S_inh_from_pv_VHO[i][j] = 0.0;
			train_S_inh_from_som_VHO[i][j] = 0.0;
			train_S_inh_VHO[i][j] = 0.0;
			train_BOT_VHO[i][j] = 0.0;
			train_TOP_VHO[i][j] = 0.0;
			train_VHO_synapse[i][j] = 0.0;

			BIT_VHO[i][j] = 0.0;
			BIT_COUNT_VHO[i][j] = 0.0;
			spike_count_VHO[i][j] = 0.0;
			LFP_VHO_synapse[i][j] = 0.0;

			train_VHO_PV_V[i][j] = 0.0;
			train_VHO_PV_U[i][j] = 0.0;
			train_VHO_PV_I[i][j] = 0.0;;
			train_VHO_PV_X[i][j] = 0.0;
			train_VHO_PV_Delta[i][j] = 0.0;
			train_VHO_PV_S_ex[i][j] = 0.0;

			train_VHO_SOM_V[i][j] = 0.0;
			train_VHO_SOM_U[i][j] = 0.0;
			train_VHO_SOM_I[i][j] = 0.0;;
			train_VHO_SOM_X[i][j] = 0.0;
			train_VHO_SOM_Delta[i][j] = 0.0;
			train_VHO_SOM_S_ex[i][j] = 0.0;
        }
    }
    //Cross correlation and LFP coherence
	for(i = 0; i < 5; i++){
		LINE_BIT_V1[i] = 0.0;
		LINE_BIT_VHO[i] = 0.0;
	}
	for(i = 0; i < 5; i++){
		LFP_synapse_V1[i] = 0.0;
		LFP_synapse_VHO[i] = 0.0;
	}
    /*End to initialize of array*/

    //Simulation start
	for (train_count = 0; train_count < Train_Task_Total; train_count++) {
        for(train_vernier = -2; train_vernier <= 2; train_vernier++){ //Move vernier offset
			//Spike count reset
			for(i = 0; i < V1_X_RANGE; i++){
				for(j = 0; j < V1_Y_RANGE; j++){
					spike_count_V1[i][j] = 0.0;
				}
			}
			for(i = 0; i < VHO_X_RANGE; i++){
				for(j = 0; j < VHO_Y_RANGE; j++){
					spike_count_VHO[i][j] = 0.0;
				}
			}

			for(train_bisection = -2; train_bisection <= 2; train_bisection++){ //Move bisection offset
				//Initialize the input switch from the LGN
				for(i = 0; i < V1_X_RANGE; i++){
					for(j = 0; j < V1_Y_RANGE; j++){
						train_LGN_Input_Switch[i][j] = 0.0;
					}
				}
				//Input switch from the LGN
				//center
				i = 9;
				for (j = 8; j <= 11; j++) {
					train_LGN_Input_Switch[i][j] = 1.0;
				}
				//left
				i = 4 + train_bisection;
				for (j = 8; j <= 11; j++) {
					train_LGN_Input_Switch[i][j] = 1.0;
				}
				//right
				i = 14 + train_bisection;
				for (j = 8; j <= 11; j++) {
					train_LGN_Input_Switch[i][j] = 1.0;
				}
				//bottom
				i = 9 + train_vernier;
				for (j = 14; j <= 17; j++) {
					train_LGN_Input_Switch[i][j] = 1.0;
				}
				//top
				i = 9 + train_vernier;
				for (j = 2; j <= 5; j++) {
					train_LGN_Input_Switch[i][j] = 1.0;
				}

				train_time_start = train_time_total + REST_TIME; //Task start time
				train_time_end = train_time_total + TASK_TIME; //Task end time
			
                for(t = train_time_start; t <= train_time_end; t = t + dt){
					/*Start to V1 firing judgment*/
					for(i = 0; i < V1_X_RANGE; i++){
						for(j = 0; j < V1_Y_RANGE; j++){
							BIT_V1[i][j] = 0.0; 
							//V1 Pyr neuron
							if(train_V_V1[i][j] >= th_V1){
								train_V_V1[i][j] = c_RS; 
								train_U_V1[i][j] = train_U_V1[i][j] + d_RS;
								BIT_V1[i][j] = BIT_FIRE; 

								if(tuning_count >= 2000){
									spike_count_V1[i][j]++; //V1スパイクカウントを+1する
								}

                                //File output
                                if(train_count == 0){
                                    //V1 center
									if(i == 9 && j == 9){
										fprintf(train_vir_v1_center, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_center, "%lf %lf\n", t, train_X_V1[i][j]);
									}
                                    //V1 left
                                    if(i == 2 && j == 9){
										fprintf(train_vir_v1_left, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_left, "%lf %lf\n", t, train_X_V1[i][j]);
									}
                                    //V1 right
									if(i == 12 && j == 9){
										fprintf(train_vir_v1_right, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_right, "%lf %lf\n", t, train_X_V1[i][j]);
									}
                                    //V1 top
									if(i == 7 && j == 4){
										fprintf(train_vir_v1_top, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_top, "%lf %lf\n", t, train_X_V1[i][j]);
									}
									//V1 bottom
									if(i == 7 && j == 15){
										fprintf(train_vir_v1_bottom, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_bottom, "%lf %lf\n", t, train_X_V1[i][j]);
									}
								}
								train_Delta_V1[i][j] = 1.0;
								train_X_V1[i][j] = runge_X(&train_X_V1[i][j], x_lambda_V1, &train_Delta_V1[i][j], tau_XV1);
                            }else{
                                //File output
                                if(train_count == 0){
									if(i == 9 && j == 9){
										fprintf(train_vir_v1_center, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_center, "%lf %lf\n", t, train_X_V1[i][j]);
									}
                                    if(i == 2 && j == 9){
										fprintf(train_vir_v1_left, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_left, "%lf %lf\n", t, train_X_V1[i][j]);
									}
									if(i == 12 && j == 9){
										fprintf(train_vir_v1_right, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_right, "%lf %lf\n", t, train_X_V1[i][j]);
									}
									if(i == 7 && j == 5){
										fprintf(train_vir_v1_top, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_top, "%lf %lf\n", t, train_X_V1[i][j]);
									}
									if(i == 7 && j == 15){
										fprintf(train_vir_v1_bottom, "%lf %lf\n", t, train_V_V1[i][j]);
										fprintf(train_vir_X_v1_bottom, "%lf %lf\n", t, train_X_V1[i][j]);
									}
								}
								train_Delta_V1[i][j] = 0.0;
								train_X_V1[i][j] = runge_X(&train_X_V1[i][j], x_lambda_V1, &train_Delta_V1[i][j], tau_XV1);
                            }
							//V1 PV neuron
							if(train_V1_PV_V[i][j] >= th_V1){
								train_V1_PV_V[i][j] = c_FS;
								train_V1_PV_U[i][j] = train_V1_PV_U[i][j] + d_FS;
								//File output
                        		if(train_count == 0){
									if(i == 9 && j == 9){
									fprintf(train_vir_pv_v1_center, "%lf %lf\n", t, train_V1_PV_V[i][j]);
									fprintf(train_vir_X_pv_v1_center, "%lf %lf\n", t, train_V1_PV_X[i][j]);
									}
								}
								train_V1_PV_Delta[i][j] = 1.0;
								train_V1_PV_X[i][j] = runge_X(&train_V1_PV_X[i][j], x_lambda_V1_PV, &train_V1_PV_Delta[i][j], tau_XV1_PV);						
							}else{
								//File output
								if(train_count == 0){
									if(i == 9 && j == 9){
										fprintf(train_vir_pv_v1_center, "%lf %lf\n", t, train_V1_PV_V[i][j]);
										fprintf(train_vir_X_pv_v1_center, "%lf %lf\n", t, train_V1_PV_X[i][j]);
									}
								}
								train_V1_PV_Delta[i][j] = 0.0;
								train_V1_PV_X[i][j] = runge_X(&train_V1_PV_X[i][j], x_lambda_V1_PV, &train_V1_PV_Delta[i][j], tau_XV1_PV);
							}
							//V1 SOM neuron
							if(train_V1_SOM_V[i][j] >= th_V1){
								train_V1_SOM_V[i][j] = c_LTS;
								train_V1_SOM_U[i][j] = train_V1_SOM_U[i][j] + d_LTS;
								//File output
                        		if(train_count == 0){
									if(i == 9 && j == 9){
									fprintf(train_vir_som_v1_center, "%lf %lf\n", t, train_V1_SOM_V[i][j]);
									fprintf(train_vir_X_som_v1_center, "%lf %lf\n", t, train_V1_SOM_X[i][j]);
									}
									if(i == 7 && j == 4){
									fprintf(train_vir_som_v1_top, "%lf %lf\n", t, train_V1_SOM_V[i][j]);
									}
								}
								train_V1_SOM_Delta[i][j] = 1.0;
								train_V1_SOM_X[i][j] = runge_X(&train_V1_SOM_X[i][j], x_lambda_V1_SOM, &train_V1_SOM_Delta[i][j], tau_XV1_SOM);						
							}else{
								if(train_count == 0){
									if(i == 9 && j == 9){
										fprintf(train_vir_som_v1_center, "%lf %lf\n", t, train_V1_SOM_V[i][j]);
										fprintf(train_vir_X_som_v1_center, "%lf %lf\n", t, train_V1_SOM_X[i][j]);
									}
									if(i == 7 && j == 4){
									fprintf(train_vir_som_v1_top, "%lf %lf\n", t, train_V1_SOM_V[i][j]);
									}
								}
								train_V1_SOM_Delta[i][j] = 0.0;
								train_V1_SOM_X[i][j] = runge_X(&train_V1_SOM_X[i][j], x_lambda_V1_SOM, &train_V1_SOM_Delta[i][j], tau_XV1_SOM);
							}
                        } //V1 firing judgment Y_RANGE
                    } //V1 firing judgment X_RANGE
                   /*End to V1 firing judgment*/

					/*Start to VHO firing judgment*/
					for(i = 0; i < VHO_X_RANGE; i++){
						for(j = 0; j < VHO_Y_RANGE; j++){
							BIT_VHO[i][j] = 0.0;
							//VHO Pyr neuron
							if(train_V_VHO[i][j] >= th_VHO){
								train_V_VHO[i][j] = c_RS;
								train_U_VHO[i][j] = train_U_VHO[i][j] + d_RS;
								BIT_VHO[i][j] = BIT_FIRE; 

								if(tuning_count >= 2000){
									spike_count_VHO[i][j]++;
								}
                                if(train_count == 0){
									if(i == 9 && j == 1){
										fprintf(train_vir_vho_center, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_center, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
                                    if(i == 2 && j == 1){
										fprintf(train_vir_vho_left, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_left, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
									if(i == 12 && j == 1){
										fprintf(train_vir_vho_right, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_right, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
									if(i == 7 && j == 0){
										fprintf(train_vir_vho_top, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_top, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
									if(i == 7 && j == 2){
										fprintf(train_vir_vho_bottom, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_bottom, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
								}
								train_Delta_VHO[i][j] = 1.0; 
								train_X_VHO[i][j] = runge_X(&train_X_VHO[i][j], x_lambda_VHO, &train_Delta_VHO[i][j], tau_XVHO); 
                            }else{
                                if(train_count == 0){
									if(i == 9 && j == 1){
										fprintf(train_vir_vho_center, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_center, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
                                    if(i == 2 && j == 1){
										fprintf(train_vir_vho_left, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_left, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
									if(i == 12 && j == 1){
										fprintf(train_vir_vho_right, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_right, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
									if(i == 7 && j == 0){
										fprintf(train_vir_vho_top, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_top, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
									if(i == 7 && j == 2){
										fprintf(train_vir_vho_bottom, "%lf %lf\n", t, train_V_VHO[i][j]);
										fprintf(train_vir_X_vho_bottom, "%lf %lf\n", t, train_X_VHO[i][j]);
									}
								}
								train_Delta_VHO[i][j] = 0.0; 
								train_X_VHO[i][j] = runge_X(&train_X_VHO[i][j], x_lambda_VHO, &train_Delta_VHO[i][j], tau_XVHO);
                            }
							//VHO PV neuron
							if(train_VHO_PV_V[i][j] >= th_VHO){
								train_VHO_PV_V[i][j] = c_FS;
								train_VHO_PV_U[i][j] = train_VHO_PV_U[i][j] + d_FS;
                        		if(train_count == 0){
									if(i == 9 && j == 1){
									fprintf(train_vir_pv_vho_center, "%lf %lf\n", t, train_VHO_PV_V[i][j]);
									fprintf(train_vir_X_pv_vho_center, "%lf %lf\n", t, train_VHO_PV_X[i][j]);
									}
								}
								train_VHO_PV_Delta[i][j] = 1.0;
								train_VHO_PV_X[i][j] = runge_X(&train_VHO_PV_X[i][j], x_lambda_VHO_PV, &train_VHO_PV_Delta[i][j], tau_XVHO_PV);						
							}else{
								if(train_count == 0){
									if(i == 9 && j == 1){
										fprintf(train_vir_pv_vho_center, "%lf %lf\n", t, train_VHO_PV_V[i][j]);
										fprintf(train_vir_X_pv_vho_center, "%lf %lf\n", t, train_VHO_PV_X[i][j]);
									}
								}
								train_VHO_PV_Delta[i][j] = 0.0;
								train_VHO_PV_X[i][j] = runge_X(&train_VHO_PV_X[i][j], x_lambda_VHO_PV, &train_VHO_PV_Delta[i][j], tau_XVHO_PV);
							}
							//VHO SOM neuron
							if(train_VHO_SOM_V[i][j] >= th_VHO){
								train_VHO_SOM_V[i][j] = c_LTS; 
								train_VHO_SOM_U[i][j] = train_VHO_SOM_U[i][j] + d_LTS;
                        		if(train_count == 0){
									if(i == 9 && j == 1){
									fprintf(train_vir_som_vho_center, "%lf %lf\n", t, train_VHO_SOM_V[i][j]);
									fprintf(train_vir_X_som_vho_center, "%lf %lf\n", t, train_VHO_SOM_X[i][j]);
									}
								}
								train_VHO_SOM_Delta[i][j] = 1.0;
								train_VHO_SOM_X[i][j] = runge_X(&train_VHO_SOM_X[i][j], x_lambda_VHO_SOM, &train_VHO_SOM_Delta[i][j], tau_XVHO_SOM);						
							}else{
								if(train_count == 0){
									if(i == 9 && j == 1){
										fprintf(train_vir_som_vho_center, "%lf %lf\n", t, train_VHO_SOM_V[i][j]);
										fprintf(train_vir_X_som_vho_center, "%lf %lf\n", t, train_VHO_SOM_X[i][j]);
									}
								}
								train_VHO_SOM_Delta[i][j] = 0.0;
								train_VHO_SOM_X[i][j] = runge_X(&train_VHO_SOM_X[i][j], x_lambda_VHO_SOM, &train_VHO_SOM_Delta[i][j], tau_XVHO_SOM);
							}
                        } //VHO firing judgment
                    } //VHO firing judgment 
                    /*End to VHO firing judgment*/

					//V1 LFP
					for(i = 0; i < V1_X_RANGE; i++){
						for(j = 0; j < V1_Y_RANGE; j++){
							LFP_V1_synapse[i][j] = train_V1_synapse[i][j];
						}
					}
					
					for(i = 0; i < 5; i++){
						LFP_synapse_V1[i] = 0.0;
					}

					i = 9;
					for(j = 8; j <= 11; j++){
						LFP_synapse_V1[0] += LFP_V1_synapse[i][j]; 
					}
					i = 2;
					for(j = 8; j <= 11; j++){
						LFP_synapse_V1[1] += LFP_V1_synapse[i][j]; 
					}
					i = 12;
					for(j = 8; j <= 11; j++){
						LFP_synapse_V1[2] += LFP_V1_synapse[i][j]; 
					}
					i = 7;
					for(j = 2; j <= 5; j++){
						LFP_synapse_V1[3] += LFP_V1_synapse[i][j]; 
					}
					i = 7;
					for(j = 14; j <= 17; j++){
						LFP_synapse_V1[4] += LFP_V1_synapse[i][j]; 
					}

					//VHO LFP
					for(i = 0; i < VHO_X_RANGE; i++){
						for(j = 0; j < VHO_Y_RANGE; j++){
							LFP_VHO_synapse[i][j] = train_VHO_synapse[i][j];
						}
					}
					
					for(i = 0; i < 5; i++){
						LFP_synapse_VHO[i] = 0.0;
					}

					i = 9;
					j = 1;
					LFP_synapse_VHO[0] = LFP_VHO_synapse[i][j]; 
					
					i = 2;
					j = 1;
					LFP_synapse_VHO[1] = LFP_VHO_synapse[i][j]; 
					
					i = 12;
					j = 1;
					LFP_synapse_VHO[2] = LFP_VHO_synapse[i][j]; 
					
					i = 7;
					j = 0;
					LFP_synapse_VHO[3] = LFP_VHO_synapse[i][j]; 
					
					i = 7;
					j = 2;
					LFP_synapse_VHO[4] = LFP_VHO_synapse[i][j]; 

					if((t_lfp % T_LFP) == 0){
						if(t > 200.0 && t <= 400.0){
							fprintf(vir_lfp_v1_center_synapse, "%lf\n", LFP_synapse_V1[0] / 4.0);
							fprintf(vir_lfp_v1_left_synapse, "%lf\n", LFP_synapse_V1[1] / 4.0);
							fprintf(vir_lfp_v1_right_synapse, "%lf\n", LFP_synapse_V1[2] / 4.0);
							fprintf(vir_lfp_v1_top_synapse, "%lf\n", LFP_synapse_V1[3] / 4.0);
							fprintf(vir_lfp_v1_bottom_synapse, "%lf\n", LFP_synapse_V1[4] / 4.0);

							fprintf(vir_lfp_vho_center_synapse, "%lf\n", LFP_synapse_VHO[0]);
							fprintf(vir_lfp_vho_left_synapse, "%lf\n", LFP_synapse_VHO[1]);
							fprintf(vir_lfp_vho_right_synapse, "%lf\n", LFP_synapse_VHO[2]);
							fprintf(vir_lfp_vho_top_synapse, "%lf\n", LFP_synapse_VHO[3]);
							fprintf(vir_lfp_vho_bottom_synapse, "%lf\n", LFP_synapse_VHO[4]);
						}
						if(t > 600.0 && t <= 800.0){
							fprintf(vir_lfp_v1_center_synapse, "%lf\n", LFP_synapse_V1[0] / 4.0);
							fprintf(vir_lfp_v1_left_synapse, "%lf\n", LFP_synapse_V1[1] / 4.0);
							fprintf(vir_lfp_v1_right_synapse, "%lf\n", LFP_synapse_V1[2] / 4.0);
							fprintf(vir_lfp_v1_top_synapse, "%lf\n", LFP_synapse_V1[3] / 4.0);
							fprintf(vir_lfp_v1_bottom_synapse, "%lf\n", LFP_synapse_V1[4] / 4.0);

							fprintf(vir_lfp_vho_center_synapse, "%lf\n", LFP_synapse_VHO[0]);
							fprintf(vir_lfp_vho_left_synapse, "%lf\n", LFP_synapse_VHO[1]);
							fprintf(vir_lfp_vho_right_synapse, "%lf\n", LFP_synapse_VHO[2]);
							fprintf(vir_lfp_vho_top_synapse, "%lf\n", LFP_synapse_VHO[3]);
							fprintf(vir_lfp_vho_bottom_synapse, "%lf\n", LFP_synapse_VHO[4]);
						}
						if(t > 1000.0 && t <= 1200.0){
							fprintf(vir_lfp_v1_center_synapse, "%lf\n", LFP_synapse_V1[0] / 4.0);
							fprintf(vir_lfp_v1_left_synapse, "%lf\n", LFP_synapse_V1[1] / 4.0);
							fprintf(vir_lfp_v1_right_synapse, "%lf\n", LFP_synapse_V1[2] / 4.0);
							fprintf(vir_lfp_v1_top_synapse, "%lf\n", LFP_synapse_V1[3] / 4.0);
							fprintf(vir_lfp_v1_bottom_synapse, "%lf\n", LFP_synapse_V1[4] / 4.0);

							fprintf(vir_lfp_vho_center_synapse, "%lf\n", LFP_synapse_VHO[0]);
							fprintf(vir_lfp_vho_left_synapse, "%lf\n", LFP_synapse_VHO[1]);
							fprintf(vir_lfp_vho_right_synapse, "%lf\n", LFP_synapse_VHO[2]);
							fprintf(vir_lfp_vho_top_synapse, "%lf\n", LFP_synapse_VHO[3]);
							fprintf(vir_lfp_vho_bottom_synapse, "%lf\n", LFP_synapse_VHO[4]);
						}
						if(t > 1400.0 && t <= 1600.0){
							fprintf(vir_lfp_v1_center_synapse, "%lf\n", LFP_synapse_V1[0] / 4.0);
							fprintf(vir_lfp_v1_left_synapse, "%lf\n", LFP_synapse_V1[1] / 4.0);
							fprintf(vir_lfp_v1_right_synapse, "%lf\n", LFP_synapse_V1[2] / 4.0);
							fprintf(vir_lfp_v1_top_synapse, "%lf\n", LFP_synapse_V1[3] / 4.0);
							fprintf(vir_lfp_v1_bottom_synapse, "%lf\n", LFP_synapse_V1[4] / 4.0);

							fprintf(vir_lfp_vho_center_synapse, "%lf\n", LFP_synapse_VHO[0]);
							fprintf(vir_lfp_vho_left_synapse, "%lf\n", LFP_synapse_VHO[1]);
							fprintf(vir_lfp_vho_right_synapse, "%lf\n", LFP_synapse_VHO[2]);
							fprintf(vir_lfp_vho_top_synapse, "%lf\n", LFP_synapse_VHO[3]);
							fprintf(vir_lfp_vho_bottom_synapse, "%lf\n", LFP_synapse_VHO[4]);
						}
						if(t > 1800.0 && t <= 2000.0){
							fprintf(vir_lfp_v1_center_synapse, "%lf\n", LFP_synapse_V1[0] / 4.0);
							fprintf(vir_lfp_v1_left_synapse, "%lf\n", LFP_synapse_V1[1] / 4.0);
							fprintf(vir_lfp_v1_right_synapse, "%lf\n", LFP_synapse_V1[2] / 4.0);
							fprintf(vir_lfp_v1_top_synapse, "%lf\n", LFP_synapse_V1[3] / 4.0);
							fprintf(vir_lfp_v1_bottom_synapse, "%lf\n", LFP_synapse_V1[4] / 4.0);

							fprintf(vir_lfp_vho_center_synapse, "%lf\n", LFP_synapse_VHO[0]);
							fprintf(vir_lfp_vho_left_synapse, "%lf\n", LFP_synapse_VHO[1]);
							fprintf(vir_lfp_vho_right_synapse, "%lf\n", LFP_synapse_VHO[2]);
							fprintf(vir_lfp_vho_top_synapse, "%lf\n", LFP_synapse_VHO[3]);
							fprintf(vir_lfp_vho_bottom_synapse, "%lf\n", LFP_synapse_VHO[4]);
						}
						t_lfp = 0;
					}

					t_lfp++;

                    //cross correlation
					BIT_COUNT_V1[9][8] += BIT_V1[9][8];
					BIT_COUNT_V1[9][9] += BIT_V1[9][9];
					BIT_COUNT_V1[9][10] += BIT_V1[9][10];
					BIT_COUNT_V1[9][11] += BIT_V1[9][11];

					BIT_COUNT_V1[2][8] += BIT_V1[2][8];
					BIT_COUNT_V1[2][9] += BIT_V1[2][9];
					BIT_COUNT_V1[2][10] += BIT_V1[2][10];
					BIT_COUNT_V1[2][11] += BIT_V1[2][11];

					BIT_COUNT_V1[12][8] += BIT_V1[12][8];
					BIT_COUNT_V1[12][9] += BIT_V1[12][9];
					BIT_COUNT_V1[12][10] += BIT_V1[12][10];
					BIT_COUNT_V1[12][11] += BIT_V1[12][11];

					BIT_COUNT_V1[7][2] += BIT_V1[7][2];
					BIT_COUNT_V1[7][3] += BIT_V1[7][3];
					BIT_COUNT_V1[7][4] += BIT_V1[7][4];
					BIT_COUNT_V1[7][5] += BIT_V1[7][5];

					BIT_COUNT_V1[7][14] += BIT_V1[7][14];
					BIT_COUNT_V1[7][15] += BIT_V1[7][15];
					BIT_COUNT_V1[7][16] += BIT_V1[7][16];
					BIT_COUNT_V1[7][17] += BIT_V1[7][17];

					BIT_COUNT_VHO[9][1] += BIT_VHO[9][1];
					BIT_COUNT_VHO[2][1] += BIT_VHO[2][1];
					BIT_COUNT_VHO[12][1] += BIT_VHO[12][1];
					BIT_COUNT_VHO[7][0] += BIT_VHO[7][0];
					BIT_COUNT_VHO[7][2] += BIT_VHO[7][2];
					
					if((t_bit % T_BIT) == 0){
						if(t > 200.0 && t <= 400.0){
							LINE_BIT_V1[0] = BIT_COUNT_V1[9][8] + BIT_COUNT_V1[9][9] + BIT_COUNT_V1[9][10] + BIT_COUNT_V1[9][11];
							LINE_BIT_V1[1] = BIT_COUNT_V1[2][8] + BIT_COUNT_V1[2][9] + BIT_COUNT_V1[2][10] + BIT_COUNT_V1[2][11];
							LINE_BIT_V1[2] = BIT_COUNT_V1[12][8] + BIT_COUNT_V1[12][9] + BIT_COUNT_V1[12][10] + BIT_COUNT_V1[12][11];
							LINE_BIT_V1[3] = BIT_COUNT_V1[7][2] + BIT_COUNT_V1[7][3] + BIT_COUNT_V1[7][4] + BIT_COUNT_V1[7][5];
							LINE_BIT_V1[4] = BIT_COUNT_V1[7][14] + BIT_COUNT_V1[7][15] + BIT_COUNT_V1[7][16] + BIT_COUNT_V1[7][17];

							LINE_BIT_VHO[0] = BIT_COUNT_VHO[9][1];
							LINE_BIT_VHO[1] = BIT_COUNT_VHO[2][1];
							LINE_BIT_VHO[2] = BIT_COUNT_VHO[12][1];
							LINE_BIT_VHO[3] = BIT_COUNT_VHO[7][0];
							LINE_BIT_VHO[4] = BIT_COUNT_VHO[7][2];

							fprintf(bit_V1center, "%lf\n", (LINE_BIT_V1[0] / 4.0));
							fprintf(bit_V1left, "%lf\n", (LINE_BIT_V1[1] / 4.0));
							fprintf(bit_V1right, "%lf\n", (LINE_BIT_V1[2] / 4.0));
							fprintf(bit_V1top, "%lf\n", (LINE_BIT_V1[3] / 4.0));
							fprintf(bit_V1bottom, "%lf\n", (LINE_BIT_V1[4] / 4.0));

							fprintf(bit_VHOcenter, "%lf\n", LINE_BIT_VHO[0]);
							fprintf(bit_VHOleft, "%lf\n", LINE_BIT_VHO[1]);
							fprintf(bit_VHOright, "%lf\n", LINE_BIT_VHO[2]);
							fprintf(bit_VHOtop, "%lf\n", LINE_BIT_VHO[3]);
							fprintf(bit_VHObottom, "%lf\n", LINE_BIT_VHO[4]);
						}
						if(t > 600.0 && t <= 800.0){
							LINE_BIT_V1[0] = BIT_COUNT_V1[9][8] + BIT_COUNT_V1[9][9] + BIT_COUNT_V1[9][10] + BIT_COUNT_V1[9][11];
							LINE_BIT_V1[1] = BIT_COUNT_V1[2][8] + BIT_COUNT_V1[2][9] + BIT_COUNT_V1[2][10] + BIT_COUNT_V1[2][11];
							LINE_BIT_V1[2] = BIT_COUNT_V1[12][8] + BIT_COUNT_V1[12][9] + BIT_COUNT_V1[12][10] + BIT_COUNT_V1[12][11];
							LINE_BIT_V1[3] = BIT_COUNT_V1[7][2] + BIT_COUNT_V1[7][3] + BIT_COUNT_V1[7][4] + BIT_COUNT_V1[7][5];
							LINE_BIT_V1[4] = BIT_COUNT_V1[7][14] + BIT_COUNT_V1[7][15] + BIT_COUNT_V1[7][16] + BIT_COUNT_V1[7][17];

							LINE_BIT_VHO[0] = BIT_COUNT_VHO[9][1];
							LINE_BIT_VHO[1] = BIT_COUNT_VHO[2][1];
							LINE_BIT_VHO[2] = BIT_COUNT_VHO[12][1];
							LINE_BIT_VHO[3] = BIT_COUNT_VHO[7][0];
							LINE_BIT_VHO[4] = BIT_COUNT_VHO[7][2];

							fprintf(bit_V1center, "%lf\n", (LINE_BIT_V1[0] / 4.0));
							fprintf(bit_V1left, "%lf\n", (LINE_BIT_V1[1] / 4.0));
							fprintf(bit_V1right, "%lf\n", (LINE_BIT_V1[2] / 4.0));
							fprintf(bit_V1top, "%lf\n", (LINE_BIT_V1[3] / 4.0));
							fprintf(bit_V1bottom, "%lf\n", (LINE_BIT_V1[4] / 4.0));

							fprintf(bit_VHOcenter, "%lf\n", LINE_BIT_VHO[0]);
							fprintf(bit_VHOleft, "%lf\n", LINE_BIT_VHO[1]);
							fprintf(bit_VHOright, "%lf\n", LINE_BIT_VHO[2]);
							fprintf(bit_VHOtop, "%lf\n", LINE_BIT_VHO[3]);
							fprintf(bit_VHObottom, "%lf\n", LINE_BIT_VHO[4]);
						}
						if(t > 1000.0 && t <= 1200.0){
							LINE_BIT_V1[0] = BIT_COUNT_V1[9][8] + BIT_COUNT_V1[9][9] + BIT_COUNT_V1[9][10] + BIT_COUNT_V1[9][11];
							LINE_BIT_V1[1] = BIT_COUNT_V1[2][8] + BIT_COUNT_V1[2][9] + BIT_COUNT_V1[2][10] + BIT_COUNT_V1[2][11];
							LINE_BIT_V1[2] = BIT_COUNT_V1[12][8] + BIT_COUNT_V1[12][9] + BIT_COUNT_V1[12][10] + BIT_COUNT_V1[12][11];
							LINE_BIT_V1[3] = BIT_COUNT_V1[7][2] + BIT_COUNT_V1[7][3] + BIT_COUNT_V1[7][4] + BIT_COUNT_V1[7][5];
							LINE_BIT_V1[4] = BIT_COUNT_V1[7][14] + BIT_COUNT_V1[7][15] + BIT_COUNT_V1[7][16] + BIT_COUNT_V1[7][17];

							LINE_BIT_VHO[0] = BIT_COUNT_VHO[9][1];
							LINE_BIT_VHO[1] = BIT_COUNT_VHO[2][1];
							LINE_BIT_VHO[2] = BIT_COUNT_VHO[12][1];
							LINE_BIT_VHO[3] = BIT_COUNT_VHO[7][0];
							LINE_BIT_VHO[4] = BIT_COUNT_VHO[7][2];

							fprintf(bit_V1center, "%lf\n", (LINE_BIT_V1[0] / 4.0));
							fprintf(bit_V1left, "%lf\n", (LINE_BIT_V1[1] / 4.0));
							fprintf(bit_V1right, "%lf\n", (LINE_BIT_V1[2] / 4.0));
							fprintf(bit_V1top, "%lf\n", (LINE_BIT_V1[3] / 4.0));
							fprintf(bit_V1bottom, "%lf\n", (LINE_BIT_V1[4] / 4.0));

							fprintf(bit_VHOcenter, "%lf\n", LINE_BIT_VHO[0]);
							fprintf(bit_VHOleft, "%lf\n", LINE_BIT_VHO[1]);
							fprintf(bit_VHOright, "%lf\n", LINE_BIT_VHO[2]);
							fprintf(bit_VHOtop, "%lf\n", LINE_BIT_VHO[3]);
							fprintf(bit_VHObottom, "%lf\n", LINE_BIT_VHO[4]);
						}
						if(t > 1400.0 && t <= 1600.0){
							LINE_BIT_V1[0] = BIT_COUNT_V1[9][8] + BIT_COUNT_V1[9][9] + BIT_COUNT_V1[9][10] + BIT_COUNT_V1[9][11];
							LINE_BIT_V1[1] = BIT_COUNT_V1[2][8] + BIT_COUNT_V1[2][9] + BIT_COUNT_V1[2][10] + BIT_COUNT_V1[2][11];
							LINE_BIT_V1[2] = BIT_COUNT_V1[12][8] + BIT_COUNT_V1[12][9] + BIT_COUNT_V1[12][10] + BIT_COUNT_V1[12][11];
							LINE_BIT_V1[3] = BIT_COUNT_V1[7][2] + BIT_COUNT_V1[7][3] + BIT_COUNT_V1[7][4] + BIT_COUNT_V1[7][5];
							LINE_BIT_V1[4] = BIT_COUNT_V1[7][14] + BIT_COUNT_V1[7][15] + BIT_COUNT_V1[7][16] + BIT_COUNT_V1[7][17];

							LINE_BIT_VHO[0] = BIT_COUNT_VHO[9][1];
							LINE_BIT_VHO[1] = BIT_COUNT_VHO[2][1];
							LINE_BIT_VHO[2] = BIT_COUNT_VHO[12][1];
							LINE_BIT_VHO[3] = BIT_COUNT_VHO[7][0];
							LINE_BIT_VHO[4] = BIT_COUNT_VHO[7][2];

							fprintf(bit_V1center, "%lf\n", (LINE_BIT_V1[0] / 4.0));
							fprintf(bit_V1left, "%lf\n", (LINE_BIT_V1[1] / 4.0));
							fprintf(bit_V1right, "%lf\n", (LINE_BIT_V1[2] / 4.0));
							fprintf(bit_V1top, "%lf\n", (LINE_BIT_V1[3] / 4.0));
							fprintf(bit_V1bottom, "%lf\n", (LINE_BIT_V1[4] / 4.0));

							fprintf(bit_VHOcenter, "%lf\n", LINE_BIT_VHO[0]);
							fprintf(bit_VHOleft, "%lf\n", LINE_BIT_VHO[1]);
							fprintf(bit_VHOright, "%lf\n", LINE_BIT_VHO[2]);
							fprintf(bit_VHOtop, "%lf\n", LINE_BIT_VHO[3]);
							fprintf(bit_VHObottom, "%lf\n", LINE_BIT_VHO[4]);
						}
						if(t > 1800.0 && t <= 2000.0){
							LINE_BIT_V1[0] = BIT_COUNT_V1[9][8] + BIT_COUNT_V1[9][9] + BIT_COUNT_V1[9][10] + BIT_COUNT_V1[9][11];
							LINE_BIT_V1[1] = BIT_COUNT_V1[2][8] + BIT_COUNT_V1[2][9] + BIT_COUNT_V1[2][10] + BIT_COUNT_V1[2][11];
							LINE_BIT_V1[2] = BIT_COUNT_V1[12][8] + BIT_COUNT_V1[12][9] + BIT_COUNT_V1[12][10] + BIT_COUNT_V1[12][11];
							LINE_BIT_V1[3] = BIT_COUNT_V1[7][2] + BIT_COUNT_V1[7][3] + BIT_COUNT_V1[7][4] + BIT_COUNT_V1[7][5];
							LINE_BIT_V1[4] = BIT_COUNT_V1[7][14] + BIT_COUNT_V1[7][15] + BIT_COUNT_V1[7][16] + BIT_COUNT_V1[7][17];

							LINE_BIT_VHO[0] = BIT_COUNT_VHO[9][1];
							LINE_BIT_VHO[1] = BIT_COUNT_VHO[2][1];
							LINE_BIT_VHO[2] = BIT_COUNT_VHO[12][1];
							LINE_BIT_VHO[3] = BIT_COUNT_VHO[7][0];
							LINE_BIT_VHO[4] = BIT_COUNT_VHO[7][2];

							fprintf(bit_V1center, "%lf\n", (LINE_BIT_V1[0] / 4.0));
							fprintf(bit_V1left, "%lf\n", (LINE_BIT_V1[1] / 4.0));
							fprintf(bit_V1right, "%lf\n", (LINE_BIT_V1[2] / 4.0));
							fprintf(bit_V1top, "%lf\n", (LINE_BIT_V1[3] / 4.0));
							fprintf(bit_V1bottom, "%lf\n", (LINE_BIT_V1[4] / 4.0));

							fprintf(bit_VHOcenter, "%lf\n", LINE_BIT_VHO[0]);
							fprintf(bit_VHOleft, "%lf\n", LINE_BIT_VHO[1]);
							fprintf(bit_VHOright, "%lf\n", LINE_BIT_VHO[2]);
							fprintf(bit_VHOtop, "%lf\n", LINE_BIT_VHO[3]);
							fprintf(bit_VHObottom, "%lf\n", LINE_BIT_VHO[4]);
						}

						for(i=0; i < V1_X_RANGE; i++){
							for(j=0; j < V1_Y_RANGE; j++){
								BIT_COUNT_V1[i][j] = 0.0;
							}
						}
						for(i=0; i < VHO_X_RANGE; i++){
							for(j=0; j < VHO_Y_RANGE; j++){
								BIT_COUNT_VHO[i][j] = 0.0;
							}
						}
						for(i=0;i<5;i++){
							LINE_BIT_V1[i] = 0.0;
							LINE_BIT_VHO[i] = 0.0;
						}

						t_bit = 0;
					}
					t_bit = t_bit + 1;
					
					//Input from LGN
					for(i = 0; i < V1_X_RANGE; i++){
						for(j = 0; j < V1_Y_RANGE; j++){
							URN_V1_LGN = genrand_real1();
							if(URN_V1_LGN < firingrate_Input_V1*firingrate_Input_dt){
								train_Delta_Input_V1[i][j] = 1.0;
								train_X_Input_V1[i][j] = runge_X(&train_X_Input_V1[i][j], x_lambda_Input, &train_Delta_Input_V1[i][j], tau_Input);
							}else{
								train_Delta_Input_V1[i][j] = 0.0;
								train_X_Input_V1[i][j] = runge_X(&train_X_Input_V1[i][j], x_lambda_Input, &train_Delta_Input_V1[i][j], tau_Input);
							}
							train_LGN_V1[i][j] = Input_weight_V1 * train_X_Input_V1[i][j] * train_LGN_Input_Switch[i][j];
						}
					}

					//Array initialization (otherwise it will not be reset even if the offset changes)
					for(i = 0; i < V1_X_RANGE; i++){
						for(j = 0; j < V1_Y_RANGE; j++){
							train_S_ex_V1[i][j] = 0.0;
							train_S_inh_from_pv_V1[i][j] = 0.0;
							train_S_inh_from_som_V1[i][j] = 0.0;
							train_S_inh_V1[i][j] = 0.0;
							train_V1_PV_S_ex[i][j] = 0.0;
							train_V1_SOM_S_ex[i][j] = 0.0;
						}
					}

					/*Start to connection within the V1 layer*/
					h = 9;
					i = 4 + train_bisection;
					j = 14 + train_bisection;
					l = 9 + train_vernier;

					for(m = 8; m < 12; m++){
						//V1 Pyr -> PV
						train_V1_PV_S_ex[h][h] += w_ex_V1_PV * train_X_V1[h][m];
						train_V1_PV_S_ex[i][h] += w_ex_V1_PV * train_X_V1[i][m];
						train_V1_PV_S_ex[j][h] += w_ex_V1_PV * train_X_V1[j][m];
						train_V1_PV_S_ex[l][h-5] += w_ex_V1_PV * train_X_V1[l][m-6];
						train_V1_PV_S_ex[l][h+6] += w_ex_V1_PV * train_X_V1[l][m+6];
						//V1 Pyr -> SOM
						train_V1_SOM_S_ex[h][h] += (DistGauss(h, h, h, m, w_ex_V1_SOM_local, dist_sigma_I) * train_X_V1[h][m]) + (DistGauss(h, h, i, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[i][m]) + (DistGauss(h, h, j, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[j][m])
												+ (DistGauss(h, h, l, m-6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m-6]) + (DistGauss(h, h, l, m+6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m+6]);
						train_V1_SOM_S_ex[i][h] += (DistGauss(i, h, h, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[h][m]) + (DistGauss(i, h, i, m, w_ex_V1_SOM_local, dist_sigma_I) * train_X_V1[i][m]) + (DistGauss(i, h, j, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[j][m])
												+ (DistGauss(i, h, l, m-6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m-6]) + (DistGauss(i, h, l, m+6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m+6]);
						train_V1_SOM_S_ex[j][h] += (DistGauss(j, h, h, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[h][m]) + (DistGauss(j, h, i, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[i][m]) + (DistGauss(j, h, j, m, w_ex_V1_SOM_local, dist_sigma_I) * train_X_V1[j][m])
												+ (DistGauss(j, h, l, m-6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m-6]) + (DistGauss(j, h, l, m+6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m+6]);
						train_V1_SOM_S_ex[l][h-5] += (DistGauss(l, h-5, h, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[h][m]) + (DistGauss(l, h-5, i, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[i][m]) + (DistGauss(l, h-5, j, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[j][m])
												+ (DistGauss(l, h-5, l, m-6, w_ex_V1_SOM_local, dist_sigma_I) * train_X_V1[l][m-6]) + (DistGauss(l, h-5, l, m+6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m+6]);
						train_V1_SOM_S_ex[l][h+6] += (DistGauss(l, h+6, h, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[h][m]) + (DistGauss(l, h+6, i, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[i][m]) + (DistGauss(l, h+6, j, m, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[j][m])
												+ (DistGauss(l, h+6, l, m-6, w_ex_V1_SOM_global, dist_sigma_I) * train_X_V1[l][m-6]) + (DistGauss(l, h+6, l, m+6, w_ex_V1_SOM_local, dist_sigma_I) * train_X_V1[l][m+6]);

						for(k = 8; k < 12; k++){
							//V1 Pyr -> Pyr
							if(m != k){	
								train_S_ex_V1[h][m] += (DistGauss(h, m, h, k, w_ex_V1, dist_sigma_E) * train_X_V1[h][k]);
								train_S_ex_V1[i][m] += (DistGauss(i, m, i, k, w_ex_V1, dist_sigma_E) * train_X_V1[i][k]);
								train_S_ex_V1[j][m] += (DistGauss(j, m, j, k, w_ex_V1, dist_sigma_E) * train_X_V1[j][k]);
								train_S_ex_V1[l][m-6] += (DistGauss(l, m-6, l, k-6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k-6]);
								train_S_ex_V1[l][m+6] += (DistGauss(l, m+6, l, k+6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k+6]);
							}
							
							train_S_ex_V1[h][m] += (DistGauss(h, m, i, k, w_ex_V1, dist_sigma_E) * train_X_V1[i][k]) + (DistGauss(h, m, j, k, w_ex_V1, dist_sigma_E) * train_X_V1[j][k])
													+ (DistGauss(h, m, l, k-6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k-6]) + (DistGauss(h, m, l, k+6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k+6]);
							train_S_ex_V1[i][m] += (DistGauss(i, m, h, k, w_ex_V1, dist_sigma_E) * train_X_V1[h][k]) + (DistGauss(i, m, j, k, w_ex_V1, dist_sigma_E) * train_X_V1[j][k])
													+ (DistGauss(i, m, l, k-6, w_ex_V1, dist_sigma_E) * train_X_V1[i][k-6]) + (DistGauss(i, m, l, k+6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k+6]);
							train_S_ex_V1[j][m] += (DistGauss(j, m, i, k, w_ex_V1, dist_sigma_E) * train_X_V1[i][k]) + (DistGauss(j, m, h, k, w_ex_V1, dist_sigma_E) * train_X_V1[h][k])
													+ (DistGauss(j, m, l, k-6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k-6]) + (DistGauss(j, m, l, k+6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k+6]);
							train_S_ex_V1[l][m-6] += (DistGauss(l, m-6, i, k, w_ex_V1, dist_sigma_E) * train_X_V1[i][k]) + (DistGauss(l, m-6, j, k, w_ex_V1, dist_sigma_E) * train_X_V1[j][k])
													+ (DistGauss(l, m-6, h, k, w_ex_V1, dist_sigma_E) * train_X_V1[h][k]) + (DistGauss(l, m-6, l, k+6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k+6]);
							train_S_ex_V1[l][m+6] += (DistGauss(l, m+6, i, k, w_ex_V1, dist_sigma_E) * train_X_V1[i][k]) + (DistGauss(l, m+6, j, k, w_ex_V1, dist_sigma_E) * train_X_V1[j][k])
													+ (DistGauss(l, m+6, l, k-6, w_ex_V1, dist_sigma_E) * train_X_V1[l][k-6]) + (DistGauss(l, m+6, h, k, w_ex_V1, dist_sigma_E) * train_X_V1[h][k]);
						}
					}

					h = 9;
					i = 4 + train_bisection;
					j = 14 + train_bisection;
					l = 9 + train_vernier;
					for(k = 8; k < 12; k++){
						//V1 PV -> Pyr
						train_S_inh_from_pv_V1[h][k] = -1 * w_inh_V1_PV_PC * train_V1_PV_X[h][h];
						train_S_inh_from_pv_V1[i][k] = -1 * w_inh_V1_PV_PC * train_V1_PV_X[i][h];
						train_S_inh_from_pv_V1[j][k] = -1 * w_inh_V1_PV_PC * train_V1_PV_X[j][h];
						train_S_inh_from_pv_V1[l][k-6] = -1 * w_inh_V1_PV_PC * train_V1_PV_X[l][h-5];
						train_S_inh_from_pv_V1[l][k+6] = -1 * w_inh_V1_PV_PC * train_V1_PV_X[l][h+6];
						//V1 SOM -> Pyr
						train_S_inh_from_som_V1[h][k] = -1 * w_inh_V1_SOM_PC * train_V1_SOM_X[h][h];
						train_S_inh_from_som_V1[i][k] = -1 * w_inh_V1_SOM_PC * train_V1_SOM_X[i][h];
						train_S_inh_from_som_V1[j][k] = -1 * w_inh_V1_SOM_PC * train_V1_SOM_X[j][h];
						train_S_inh_from_som_V1[l][k-6] = -1 * w_inh_V1_SOM_PC * train_V1_SOM_X[l][h-5];
						train_S_inh_from_som_V1[l][k+6] = -1 * w_inh_V1_SOM_PC * train_V1_SOM_X[l][h+6];
						
						train_S_inh_V1[h][k] = train_S_inh_from_pv_V1[h][k] + train_S_inh_from_som_V1[h][k];
						train_S_inh_V1[i][k] = train_S_inh_from_pv_V1[i][k] + train_S_inh_from_som_V1[i][k];
						train_S_inh_V1[j][k] = train_S_inh_from_pv_V1[j][k] + train_S_inh_from_som_V1[j][k];
						train_S_inh_V1[l][k-6] = train_S_inh_from_pv_V1[l][k-6] + train_S_inh_from_som_V1[l][k-6];
						train_S_inh_V1[l][k+6] = train_S_inh_from_pv_V1[l][k+6] + train_S_inh_from_som_V1[l][k+6];
					}
					/*End to connection within the V1 layer*/

					//Array initialization (otherwise it will not be reset even if the offset changes)
					for(i = 0; i < VHO_X_RANGE; i++){
						for(j = 0; j < VHO_Y_RANGE; j++){
							train_S_ex_VHO[i][j] = 0.0;
							train_S_inh_from_pv_VHO[i][j] = 0.0;
							train_S_inh_from_som_VHO[i][j] = 0.0;
							train_S_inh_VHO[i][j] = 0.0;
							train_VHO_PV_S_ex[i][j] = 0.0;
							train_VHO_SOM_S_ex[i][j] = 0.0;
						}
					}
					
					/*Start to connection within the VHO layer*/
					h = 9;
					i = 4 + train_bisection;
					j = 14 + train_bisection;
					l = 9 + train_vernier;

					//VHO Pyr -> PV
					train_VHO_PV_S_ex[h][1] = w_ex_VHO_PV * train_X_VHO[h][1];
					train_VHO_PV_S_ex[i][1] = w_ex_VHO_PV * train_X_VHO[i][1];
					train_VHO_PV_S_ex[j][1] = w_ex_VHO_PV * train_X_VHO[j][1];
					train_VHO_PV_S_ex[l][0] = w_ex_VHO_PV * train_X_VHO[l][0];
					train_VHO_PV_S_ex[l][2] = w_ex_VHO_PV * train_X_VHO[l][2];
					//VHO Pyr -> Pyr
                    train_S_ex_VHO[h][1] = (DistGauss(h, 1, h, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[h][1]) + (DistGauss(h, 1, i, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[i][1]) + (DistGauss(h, 1, j, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[j][1]) + (DistGauss(h, 1, l, 0, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][0]) + (DistGauss(h, 1, l, 2, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][2]);
					train_S_ex_VHO[i][1] = (DistGauss(i, 1, h, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[h][1]) + (DistGauss(i, 1, i, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[i][1]) + (DistGauss(i, 1, j, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[j][1]) + (DistGauss(i, 1, l, 0, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][0]) + (DistGauss(i, 1, l, 2, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][2]);
					train_S_ex_VHO[j][1] = (DistGauss(j, 1, h, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[h][1]) + (DistGauss(j, 1, i, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[i][1]) + (DistGauss(j, 1, j, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[j][1]) + (DistGauss(j, 1, l, 0, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][0]) + (DistGauss(j, 1, l, 2, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][2]);
					train_S_ex_VHO[l][0] = (DistGauss(l, 0, h, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[h][1]) + (DistGauss(l, 0, i, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[i][1]) + (DistGauss(l, 0, j, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[j][1]) + (DistGauss(l, 0, l, 0, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][0]) + (DistGauss(l, 0, l, 2, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][2]);
					train_S_ex_VHO[l][2] = (DistGauss(l, 2, h, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[h][1]) + (DistGauss(l, 2, i, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[i][1]) + (DistGauss(l, 2, j, 1, w_ex_VHO, dist_sigma_E) * train_X_VHO[j][1]) + (DistGauss(l, 2, l, 0, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][0]) + (DistGauss(l, 2, l, 2, w_ex_VHO, dist_sigma_E) * train_X_VHO[l][2]);
					//VHO Pyr -> SOM
					train_VHO_SOM_S_ex[h][1] = (DistGauss(h, 1, h, 1, w_ex_VHO_SOM_local, dist_sigma_I) * train_X_VHO[h][1]) + (DistGauss(h, 1, i, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[i][1]) + (DistGauss(h, 1, j, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[j][1]) + (DistGauss(h, 1, l, 0, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][0]) + (DistGauss(h, 1, l, 2, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][2]);
					train_VHO_SOM_S_ex[i][1] = (DistGauss(i, 1, h, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[h][1]) + (DistGauss(i, 1, i, 1, w_ex_VHO_SOM_local, dist_sigma_I) * train_X_VHO[i][1]) + (DistGauss(i, 1, j, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[j][1]) + (DistGauss(i, 1, l, 0, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][0]) + (DistGauss(i, 1, l, 2, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][2]);
					train_VHO_SOM_S_ex[j][1] = (DistGauss(j, 1, h, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[h][1]) + (DistGauss(j, 1, i, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[i][1]) + (DistGauss(j, 1, j, 1, w_ex_VHO_SOM_local, dist_sigma_I) * train_X_VHO[j][1]) + (DistGauss(j, 1, l, 0, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][0]) + (DistGauss(j, 1, l, 2, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][2]);
					train_VHO_SOM_S_ex[l][0] = (DistGauss(l, 0, h, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[h][1]) + (DistGauss(l, 0, i, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[i][1]) + (DistGauss(l, 0, j, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[j][1]) + (DistGauss(l, 0, l, 0, w_ex_VHO_SOM_local, dist_sigma_I) * train_X_VHO[l][0]) + (DistGauss(l, 0, l, 2, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][2]);
					train_VHO_SOM_S_ex[l][2] = (DistGauss(l, 2, h, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[h][1]) + (DistGauss(l, 2, i, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[i][1]) + (DistGauss(l, 2, j, 1, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[j][1]) + (DistGauss(l, 2, l, 0, w_ex_VHO_SOM_global, dist_sigma_I) * train_X_VHO[l][0]) + (DistGauss(l, 2, l, 2, w_ex_VHO_SOM_local, dist_sigma_I) * train_X_VHO[l][2]);

					h = 9;
					i = 4 + train_bisection;
					j = 14 + train_bisection;
					l = 9 + train_vernier;
					//VHO PV -> Pyr
					train_S_inh_from_pv_VHO[h][1] = -1 * w_inh_VHO_PV_PC * train_VHO_PV_X[h][1];
					train_S_inh_from_pv_VHO[i][1] = -1 * w_inh_VHO_PV_PC * train_VHO_PV_X[i][1];
					train_S_inh_from_pv_VHO[j][1] = -1 * w_inh_VHO_PV_PC * train_VHO_PV_X[j][1];
					train_S_inh_from_pv_VHO[l][0] = -1 * w_inh_VHO_PV_PC * train_VHO_PV_X[l][0];
					train_S_inh_from_pv_VHO[l][2] = -1 * w_inh_VHO_PV_PC * train_VHO_PV_X[l][2];
					//VHO SOM -> Pyr
					train_S_inh_from_som_VHO[h][1] = -1 * w_inh_VHO_SOM_PC * train_VHO_SOM_X[h][1];
					train_S_inh_from_som_VHO[i][1] = -1 * w_inh_VHO_SOM_PC * train_VHO_SOM_X[i][1];
					train_S_inh_from_som_VHO[j][1] = -1 * w_inh_VHO_SOM_PC * train_VHO_SOM_X[j][1];
					train_S_inh_from_som_VHO[l][0] = -1 * w_inh_VHO_SOM_PC * train_VHO_SOM_X[l][0];
					train_S_inh_from_som_VHO[l][2] = -1 * w_inh_VHO_SOM_PC * train_VHO_SOM_X[l][2];
					
					train_S_inh_VHO[h][1] = train_S_inh_from_pv_VHO[h][1] + train_S_inh_from_som_VHO[h][1];
					train_S_inh_VHO[i][1] = train_S_inh_from_pv_VHO[i][1] + train_S_inh_from_som_VHO[i][1];
					train_S_inh_VHO[j][1] = train_S_inh_from_pv_VHO[j][1] + train_S_inh_from_som_VHO[j][1];
					train_S_inh_VHO[l][0] = train_S_inh_from_pv_VHO[l][0] + train_S_inh_from_som_VHO[l][0];
					train_S_inh_VHO[l][2] = train_S_inh_from_pv_VHO[l][2] + train_S_inh_from_som_VHO[l][2];
					/*End to connection within the VHO layer*/

					//V1 -> VHO feedforward
					for(i = 0; i < VHO_X_RANGE; i++){
						for(j = 0; j < VHO_Y_RANGE; j++){
							train_BOT_VHO[i][j] = 0.0;
						}
					}

					h = 9;
					i = 4 + train_bisection;
					j = 14 + train_bisection;
					l = 9 + train_vernier;

					for(m = 8; m < 12; m++){
						train_BOT_VHO[h][1] += w_BOT_V1_VHO * train_X_V1[h][m];
						train_BOT_VHO[i][1] += w_BOT_V1_VHO * train_X_V1[i][m];
						train_BOT_VHO[j][1] += w_BOT_V1_VHO * train_X_V1[j][m];
						train_BOT_VHO[l][0] += w_BOT_V1_VHO * train_X_V1[l][m-6];
						train_BOT_VHO[l][2] += w_BOT_V1_VHO * train_X_V1[l][m+6];
					}

					//VHO -> V1 feedback
					for(i = 0; i < V1_X_RANGE; i++){
						for(j = 0; j < V1_Y_RANGE; j++){
							train_TOP_V1[i][j] = 0.0;
						}
					}

					h = 9;
					i = 4 + train_bisection;
					j = 14 + train_bisection;
					l = 9 + train_vernier;

					for(k = 8; k < 12; k++){
						train_TOP_V1[h][k] = w_TOP_VHO_V1 * train_X_VHO[h][1];
						train_TOP_V1[i][k] = w_TOP_VHO_V1 * train_X_VHO[i][1];
						train_TOP_V1[j][k] = w_TOP_VHO_V1 * train_X_VHO[j][1];
						train_TOP_V1[l][k-6] = w_TOP_VHO_V1 * train_X_VHO[l][0];
						train_TOP_V1[l][k+6] = w_TOP_VHO_V1 * train_X_VHO[l][2];
					}

					/*Start to V1 membrane update*/
					for(i = 0; i < V1_X_RANGE; i++){
						for(j = 0; j < V1_Y_RANGE; j++){
							train_I_V1[i][j] =  train_LGN_V1[i][j] + train_S_ex_V1[i][j] + train_S_inh_V1[i][j] + train_TOP_V1[i][j];
							train_V1_synapse[i][j] = train_LGN_V1[i][j] + train_S_ex_V1[i][j] + train_S_inh_V1[i][j] + train_TOP_V1[i][j];
							
							train_V1_PV_I[i][j] = train_V1_PV_S_ex[i][j];

							train_V1_SOM_I[i][j] = train_V1_SOM_S_ex[i][j];

                            if(train_count == 0){
								if(i == 9 && j == 9){
									fprintf(train_vir_Input_v1_center, "%lf %lf\n", t, train_I_V1[i][j]);
                                    fprintf(train_vir_S_ex_v1_center, "%lf %lf\n", t, train_S_ex_V1[i][j]);
									fprintf(train_vir_S_inh_from_pv_v1_center, "%lf %lf\n", t, train_S_inh_from_pv_V1[i][j]);
									fprintf(train_vir_S_inh_from_som_v1_center, "%lf %lf\n", t, train_S_inh_from_som_V1[i][j]);
									fprintf(train_vir_S_v1_center, "%lf %lf\n", t, (train_S_ex_V1[i][j] + train_S_inh_V1[i][j]));
									fprintf(train_vir_Top_v1_center, "%lf %lf\n", t, train_TOP_V1[i][j]);

									fprintf(train_vir_Input_pv_v1_center, "%lf %lf\n", t, train_V1_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_v1_center, "%lf %lf\n", t, train_V1_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_v1_center, "%lf %lf\n", t, train_V1_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_v1_center, "%lf %lf\n", t, train_V1_SOM_S_ex[i][j]);
									fprintf(train_vir_S_som_v1_center, "%lf %lf\n", t, train_V1_SOM_S_ex[i][j]);
								}
								if(i == 12 && j == 9){								
									fprintf(train_vir_Input_v1_right, "%lf %lf\n", t, train_I_V1[i][j]);
                                    fprintf(train_vir_S_ex_v1_right, "%lf %lf\n", t, train_S_ex_V1[i][j]);
									fprintf(train_vir_S_inh_v1_right, "%lf %lf\n", t, train_S_inh_V1[i][j]);
									fprintf(train_vir_S_v1_right, "%lf %lf\n", t, (train_S_ex_V1[i][j] + train_S_inh_V1[i][j]));

									fprintf(train_vir_Input_pv_v1_right, "%lf %lf\n", t, train_V1_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_v1_right, "%lf %lf\n", t, train_V1_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_v1_right, "%lf %lf\n", t, train_V1_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_v1_right, "%lf %lf\n", t, train_V1_SOM_S_ex[i][j]);
								}
								if(i == 2 && j == 9){
									fprintf(train_vir_Input_v1_left, "%lf %lf\n", t, train_I_V1[i][j]);
                                    fprintf(train_vir_S_ex_v1_left, "%lf %lf\n", t, train_S_ex_V1[i][j]);
									fprintf(train_vir_S_inh_v1_left, "%lf %lf\n", t, train_S_inh_V1[i][j]);
									fprintf(train_vir_S_v1_left, "%lf %lf\n", t, (train_S_ex_V1[i][j] + train_S_inh_V1[i][j]));

									fprintf(train_vir_Input_pv_v1_left, "%lf %lf\n", t, train_V1_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_v1_left, "%lf %lf\n", t, train_V1_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_v1_left, "%lf %lf\n", t, train_V1_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_v1_left, "%lf %lf\n", t, train_V1_SOM_S_ex[i][j]);
								}
								if(i == 7 && j == 4){
                                    fprintf(train_vir_Input_v1_top, "%lf %lf\n", t, train_I_V1[i][j]);
                                    fprintf(train_vir_S_ex_v1_top, "%lf %lf\n", t, train_S_ex_V1[i][j]);
									fprintf(train_vir_S_inh_v1_top, "%lf %lf\n", t, train_S_inh_V1[i][j]);
									fprintf(train_vir_S_v1_top, "%lf %lf\n", t, (train_S_ex_V1[i][j] + train_S_inh_V1[i][j]));

									fprintf(train_vir_Input_pv_v1_top, "%lf %lf\n", t, train_V1_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_v1_top, "%lf %lf\n", t, train_V1_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_v1_top, "%lf %lf\n", t, train_V1_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_v1_top, "%lf %lf\n", t, train_V1_SOM_S_ex[i][j]);
                                }
								if(i == 7 && j == 15){
                                    fprintf(train_vir_Input_v1_bottom, "%lf %lf\n", t, train_I_V1[i][j]);
                                    fprintf(train_vir_S_ex_v1_bottom, "%lf %lf\n", t, train_S_ex_V1[i][j]);
									fprintf(train_vir_S_inh_v1_bottom, "%lf %lf\n", t, train_S_inh_V1[i][j]);
									fprintf(train_vir_S_v1_bottom, "%lf %lf\n", t, (train_S_ex_V1[i][j] + train_S_inh_V1[i][j]));

									fprintf(train_vir_Input_pv_v1_bottom, "%lf %lf\n", t, train_V1_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_v1_bottom, "%lf %lf\n", t, train_V1_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_v1_bottom, "%lf %lf\n", t, train_V1_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_v1_bottom, "%lf %lf\n", t, train_V1_SOM_S_ex[i][j]);
                                }
							}
                            train_V_V1[i][j] = runge_V(&train_V_V1[i][j], &train_U_V1[i][j], &train_I_V1[i][j]);
							train_U_V1[i][j] = runge_U(&train_V_V1[i][j], &train_U_V1[i][j], a_RS, b_RS);

							train_V1_PV_V[i][j] = runge_V(&train_V1_PV_V[i][j], &train_V1_PV_U[i][j], &train_V1_PV_I[i][j]);
							train_V1_PV_U[i][j] = runge_U(&train_V1_PV_V[i][j], &train_V1_PV_U[i][j], a_FS, b_FS);

							train_V1_SOM_V[i][j] = runge_V(&train_V1_SOM_V[i][j], &train_V1_SOM_U[i][j], &train_V1_SOM_I[i][j]);
							train_V1_SOM_U[i][j] = runge_U(&train_V1_SOM_V[i][j], &train_V1_SOM_U[i][j], a_LTS, b_LTS);
						}
					}
                	/*End to V1 membrane update*/

					/*Start to VHO membrane update*/
					for(i = 0; i < VHO_X_RANGE; i++){
						for(j = 0; j < VHO_Y_RANGE; j++){
							train_I_VHO[i][j] =  train_S_ex_VHO[i][j] + train_S_inh_VHO[i][j] + train_BOT_VHO[i][j];
							train_VHO_synapse[i][j] = train_S_ex_VHO[i][j] + train_S_inh_VHO[i][j] + train_BOT_VHO[i][j];
							
							train_VHO_PV_I[i][j] = train_VHO_PV_S_ex[i][j];

							train_VHO_SOM_I[i][j] = train_VHO_SOM_S_ex[i][j];

                            if(train_count == 0){
								if(i == 9 && j == 1){
									fprintf(train_vir_Input_vho_center, "%lf %lf\n", t, train_I_VHO[i][j]);
                                    fprintf(train_vir_S_ex_vho_center, "%lf %lf\n", t, train_S_ex_VHO[i][j]);
									fprintf(train_vir_S_inh_from_pv_vho_center, "%lf %lf\n", t, train_S_inh_from_pv_VHO[i][j]);
									fprintf(train_vir_S_inh_from_som_vho_center, "%lf %lf\n", t, train_S_inh_from_som_VHO[i][j]);
									fprintf(train_vir_Bot_vho_center, "%lf %lf\n", t, train_BOT_VHO[i][j]);
									fprintf(train_vir_Top_vho_center, "%lf %lf\n", t, train_TOP_VHO[i][j]);
									fprintf(train_vir_S_vho_center, "%lf %lf\n", t, (train_S_ex_VHO[i][j] + train_S_inh_VHO[i][j]));

									fprintf(train_vir_Input_pv_vho_center, "%lf %lf\n", t, train_VHO_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_vho_center, "%lf %lf\n", t, train_VHO_PV_S_ex[i][j]);
									fprintf(train_vir_S_pv_vho_center, "%lf %lf\n", t, train_VHO_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_vho_center, "%lf %lf\n", t, train_VHO_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_vho_center, "%lf %lf\n", t, train_VHO_SOM_S_ex[i][j]);
									fprintf(train_vir_S_som_vho_center, "%lf %lf\n", t, train_VHO_SOM_S_ex[i][j]);
								}
								if(i == 12 && j == 1){								
									fprintf(train_vir_Input_vho_right, "%lf %lf\n", t, train_I_VHO[i][j]);
                                    fprintf(train_vir_S_ex_vho_right, "%lf %lf\n", t, train_S_ex_VHO[i][j]);
									fprintf(train_vir_S_inh_vho_right, "%lf %lf\n", t, train_S_inh_VHO[i][j]);
									fprintf(train_vir_Bot_vho_right, "%lf %lf\n", t, train_BOT_VHO[i][j]);
									fprintf(train_vir_S_vho_right, "%lf %lf\n", t, (train_S_ex_VHO[i][j] + train_S_inh_VHO[i][j]));

									fprintf(train_vir_Input_pv_vho_right, "%lf %lf\n", t, train_VHO_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_vho_right, "%lf %lf\n", t, train_VHO_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_vho_right, "%lf %lf\n", t, train_VHO_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_vho_right, "%lf %lf\n", t, train_VHO_SOM_S_ex[i][j]);
								}
								if(i == 2 && j == 1){
									fprintf(train_vir_Input_vho_left, "%lf %lf\n", t, train_I_VHO[i][j]);
                                    fprintf(train_vir_S_ex_vho_left, "%lf %lf\n", t, train_S_ex_VHO[i][j]);
									fprintf(train_vir_S_inh_vho_left, "%lf %lf\n", t, train_S_inh_VHO[i][j]);
									fprintf(train_vir_Bot_vho_left, "%lf %lf\n", t, train_BOT_VHO[i][j]);
									fprintf(train_vir_S_vho_left, "%lf %lf\n", t, (train_S_ex_VHO[i][j] + train_S_inh_VHO[i][j]));

									fprintf(train_vir_Input_pv_vho_left, "%lf %lf\n", t, train_VHO_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_vho_left, "%lf %lf\n", t, train_VHO_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_vho_left, "%lf %lf\n", t, train_VHO_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_vho_left, "%lf %lf\n", t, train_VHO_SOM_S_ex[i][j]);
								}
								if(i == 7 && j == 0){
                                    fprintf(train_vir_Input_vho_top, "%lf %lf\n", t, train_I_VHO[i][j]);
                                    fprintf(train_vir_S_ex_vho_top, "%lf %lf\n", t, train_S_ex_VHO[i][j]);
									fprintf(train_vir_S_inh_vho_top, "%lf %lf\n", t, train_S_inh_VHO[i][j]);
									fprintf(train_vir_Bot_vho_top, "%lf %lf\n", t, train_BOT_VHO[i][j]);
									fprintf(train_vir_S_vho_top, "%lf %lf\n", t, (train_S_ex_VHO[i][j] + train_S_inh_VHO[i][j]));

									fprintf(train_vir_Input_pv_vho_top, "%lf %lf\n", t, train_VHO_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_vho_top, "%lf %lf\n", t, train_VHO_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_vho_top, "%lf %lf\n", t, train_VHO_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_vho_top, "%lf %lf\n", t, train_VHO_SOM_S_ex[i][j]);
                                }
								if(i == 7 && j == 2){
                                    fprintf(train_vir_Input_vho_bottom, "%lf %lf\n", t, train_I_VHO[i][j]);
                                    fprintf(train_vir_S_ex_vho_bottom, "%lf %lf\n", t, train_S_ex_VHO[i][j]);
									fprintf(train_vir_S_inh_vho_bottom, "%lf %lf\n", t, train_S_inh_VHO[i][j]);
									fprintf(train_vir_Bot_vho_bottom, "%lf %lf\n", t, train_BOT_VHO[i][j]);
									fprintf(train_vir_S_vho_bottom, "%lf %lf\n", t, (train_S_ex_VHO[i][j] + train_S_inh_VHO[i][j]));

									fprintf(train_vir_Input_pv_vho_bottom, "%lf %lf\n", t, train_VHO_PV_I[i][j]);
                                    fprintf(train_vir_S_ex_pv_vho_bottom, "%lf %lf\n", t, train_VHO_PV_S_ex[i][j]);

									fprintf(train_vir_Input_som_vho_bottom, "%lf %lf\n", t, train_VHO_SOM_I[i][j]);
                                    fprintf(train_vir_S_ex_som_vho_bottom, "%lf %lf\n", t, train_VHO_SOM_S_ex[i][j]);
                                }
							}
                            train_V_VHO[i][j] = runge_V(&train_V_VHO[i][j], &train_U_VHO[i][j], &train_I_VHO[i][j]);
							train_U_VHO[i][j] = runge_U(&train_V_VHO[i][j], &train_U_VHO[i][j], a_RS, b_RS);

							train_VHO_PV_V[i][j] = runge_V(&train_VHO_PV_V[i][j], &train_VHO_PV_U[i][j], &train_VHO_PV_I[i][j]);
							train_VHO_PV_U[i][j] = runge_U(&train_VHO_PV_V[i][j], &train_VHO_PV_U[i][j], a_FS, b_FS);

							train_VHO_SOM_V[i][j] = runge_V(&train_VHO_SOM_V[i][j], &train_VHO_SOM_U[i][j], &train_VHO_SOM_I[i][j]);
							train_VHO_SOM_U[i][j] = runge_U(&train_VHO_SOM_V[i][j], &train_VHO_SOM_U[i][j], a_LTS, b_LTS);
						}
					}
                    /*END to VHO membrane update*/
					tuning_count++;
				}
				tuning_count = 0;
				train_time_total += TASK_TIME; 
            } //End of train_bisection
			
			//V1 Tuning curve
			pattern_V1_center = 0.0;
			pattern_V1_left = 0.0;
			pattern_V1_right = 0.0;
			pattern_V1_top = 0.0;
			pattern_V1_bottom = 0.0;

			i = 9;
			for(j = 8; j < 12; j++){
				pattern_V1_center += spike_count_V1[i][j];
			}
			i = 2;
			for(j = 8; j < 12; j++){
				pattern_V1_left += spike_count_V1[i][j];
			}
			i = 12;
			for(j = 8; j < 12; j++){
				pattern_V1_right += spike_count_V1[i][j];
			}
			i = 7;
			for(j = 2; j < 6; j++){
				pattern_V1_top += spike_count_V1[i][j];
			}
			i = 7;
			for(j = 14; j < 18; j++){
				pattern_V1_bottom += spike_count_V1[i][j];
			}

			if(train_count == 0){
				fprintf(vir_tuning_V1_center, "center %d %lf\n", train_vernier, (pattern_V1_center/4.0));
				fprintf(vir_tuning_V1_left, "left %d %lf\n", train_vernier, (pattern_V1_left/4.0));
				fprintf(vir_tuning_V1_right, "right %d %lf\n", train_vernier, (pattern_V1_right/4.0));
				fprintf(vir_tuning_V1_top, "left %d %lf\n", train_vernier, (pattern_V1_top/4.0));
				fprintf(vir_tuning_V1_bottom, "right %d %lf\n", train_vernier, (pattern_V1_bottom/4.0));
				if(train_vernier == -2){
					fprintf(vir_tuning_V1, "top %lf\ncenter %lf\nbottom %lf\n", (pattern_V1_top/4.0), (pattern_V1_center/4.0), (pattern_V1_bottom/4.0));
				}
			}

			//VHO Tuning curve
			pattern_VHO_center = 0.0;
			pattern_VHO_left = 0.0;
			pattern_VHO_right = 0.0;
			pattern_VHO_top = 0.0;
			pattern_VHO_bottom = 0.0;

			i = 9;
			j = 1;
			pattern_VHO_center = spike_count_VHO[i][j];
			
			i = 2;
			j = 1;
			pattern_VHO_left = spike_count_VHO[i][j];
			
			i = 12;
			j = 1;
			pattern_VHO_right = spike_count_VHO[i][j];
			
			i = 7;
			j = 0;
			pattern_VHO_top = spike_count_VHO[i][j];

			i = 7;
			j = 2;
			pattern_VHO_bottom = spike_count_VHO[i][j];

			if(train_count == 0){
				fprintf(vir_tuning_VHO_center, "center %d %lf\n", train_vernier, pattern_VHO_center);
				fprintf(vir_tuning_VHO_left, "left %d %lf\n", train_vernier, pattern_VHO_left);
				fprintf(vir_tuning_VHO_right, "right %d %lf\n", train_vernier, pattern_VHO_right);
				fprintf(vir_tuning_VHO_top, "left %d %lf\n", train_vernier, pattern_VHO_top);
				fprintf(vir_tuning_VHO_bottom, "right %d %lf\n", train_vernier, pattern_VHO_bottom);
				if(train_vernier == -2){
					fprintf(vir_tuning_VHO, "top %lf\ncenter %lf\nbottom %lf\n", pattern_VHO_top, pattern_VHO_center, pattern_VHO_bottom);
				}
			}

        } //End of train_vernier
    } //End of train_count

    return 0;
}