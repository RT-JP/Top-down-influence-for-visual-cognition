/* Copyright (c) 2021 RT-JP All Right Reserved. */
//bir = bisection irrelevant
//train = Training

//Train task V1 center
FILE *train_bir_v1_center, *train_bir_Input_v1_center, *train_bir_X_v1_center, *train_bir_S_ex_v1_center, *train_bir_S_inh_from_pv_v1_center, *train_bir_S_inh_from_som_v1_center, *train_bir_Top_v1_center, *train_bir_Bot_v1_center, *train_bir_S_v1_center;
FILE *train_bir_pv_v1_center, *train_bir_Input_pv_v1_center, *train_bir_X_pv_v1_center, *train_bir_S_ex_pv_v1_center;
FILE *train_bir_som_v1_center, *train_bir_Input_som_v1_center, *train_bir_X_som_v1_center, *train_bir_S_ex_som_v1_center, *train_bir_S_som_v1_center;
//Train task V1 left
FILE *train_bir_v1_left, *train_bir_Input_v1_left, *train_bir_X_v1_left, *train_bir_S_ex_v1_left, *train_bir_S_inh_v1_left, *train_bir_Top_v1_left, *train_bir_Bot_v1_left, *train_bir_S_v1_left;
FILE *train_bir_pv_v1_left, *train_bir_Input_pv_v1_left, *train_bir_X_pv_v1_left, *train_bir_S_ex_pv_v1_left, *train_bir_S_pv_v1_left;
FILE *train_bir_som_v1_left, *train_bir_Input_som_v1_left, *train_bir_X_som_v1_left, *train_bir_S_ex_som_v1_left, *train_bir_S_som_v1_left;
//Train task V1 right
FILE *train_bir_v1_right, *train_bir_Input_v1_right, *train_bir_X_v1_right, *train_bir_S_ex_v1_right, *train_bir_S_inh_v1_right, *train_bir_Top_v1_right, *train_bir_Bot_v1_right, *train_bir_S_v1_right;
FILE *train_bir_pv_v1_right, *train_bir_Input_pv_v1_right, *train_bir_X_pv_v1_right, *train_bir_S_ex_pv_v1_right, *train_bir_S_pv_v1_right;
FILE *train_bir_som_v1_right, *train_bir_Input_som_v1_right, *train_bir_X_som_v1_right, *train_bir_S_ex_som_v1_right, *train_bir_S_som_v1_right;
//Train task V1 top
FILE *train_bir_v1_top, *train_bir_Input_v1_top, *train_bir_X_v1_top, *train_bir_S_ex_v1_top, *train_bir_S_inh_v1_top, *train_bir_Top_v1_top, *train_bir_Bot_v1_top, *train_bir_S_v1_top;
FILE *train_bir_pv_v1_top, *train_bir_Input_pv_v1_top, *train_bir_X_pv_v1_top, *train_bir_S_ex_pv_v1_top, *train_bir_S_pv_v1_top;
FILE *train_bir_som_v1_top, *train_bir_Input_som_v1_top, *train_bir_X_som_v1_top, *train_bir_S_ex_som_v1_top, *train_bir_S_som_v1_top;
//Train task V1 bottom
FILE *train_bir_v1_bottom, *train_bir_Input_v1_bottom, *train_bir_X_v1_bottom, *train_bir_S_ex_v1_bottom, *train_bir_S_inh_v1_bottom, *train_bir_Top_v1_bottom, *train_bir_Bot_v1_bottom, *train_bir_S_v1_bottom;
FILE *train_bir_pv_v1_bottom, *train_bir_Input_pv_v1_bottom, *train_bir_X_pv_v1_bottom, *train_bir_S_ex_pv_v1_bottom, *train_bir_S_pv_v1_bottom;
FILE *train_bir_som_v1_bottom, *train_bir_Input_som_v1_bottom, *train_bir_X_som_v1_bottom, *train_bir_S_ex_som_v1_bottom, *train_bir_S_som_v1_bottom;
//cross correlation
FILE *bit_V1center, *bit_V1left, *bit_V1right,  *bit_V1top, *bit_V1bottom;
//LFP
FILE *bir_lfp_v1_center_synapse, *bir_lfp_v1_left_synapse, *bir_lfp_v1_right_synapse, *bir_lfp_v1_top_synapse, *bir_lfp_v1_bottom_synapse;
//V1 tuning curve
FILE *bir_tuning_V1_center, *bir_tuning_V1_left, *bir_tuning_V1_right, *bir_tuning_V1_top, *bir_tuning_V1_bottom, *bir_tuning_V1;

void FileOpenV1(void){
    //center
    train_bir_v1_center = fopen("train_bir_v1_center.csv", "w");
    train_bir_Input_v1_center = fopen("train_bir_Input_v1_center.csv", "w");
    train_bir_X_v1_center = fopen("train_bir_X_v1_center.csv", "w");
    train_bir_S_ex_v1_center = fopen("train_bir_S_ex_v1_center.csv", "w");
    train_bir_S_inh_from_pv_v1_center = fopen("train_bir_S_inh_from_pv_v1_center.csv", "w");
    train_bir_S_inh_from_som_v1_center = fopen("train_bir_S_inh_from_som_v1_center.csv", "w");
    train_bir_Top_v1_center = fopen("train_bir_Top_v1_center.csv", "w");
    train_bir_Bot_v1_center = fopen("train_bir_Bot_v1_center.csv", "w");
    train_bir_S_v1_center = fopen("train_bir_S_v1_center.csv", "w");

    train_bir_pv_v1_center = fopen("train_bir_pv_v1_center.csv", "w");
    train_bir_Input_pv_v1_center = fopen("train_bir_Input_pv_v1_center.csv", "w");
    train_bir_X_pv_v1_center = fopen("train_bir_X_pv_v1_center.csv", "w");
    train_bir_S_ex_pv_v1_center = fopen("train_bir_S_ex_pv_v1_center.csv", "w");

    train_bir_som_v1_center = fopen("train_bir_som_v1_center.csv", "w");
    train_bir_Input_som_v1_center = fopen("train_bir_Input_som_v1_center.csv", "w");
    train_bir_X_som_v1_center = fopen("train_bir_X_som_v1_center.csv", "w");
    train_bir_S_ex_som_v1_center = fopen("train_bir_S_ex_som_v1_center.csv", "w");
    train_bir_S_som_v1_center = fopen("train_bir_S_som_v1_center.csv", "w");
    //left
    train_bir_v1_left = fopen("train_bir_v1_left.csv", "w");
    train_bir_Input_v1_left = fopen("train_bir_Input_v1_left.csv", "w");
    train_bir_X_v1_left = fopen("train_bir_X_v1_left.csv", "w");
    train_bir_S_ex_v1_left = fopen("train_bir_S_ex_v1_left.csv", "w");
    train_bir_S_inh_v1_left = fopen("train_bir_S_inh_v1_left.csv", "w");
    train_bir_Top_v1_left = fopen("train_bir_Top_v1_left.csv", "w");
    train_bir_Bot_v1_left = fopen("train_bir_Bot_v1_left.csv", "w");
    train_bir_S_v1_left = fopen("train_bir_S_v1_left.csv", "w");

    train_bir_pv_v1_left = fopen("train_bir_pv_v1_left.csv", "w");
    train_bir_Input_pv_v1_left = fopen("train_bir_Input_pv_v1_left.csv", "w");
    train_bir_X_pv_v1_left = fopen("train_bir_X_pv_v1_left.csv", "w");
    train_bir_S_ex_pv_v1_left = fopen("train_bir_S_ex_pv_v1_left.csv", "w");
    train_bir_S_pv_v1_left = fopen("train_bir_S_pv_v1_left.csv", "w");

    train_bir_som_v1_left = fopen("train_bir_som_v1_left.csv", "w");
    train_bir_Input_som_v1_left = fopen("train_bir_Input_som_v1_left.csv", "w");
    train_bir_X_som_v1_left = fopen("train_bir_X_som_v1_left.csv", "w");
    train_bir_S_ex_som_v1_left = fopen("train_bir_S_ex_som_v1_left.csv", "w");
    train_bir_S_som_v1_left = fopen("train_bir_S_som_v1_left.csv", "w");
    //right
    train_bir_v1_right = fopen("train_bir_v1_right.csv", "w");
    train_bir_Input_v1_right = fopen("train_bir_Input_v1_right.csv", "w");
    train_bir_X_v1_right = fopen("train_bir_X_v1_right.csv", "w");
    train_bir_S_ex_v1_right = fopen("train_bir_S_ex_v1_right.csv", "w");
    train_bir_S_inh_v1_right = fopen("train_bir_S_inh_v1_right.csv", "w");
    train_bir_Top_v1_right = fopen("train_bir_Top_v1_right.csv", "w");
    train_bir_Bot_v1_right = fopen("train_bir_Bot_v1_right.csv", "w");
    train_bir_S_v1_right = fopen("train_bir_S_v1_right.csv", "w");

    train_bir_pv_v1_right = fopen("train_bir_pv_v1_right.csv", "w");
    train_bir_Input_pv_v1_right = fopen("train_bir_Input_pv_v1_right.csv", "w");
    train_bir_X_pv_v1_right = fopen("train_bir_X_pv_v1_right.csv", "w");
    train_bir_S_ex_pv_v1_right = fopen("train_bir_S_ex_pv_v1_right.csv", "w");
    train_bir_S_pv_v1_right = fopen("train_bir_S_pv_v1_right.csv", "w");

    train_bir_som_v1_right = fopen("train_bir_som_v1_right.csv", "w");
    train_bir_Input_som_v1_right = fopen("train_bir_Input_som_v1_right.csv", "w");
    train_bir_X_som_v1_right = fopen("train_bir_X_som_v1_right.csv", "w");
    train_bir_S_ex_som_v1_right = fopen("train_bir_S_ex_som_v1_right.csv", "w");
    train_bir_S_som_v1_right = fopen("train_bir_S_som_v1_right.csv", "w");
    //top
    train_bir_v1_top = fopen("train_bir_v1_top.csv", "w");
    train_bir_Input_v1_top = fopen("train_bir_Input_v1_top.csv", "w");
    train_bir_X_v1_top = fopen("train_bir_X_v1_top.csv", "w");
    train_bir_S_ex_v1_top = fopen("train_bir_S_ex_v1_top.csv", "w");
    train_bir_S_inh_v1_top = fopen("train_bir_S_inh_v1_top.csv", "w");
    train_bir_Top_v1_top = fopen("train_bir_Top_v1_top.csv", "w");
    train_bir_Bot_v1_top = fopen("train_bir_Bot_v1_top.csv", "w");
    train_bir_S_v1_top = fopen("train_bir_S_v1_top.csv", "w");

    train_bir_pv_v1_top = fopen("train_bir_pv_v1_top.csv", "w");
    train_bir_Input_pv_v1_top = fopen("train_bir_Input_pv_v1_top.csv", "w");
    train_bir_X_pv_v1_top = fopen("train_bir_X_pv_v1_top.csv", "w");
    train_bir_S_ex_pv_v1_top = fopen("train_bir_S_ex_pv_v1_top.csv", "w");
    train_bir_S_pv_v1_top = fopen("train_bir_S_pv_v1_top.csv", "w");

    train_bir_som_v1_top = fopen("train_bir_som_v1_top.csv", "w");
    train_bir_Input_som_v1_top = fopen("train_bir_Input_som_v1_top.csv", "w");
    train_bir_X_som_v1_top = fopen("train_bir_X_som_v1_top.csv", "w");
    train_bir_S_ex_som_v1_top = fopen("train_bir_S_ex_som_v1_top.csv", "w");
    train_bir_S_som_v1_top = fopen("train_bir_S_som_v1_top.csv", "w");
    //bottom
    train_bir_v1_bottom = fopen("train_bir_v1_bottom.csv", "w");
    train_bir_Input_v1_bottom = fopen("train_bir_Input_v1_bottom.csv", "w");
    train_bir_X_v1_bottom = fopen("train_bir_X_v1_bottom.csv", "w");
    train_bir_S_ex_v1_bottom = fopen("train_bir_S_ex_v1_bottom.csv", "w");
    train_bir_S_inh_v1_bottom = fopen("train_bir_S_inh_v1_bottom.csv", "w");
    train_bir_Top_v1_bottom = fopen("train_bir_Top_v1_bottom.csv", "w");
    train_bir_Bot_v1_bottom = fopen("train_bir_Bot_v1_bottom.csv", "w");
    train_bir_S_v1_bottom = fopen("train_bir_S_v1_bottom.csv", "w");

    train_bir_pv_v1_bottom = fopen("train_bir_pv_v1_bottom.csv", "w");
    train_bir_Input_pv_v1_bottom = fopen("train_bir_Input_pv_v1_bottom.csv", "w");
    train_bir_X_pv_v1_bottom = fopen("train_bir_X_pv_v1_bottom.csv", "w");
    train_bir_S_ex_pv_v1_bottom = fopen("train_bir_S_ex_pv_v1_bottom.csv", "w");
    train_bir_S_pv_v1_bottom = fopen("train_bir_S_pv_v1_bottom.csv", "w");

    train_bir_som_v1_bottom = fopen("train_bir_som_v1_bottom.csv", "w");
    train_bir_Input_som_v1_bottom = fopen("train_bir_Input_som_v1_bottom.csv", "w");
    train_bir_X_som_v1_bottom = fopen("train_bir_X_som_v1_bottom.csv", "w");
    train_bir_S_ex_som_v1_bottom = fopen("train_bir_S_ex_som_v1_bottom.csv", "w");
    train_bir_S_som_v1_bottom = fopen("train_bir_S_som_v1_bottom.csv", "w");
    //cross correlation
    bit_V1center = fopen("bir_bit_v1_center.csv", "w");
    bit_V1left = fopen("bir_bit_v1_left.csv", "w");
    bit_V1right = fopen("bir_bit_v1_right.csv", "w");
    bit_V1top = fopen("bir_bit_v1_top.csv", "w");
    bit_V1bottom = fopen("bir_bit_v1_bottom.csv", "w");
    //LFP
    bir_lfp_v1_center_synapse = fopen("bir_lfp_v1_center_synapse.csv", "w");
    bir_lfp_v1_left_synapse = fopen("bir_lfp_v1_left_synapse.csv", "w");
    bir_lfp_v1_right_synapse = fopen("bir_lfp_v1_right_synapse.csv", "w");
    bir_lfp_v1_top_synapse = fopen("bir_lfp_v1_top_synapse.csv", "w");
    bir_lfp_v1_bottom_synapse = fopen("bir_lfp_v1_bottom_synapse.csv", "w");
    //tuning curve
    bir_tuning_V1 = fopen("bir_tuning_V1.csv", "w");
    bir_tuning_V1_center = fopen("bir_tuning_V1_center.csv", "w");
    bir_tuning_V1_left = fopen("bir_tuning_V1_left.csv", "w");
    bir_tuning_V1_right = fopen("bir_tuning_V1_right.csv", "w");
    bir_tuning_V1_top = fopen("bir_tuning_V1_top.csv", "w");
    bir_tuning_V1_bottom = fopen("bir_tuning_V1_bottom.csv", "w");
}

void FileCloseV1(void){
    //center
    fclose(train_bir_v1_center);
    fclose(train_bir_Input_v1_center);
    fclose(train_bir_X_v1_center);
    fclose(train_bir_S_ex_v1_center);
    fclose(train_bir_S_inh_from_pv_v1_center);
    fclose(train_bir_S_inh_from_som_v1_center);
    fclose(train_bir_Top_v1_center);
    fclose(train_bir_Bot_v1_center);
    fclose(train_bir_S_v1_center);

    fclose(train_bir_pv_v1_center);
    fclose(train_bir_Input_pv_v1_center);
    fclose(train_bir_X_pv_v1_center);
    fclose(train_bir_S_ex_pv_v1_center);

    fclose(train_bir_som_v1_center);
    fclose(train_bir_Input_som_v1_center);
    fclose(train_bir_X_som_v1_center);
    fclose(train_bir_S_ex_som_v1_center);
    fclose(train_bir_S_som_v1_center);
    //left
    fclose(train_bir_v1_left);
    fclose(train_bir_Input_v1_left);
    fclose(train_bir_X_v1_left);
    fclose(train_bir_S_ex_v1_left);
    fclose(train_bir_S_inh_v1_left);
    fclose(train_bir_Top_v1_left);
    fclose(train_bir_Bot_v1_left);
    fclose(train_bir_S_v1_left);

    fclose(train_bir_pv_v1_left);
    fclose(train_bir_Input_pv_v1_left);
    fclose(train_bir_X_pv_v1_left);
    fclose(train_bir_S_ex_pv_v1_left);
    fclose(train_bir_S_pv_v1_left);

    fclose(train_bir_som_v1_left);
    fclose(train_bir_Input_som_v1_left);
    fclose(train_bir_X_som_v1_left);
    fclose(train_bir_S_ex_som_v1_left);
    fclose(train_bir_S_som_v1_left);
    //right
    fclose(train_bir_v1_right);
    fclose(train_bir_Input_v1_right);
    fclose(train_bir_X_v1_right);
    fclose(train_bir_S_ex_v1_right);
    fclose(train_bir_S_inh_v1_right);
    fclose(train_bir_Top_v1_right);
    fclose(train_bir_Bot_v1_right);
    fclose(train_bir_S_v1_right);

    fclose(train_bir_pv_v1_right);
    fclose(train_bir_Input_pv_v1_right);
    fclose(train_bir_X_pv_v1_right);
    fclose(train_bir_S_ex_pv_v1_right);
    fclose(train_bir_S_pv_v1_right);

    fclose(train_bir_som_v1_right);
    fclose(train_bir_Input_som_v1_right);
    fclose(train_bir_X_som_v1_right);
    fclose(train_bir_S_ex_som_v1_right);
    fclose(train_bir_S_som_v1_right);
    //top
    fclose(train_bir_v1_top);
    fclose(train_bir_Input_v1_top);
    fclose(train_bir_X_v1_top);
    fclose(train_bir_S_ex_v1_top);
    fclose(train_bir_S_inh_v1_top);
    fclose(train_bir_Top_v1_top);
    fclose(train_bir_Bot_v1_top);
    fclose(train_bir_S_v1_top);

    fclose(train_bir_pv_v1_top);
    fclose(train_bir_Input_pv_v1_top);
    fclose(train_bir_X_pv_v1_top);
    fclose(train_bir_S_ex_pv_v1_top);
    fclose(train_bir_S_pv_v1_top);

    fclose(train_bir_som_v1_top);
    fclose(train_bir_Input_som_v1_top);
    fclose(train_bir_X_som_v1_top);
    fclose(train_bir_S_ex_som_v1_top);
    fclose(train_bir_S_som_v1_top);
    //bottom
    fclose(train_bir_v1_bottom);
    fclose(train_bir_Input_v1_bottom);
    fclose(train_bir_X_v1_bottom);
    fclose(train_bir_S_ex_v1_bottom);
    fclose(train_bir_S_inh_v1_bottom);
    fclose(train_bir_Top_v1_bottom);
    fclose(train_bir_Bot_v1_bottom);
    fclose(train_bir_S_v1_bottom);

    fclose(train_bir_pv_v1_bottom);
    fclose(train_bir_Input_pv_v1_bottom);
    fclose(train_bir_X_pv_v1_bottom);
    fclose(train_bir_S_ex_pv_v1_bottom);
    fclose(train_bir_S_pv_v1_bottom);

    fclose(train_bir_som_v1_bottom);
    fclose(train_bir_Input_som_v1_bottom);
    fclose(train_bir_X_som_v1_bottom);
    fclose(train_bir_S_ex_som_v1_bottom);
    fclose(train_bir_S_som_v1_bottom);
    //cross correlation
    fclose(bit_V1center);
    fclose(bit_V1left);
    fclose(bit_V1right);
    fclose(bit_V1top);
    fclose(bit_V1bottom);
    //LFP
    fclose(bir_lfp_v1_center_synapse);
    fclose(bir_lfp_v1_left_synapse);
    fclose(bir_lfp_v1_right_synapse);
    fclose(bir_lfp_v1_top_synapse);
    fclose(bir_lfp_v1_bottom_synapse);
    //tuning curve
    fclose(bir_tuning_V1);
    fclose(bir_tuning_V1_center);
    fclose(bir_tuning_V1_left);
    fclose(bir_tuning_V1_right);
    fclose(bir_tuning_V1_top);
    fclose(bir_tuning_V1_bottom);
}