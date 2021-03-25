/* Copyright (c) 2021 RT-JP All Right Reserved. */
//bir = bisection irrelevant
//train = Training

//Train task VHO center
FILE *train_bir_vho_center, *train_bir_Input_vho_center, *train_bir_X_vho_center, *train_bir_S_ex_vho_center, *train_bir_S_inh_from_pv_vho_center, *train_bir_S_inh_from_som_vho_center, *train_bir_Top_vho_center, *train_bir_Bot_vho_center, *train_bir_S_vho_center;
FILE *train_bir_pv_vho_center, *train_bir_Input_pv_vho_center, *train_bir_X_pv_vho_center, *train_bir_S_ex_pv_vho_center, *train_bir_S_inh_pv_vho_center, *train_bir_S_pv_vho_center;
FILE *train_bir_som_vho_center, *train_bir_Input_som_vho_center, *train_bir_X_som_vho_center, *train_bir_S_ex_som_vho_center, *train_bir_S_inh_som_vho_center, *train_bir_S_som_vho_center;
//Train task VHO left
FILE *train_bir_vho_left, *train_bir_Input_vho_left, *train_bir_X_vho_left, *train_bir_S_ex_vho_left, *train_bir_S_inh_vho_left, *train_bir_Top_vho_left, *train_bir_Bot_vho_left, *train_bir_S_vho_left;
FILE *train_bir_pv_vho_left, *train_bir_Input_pv_vho_left, *train_bir_X_pv_vho_left, *train_bir_S_ex_pv_vho_left, *train_bir_S_inh_pv_vho_left, *train_bir_S_pv_vho_left;
FILE *train_bir_som_vho_left, *train_bir_Input_som_vho_left, *train_bir_X_som_vho_left, *train_bir_S_ex_som_vho_left, *train_bir_S_inh_som_vho_left, *train_bir_S_som_vho_left;
//Train task VHO right
FILE *train_bir_vho_right, *train_bir_Input_vho_right, *train_bir_X_vho_right, *train_bir_S_ex_vho_right, *train_bir_S_inh_vho_right, *train_bir_Top_vho_right, *train_bir_Bot_vho_right, *train_bir_S_vho_right;
FILE *train_bir_pv_vho_right, *train_bir_Input_pv_vho_right, *train_bir_X_pv_vho_right, *train_bir_S_ex_pv_vho_right, *train_bir_S_inh_pv_vho_right, *train_bir_S_pv_vho_right;
FILE *train_bir_som_vho_right, *train_bir_Input_som_vho_right, *train_bir_X_som_vho_right, *train_bir_S_ex_som_vho_right, *train_bir_S_inh_som_vho_right, *train_bir_S_som_vho_right;
//Train task VHO top
FILE *train_bir_vho_top, *train_bir_Input_vho_top, *train_bir_X_vho_top, *train_bir_S_ex_vho_top, *train_bir_S_inh_vho_top, *train_bir_Top_vho_top, *train_bir_Bot_vho_top, *train_bir_S_vho_top;
FILE *train_bir_pv_vho_top, *train_bir_Input_pv_vho_top, *train_bir_X_pv_vho_top, *train_bir_S_ex_pv_vho_top, *train_bir_S_inh_pv_vho_top, *train_bir_S_pv_vho_top;
FILE *train_bir_som_vho_top, *train_bir_Input_som_vho_top, *train_bir_X_som_vho_top, *train_bir_S_ex_som_vho_top, *train_bir_S_inh_som_vho_top, *train_bir_S_som_vho_top;
//Train task VHO bottom
FILE *train_bir_vho_bottom, *train_bir_Input_vho_bottom, *train_bir_X_vho_bottom, *train_bir_S_ex_vho_bottom, *train_bir_S_inh_vho_bottom, *train_bir_Top_vho_bottom, *train_bir_Bot_vho_bottom, *train_bir_S_vho_bottom;
FILE *train_bir_pv_vho_bottom, *train_bir_Input_pv_vho_bottom, *train_bir_X_pv_vho_bottom, *train_bir_S_ex_pv_vho_bottom, *train_bir_S_inh_pv_vho_bottom, *train_bir_S_pv_vho_bottom;
FILE *train_bir_som_vho_bottom, *train_bir_Input_som_vho_bottom, *train_bir_X_som_vho_bottom, *train_bir_S_ex_som_vho_bottom, *train_bir_S_inh_som_vho_bottom, *train_bir_S_som_vho_bottom;
//cross correlation
FILE *bit_VHOcenter, *bit_VHOleft, *bit_VHOright,  *bit_VHOtop, *bit_VHObottom;
//LFP
FILE *bir_lfp_vho_center_synapse, *bir_lfp_vho_left_synapse, *bir_lfp_vho_right_synapse, *bir_lfp_vho_top_synapse, *bir_lfp_vho_bottom_synapse;
//VHO tuning curve
FILE *bir_tuning_VHO_center, *bir_tuning_VHO_left, *bir_tuning_VHO_right, *bir_tuning_VHO_top, *bir_tuning_VHO_bottom, *bir_tuning_VHO;

void FileOpenVHO(void){
    //center
    train_bir_vho_center = fopen("train_bir_vho_center.csv", "w");
    train_bir_Input_vho_center = fopen("train_bir_Input_vho_center.csv", "w");
    train_bir_X_vho_center = fopen("train_bir_X_vho_center.csv", "w");
    train_bir_S_ex_vho_center = fopen("train_bir_S_ex_vho_center.csv", "w");
    train_bir_S_inh_from_pv_vho_center = fopen("train_bir_S_inh_from_pv_vho_center.csv", "w");
    train_bir_S_inh_from_som_vho_center = fopen("train_bir_S_inh_from_som_vho_center.csv", "w");
    train_bir_Top_vho_center = fopen("train_bir_Top_vho_center.csv", "w");
    train_bir_Bot_vho_center = fopen("train_bir_Bot_vho_center.csv", "w");
    train_bir_S_vho_center = fopen("train_bir_S_vho_center.csv", "w");

    train_bir_pv_vho_center = fopen("train_bir_pv_vho_center.csv", "w");
    train_bir_Input_pv_vho_center = fopen("train_bir_Input_pv_vho_center.csv", "w");
    train_bir_X_pv_vho_center = fopen("train_bir_X_pv_vho_center.csv", "w");
    train_bir_S_ex_pv_vho_center = fopen("train_bir_S_ex_pv_vho_center.csv", "w");
    train_bir_S_inh_pv_vho_center = fopen("train_bir_S_inh_pv_vho_center.csv", "w");
    train_bir_S_pv_vho_center = fopen("train_bir_S_pv_vho_center.csv", "w");

    train_bir_som_vho_center = fopen("train_bir_som_vho_center.csv", "w");
    train_bir_Input_som_vho_center = fopen("train_bir_Input_som_vho_center.csv", "w");
    train_bir_X_som_vho_center = fopen("train_bir_X_som_vho_center.csv", "w");
    train_bir_S_ex_som_vho_center = fopen("train_bir_S_ex_som_vho_center.csv", "w");
    train_bir_S_inh_som_vho_center = fopen("train_bir_S_inh_som_vho_center.csv", "w");
    train_bir_S_som_vho_center = fopen("train_bir_S_som_vho_center.csv", "w");
    //left
    train_bir_vho_left = fopen("train_bir_vho_left.csv", "w");
    train_bir_Input_vho_left = fopen("train_bir_Input_vho_left.csv", "w");
    train_bir_X_vho_left = fopen("train_bir_X_vho_left.csv", "w");
    train_bir_S_ex_vho_left = fopen("train_bir_S_ex_vho_left.csv", "w");
    train_bir_S_inh_vho_left = fopen("train_bir_S_inh_vho_left.csv", "w");
    train_bir_Top_vho_left = fopen("train_bir_Top_vho_left.csv", "w");
    train_bir_Bot_vho_left = fopen("train_bir_Bot_vho_left.csv", "w");
    train_bir_S_vho_left = fopen("train_bir_S_vho_left.csv", "w");

    train_bir_pv_vho_left = fopen("train_bir_pv_vho_left.csv", "w");
    train_bir_Input_pv_vho_left = fopen("train_bir_Input_pv_vho_left.csv", "w");
    train_bir_X_pv_vho_left = fopen("train_bir_X_pv_vho_left.csv", "w");
    train_bir_S_ex_pv_vho_left = fopen("train_bir_S_ex_pv_vho_left.csv", "w");
    train_bir_S_inh_pv_vho_left = fopen("train_bir_S_inh_pv_vho_left.csv", "w");
    train_bir_S_pv_vho_left = fopen("train_bir_S_pv_vho_left.csv", "w");

    train_bir_som_vho_left = fopen("train_bir_som_vho_left.csv", "w");
    train_bir_Input_som_vho_left = fopen("train_bir_Input_som_vho_left.csv", "w");
    train_bir_X_som_vho_left = fopen("train_bir_X_som_vho_left.csv", "w");
    train_bir_S_ex_som_vho_left = fopen("train_bir_S_ex_som_vho_left.csv", "w");
    train_bir_S_inh_som_vho_left = fopen("train_bir_S_inh_som_vho_left.csv", "w");
    train_bir_S_som_vho_left = fopen("train_bir_S_som_vho_left.csv", "w");
    //right
    train_bir_vho_right = fopen("train_bir_vho_right.csv", "w");
    train_bir_Input_vho_right = fopen("train_bir_Input_vho_right.csv", "w");
    train_bir_X_vho_right = fopen("train_bir_X_vho_right.csv", "w");
    train_bir_S_ex_vho_right = fopen("train_bir_S_ex_vho_right.csv", "w");
    train_bir_S_inh_vho_right = fopen("train_bir_S_inh_vho_right.csv", "w");
    train_bir_Top_vho_right = fopen("train_bir_Top_vho_right.csv", "w");
    train_bir_Bot_vho_right = fopen("train_bir_Bot_vho_right.csv", "w");
    train_bir_S_vho_right = fopen("train_bir_S_vho_right.csv", "w");

    train_bir_pv_vho_right = fopen("train_bir_pv_vho_right.csv", "w");
    train_bir_Input_pv_vho_right = fopen("train_bir_Input_pv_vho_right.csv", "w");
    train_bir_X_pv_vho_right = fopen("train_bir_X_pv_vho_right.csv", "w");
    train_bir_S_ex_pv_vho_right = fopen("train_bir_S_ex_pv_vho_right.csv", "w");
    train_bir_S_inh_pv_vho_right = fopen("train_bir_S_inh_pv_vho_right.csv", "w");
    train_bir_S_pv_vho_right = fopen("train_bir_S_pv_vho_right.csv", "w");

    train_bir_som_vho_right = fopen("train_bir_som_vho_right.csv", "w");
    train_bir_Input_som_vho_right = fopen("train_bir_Input_som_vho_right.csv", "w");
    train_bir_X_som_vho_right = fopen("train_bir_X_som_vho_right.csv", "w");
    train_bir_S_ex_som_vho_right = fopen("train_bir_S_ex_som_vho_right.csv", "w");
    train_bir_S_inh_som_vho_right = fopen("train_bir_S_inh_som_vho_right.csv", "w");
    train_bir_S_som_vho_right = fopen("train_bir_S_som_vho_right.csv", "w");
    //top
    train_bir_vho_top = fopen("train_bir_vho_top.csv", "w");
    train_bir_Input_vho_top = fopen("train_bir_Input_vho_top.csv", "w");
    train_bir_X_vho_top = fopen("train_bir_X_vho_top.csv", "w");
    train_bir_S_ex_vho_top = fopen("train_bir_S_ex_vho_top.csv", "w");
    train_bir_S_inh_vho_top = fopen("train_bir_S_inh_vho_top.csv", "w");
    train_bir_Top_vho_top = fopen("train_bir_Top_vho_top.csv", "w");
    train_bir_Bot_vho_top = fopen("train_bir_Bot_vho_top.csv", "w");
    train_bir_S_vho_top = fopen("train_bir_S_vho_top.csv", "w");

    train_bir_pv_vho_top = fopen("train_bir_pv_vho_top.csv", "w");
    train_bir_Input_pv_vho_top = fopen("train_bir_Input_pv_vho_top.csv", "w");
    train_bir_X_pv_vho_top = fopen("train_bir_X_pv_vho_top.csv", "w");
    train_bir_S_ex_pv_vho_top = fopen("train_bir_S_ex_pv_vho_top.csv", "w");
    train_bir_S_inh_pv_vho_top = fopen("train_bir_S_inh_pv_vho_top.csv", "w");
    train_bir_S_pv_vho_top = fopen("train_bir_S_pv_vho_top.csv", "w");

    train_bir_som_vho_top = fopen("train_bir_som_vho_top.csv", "w");
    train_bir_Input_som_vho_top = fopen("train_bir_Input_som_vho_top.csv", "w");
    train_bir_X_som_vho_top = fopen("train_bir_X_som_vho_top.csv", "w");
    train_bir_S_ex_som_vho_top = fopen("train_bir_S_ex_som_vho_top.csv", "w");
    train_bir_S_inh_som_vho_top = fopen("train_bir_S_inh_som_vho_top.csv", "w");
    train_bir_S_som_vho_top = fopen("train_bir_S_som_vho_top.csv", "w");
    //bottom
    train_bir_vho_bottom = fopen("train_bir_vho_bottom.csv", "w");
    train_bir_Input_vho_bottom = fopen("train_bir_Input_vho_bottom.csv", "w");
    train_bir_X_vho_bottom = fopen("train_bir_X_vho_bottom.csv", "w");
    train_bir_S_ex_vho_bottom = fopen("train_bir_S_ex_vho_bottom.csv", "w");
    train_bir_S_inh_vho_bottom = fopen("train_bir_S_inh_vho_bottom.csv", "w");
    train_bir_Top_vho_bottom = fopen("train_bir_Top_vho_bottom.csv", "w");
    train_bir_Bot_vho_bottom = fopen("train_bir_Bot_vho_bottom.csv", "w");
    train_bir_S_vho_bottom = fopen("train_bir_S_vho_bottom.csv", "w");

    train_bir_pv_vho_bottom = fopen("train_bir_pv_vho_bottom.csv", "w");
    train_bir_Input_pv_vho_bottom = fopen("train_bir_Input_pv_vho_bottom.csv", "w");
    train_bir_X_pv_vho_bottom = fopen("train_bir_X_pv_vho_bottom.csv", "w");
    train_bir_S_ex_pv_vho_bottom = fopen("train_bir_S_ex_pv_vho_bottom.csv", "w");
    train_bir_S_inh_pv_vho_bottom = fopen("train_bir_S_inh_pv_vho_bottom.csv", "w");
    train_bir_S_pv_vho_bottom = fopen("train_bir_S_pv_vho_bottom.csv", "w");

    train_bir_som_vho_bottom = fopen("train_bir_som_vho_bottom.csv", "w");
    train_bir_Input_som_vho_bottom = fopen("train_bir_Input_som_vho_bottom.csv", "w");
    train_bir_X_som_vho_bottom = fopen("train_bir_X_som_vho_bottom.csv", "w");
    train_bir_S_ex_som_vho_bottom = fopen("train_bir_S_ex_som_vho_bottom.csv", "w");
    train_bir_S_inh_som_vho_bottom = fopen("train_bir_S_inh_som_vho_bottom.csv", "w");
    train_bir_S_som_vho_bottom = fopen("train_bir_S_som_vho_bottom.csv", "w");
    //cross correlation
    bit_VHOcenter = fopen("bir_bit_VHO_center.csv", "w");
    bit_VHOleft = fopen("bir_bit_VHO_left.csv", "w");
    bit_VHOright = fopen("bir_bit_VHO_right.csv", "w");
    bit_VHOtop = fopen("bir_bit_VHO_top.csv", "w");
    bit_VHObottom = fopen("bir_bit_VHO_bottom.csv", "w");
    //LFP
    bir_lfp_vho_center_synapse = fopen("bir_lfp_VHO_center_synapse.csv", "w");
    bir_lfp_vho_left_synapse = fopen("bir_lfp_VHO_left_synapse.csv", "w");
    bir_lfp_vho_right_synapse = fopen("bir_lfp_VHO_right_synapse.csv", "w");
    bir_lfp_vho_top_synapse = fopen("bir_lfp_VHO_top_synapse.csv", "w");
    bir_lfp_vho_bottom_synapse = fopen("bir_lfp_VHO_bottom_synapse.csv", "w");
    //tuning curve
    bir_tuning_VHO = fopen("bir_tuning_VHO.csv", "w");
    bir_tuning_VHO_center = fopen("bir_tuning_VHO_center.csv", "w");
    bir_tuning_VHO_left = fopen("bir_tuning_VHO_left.csv", "w");
    bir_tuning_VHO_right = fopen("bir_tuning_VHO_right.csv", "w");
    bir_tuning_VHO_top = fopen("bir_tuning_VHO_top.csv", "w");
    bir_tuning_VHO_bottom = fopen("bir_tuning_VHO_bottom.csv", "w");
}

void FileCloseVHO(void){
    //center
    fclose(train_bir_vho_center);
    fclose(train_bir_Input_vho_center);
    fclose(train_bir_X_vho_center);
    fclose(train_bir_S_ex_vho_center);
    fclose(train_bir_S_inh_from_pv_vho_center);
    fclose(train_bir_S_inh_from_som_vho_center);
    fclose(train_bir_Top_vho_center);
    fclose(train_bir_Bot_vho_center);
    fclose(train_bir_S_vho_center);

    fclose(train_bir_pv_vho_center);
    fclose(train_bir_Input_pv_vho_center);
    fclose(train_bir_X_pv_vho_center);
    fclose(train_bir_S_ex_pv_vho_center);
    fclose(train_bir_S_inh_pv_vho_center);
    fclose(train_bir_S_pv_vho_center);

    fclose(train_bir_som_vho_center);
    fclose(train_bir_Input_som_vho_center);
    fclose(train_bir_X_som_vho_center);
    fclose(train_bir_S_ex_som_vho_center);
    fclose(train_bir_S_inh_som_vho_center);
    fclose(train_bir_S_som_vho_center);
    //left
    fclose(train_bir_vho_left);
    fclose(train_bir_Input_vho_left);
    fclose(train_bir_X_vho_left);
    fclose(train_bir_S_ex_vho_left);
    fclose(train_bir_S_inh_vho_left);
    fclose(train_bir_Top_vho_left);
    fclose(train_bir_Bot_vho_left);
    fclose(train_bir_S_vho_left);

    fclose(train_bir_pv_vho_left);
    fclose(train_bir_Input_pv_vho_left);
    fclose(train_bir_X_pv_vho_left);
    fclose(train_bir_S_ex_pv_vho_left);
    fclose(train_bir_S_inh_pv_vho_left);
    fclose(train_bir_S_pv_vho_left);

    fclose(train_bir_som_vho_left);
    fclose(train_bir_Input_som_vho_left);
    fclose(train_bir_X_som_vho_left);
    fclose(train_bir_S_ex_som_vho_left);
    fclose(train_bir_S_inh_som_vho_left);
    fclose(train_bir_S_som_vho_left);
    //right
    fclose(train_bir_vho_right);
    fclose(train_bir_Input_vho_right);
    fclose(train_bir_X_vho_right);
    fclose(train_bir_S_ex_vho_right);
    fclose(train_bir_S_inh_vho_right);
    fclose(train_bir_Top_vho_right);
    fclose(train_bir_Bot_vho_right);
    fclose(train_bir_S_vho_right);

    fclose(train_bir_pv_vho_right);
    fclose(train_bir_Input_pv_vho_right);
    fclose(train_bir_X_pv_vho_right);
    fclose(train_bir_S_ex_pv_vho_right);
    fclose(train_bir_S_inh_pv_vho_right);
    fclose(train_bir_S_pv_vho_right);

    fclose(train_bir_som_vho_right);
    fclose(train_bir_Input_som_vho_right);
    fclose(train_bir_X_som_vho_right);
    fclose(train_bir_S_ex_som_vho_right);
    fclose(train_bir_S_inh_som_vho_right);
    fclose(train_bir_S_som_vho_right);
    //top
    fclose(train_bir_vho_top);
    fclose(train_bir_Input_vho_top);
    fclose(train_bir_X_vho_top);
    fclose(train_bir_S_ex_vho_top);
    fclose(train_bir_S_inh_vho_top);
    fclose(train_bir_Top_vho_top);
    fclose(train_bir_Bot_vho_top);
    fclose(train_bir_S_vho_top);

    fclose(train_bir_pv_vho_top);
    fclose(train_bir_Input_pv_vho_top);
    fclose(train_bir_X_pv_vho_top);
    fclose(train_bir_S_ex_pv_vho_top);
    fclose(train_bir_S_inh_pv_vho_top);
    fclose(train_bir_S_pv_vho_top);

    fclose(train_bir_som_vho_top);
    fclose(train_bir_Input_som_vho_top);
    fclose(train_bir_X_som_vho_top);
    fclose(train_bir_S_ex_som_vho_top);
    fclose(train_bir_S_inh_som_vho_top);
    fclose(train_bir_S_som_vho_top);
    //bottom
    fclose(train_bir_vho_bottom);
    fclose(train_bir_Input_vho_bottom);
    fclose(train_bir_X_vho_bottom);
    fclose(train_bir_S_ex_vho_bottom);
    fclose(train_bir_S_inh_vho_bottom);
    fclose(train_bir_Top_vho_bottom);
    fclose(train_bir_Bot_vho_bottom);
    fclose(train_bir_S_vho_bottom);

    fclose(train_bir_pv_vho_bottom);
    fclose(train_bir_Input_pv_vho_bottom);
    fclose(train_bir_X_pv_vho_bottom);
    fclose(train_bir_S_ex_pv_vho_bottom);
    fclose(train_bir_S_inh_pv_vho_bottom);
    fclose(train_bir_S_pv_vho_bottom);

    fclose(train_bir_som_vho_bottom);
    fclose(train_bir_Input_som_vho_bottom);
    fclose(train_bir_X_som_vho_bottom);
    fclose(train_bir_S_ex_som_vho_bottom);
    fclose(train_bir_S_inh_som_vho_bottom);
    fclose(train_bir_S_som_vho_bottom);
    //cross correlation
    fclose(bit_VHOcenter);
    fclose(bit_VHOleft);
    fclose(bit_VHOright);
    fclose(bit_VHOtop);
    fclose(bit_VHObottom);
    //LFP
    fclose(bir_lfp_vho_center_synapse);
    fclose(bir_lfp_vho_left_synapse);
    fclose(bir_lfp_vho_right_synapse);
    fclose(bir_lfp_vho_top_synapse);
    fclose(bir_lfp_vho_bottom_synapse);
    //tuning curve
    fclose(bir_tuning_VHO);
    fclose(bir_tuning_VHO_center);
    fclose(bir_tuning_VHO_left);
    fclose(bir_tuning_VHO_right);
    fclose(bir_tuning_VHO_top);
    fclose(bir_tuning_VHO_bottom);
}