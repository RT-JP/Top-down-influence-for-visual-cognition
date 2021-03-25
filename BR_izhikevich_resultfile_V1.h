/* Copyright (c) 2021 RT-JP All Right Reserved. */
//br = bisection relevant
//train = Training

//Train task V1 center
FILE *train_br_v1_center, *train_br_Input_v1_center, *train_br_X_v1_center, *train_br_S_ex_v1_center, *train_br_S_inh_from_pv_v1_center, *train_br_S_inh_from_som_v1_center, *train_br_Top_v1_center, *train_br_Bot_v1_center, *train_br_S_v1_center;
FILE *train_br_pv_v1_center, *train_br_Input_pv_v1_center, *train_br_X_pv_v1_center, *train_br_S_ex_pv_v1_center;
FILE *train_br_som_v1_center, *train_br_Input_som_v1_center, *train_br_X_som_v1_center, *train_br_S_ex_som_v1_center, *train_br_S_inh_som_v1_center, *train_br_S_som_v1_center;
//Train task V1 left
FILE *train_br_v1_left, *train_br_Input_v1_left, *train_br_X_v1_left, *train_br_S_ex_v1_left, *train_br_S_inh_v1_left, *train_br_Top_v1_left, *train_br_Bot_v1_left, *train_br_S_v1_left;
FILE *train_br_pv_v1_left, *train_br_Input_pv_v1_left, *train_br_X_pv_v1_left, *train_br_S_ex_pv_v1_left;
FILE *train_br_som_v1_left, *train_br_Input_som_v1_left, *train_br_X_som_v1_left, *train_br_S_ex_som_v1_left, *train_br_S_inh_som_v1_left;
//Train task V1 right
FILE *train_br_v1_right, *train_br_Input_v1_right, *train_br_X_v1_right, *train_br_S_ex_v1_right, *train_br_S_inh_v1_right, *train_br_Top_v1_right, *train_br_Bot_v1_right, *train_br_S_v1_right;
FILE *train_br_pv_v1_right, *train_br_Input_pv_v1_right, *train_br_X_pv_v1_right, *train_br_S_ex_pv_v1_right;
FILE *train_br_som_v1_right, *train_br_Input_som_v1_right, *train_br_X_som_v1_right, *train_br_S_ex_som_v1_right, *train_br_S_inh_som_v1_right;
//Train task V1 top
FILE *train_br_v1_top, *train_br_Input_v1_top, *train_br_X_v1_top, *train_br_S_ex_v1_top, *train_br_S_inh_v1_top, *train_br_Top_v1_top, *train_br_Bot_v1_top, *train_br_S_v1_top;
FILE *train_br_pv_v1_top, *train_br_Input_pv_v1_top, *train_br_X_pv_v1_top, *train_br_S_ex_pv_v1_top;
FILE *train_br_som_v1_top, *train_br_Input_som_v1_top, *train_br_X_som_v1_top, *train_br_S_ex_som_v1_top, *train_br_S_inh_som_v1_top;
//Train task V1 bottom
FILE *train_br_v1_bottom, *train_br_Input_v1_bottom, *train_br_X_v1_bottom, *train_br_S_ex_v1_bottom, *train_br_S_inh_v1_bottom, *train_br_Top_v1_bottom, *train_br_Bot_v1_bottom, *train_br_S_v1_bottom;
FILE *train_br_pv_v1_bottom, *train_br_Input_pv_v1_bottom, *train_br_X_pv_v1_bottom, *train_br_S_ex_pv_v1_bottom;
FILE *train_br_som_v1_bottom, *train_br_Input_som_v1_bottom, *train_br_X_som_v1_bottom, *train_br_S_ex_som_v1_bottom, *train_br_S_inh_som_v1_bottom;
//cross correlation
FILE *bit_V1center, *bit_V1left, *bit_V1right,  *bit_V1top, *bit_V1bottom;
//LFP
FILE *br_lfp_v1_center_synapse, *br_lfp_v1_left_synapse, *br_lfp_v1_right_synapse, *br_lfp_v1_top_synapse, *br_lfp_v1_bottom_synapse;
//V1 tuning curve
FILE *br_tuning_V1_center, *br_tuning_V1_left, *br_tuning_V1_right, *br_tuning_V1_top, *br_tuning_V1_bottom, *br_tuning_V1;

void FileOpenV1(void){
    //center
    train_br_v1_center = fopen("train_br_v1_center.csv", "w");
    train_br_Input_v1_center = fopen("train_br_Input_v1_center.csv", "w");
    train_br_X_v1_center = fopen("train_br_X_v1_center.csv", "w");
    train_br_S_ex_v1_center = fopen("train_br_S_ex_v1_center.csv", "w");
    train_br_S_inh_from_pv_v1_center = fopen("train_br_S_inh_from_pv_v1_center.csv", "w");
    train_br_S_inh_from_som_v1_center = fopen("train_br_S_inh_from_som_v1_center.csv", "w");
    train_br_Top_v1_center = fopen("train_br_Top_v1_center.csv", "w");
    train_br_Bot_v1_center = fopen("train_br_Bot_v1_center.csv", "w");
    train_br_S_v1_center = fopen("train_br_S_v1_center.csv", "w");

    train_br_pv_v1_center = fopen("train_br_pv_v1_center.csv", "w");
    train_br_Input_pv_v1_center = fopen("train_br_Input_pv_v1_center.csv", "w");
    train_br_X_pv_v1_center = fopen("train_br_X_pv_v1_center.csv", "w");
    train_br_S_ex_pv_v1_center = fopen("train_br_S_ex_pv_v1_center.csv", "w");
    
    train_br_som_v1_center = fopen("train_br_som_v1_center.csv", "w");
    train_br_Input_som_v1_center = fopen("train_br_Input_som_v1_center.csv", "w");
    train_br_X_som_v1_center = fopen("train_br_X_som_v1_center.csv", "w");
    train_br_S_ex_som_v1_center = fopen("train_br_S_ex_som_v1_center.csv", "w");
    train_br_S_inh_som_v1_center = fopen("train_br_S_inh_som_v1_center.csv", "w");
    train_br_S_som_v1_center = fopen("train_br_S_som_v1_center.csv", "w");
    //left
    train_br_v1_left = fopen("train_br_v1_left.csv", "w");
    train_br_Input_v1_left = fopen("train_br_Input_v1_left.csv", "w");
    train_br_X_v1_left = fopen("train_br_X_v1_left.csv", "w");
    train_br_S_ex_v1_left = fopen("train_br_S_ex_v1_left.csv", "w");
    train_br_S_inh_v1_left = fopen("train_br_S_inh_v1_left.csv", "w");
    train_br_Top_v1_left = fopen("train_br_Top_v1_left.csv", "w");
    train_br_Bot_v1_left = fopen("train_br_Bot_v1_left.csv", "w");
    train_br_S_v1_left = fopen("train_br_S_v1_left.csv", "w");

    train_br_pv_v1_left = fopen("train_br_pv_v1_left.csv", "w");
    train_br_Input_pv_v1_left = fopen("train_br_Input_pv_v1_left.csv", "w");
    train_br_X_pv_v1_left = fopen("train_br_X_pv_v1_left.csv", "w");
    train_br_S_ex_pv_v1_left = fopen("train_br_S_ex_pv_v1_left.csv", "w");

    train_br_som_v1_left = fopen("train_br_som_v1_left.csv", "w");
    train_br_Input_som_v1_left = fopen("train_br_Input_som_v1_left.csv", "w");
    train_br_X_som_v1_left = fopen("train_br_X_som_v1_left.csv", "w");
    train_br_S_ex_som_v1_left = fopen("train_br_S_ex_som_v1_left.csv", "w");
    train_br_S_inh_som_v1_left = fopen("train_br_S_inh_som_v1_left.csv", "w");
    //right
    train_br_v1_right = fopen("train_br_v1_right.csv", "w");
    train_br_Input_v1_right = fopen("train_br_Input_v1_right.csv", "w");
    train_br_X_v1_right = fopen("train_br_X_v1_right.csv", "w");
    train_br_S_ex_v1_right = fopen("train_br_S_ex_v1_right.csv", "w");
    train_br_S_inh_v1_right = fopen("train_br_S_inh_v1_right.csv", "w");
    train_br_Top_v1_right = fopen("train_br_Top_v1_right.csv", "w");
    train_br_Bot_v1_right = fopen("train_br_Bot_v1_right.csv", "w");
    train_br_S_v1_right = fopen("train_br_S_v1_right.csv", "w");

    train_br_pv_v1_right = fopen("train_br_pv_v1_right.csv", "w");
    train_br_Input_pv_v1_right = fopen("train_br_Input_pv_v1_right.csv", "w");
    train_br_X_pv_v1_right = fopen("train_br_X_pv_v1_right.csv", "w");
    train_br_S_ex_pv_v1_right = fopen("train_br_S_ex_pv_v1_right.csv", "w");

    train_br_som_v1_right = fopen("train_br_som_v1_right.csv", "w");
    train_br_Input_som_v1_right = fopen("train_br_Input_som_v1_right.csv", "w");
    train_br_X_som_v1_right = fopen("train_br_X_som_v1_right.csv", "w");
    train_br_S_ex_som_v1_right = fopen("train_br_S_ex_som_v1_right.csv", "w");
    train_br_S_inh_som_v1_right = fopen("train_br_S_inh_som_v1_right.csv", "w");
    //top
    train_br_v1_top = fopen("train_br_v1_top.csv", "w");
    train_br_Input_v1_top = fopen("train_br_Input_v1_top.csv", "w");
    train_br_X_v1_top = fopen("train_br_X_v1_top.csv", "w");
    train_br_S_ex_v1_top = fopen("train_br_S_ex_v1_top.csv", "w");
    train_br_S_inh_v1_top = fopen("train_br_S_inh_v1_top.csv", "w");
    train_br_Top_v1_top = fopen("train_br_Top_v1_top.csv", "w");
    train_br_Bot_v1_top = fopen("train_br_Bot_v1_top.csv", "w");
    train_br_S_v1_top = fopen("train_br_S_v1_top.csv", "w");

    train_br_pv_v1_top = fopen("train_br_pv_v1_top.csv", "w");
    train_br_Input_pv_v1_top = fopen("train_br_Input_pv_v1_top.csv", "w");
    train_br_X_pv_v1_top = fopen("train_br_X_pv_v1_top.csv", "w");
    train_br_S_ex_pv_v1_top = fopen("train_br_S_ex_pv_v1_top.csv", "w");

    train_br_som_v1_top = fopen("train_br_som_v1_top.csv", "w");
    train_br_Input_som_v1_top = fopen("train_br_Input_som_v1_top.csv", "w");
    train_br_X_som_v1_top = fopen("train_br_X_som_v1_top.csv", "w");
    train_br_S_ex_som_v1_top = fopen("train_br_S_ex_som_v1_top.csv", "w");
    train_br_S_inh_som_v1_top = fopen("train_br_S_inh_som_v1_top.csv", "w");
    //bottom
    train_br_v1_bottom = fopen("train_br_v1_bottom.csv", "w");
    train_br_Input_v1_bottom = fopen("train_br_Input_v1_bottom.csv", "w");
    train_br_X_v1_bottom = fopen("train_br_X_v1_bottom.csv", "w");
    train_br_S_ex_v1_bottom = fopen("train_br_S_ex_v1_bottom.csv", "w");
    train_br_S_inh_v1_bottom = fopen("train_br_S_inh_v1_bottom.csv", "w");
    train_br_Top_v1_bottom = fopen("train_br_Top_v1_bottom.csv", "w");
    train_br_Bot_v1_bottom = fopen("train_br_Bot_v1_bottom.csv", "w");
    train_br_S_v1_bottom = fopen("train_br_S_v1_bottom.csv", "w");

    train_br_pv_v1_bottom = fopen("train_br_pv_v1_bottom.csv", "w");
    train_br_Input_pv_v1_bottom = fopen("train_br_Input_pv_v1_bottom.csv", "w");
    train_br_X_pv_v1_bottom = fopen("train_br_X_pv_v1_bottom.csv", "w");
    train_br_S_ex_pv_v1_bottom = fopen("train_br_S_ex_pv_v1_bottom.csv", "w");

    train_br_som_v1_bottom = fopen("train_br_som_v1_bottom.csv", "w");
    train_br_Input_som_v1_bottom = fopen("train_br_Input_som_v1_bottom.csv", "w");
    train_br_X_som_v1_bottom = fopen("train_br_X_som_v1_bottom.csv", "w");
    train_br_S_ex_som_v1_bottom = fopen("train_br_S_ex_som_v1_bottom.csv", "w");
    train_br_S_inh_som_v1_bottom = fopen("train_br_S_inh_som_v1_bottom.csv", "w");
    //cross correlation
    bit_V1center = fopen("br_bit_v1_center.csv", "w");
    bit_V1left = fopen("br_bit_v1_left.csv", "w");
    bit_V1right = fopen("br_bit_v1_right.csv", "w");
    bit_V1top = fopen("br_bit_v1_top.csv", "w");
    bit_V1bottom = fopen("br_bit_v1_bottom.csv", "w");
    //LFP
    br_lfp_v1_center_synapse = fopen("br_lfp_v1_center_synapse.csv", "w");
    br_lfp_v1_left_synapse = fopen("br_lfp_v1_left_synapse.csv", "w");
    br_lfp_v1_right_synapse = fopen("br_lfp_v1_right_synapse.csv", "w");
    br_lfp_v1_top_synapse = fopen("br_lfp_v1_top_synapse.csv", "w");
    br_lfp_v1_bottom_synapse = fopen("br_lfp_v1_bottom_synapse.csv", "w");
    //tuning curve
    br_tuning_V1 = fopen("br_tuning_V1.csv", "w");
    br_tuning_V1_center = fopen("br_tuning_V1_center.csv", "w");
    br_tuning_V1_left = fopen("br_tuning_V1_left.csv", "w");
    br_tuning_V1_right = fopen("br_tuning_V1_right.csv", "w");
    br_tuning_V1_top = fopen("br_tuning_V1_top.csv", "w");
    br_tuning_V1_bottom = fopen("br_tuning_V1_bottom.csv", "w");
}

void FileCloseV1(void){
    //center
    fclose(train_br_v1_center);
    fclose(train_br_Input_v1_center);
    fclose(train_br_X_v1_center);
    fclose(train_br_S_ex_v1_center);
    fclose(train_br_S_inh_from_pv_v1_center);
    fclose(train_br_S_inh_from_som_v1_center);
    fclose(train_br_Top_v1_center);
    fclose(train_br_Bot_v1_center);
    fclose(train_br_S_v1_center);

    fclose(train_br_pv_v1_center);
    fclose(train_br_Input_pv_v1_center);
    fclose(train_br_X_pv_v1_center);
    fclose(train_br_S_ex_pv_v1_center);

    fclose(train_br_som_v1_center);
    fclose(train_br_Input_som_v1_center);
    fclose(train_br_X_som_v1_center);
    fclose(train_br_S_ex_som_v1_center);
    fclose(train_br_S_inh_som_v1_center);
    fclose(train_br_S_som_v1_center);
    //left   
    fclose(train_br_v1_left);
    fclose(train_br_Input_v1_left);
    fclose(train_br_X_v1_left);
    fclose(train_br_S_ex_v1_left);
    fclose(train_br_S_inh_v1_left);
    fclose(train_br_Top_v1_left);
    fclose(train_br_Bot_v1_left);
    fclose(train_br_S_v1_left);

    fclose(train_br_pv_v1_left);
    fclose(train_br_Input_pv_v1_left);
    fclose(train_br_X_pv_v1_left);
    fclose(train_br_S_ex_pv_v1_left);

    fclose(train_br_som_v1_left);
    fclose(train_br_Input_som_v1_left);
    fclose(train_br_X_som_v1_left);
    fclose(train_br_S_ex_som_v1_left);
    fclose(train_br_S_inh_som_v1_left);
    //right    
    fclose(train_br_v1_right);
    fclose(train_br_Input_v1_right);
    fclose(train_br_X_v1_right);
    fclose(train_br_S_ex_v1_right);
    fclose(train_br_S_inh_v1_right);
    fclose(train_br_Top_v1_right);
    fclose(train_br_Bot_v1_right);
    fclose(train_br_S_v1_right);

    fclose(train_br_pv_v1_right);
    fclose(train_br_Input_pv_v1_right);
    fclose(train_br_X_pv_v1_right);
    fclose(train_br_S_ex_pv_v1_right);

    fclose(train_br_som_v1_right);
    fclose(train_br_Input_som_v1_right);
    fclose(train_br_X_som_v1_right);
    fclose(train_br_S_ex_som_v1_right);
    fclose(train_br_S_inh_som_v1_right);
    //top
    fclose(train_br_v1_top);
    fclose(train_br_Input_v1_top);
    fclose(train_br_X_v1_top);
    fclose(train_br_S_ex_v1_top);
    fclose(train_br_S_inh_v1_top);
    fclose(train_br_Top_v1_top);
    fclose(train_br_Bot_v1_top);
    fclose(train_br_S_v1_top);

    fclose(train_br_pv_v1_top);
    fclose(train_br_Input_pv_v1_top);
    fclose(train_br_X_pv_v1_top);
    fclose(train_br_S_ex_pv_v1_top);

    fclose(train_br_som_v1_top);
    fclose(train_br_Input_som_v1_top);
    fclose(train_br_X_som_v1_top);
    fclose(train_br_S_ex_som_v1_top);
    fclose(train_br_S_inh_som_v1_top);
    //bottom
    fclose(train_br_v1_bottom);
    fclose(train_br_Input_v1_bottom);
    fclose(train_br_X_v1_bottom);
    fclose(train_br_S_ex_v1_bottom);
    fclose(train_br_S_inh_v1_bottom);
    fclose(train_br_Top_v1_bottom);
    fclose(train_br_Bot_v1_bottom);
    fclose(train_br_S_v1_bottom);

    fclose(train_br_pv_v1_bottom);
    fclose(train_br_Input_pv_v1_bottom);
    fclose(train_br_X_pv_v1_bottom);
    fclose(train_br_S_ex_pv_v1_bottom);

    fclose(train_br_som_v1_bottom);
    fclose(train_br_Input_som_v1_bottom);
    fclose(train_br_X_som_v1_bottom);
    fclose(train_br_S_ex_som_v1_bottom);
    fclose(train_br_S_inh_som_v1_bottom);
    //cross correlation
    fclose(bit_V1center);
    fclose(bit_V1left);
    fclose(bit_V1right);
    fclose(bit_V1top);
    fclose(bit_V1bottom);
    //LFP
    fclose(br_lfp_v1_center_synapse);
    fclose(br_lfp_v1_left_synapse);
    fclose(br_lfp_v1_right_synapse);
    fclose(br_lfp_v1_top_synapse);
    fclose(br_lfp_v1_bottom_synapse);
    //tuning curve
    fclose(br_tuning_V1);
    fclose(br_tuning_V1_center);
    fclose(br_tuning_V1_left);
    fclose(br_tuning_V1_right);
    fclose(br_tuning_V1_top);
    fclose(br_tuning_V1_bottom);
}