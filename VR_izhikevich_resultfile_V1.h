/* Copyright (c) 2021 RT-JP All Right Reserved. */
//vr = vernier relevant
//train = Training

//Train task V1 center
FILE *train_vr_v1_center, *train_vr_Input_v1_center, *train_vr_X_v1_center, *train_vr_S_ex_v1_center, *train_vr_S_inh_from_pv_v1_center, *train_vr_S_inh_from_som_v1_center, *train_vr_Top_v1_center, *train_vr_Bot_v1_center, *train_vr_S_v1_center;
FILE *train_vr_pv_v1_center, *train_vr_Input_pv_v1_center, *train_vr_X_pv_v1_center, *train_vr_S_ex_pv_v1_center;
FILE *train_vr_som_v1_center, *train_vr_Input_som_v1_center, *train_vr_X_som_v1_center, *train_vr_S_ex_som_v1_center, *train_vr_S_inh_som_v1_center, *train_vr_S_som_v1_center;
//Train task V1 left
FILE *train_vr_v1_left, *train_vr_Input_v1_left, *train_vr_X_v1_left, *train_vr_S_ex_v1_left, *train_vr_S_inh_v1_left, *train_vr_Top_v1_left, *train_vr_Bot_v1_left, *train_vr_S_v1_left;
FILE *train_vr_pv_v1_left, *train_vr_Input_pv_v1_left, *train_vr_X_pv_v1_left, *train_vr_S_ex_pv_v1_left;
FILE *train_vr_som_v1_left, *train_vr_Input_som_v1_left, *train_vr_X_som_v1_left, *train_vr_S_ex_som_v1_left, *train_vr_S_inh_som_v1_left;
//Train task V1 right
FILE *train_vr_v1_right, *train_vr_Input_v1_right, *train_vr_X_v1_right, *train_vr_S_ex_v1_right, *train_vr_S_inh_v1_right, *train_vr_Top_v1_right, *train_vr_Bot_v1_right, *train_vr_S_v1_right;
FILE *train_vr_pv_v1_right, *train_vr_Input_pv_v1_right, *train_vr_X_pv_v1_right, *train_vr_S_ex_pv_v1_right;
FILE *train_vr_som_v1_right, *train_vr_Input_som_v1_right, *train_vr_X_som_v1_right, *train_vr_S_ex_som_v1_right, *train_vr_S_inh_som_v1_right;
//Train task V1 top
FILE *train_vr_v1_top, *train_vr_Input_v1_top, *train_vr_X_v1_top, *train_vr_S_ex_v1_top, *train_vr_S_inh_v1_top, *train_vr_Top_v1_top, *train_vr_Bot_v1_top, *train_vr_S_v1_top;
FILE *train_vr_pv_v1_top, *train_vr_Input_pv_v1_top, *train_vr_X_pv_v1_top, *train_vr_S_ex_pv_v1_top;
FILE *train_vr_som_v1_top, *train_vr_Input_som_v1_top, *train_vr_X_som_v1_top, *train_vr_S_ex_som_v1_top, *train_vr_S_inh_som_v1_top;
//Train task V1 bottom
FILE *train_vr_v1_bottom, *train_vr_Input_v1_bottom, *train_vr_X_v1_bottom, *train_vr_S_ex_v1_bottom, *train_vr_S_inh_v1_bottom, *train_vr_Top_v1_bottom, *train_vr_Bot_v1_bottom, *train_vr_S_v1_bottom;
FILE *train_vr_pv_v1_bottom, *train_vr_Input_pv_v1_bottom, *train_vr_X_pv_v1_bottom, *train_vr_S_ex_pv_v1_bottom;
FILE *train_vr_som_v1_bottom, *train_vr_Input_som_v1_bottom, *train_vr_X_som_v1_bottom, *train_vr_S_ex_som_v1_bottom, *train_vr_S_inh_som_v1_bottom;
//cross correlation
FILE *bit_V1center, *bit_V1left, *bit_V1right,  *bit_V1top, *bit_V1bottom;
//LFP
FILE *vr_lfp_v1_center_synapse, *vr_lfp_v1_left_synapse, *vr_lfp_v1_right_synapse, *vr_lfp_v1_top_synapse, *vr_lfp_v1_bottom_synapse;
//V1 tuning curve
FILE *vr_tuning_V1_center, *vr_tuning_V1_left, *vr_tuning_V1_right, *vr_tuning_V1_top, *vr_tuning_V1_bottom, *vr_tuning_V1;

void FileOpenV1(void){
    //center
    train_vr_v1_center = fopen("train_vr_v1_center.csv", "w");
    train_vr_Input_v1_center = fopen("train_vr_Input_v1_center.csv", "w");
    train_vr_X_v1_center = fopen("train_vr_X_v1_center.csv", "w");
    train_vr_S_ex_v1_center = fopen("train_vr_S_ex_v1_center.csv", "w");
    train_vr_S_inh_from_pv_v1_center = fopen("train_vr_S_inh_from_pv_v1_center.csv", "w");
    train_vr_S_inh_from_som_v1_center = fopen("train_vr_S_inh_from_som_v1_center.csv", "w");
    train_vr_Top_v1_center = fopen("train_vr_Top_v1_center.csv", "w");
    train_vr_Bot_v1_center = fopen("train_vr_Bot_v1_center.csv", "w");
    train_vr_S_v1_center = fopen("train_vr_S_v1_center.csv", "w");

    train_vr_pv_v1_center = fopen("train_vr_pv_v1_center.csv", "w");
    train_vr_Input_pv_v1_center = fopen("train_vr_Input_pv_v1_center.csv", "w");
    train_vr_X_pv_v1_center = fopen("train_vr_X_pv_v1_center.csv", "w");
    train_vr_S_ex_pv_v1_center = fopen("train_vr_S_ex_pv_v1_center.csv", "w");
    
    train_vr_som_v1_center = fopen("train_vr_som_v1_center.csv", "w");
    train_vr_Input_som_v1_center = fopen("train_vr_Input_som_v1_center.csv", "w");
    train_vr_X_som_v1_center = fopen("train_vr_X_som_v1_center.csv", "w");
    train_vr_S_ex_som_v1_center = fopen("train_vr_S_ex_som_v1_center.csv", "w");
    train_vr_S_inh_som_v1_center = fopen("train_vr_S_inh_som_v1_center.csv", "w");
    train_vr_S_som_v1_center = fopen("train_vr_S_som_v1_center.csv", "w");
    //left
    train_vr_v1_left = fopen("train_vr_v1_left.csv", "w");
    train_vr_Input_v1_left = fopen("train_vr_Input_v1_left.csv", "w");
    train_vr_X_v1_left = fopen("train_vr_X_v1_left.csv", "w");
    train_vr_S_ex_v1_left = fopen("train_vr_S_ex_v1_left.csv", "w");
    train_vr_S_inh_v1_left = fopen("train_vr_S_inh_v1_left.csv", "w");
    train_vr_Top_v1_left = fopen("train_vr_Top_v1_left.csv", "w");
    train_vr_Bot_v1_left = fopen("train_vr_Bot_v1_left.csv", "w");
    train_vr_S_v1_left = fopen("train_vr_S_v1_left.csv", "w");

    train_vr_pv_v1_left = fopen("train_vr_pv_v1_left.csv", "w");
    train_vr_Input_pv_v1_left = fopen("train_vr_Input_pv_v1_left.csv", "w");
    train_vr_X_pv_v1_left = fopen("train_vr_X_pv_v1_left.csv", "w");
    train_vr_S_ex_pv_v1_left = fopen("train_vr_S_ex_pv_v1_left.csv", "w");

    train_vr_som_v1_left = fopen("train_vr_som_v1_left.csv", "w");
    train_vr_Input_som_v1_left = fopen("train_vr_Input_som_v1_left.csv", "w");
    train_vr_X_som_v1_left = fopen("train_vr_X_som_v1_left.csv", "w");
    train_vr_S_ex_som_v1_left = fopen("train_vr_S_ex_som_v1_left.csv", "w");
    train_vr_S_inh_som_v1_left = fopen("train_vr_S_inh_som_v1_left.csv", "w");
    //right
    train_vr_v1_right = fopen("train_vr_v1_right.csv", "w");
    train_vr_Input_v1_right = fopen("train_vr_Input_v1_right.csv", "w");
    train_vr_X_v1_right = fopen("train_vr_X_v1_right.csv", "w");
    train_vr_S_ex_v1_right = fopen("train_vr_S_ex_v1_right.csv", "w");
    train_vr_S_inh_v1_right = fopen("train_vr_S_inh_v1_right.csv", "w");
    train_vr_Top_v1_right = fopen("train_vr_Top_v1_right.csv", "w");
    train_vr_Bot_v1_right = fopen("train_vr_Bot_v1_right.csv", "w");
    train_vr_S_v1_right = fopen("train_vr_S_v1_right.csv", "w");

    train_vr_pv_v1_right = fopen("train_vr_pv_v1_right.csv", "w");
    train_vr_Input_pv_v1_right = fopen("train_vr_Input_pv_v1_right.csv", "w");
    train_vr_X_pv_v1_right = fopen("train_vr_X_pv_v1_right.csv", "w");
    train_vr_S_ex_pv_v1_right = fopen("train_vr_S_ex_pv_v1_right.csv", "w");

    train_vr_som_v1_right = fopen("train_vr_som_v1_right.csv", "w");
    train_vr_Input_som_v1_right = fopen("train_vr_Input_som_v1_right.csv", "w");
    train_vr_X_som_v1_right = fopen("train_vr_X_som_v1_right.csv", "w");
    train_vr_S_ex_som_v1_right = fopen("train_vr_S_ex_som_v1_right.csv", "w");
    train_vr_S_inh_som_v1_right = fopen("train_vr_S_inh_som_v1_right.csv", "w");
    //top
    train_vr_v1_top = fopen("train_vr_v1_top.csv", "w");
    train_vr_Input_v1_top = fopen("train_vr_Input_v1_top.csv", "w");
    train_vr_X_v1_top = fopen("train_vr_X_v1_top.csv", "w");
    train_vr_S_ex_v1_top = fopen("train_vr_S_ex_v1_top.csv", "w");
    train_vr_S_inh_v1_top = fopen("train_vr_S_inh_v1_top.csv", "w");
    train_vr_Top_v1_top = fopen("train_vr_Top_v1_top.csv", "w");
    train_vr_Bot_v1_top = fopen("train_vr_Bot_v1_top.csv", "w");
    train_vr_S_v1_top = fopen("train_vr_S_v1_top.csv", "w");

    train_vr_pv_v1_top = fopen("train_vr_pv_v1_top.csv", "w");
    train_vr_Input_pv_v1_top = fopen("train_vr_Input_pv_v1_top.csv", "w");
    train_vr_X_pv_v1_top = fopen("train_vr_X_pv_v1_top.csv", "w");
    train_vr_S_ex_pv_v1_top = fopen("train_vr_S_ex_pv_v1_top.csv", "w");

    train_vr_som_v1_top = fopen("train_vr_som_v1_top.csv", "w");
    train_vr_Input_som_v1_top = fopen("train_vr_Input_som_v1_top.csv", "w");
    train_vr_X_som_v1_top = fopen("train_vr_X_som_v1_top.csv", "w");
    train_vr_S_ex_som_v1_top = fopen("train_vr_S_ex_som_v1_top.csv", "w");
    train_vr_S_inh_som_v1_top = fopen("train_vr_S_inh_som_v1_top.csv", "w");
    //bottom
    train_vr_v1_bottom = fopen("train_vr_v1_bottom.csv", "w");
    train_vr_Input_v1_bottom = fopen("train_vr_Input_v1_bottom.csv", "w");
    train_vr_X_v1_bottom = fopen("train_vr_X_v1_bottom.csv", "w");
    train_vr_S_ex_v1_bottom = fopen("train_vr_S_ex_v1_bottom.csv", "w");
    train_vr_S_inh_v1_bottom = fopen("train_vr_S_inh_v1_bottom.csv", "w");
    train_vr_Top_v1_bottom = fopen("train_vr_Top_v1_bottom.csv", "w");
    train_vr_Bot_v1_bottom = fopen("train_vr_Bot_v1_bottom.csv", "w");
    train_vr_S_v1_bottom = fopen("train_vr_S_v1_bottom.csv", "w");

    train_vr_pv_v1_bottom = fopen("train_vr_pv_v1_bottom.csv", "w");
    train_vr_Input_pv_v1_bottom = fopen("train_vr_Input_pv_v1_bottom.csv", "w");
    train_vr_X_pv_v1_bottom = fopen("train_vr_X_pv_v1_bottom.csv", "w");
    train_vr_S_ex_pv_v1_bottom = fopen("train_vr_S_ex_pv_v1_bottom.csv", "w");

    train_vr_som_v1_bottom = fopen("train_vr_som_v1_bottom.csv", "w");
    train_vr_Input_som_v1_bottom = fopen("train_vr_Input_som_v1_bottom.csv", "w");
    train_vr_X_som_v1_bottom = fopen("train_vr_X_som_v1_bottom.csv", "w");
    train_vr_S_ex_som_v1_bottom = fopen("train_vr_S_ex_som_v1_bottom.csv", "w");
    train_vr_S_inh_som_v1_bottom = fopen("train_vr_S_inh_som_v1_bottom.csv", "w");
    //cross correlation
    bit_V1center = fopen("vr_bit_v1_center.csv", "w");
    bit_V1left = fopen("vr_bit_v1_left.csv", "w");
    bit_V1right = fopen("vr_bit_v1_right.csv", "w");
    bit_V1top = fopen("vr_bit_v1_top.csv", "w");
    bit_V1bottom = fopen("vr_bit_v1_bottom.csv", "w");
    //LFP
    vr_lfp_v1_center_synapse = fopen("vr_lfp_v1_center_synapse.csv", "w");
    vr_lfp_v1_left_synapse = fopen("vr_lfp_v1_left_synapse.csv", "w");
    vr_lfp_v1_right_synapse = fopen("vr_lfp_v1_right_synapse.csv", "w");
    vr_lfp_v1_top_synapse = fopen("vr_lfp_v1_top_synapse.csv", "w");
    vr_lfp_v1_bottom_synapse = fopen("vr_lfp_v1_bottom_synapse.csv", "w");
    //tuning curve
    vr_tuning_V1 = fopen("vr_tuning_V1.csv", "w");
    vr_tuning_V1_center = fopen("vr_tuning_V1_center.csv", "w");
    vr_tuning_V1_left = fopen("vr_tuning_V1_left.csv", "w");
    vr_tuning_V1_right = fopen("vr_tuning_V1_right.csv", "w");
    vr_tuning_V1_top = fopen("vr_tuning_V1_top.csv", "w");
    vr_tuning_V1_bottom = fopen("vr_tuning_V1_bottom.csv", "w");
}

void FileCloseV1(void){
    //center
    fclose(train_vr_v1_center);
    fclose(train_vr_Input_v1_center);
    fclose(train_vr_X_v1_center);
    fclose(train_vr_S_ex_v1_center);
    fclose(train_vr_S_inh_from_pv_v1_center);
    fclose(train_vr_S_inh_from_som_v1_center);
    fclose(train_vr_Top_v1_center);
    fclose(train_vr_Bot_v1_center);
    fclose(train_vr_S_v1_center);

    fclose(train_vr_pv_v1_center);
    fclose(train_vr_Input_pv_v1_center);
    fclose(train_vr_X_pv_v1_center);
    fclose(train_vr_S_ex_pv_v1_center);

    fclose(train_vr_som_v1_center);
    fclose(train_vr_Input_som_v1_center);
    fclose(train_vr_X_som_v1_center);
    fclose(train_vr_S_ex_som_v1_center);
    fclose(train_vr_S_inh_som_v1_center);
    fclose(train_vr_S_som_v1_center);
    //left   
    fclose(train_vr_v1_left);
    fclose(train_vr_Input_v1_left);
    fclose(train_vr_X_v1_left);
    fclose(train_vr_S_ex_v1_left);
    fclose(train_vr_S_inh_v1_left);
    fclose(train_vr_Top_v1_left);
    fclose(train_vr_Bot_v1_left);
    fclose(train_vr_S_v1_left);

    fclose(train_vr_pv_v1_left);
    fclose(train_vr_Input_pv_v1_left);
    fclose(train_vr_X_pv_v1_left);
    fclose(train_vr_S_ex_pv_v1_left);

    fclose(train_vr_som_v1_left);
    fclose(train_vr_Input_som_v1_left);
    fclose(train_vr_X_som_v1_left);
    fclose(train_vr_S_ex_som_v1_left);
    fclose(train_vr_S_inh_som_v1_left);
    //right    
    fclose(train_vr_v1_right);
    fclose(train_vr_Input_v1_right);
    fclose(train_vr_X_v1_right);
    fclose(train_vr_S_ex_v1_right);
    fclose(train_vr_S_inh_v1_right);
    fclose(train_vr_Top_v1_right);
    fclose(train_vr_Bot_v1_right);
    fclose(train_vr_S_v1_right);

    fclose(train_vr_pv_v1_right);
    fclose(train_vr_Input_pv_v1_right);
    fclose(train_vr_X_pv_v1_right);
    fclose(train_vr_S_ex_pv_v1_right);

    fclose(train_vr_som_v1_right);
    fclose(train_vr_Input_som_v1_right);
    fclose(train_vr_X_som_v1_right);
    fclose(train_vr_S_ex_som_v1_right);
    fclose(train_vr_S_inh_som_v1_right);
    //top
    fclose(train_vr_v1_top);
    fclose(train_vr_Input_v1_top);
    fclose(train_vr_X_v1_top);
    fclose(train_vr_S_ex_v1_top);
    fclose(train_vr_S_inh_v1_top);
    fclose(train_vr_Top_v1_top);
    fclose(train_vr_Bot_v1_top);
    fclose(train_vr_S_v1_top);

    fclose(train_vr_pv_v1_top);
    fclose(train_vr_Input_pv_v1_top);
    fclose(train_vr_X_pv_v1_top);
    fclose(train_vr_S_ex_pv_v1_top);

    fclose(train_vr_som_v1_top);
    fclose(train_vr_Input_som_v1_top);
    fclose(train_vr_X_som_v1_top);
    fclose(train_vr_S_ex_som_v1_top);
    fclose(train_vr_S_inh_som_v1_top);
    //bottom
    fclose(train_vr_v1_bottom);
    fclose(train_vr_Input_v1_bottom);
    fclose(train_vr_X_v1_bottom);
    fclose(train_vr_S_ex_v1_bottom);
    fclose(train_vr_S_inh_v1_bottom);
    fclose(train_vr_Top_v1_bottom);
    fclose(train_vr_Bot_v1_bottom);
    fclose(train_vr_S_v1_bottom);

    fclose(train_vr_pv_v1_bottom);
    fclose(train_vr_Input_pv_v1_bottom);
    fclose(train_vr_X_pv_v1_bottom);
    fclose(train_vr_S_ex_pv_v1_bottom);

    fclose(train_vr_som_v1_bottom);
    fclose(train_vr_Input_som_v1_bottom);
    fclose(train_vr_X_som_v1_bottom);
    fclose(train_vr_S_ex_som_v1_bottom);
    fclose(train_vr_S_inh_som_v1_bottom);
    //cross correlation
    fclose(bit_V1center);
    fclose(bit_V1left);
    fclose(bit_V1right);
    fclose(bit_V1top);
    fclose(bit_V1bottom);
    //LFP
    fclose(vr_lfp_v1_center_synapse);
    fclose(vr_lfp_v1_left_synapse);
    fclose(vr_lfp_v1_right_synapse);
    fclose(vr_lfp_v1_top_synapse);
    fclose(vr_lfp_v1_bottom_synapse);
    //tuning curve
    fclose(vr_tuning_V1);
    fclose(vr_tuning_V1_center);
    fclose(vr_tuning_V1_left);
    fclose(vr_tuning_V1_right);
    fclose(vr_tuning_V1_top);
    fclose(vr_tuning_V1_bottom);
}