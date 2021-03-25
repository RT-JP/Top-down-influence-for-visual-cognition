/* Copyright (c) 2021 RT-JP All Right Reserved. */
//vir = vernier irrelevant
//train = Training

//Train task V1 center
FILE *train_vir_v1_center, *train_vir_Input_v1_center, *train_vir_X_v1_center, *train_vir_S_ex_v1_center, *train_vir_S_inh_from_pv_v1_center, *train_vir_S_inh_from_som_v1_center, *train_vir_Top_v1_center, *train_vir_Bot_v1_center, *train_vir_S_v1_center;
FILE *train_vir_pv_v1_center, *train_vir_Input_pv_v1_center, *train_vir_X_pv_v1_center, *train_vir_S_ex_pv_v1_center;
FILE *train_vir_som_v1_center, *train_vir_Input_som_v1_center, *train_vir_X_som_v1_center, *train_vir_S_ex_som_v1_center, *train_vir_S_som_v1_center;
//Train task V1 left
FILE *train_vir_v1_left, *train_vir_Input_v1_left, *train_vir_X_v1_left, *train_vir_S_ex_v1_left, *train_vir_S_inh_v1_left, *train_vir_Top_v1_left, *train_vir_Bot_v1_left, *train_vir_S_v1_left;
FILE *train_vir_pv_v1_left, *train_vir_Input_pv_v1_left, *train_vir_X_pv_v1_left, *train_vir_S_ex_pv_v1_left, *train_vir_S_pv_v1_left;
FILE *train_vir_som_v1_left, *train_vir_Input_som_v1_left, *train_vir_X_som_v1_left, *train_vir_S_ex_som_v1_left, *train_vir_S_som_v1_left;
//Train task V1 right
FILE *train_vir_v1_right, *train_vir_Input_v1_right, *train_vir_X_v1_right, *train_vir_S_ex_v1_right, *train_vir_S_inh_v1_right, *train_vir_Top_v1_right, *train_vir_Bot_v1_right, *train_vir_S_v1_right;
FILE *train_vir_pv_v1_right, *train_vir_Input_pv_v1_right, *train_vir_X_pv_v1_right, *train_vir_S_ex_pv_v1_right, *train_vir_S_pv_v1_right;
FILE *train_vir_som_v1_right, *train_vir_Input_som_v1_right, *train_vir_X_som_v1_right, *train_vir_S_ex_som_v1_right, *train_vir_S_som_v1_right;
//Train task V1 top
FILE *train_vir_v1_top, *train_vir_Input_v1_top, *train_vir_X_v1_top, *train_vir_S_ex_v1_top, *train_vir_S_inh_v1_top, *train_vir_Top_v1_top, *train_vir_Bot_v1_top, *train_vir_S_v1_top;
FILE *train_vir_pv_v1_top, *train_vir_Input_pv_v1_top, *train_vir_X_pv_v1_top, *train_vir_S_ex_pv_v1_top, *train_vir_S_pv_v1_top;
FILE *train_vir_som_v1_top, *train_vir_Input_som_v1_top, *train_vir_X_som_v1_top, *train_vir_S_ex_som_v1_top, *train_vir_S_som_v1_top;
//Train task V1 bottom
FILE *train_vir_v1_bottom, *train_vir_Input_v1_bottom, *train_vir_X_v1_bottom, *train_vir_S_ex_v1_bottom, *train_vir_S_inh_v1_bottom, *train_vir_Top_v1_bottom, *train_vir_Bot_v1_bottom, *train_vir_S_v1_bottom;
FILE *train_vir_pv_v1_bottom, *train_vir_Input_pv_v1_bottom, *train_vir_X_pv_v1_bottom, *train_vir_S_ex_pv_v1_bottom, *train_vir_S_pv_v1_bottom;
FILE *train_vir_som_v1_bottom, *train_vir_Input_som_v1_bottom, *train_vir_X_som_v1_bottom, *train_vir_S_ex_som_v1_bottom, *train_vir_S_som_v1_bottom;
//cross correlation
FILE *bit_V1center, *bit_V1left, *bit_V1right,  *bit_V1top, *bit_V1bottom;
//LFP
FILE *vir_lfp_v1_center_synapse, *vir_lfp_v1_left_synapse, *vir_lfp_v1_right_synapse, *vir_lfp_v1_top_synapse, *vir_lfp_v1_bottom_synapse;
//V1 tuning curve
FILE *vir_tuning_V1_center, *vir_tuning_V1_left, *vir_tuning_V1_right, *vir_tuning_V1_top, *vir_tuning_V1_bottom, *vir_tuning_V1;

void FileOpenV1(void){
    //center
    train_vir_v1_center = fopen("train_vir_v1_center.csv", "w");
    train_vir_Input_v1_center = fopen("train_vir_Input_v1_center.csv", "w");
    train_vir_X_v1_center = fopen("train_vir_X_v1_center.csv", "w");
    train_vir_S_ex_v1_center = fopen("train_vir_S_ex_v1_center.csv", "w");
    train_vir_S_inh_from_pv_v1_center = fopen("train_vir_S_inh_from_pv_v1_center.csv", "w");
    train_vir_S_inh_from_som_v1_center = fopen("train_vir_S_inh_from_som_v1_center.csv", "w");
    train_vir_Top_v1_center = fopen("train_vir_Top_v1_center.csv", "w");
    train_vir_Bot_v1_center = fopen("train_vir_Bot_v1_center.csv", "w");
    train_vir_S_v1_center = fopen("train_vir_S_v1_center.csv", "w");

    train_vir_pv_v1_center = fopen("train_vir_pv_v1_center.csv", "w");
    train_vir_Input_pv_v1_center = fopen("train_vir_Input_pv_v1_center.csv", "w");
    train_vir_X_pv_v1_center = fopen("train_vir_X_pv_v1_center.csv", "w");
    train_vir_S_ex_pv_v1_center = fopen("train_vir_S_ex_pv_v1_center.csv", "w");

    train_vir_som_v1_center = fopen("train_vir_som_v1_center.csv", "w");
    train_vir_Input_som_v1_center = fopen("train_vir_Input_som_v1_center.csv", "w");
    train_vir_X_som_v1_center = fopen("train_vir_X_som_v1_center.csv", "w");
    train_vir_S_ex_som_v1_center = fopen("train_vir_S_ex_som_v1_center.csv", "w");
    train_vir_S_som_v1_center = fopen("train_vir_S_som_v1_center.csv", "w");
    //left
    train_vir_v1_left = fopen("train_vir_v1_left.csv", "w");
    train_vir_Input_v1_left = fopen("train_vir_Input_v1_left.csv", "w");
    train_vir_X_v1_left = fopen("train_vir_X_v1_left.csv", "w");
    train_vir_S_ex_v1_left = fopen("train_vir_S_ex_v1_left.csv", "w");
    train_vir_S_inh_v1_left = fopen("train_vir_S_inh_v1_left.csv", "w");
    train_vir_Top_v1_left = fopen("train_vir_Top_v1_left.csv", "w");
    train_vir_Bot_v1_left = fopen("train_vir_Bot_v1_left.csv", "w");
    train_vir_S_v1_left = fopen("train_vir_S_v1_left.csv", "w");

    train_vir_pv_v1_left = fopen("train_vir_pv_v1_left.csv", "w");
    train_vir_Input_pv_v1_left = fopen("train_vir_Input_pv_v1_left.csv", "w");
    train_vir_X_pv_v1_left = fopen("train_vir_X_pv_v1_left.csv", "w");
    train_vir_S_ex_pv_v1_left = fopen("train_vir_S_ex_pv_v1_left.csv", "w");
    train_vir_S_pv_v1_left = fopen("train_vir_S_pv_v1_left.csv", "w");

    train_vir_som_v1_left = fopen("train_vir_som_v1_left.csv", "w");
    train_vir_Input_som_v1_left = fopen("train_vir_Input_som_v1_left.csv", "w");
    train_vir_X_som_v1_left = fopen("train_vir_X_som_v1_left.csv", "w");
    train_vir_S_ex_som_v1_left = fopen("train_vir_S_ex_som_v1_left.csv", "w");
    train_vir_S_som_v1_left = fopen("train_vir_S_som_v1_left.csv", "w");
    //right
    train_vir_v1_right = fopen("train_vir_v1_right.csv", "w");
    train_vir_Input_v1_right = fopen("train_vir_Input_v1_right.csv", "w");
    train_vir_X_v1_right = fopen("train_vir_X_v1_right.csv", "w");
    train_vir_S_ex_v1_right = fopen("train_vir_S_ex_v1_right.csv", "w");
    train_vir_S_inh_v1_right = fopen("train_vir_S_inh_v1_right.csv", "w");
    train_vir_Top_v1_right = fopen("train_vir_Top_v1_right.csv", "w");
    train_vir_Bot_v1_right = fopen("train_vir_Bot_v1_right.csv", "w");
    train_vir_S_v1_right = fopen("train_vir_S_v1_right.csv", "w");

    train_vir_pv_v1_right = fopen("train_vir_pv_v1_right.csv", "w");
    train_vir_Input_pv_v1_right = fopen("train_vir_Input_pv_v1_right.csv", "w");
    train_vir_X_pv_v1_right = fopen("train_vir_X_pv_v1_right.csv", "w");
    train_vir_S_ex_pv_v1_right = fopen("train_vir_S_ex_pv_v1_right.csv", "w");
    train_vir_S_pv_v1_right = fopen("train_vir_S_pv_v1_right.csv", "w");

    train_vir_som_v1_right = fopen("train_vir_som_v1_right.csv", "w");
    train_vir_Input_som_v1_right = fopen("train_vir_Input_som_v1_right.csv", "w");
    train_vir_X_som_v1_right = fopen("train_vir_X_som_v1_right.csv", "w");
    train_vir_S_ex_som_v1_right = fopen("train_vir_S_ex_som_v1_right.csv", "w");
    train_vir_S_som_v1_right = fopen("train_vir_S_som_v1_right.csv", "w");
    //top
    train_vir_v1_top = fopen("train_vir_v1_top.csv", "w");
    train_vir_Input_v1_top = fopen("train_vir_Input_v1_top.csv", "w");
    train_vir_X_v1_top = fopen("train_vir_X_v1_top.csv", "w");
    train_vir_S_ex_v1_top = fopen("train_vir_S_ex_v1_top.csv", "w");
    train_vir_S_inh_v1_top = fopen("train_vir_S_inh_v1_top.csv", "w");
    train_vir_Top_v1_top = fopen("train_vir_Top_v1_top.csv", "w");
    train_vir_Bot_v1_top = fopen("train_vir_Bot_v1_top.csv", "w");
    train_vir_S_v1_top = fopen("train_vir_S_v1_top.csv", "w");

    train_vir_pv_v1_top = fopen("train_vir_pv_v1_top.csv", "w");
    train_vir_Input_pv_v1_top = fopen("train_vir_Input_pv_v1_top.csv", "w");
    train_vir_X_pv_v1_top = fopen("train_vir_X_pv_v1_top.csv", "w");
    train_vir_S_ex_pv_v1_top = fopen("train_vir_S_ex_pv_v1_top.csv", "w");
    train_vir_S_pv_v1_top = fopen("train_vir_S_pv_v1_top.csv", "w");

    train_vir_som_v1_top = fopen("train_vir_som_v1_top.csv", "w");
    train_vir_Input_som_v1_top = fopen("train_vir_Input_som_v1_top.csv", "w");
    train_vir_X_som_v1_top = fopen("train_vir_X_som_v1_top.csv", "w");
    train_vir_S_ex_som_v1_top = fopen("train_vir_S_ex_som_v1_top.csv", "w");
    train_vir_S_som_v1_top = fopen("train_vir_S_som_v1_top.csv", "w");
    //bottom
    train_vir_v1_bottom = fopen("train_vir_v1_bottom.csv", "w");
    train_vir_Input_v1_bottom = fopen("train_vir_Input_v1_bottom.csv", "w");
    train_vir_X_v1_bottom = fopen("train_vir_X_v1_bottom.csv", "w");
    train_vir_S_ex_v1_bottom = fopen("train_vir_S_ex_v1_bottom.csv", "w");
    train_vir_S_inh_v1_bottom = fopen("train_vir_S_inh_v1_bottom.csv", "w");
    train_vir_Top_v1_bottom = fopen("train_vir_Top_v1_bottom.csv", "w");
    train_vir_Bot_v1_bottom = fopen("train_vir_Bot_v1_bottom.csv", "w");
    train_vir_S_v1_bottom = fopen("train_vir_S_v1_bottom.csv", "w");

    train_vir_pv_v1_bottom = fopen("train_vir_pv_v1_bottom.csv", "w");
    train_vir_Input_pv_v1_bottom = fopen("train_vir_Input_pv_v1_bottom.csv", "w");
    train_vir_X_pv_v1_bottom = fopen("train_vir_X_pv_v1_bottom.csv", "w");
    train_vir_S_ex_pv_v1_bottom = fopen("train_vir_S_ex_pv_v1_bottom.csv", "w");
    train_vir_S_pv_v1_bottom = fopen("train_vir_S_pv_v1_bottom.csv", "w");

    train_vir_som_v1_bottom = fopen("train_vir_som_v1_bottom.csv", "w");
    train_vir_Input_som_v1_bottom = fopen("train_vir_Input_som_v1_bottom.csv", "w");
    train_vir_X_som_v1_bottom = fopen("train_vir_X_som_v1_bottom.csv", "w");
    train_vir_S_ex_som_v1_bottom = fopen("train_vir_S_ex_som_v1_bottom.csv", "w");
    train_vir_S_som_v1_bottom = fopen("train_vir_S_som_v1_bottom.csv", "w");
    //cross correlation
    bit_V1center = fopen("vir_bit_v1_center.csv", "w");
    bit_V1left = fopen("vir_bit_v1_left.csv", "w");
    bit_V1right = fopen("vir_bit_v1_right.csv", "w");
    bit_V1top = fopen("vir_bit_v1_top.csv", "w");
    bit_V1bottom = fopen("vir_bit_v1_bottom.csv", "w");
    //LFP
    vir_lfp_v1_center_synapse = fopen("vir_lfp_v1_center_synapse.csv", "w");
    vir_lfp_v1_left_synapse = fopen("vir_lfp_v1_left_synapse.csv", "w");
    vir_lfp_v1_right_synapse = fopen("vir_lfp_v1_right_synapse.csv", "w");
    vir_lfp_v1_top_synapse = fopen("vir_lfp_v1_top_synapse.csv", "w");
    vir_lfp_v1_bottom_synapse = fopen("vir_lfp_v1_bottom_synapse.csv", "w");
    //tuning curve
    vir_tuning_V1 = fopen("vir_tuning_V1.csv", "w");
    vir_tuning_V1_center = fopen("vir_tuning_V1_center.csv", "w");
    vir_tuning_V1_left = fopen("vir_tuning_V1_left.csv", "w");
    vir_tuning_V1_right = fopen("vir_tuning_V1_right.csv", "w");
    vir_tuning_V1_top = fopen("vir_tuning_V1_top.csv", "w");
    vir_tuning_V1_bottom = fopen("vir_tuning_V1_bottom.csv", "w");
}

void FileCloseV1(void){
    //center
    fclose(train_vir_v1_center);
    fclose(train_vir_Input_v1_center);
    fclose(train_vir_X_v1_center);
    fclose(train_vir_S_ex_v1_center);
    fclose(train_vir_S_inh_from_pv_v1_center);
    fclose(train_vir_S_inh_from_som_v1_center);
    fclose(train_vir_Top_v1_center);
    fclose(train_vir_Bot_v1_center);
    fclose(train_vir_S_v1_center);

    fclose(train_vir_pv_v1_center);
    fclose(train_vir_Input_pv_v1_center);
    fclose(train_vir_X_pv_v1_center);
    fclose(train_vir_S_ex_pv_v1_center);

    fclose(train_vir_som_v1_center);
    fclose(train_vir_Input_som_v1_center);
    fclose(train_vir_X_som_v1_center);
    fclose(train_vir_S_ex_som_v1_center);
    fclose(train_vir_S_som_v1_center);
    //left
    fclose(train_vir_v1_left);
    fclose(train_vir_Input_v1_left);
    fclose(train_vir_X_v1_left);
    fclose(train_vir_S_ex_v1_left);
    fclose(train_vir_S_inh_v1_left);
    fclose(train_vir_Top_v1_left);
    fclose(train_vir_Bot_v1_left);
    fclose(train_vir_S_v1_left);

    fclose(train_vir_pv_v1_left);
    fclose(train_vir_Input_pv_v1_left);
    fclose(train_vir_X_pv_v1_left);
    fclose(train_vir_S_ex_pv_v1_left);
    fclose(train_vir_S_pv_v1_left);

    fclose(train_vir_som_v1_left);
    fclose(train_vir_Input_som_v1_left);
    fclose(train_vir_X_som_v1_left);
    fclose(train_vir_S_ex_som_v1_left);
    fclose(train_vir_S_som_v1_left);
    //right
    fclose(train_vir_v1_right);
    fclose(train_vir_Input_v1_right);
    fclose(train_vir_X_v1_right);
    fclose(train_vir_S_ex_v1_right);
    fclose(train_vir_S_inh_v1_right);
    fclose(train_vir_Top_v1_right);
    fclose(train_vir_Bot_v1_right);
    fclose(train_vir_S_v1_right);

    fclose(train_vir_pv_v1_right);
    fclose(train_vir_Input_pv_v1_right);
    fclose(train_vir_X_pv_v1_right);
    fclose(train_vir_S_ex_pv_v1_right);
    fclose(train_vir_S_pv_v1_right);

    fclose(train_vir_som_v1_right);
    fclose(train_vir_Input_som_v1_right);
    fclose(train_vir_X_som_v1_right);
    fclose(train_vir_S_ex_som_v1_right);
    fclose(train_vir_S_som_v1_right);
    //top
    fclose(train_vir_v1_top);
    fclose(train_vir_Input_v1_top);
    fclose(train_vir_X_v1_top);
    fclose(train_vir_S_ex_v1_top);
    fclose(train_vir_S_inh_v1_top);
    fclose(train_vir_Top_v1_top);
    fclose(train_vir_Bot_v1_top);
    fclose(train_vir_S_v1_top);

    fclose(train_vir_pv_v1_top);
    fclose(train_vir_Input_pv_v1_top);
    fclose(train_vir_X_pv_v1_top);
    fclose(train_vir_S_ex_pv_v1_top);
    fclose(train_vir_S_pv_v1_top);

    fclose(train_vir_som_v1_top);
    fclose(train_vir_Input_som_v1_top);
    fclose(train_vir_X_som_v1_top);
    fclose(train_vir_S_ex_som_v1_top);
    fclose(train_vir_S_som_v1_top);
    //bottom
    fclose(train_vir_v1_bottom);
    fclose(train_vir_Input_v1_bottom);
    fclose(train_vir_X_v1_bottom);
    fclose(train_vir_S_ex_v1_bottom);
    fclose(train_vir_S_inh_v1_bottom);
    fclose(train_vir_Top_v1_bottom);
    fclose(train_vir_Bot_v1_bottom);
    fclose(train_vir_S_v1_bottom);

    fclose(train_vir_pv_v1_bottom);
    fclose(train_vir_Input_pv_v1_bottom);
    fclose(train_vir_X_pv_v1_bottom);
    fclose(train_vir_S_ex_pv_v1_bottom);
    fclose(train_vir_S_pv_v1_bottom);

    fclose(train_vir_som_v1_bottom);
    fclose(train_vir_Input_som_v1_bottom);
    fclose(train_vir_X_som_v1_bottom);
    fclose(train_vir_S_ex_som_v1_bottom);
    fclose(train_vir_S_som_v1_bottom);
    //cross correlation
    fclose(bit_V1center);
    fclose(bit_V1left);
    fclose(bit_V1right);
    fclose(bit_V1top);
    fclose(bit_V1bottom);
    //LFP
    fclose(vir_lfp_v1_center_synapse);
    fclose(vir_lfp_v1_left_synapse);
    fclose(vir_lfp_v1_right_synapse);
    fclose(vir_lfp_v1_top_synapse);
    fclose(vir_lfp_v1_bottom_synapse);
    //tuning curve
    fclose(vir_tuning_V1);
    fclose(vir_tuning_V1_center);
    fclose(vir_tuning_V1_left);
    fclose(vir_tuning_V1_right);
    fclose(vir_tuning_V1_top);
    fclose(vir_tuning_V1_bottom);
}