/* Copyright (c) 2021 RT-JP All Right Reserved. */
//br = bisection relevant
//train = Training

//Train task VHO center
FILE *train_br_vho_center, *train_br_Input_vho_center, *train_br_X_vho_center, *train_br_S_ex_vho_center, *train_br_S_inh_from_pv_vho_center, *train_br_S_inh_from_som_vho_center, *train_br_Top_vho_center, *train_br_Bot_vho_center, *train_br_S_vho_center;
FILE *train_br_pv_vho_center, *train_br_Input_pv_vho_center, *train_br_X_pv_vho_center, *train_br_S_ex_pv_vho_center;
FILE *train_br_som_vho_center, *train_br_Input_som_vho_center, *train_br_X_som_vho_center, *train_br_S_ex_som_vho_center, *train_br_S_inh_som_vho_center, *train_br_S_som_vho_center;
//Train task VHO left
FILE *train_br_vho_left, *train_br_Input_vho_left, *train_br_X_vho_left, *train_br_S_ex_vho_left, *train_br_S_inh_vho_left, *train_br_Top_vho_left, *train_br_Bot_vho_left, *train_br_S_vho_left;
FILE *train_br_pv_vho_left, *train_br_Input_pv_vho_left, *train_br_X_pv_vho_left, *train_br_S_ex_pv_vho_left;
FILE *train_br_som_vho_left, *train_br_Input_som_vho_left, *train_br_X_som_vho_left, *train_br_S_ex_som_vho_left, *train_br_S_inh_som_vho_left;
//Train task VHO right
FILE *train_br_vho_right, *train_br_Input_vho_right, *train_br_X_vho_right, *train_br_S_ex_vho_right, *train_br_S_inh_vho_right, *train_br_Top_vho_right, *train_br_Bot_vho_right, *train_br_S_vho_right;
FILE *train_br_pv_vho_right, *train_br_Input_pv_vho_right, *train_br_X_pv_vho_right, *train_br_S_ex_pv_vho_right;
FILE *train_br_som_vho_right, *train_br_Input_som_vho_right, *train_br_X_som_vho_right, *train_br_S_ex_som_vho_right, *train_br_S_inh_som_vho_right;
//Train task VHO top
FILE *train_br_vho_top, *train_br_Input_vho_top, *train_br_X_vho_top, *train_br_S_ex_vho_top, *train_br_S_inh_vho_top, *train_br_Top_vho_top, *train_br_Bot_vho_top, *train_br_S_vho_top;
FILE *train_br_pv_vho_top, *train_br_Input_pv_vho_top, *train_br_X_pv_vho_top, *train_br_S_ex_pv_vho_top;
FILE *train_br_som_vho_top, *train_br_Input_som_vho_top, *train_br_X_som_vho_top, *train_br_S_ex_som_vho_top, *train_br_S_inh_som_vho_top;
//Train task VHO bottom
FILE *train_br_vho_bottom, *train_br_Input_vho_bottom, *train_br_X_vho_bottom, *train_br_S_ex_vho_bottom, *train_br_S_inh_vho_bottom, *train_br_Top_vho_bottom, *train_br_Bot_vho_bottom, *train_br_S_vho_bottom;
FILE *train_br_pv_vho_bottom, *train_br_Input_pv_vho_bottom, *train_br_X_pv_vho_bottom, *train_br_S_ex_pv_vho_bottom;
FILE *train_br_som_vho_bottom, *train_br_Input_som_vho_bottom, *train_br_X_som_vho_bottom, *train_br_S_ex_som_vho_bottom, *train_br_S_inh_som_vho_bottom;
//cross correlation
FILE *bit_VHOcenter, *bit_VHOleft, *bit_VHOright,  *bit_VHOtop, *bit_VHObottom;
//LFP
FILE *br_lfp_vho_center_synapse, *br_lfp_vho_left_synapse, *br_lfp_vho_right_synapse, *br_lfp_vho_top_synapse, *br_lfp_vho_bottom_synapse;
//vho tuning curve
FILE *br_tuning_VHO_center, *br_tuning_VHO_left, *br_tuning_VHO_right, *br_tuning_VHO_top, *br_tuning_VHO_bottom, *br_tuning_VHO;

void FileOpenVHO(void){
    //center
    train_br_vho_center = fopen("train_br_vho_center.csv", "w");
    train_br_Input_vho_center = fopen("train_br_Input_vho_center.csv", "w");
    train_br_X_vho_center = fopen("train_br_X_vho_center.csv", "w");
    train_br_S_ex_vho_center = fopen("train_br_S_ex_vho_center.csv", "w");
    train_br_S_inh_from_pv_vho_center = fopen("train_br_S_inh_from_pv_vho_center.csv", "w");
    train_br_S_inh_from_som_vho_center = fopen("train_br_S_inh_from_som_vho_center.csv", "w");
    train_br_Top_vho_center = fopen("train_br_Top_vho_center.csv", "w");
    train_br_Bot_vho_center = fopen("train_br_Bot_vho_center.csv", "w");
    train_br_S_vho_center = fopen("train_br_S_vho_center.csv", "w");

    train_br_pv_vho_center = fopen("train_br_pv_vho_center.csv", "w");
    train_br_Input_pv_vho_center = fopen("train_br_Input_pv_vho_center.csv", "w");
    train_br_X_pv_vho_center = fopen("train_br_X_pv_vho_center.csv", "w");
    train_br_S_ex_pv_vho_center = fopen("train_br_S_ex_pv_vho_center.csv", "w");
    
    train_br_som_vho_center = fopen("train_br_som_vho_center.csv", "w");
    train_br_Input_som_vho_center = fopen("train_br_Input_som_vho_center.csv", "w");
    train_br_X_som_vho_center = fopen("train_br_X_som_vho_center.csv", "w");
    train_br_S_ex_som_vho_center = fopen("train_br_S_ex_som_vho_center.csv", "w");
    train_br_S_inh_som_vho_center = fopen("train_br_S_inh_som_vho_center.csv", "w");
    train_br_S_som_vho_center = fopen("train_br_S_som_vho_center.csv", "w");
    //left
    train_br_vho_left = fopen("train_br_vho_left.csv", "w");
    train_br_Input_vho_left = fopen("train_br_Input_vho_left.csv", "w");
    train_br_X_vho_left = fopen("train_br_X_vho_left.csv", "w");
    train_br_S_ex_vho_left = fopen("train_br_S_ex_vho_left.csv", "w");
    train_br_S_inh_vho_left = fopen("train_br_S_inh_vho_left.csv", "w");
    train_br_Top_vho_left = fopen("train_br_Top_vho_left.csv", "w");
    train_br_Bot_vho_left = fopen("train_br_Bot_vho_left.csv", "w");
    train_br_S_vho_left = fopen("train_br_S_vho_left.csv", "w");

    train_br_pv_vho_left = fopen("train_br_pv_vho_left.csv", "w");
    train_br_Input_pv_vho_left = fopen("train_br_Input_pv_vho_left.csv", "w");
    train_br_X_pv_vho_left = fopen("train_br_X_pv_vho_left.csv", "w");
    train_br_S_ex_pv_vho_left = fopen("train_br_S_ex_pv_vho_left.csv", "w");

    train_br_som_vho_left = fopen("train_br_som_vho_left.csv", "w");
    train_br_Input_som_vho_left = fopen("train_br_Input_som_vho_left.csv", "w");
    train_br_X_som_vho_left = fopen("train_br_X_som_vho_left.csv", "w");
    train_br_S_ex_som_vho_left = fopen("train_br_S_ex_som_vho_left.csv", "w");
    train_br_S_inh_som_vho_left = fopen("train_br_S_inh_som_vho_left.csv", "w");
    //right
    train_br_vho_right = fopen("train_br_vho_right.csv", "w");
    train_br_Input_vho_right = fopen("train_br_Input_vho_right.csv", "w");
    train_br_X_vho_right = fopen("train_br_X_vho_right.csv", "w");
    train_br_S_ex_vho_right = fopen("train_br_S_ex_vho_right.csv", "w");
    train_br_S_inh_vho_right = fopen("train_br_S_inh_vho_right.csv", "w");
    train_br_Top_vho_right = fopen("train_br_Top_vho_right.csv", "w");
    train_br_Bot_vho_right = fopen("train_br_Bot_vho_right.csv", "w");
    train_br_S_vho_right = fopen("train_br_S_vho_right.csv", "w");

    train_br_pv_vho_right = fopen("train_br_pv_vho_right.csv", "w");
    train_br_Input_pv_vho_right = fopen("train_br_Input_pv_vho_right.csv", "w");
    train_br_X_pv_vho_right = fopen("train_br_X_pv_vho_right.csv", "w");
    train_br_S_ex_pv_vho_right = fopen("train_br_S_ex_pv_vho_right.csv", "w");

    train_br_som_vho_right = fopen("train_br_som_vho_right.csv", "w");
    train_br_Input_som_vho_right = fopen("train_br_Input_som_vho_right.csv", "w");
    train_br_X_som_vho_right = fopen("train_br_X_som_vho_right.csv", "w");
    train_br_S_ex_som_vho_right = fopen("train_br_S_ex_som_vho_right.csv", "w");
    train_br_S_inh_som_vho_right = fopen("train_br_S_inh_som_vho_right.csv", "w");
    //top
    train_br_vho_top = fopen("train_br_vho_top.csv", "w");
    train_br_Input_vho_top = fopen("train_br_Input_vho_top.csv", "w");
    train_br_X_vho_top = fopen("train_br_X_vho_top.csv", "w");
    train_br_S_ex_vho_top = fopen("train_br_S_ex_vho_top.csv", "w");
    train_br_S_inh_vho_top = fopen("train_br_S_inh_vho_top.csv", "w");
    train_br_Top_vho_top = fopen("train_br_Top_vho_top.csv", "w");
    train_br_Bot_vho_top = fopen("train_br_Bot_vho_top.csv", "w");
    train_br_S_vho_top = fopen("train_br_S_vho_top.csv", "w");

    train_br_pv_vho_top = fopen("train_br_pv_vho_top.csv", "w");
    train_br_Input_pv_vho_top = fopen("train_br_Input_pv_vho_top.csv", "w");
    train_br_X_pv_vho_top = fopen("train_br_X_pv_vho_top.csv", "w");
    train_br_S_ex_pv_vho_top = fopen("train_br_S_ex_pv_vho_top.csv", "w");

    train_br_som_vho_top = fopen("train_br_som_vho_top.csv", "w");
    train_br_Input_som_vho_top = fopen("train_br_Input_som_vho_top.csv", "w");
    train_br_X_som_vho_top = fopen("train_br_X_som_vho_top.csv", "w");
    train_br_S_ex_som_vho_top = fopen("train_br_S_ex_som_vho_top.csv", "w");
    train_br_S_inh_som_vho_top = fopen("train_br_S_inh_som_vho_top.csv", "w");
    //bottom
    train_br_vho_bottom = fopen("train_br_vho_bottom.csv", "w");
    train_br_Input_vho_bottom = fopen("train_br_Input_vho_bottom.csv", "w");
    train_br_X_vho_bottom = fopen("train_br_X_vho_bottom.csv", "w");
    train_br_S_ex_vho_bottom = fopen("train_br_S_ex_vho_bottom.csv", "w");
    train_br_S_inh_vho_bottom = fopen("train_br_S_inh_vho_bottom.csv", "w");
    train_br_Top_vho_bottom = fopen("train_br_Top_vho_bottom.csv", "w");
    train_br_Bot_vho_bottom = fopen("train_br_Bot_vho_bottom.csv", "w");
    train_br_S_vho_bottom = fopen("train_br_S_vho_bottom.csv", "w");

    train_br_pv_vho_bottom = fopen("train_br_pv_vho_bottom.csv", "w");
    train_br_Input_pv_vho_bottom = fopen("train_br_Input_pv_vho_bottom.csv", "w");
    train_br_X_pv_vho_bottom = fopen("train_br_X_pv_vho_bottom.csv", "w");
    train_br_S_ex_pv_vho_bottom = fopen("train_br_S_ex_pv_vho_bottom.csv", "w");

    train_br_som_vho_bottom = fopen("train_br_som_vho_bottom.csv", "w");
    train_br_Input_som_vho_bottom = fopen("train_br_Input_som_vho_bottom.csv", "w");
    train_br_X_som_vho_bottom = fopen("train_br_X_som_vho_bottom.csv", "w");
    train_br_S_ex_som_vho_bottom = fopen("train_br_S_ex_som_vho_bottom.csv", "w");
    train_br_S_inh_som_vho_bottom = fopen("train_br_S_inh_som_vho_bottom.csv", "w");
    //cross correlation
    bit_VHOcenter = fopen("br_bit_VHO_center.csv", "w");
    bit_VHOleft = fopen("br_bit_VHO_left.csv", "w");
    bit_VHOright = fopen("br_bit_VHO_right.csv", "w");
    bit_VHOtop = fopen("br_bit_VHO_top.csv", "w");
    bit_VHObottom = fopen("br_bit_VHO_bottom.csv", "w");
    //LFP
    br_lfp_vho_center_synapse = fopen("br_lfp_vho_center_synapse.csv", "w");
    br_lfp_vho_left_synapse = fopen("br_lfp_vho_left_synapse.csv", "w");
    br_lfp_vho_right_synapse = fopen("br_lfp_vho_right_synapse.csv", "w");
    br_lfp_vho_top_synapse = fopen("br_lfp_vho_top_synapse.csv", "w");
    br_lfp_vho_bottom_synapse = fopen("br_lfp_vho_bottom_synapse.csv", "w");
    //tuning curve
    br_tuning_VHO = fopen("br_tuning_VHO.csv", "w");
    br_tuning_VHO_center = fopen("br_tuning_VHO_center.csv", "w");
    br_tuning_VHO_left = fopen("br_tuning_VHO_left.csv", "w");
    br_tuning_VHO_right = fopen("br_tuning_VHO_right.csv", "w");
    br_tuning_VHO_top = fopen("br_tuning_VHO_top.csv", "w");
    br_tuning_VHO_bottom = fopen("br_tuning_VHO_bottom.csv", "w");
}

void FileClosevho(void){
    //center
    fclose(train_br_vho_center);
    fclose(train_br_Input_vho_center);
    fclose(train_br_X_vho_center);
    fclose(train_br_S_ex_vho_center);
    fclose(train_br_S_inh_from_pv_vho_center);
    fclose(train_br_S_inh_from_som_vho_center);
    fclose(train_br_Top_vho_center);
    fclose(train_br_Bot_vho_center);
    fclose(train_br_S_vho_center);

    fclose(train_br_pv_vho_center);
    fclose(train_br_Input_pv_vho_center);
    fclose(train_br_X_pv_vho_center);
    fclose(train_br_S_ex_pv_vho_center);

    fclose(train_br_som_vho_center);
    fclose(train_br_Input_som_vho_center);
    fclose(train_br_X_som_vho_center);
    fclose(train_br_S_ex_som_vho_center);
    fclose(train_br_S_inh_som_vho_center);
    fclose(train_br_S_som_vho_center);
    //left   
    fclose(train_br_vho_left);
    fclose(train_br_Input_vho_left);
    fclose(train_br_X_vho_left);
    fclose(train_br_S_ex_vho_left);
    fclose(train_br_S_inh_vho_left);
    fclose(train_br_Top_vho_left);
    fclose(train_br_Bot_vho_left);
    fclose(train_br_S_vho_left);

    fclose(train_br_pv_vho_left);
    fclose(train_br_Input_pv_vho_left);
    fclose(train_br_X_pv_vho_left);
    fclose(train_br_S_ex_pv_vho_left);

    fclose(train_br_som_vho_left);
    fclose(train_br_Input_som_vho_left);
    fclose(train_br_X_som_vho_left);
    fclose(train_br_S_ex_som_vho_left);
    fclose(train_br_S_inh_som_vho_left);
    //right    
    fclose(train_br_vho_right);
    fclose(train_br_Input_vho_right);
    fclose(train_br_X_vho_right);
    fclose(train_br_S_ex_vho_right);
    fclose(train_br_S_inh_vho_right);
    fclose(train_br_Top_vho_right);
    fclose(train_br_Bot_vho_right);
    fclose(train_br_S_vho_right);

    fclose(train_br_pv_vho_right);
    fclose(train_br_Input_pv_vho_right);
    fclose(train_br_X_pv_vho_right);
    fclose(train_br_S_ex_pv_vho_right);

    fclose(train_br_som_vho_right);
    fclose(train_br_Input_som_vho_right);
    fclose(train_br_X_som_vho_right);
    fclose(train_br_S_ex_som_vho_right);
    fclose(train_br_S_inh_som_vho_right);
    //top
    fclose(train_br_vho_top);
    fclose(train_br_Input_vho_top);
    fclose(train_br_X_vho_top);
    fclose(train_br_S_ex_vho_top);
    fclose(train_br_S_inh_vho_top);
    fclose(train_br_Top_vho_top);
    fclose(train_br_Bot_vho_top);
    fclose(train_br_S_vho_top);

    fclose(train_br_pv_vho_top);
    fclose(train_br_Input_pv_vho_top);
    fclose(train_br_X_pv_vho_top);
    fclose(train_br_S_ex_pv_vho_top);

    fclose(train_br_som_vho_top);
    fclose(train_br_Input_som_vho_top);
    fclose(train_br_X_som_vho_top);
    fclose(train_br_S_ex_som_vho_top);
    fclose(train_br_S_inh_som_vho_top);
    //bottom
    fclose(train_br_vho_bottom);
    fclose(train_br_Input_vho_bottom);
    fclose(train_br_X_vho_bottom);
    fclose(train_br_S_ex_vho_bottom);
    fclose(train_br_S_inh_vho_bottom);
    fclose(train_br_Top_vho_bottom);
    fclose(train_br_Bot_vho_bottom);
    fclose(train_br_S_vho_bottom);

    fclose(train_br_pv_vho_bottom);
    fclose(train_br_Input_pv_vho_bottom);
    fclose(train_br_X_pv_vho_bottom);
    fclose(train_br_S_ex_pv_vho_bottom);

    fclose(train_br_som_vho_bottom);
    fclose(train_br_Input_som_vho_bottom);
    fclose(train_br_X_som_vho_bottom);
    fclose(train_br_S_ex_som_vho_bottom);
    fclose(train_br_S_inh_som_vho_bottom);
    //cross correlation
    fclose(bit_VHOcenter);
    fclose(bit_VHOleft);
    fclose(bit_VHOright);
    fclose(bit_VHOtop);
    fclose(bit_VHObottom);
    //LFP
    fclose(br_lfp_vho_center_synapse);
    fclose(br_lfp_vho_left_synapse);
    fclose(br_lfp_vho_right_synapse);
    fclose(br_lfp_vho_top_synapse);
    fclose(br_lfp_vho_bottom_synapse);
    //tuning curve
    fclose(br_tuning_VHO);
    fclose(br_tuning_VHO_center);
    fclose(br_tuning_VHO_left);
    fclose(br_tuning_VHO_right);
    fclose(br_tuning_VHO_top);
    fclose(br_tuning_VHO_bottom);
}