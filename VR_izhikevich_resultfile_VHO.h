/* Copyright (c) 2021 RT-JP All Right Reserved. */
//vr = vernier relevant
//train = Training

//Train task VHO center
FILE *train_vr_vho_center, *train_vr_Input_vho_center, *train_vr_X_vho_center, *train_vr_S_ex_vho_center, *train_vr_S_inh_from_pv_vho_center, *train_vr_S_inh_from_som_vho_center, *train_vr_Top_vho_center, *train_vr_Bot_vho_center, *train_vr_S_vho_center;
FILE *train_vr_pv_vho_center, *train_vr_Input_pv_vho_center, *train_vr_X_pv_vho_center, *train_vr_S_ex_pv_vho_center;
FILE *train_vr_som_vho_center, *train_vr_Input_som_vho_center, *train_vr_X_som_vho_center, *train_vr_S_ex_som_vho_center, *train_vr_S_inh_som_vho_center, *train_vr_S_som_vho_center;
//Train task VHO left
FILE *train_vr_vho_left, *train_vr_Input_vho_left, *train_vr_X_vho_left, *train_vr_S_ex_vho_left, *train_vr_S_inh_vho_left, *train_vr_Top_vho_left, *train_vr_Bot_vho_left, *train_vr_S_vho_left;
FILE *train_vr_pv_vho_left, *train_vr_Input_pv_vho_left, *train_vr_X_pv_vho_left, *train_vr_S_ex_pv_vho_left;
FILE *train_vr_som_vho_left, *train_vr_Input_som_vho_left, *train_vr_X_som_vho_left, *train_vr_S_ex_som_vho_left, *train_vr_S_inh_som_vho_left;
//Train task VHO right
FILE *train_vr_vho_right, *train_vr_Input_vho_right, *train_vr_X_vho_right, *train_vr_S_ex_vho_right, *train_vr_S_inh_vho_right, *train_vr_Top_vho_right, *train_vr_Bot_vho_right, *train_vr_S_vho_right;
FILE *train_vr_pv_vho_right, *train_vr_Input_pv_vho_right, *train_vr_X_pv_vho_right, *train_vr_S_ex_pv_vho_right;
FILE *train_vr_som_vho_right, *train_vr_Input_som_vho_right, *train_vr_X_som_vho_right, *train_vr_S_ex_som_vho_right, *train_vr_S_inh_som_vho_right;
//Train task VHO top
FILE *train_vr_vho_top, *train_vr_Input_vho_top, *train_vr_X_vho_top, *train_vr_S_ex_vho_top, *train_vr_S_inh_vho_top, *train_vr_Top_vho_top, *train_vr_Bot_vho_top, *train_vr_S_vho_top;
FILE *train_vr_pv_vho_top, *train_vr_Input_pv_vho_top, *train_vr_X_pv_vho_top, *train_vr_S_ex_pv_vho_top;
FILE *train_vr_som_vho_top, *train_vr_Input_som_vho_top, *train_vr_X_som_vho_top, *train_vr_S_ex_som_vho_top, *train_vr_S_inh_som_vho_top;
//Train task VHO bottom
FILE *train_vr_vho_bottom, *train_vr_Input_vho_bottom, *train_vr_X_vho_bottom, *train_vr_S_ex_vho_bottom, *train_vr_S_inh_vho_bottom, *train_vr_Top_vho_bottom, *train_vr_Bot_vho_bottom, *train_vr_S_vho_bottom;
FILE *train_vr_pv_vho_bottom, *train_vr_Input_pv_vho_bottom, *train_vr_X_pv_vho_bottom, *train_vr_S_ex_pv_vho_bottom;
FILE *train_vr_som_vho_bottom, *train_vr_Input_som_vho_bottom, *train_vr_X_som_vho_bottom, *train_vr_S_ex_som_vho_bottom, *train_vr_S_inh_som_vho_bottom;
//cross correlation
FILE *bit_VHOcenter, *bit_VHOleft, *bit_VHOright,  *bit_VHOtop, *bit_VHObottom;
//LFP
FILE *vr_lfp_vho_center_synapse, *vr_lfp_vho_left_synapse, *vr_lfp_vho_right_synapse, *vr_lfp_vho_top_synapse, *vr_lfp_vho_bottom_synapse;
//vho tuning curve
FILE *vr_tuning_VHO_center, *vr_tuning_VHO_left, *vr_tuning_VHO_right, *vr_tuning_VHO_top, *vr_tuning_VHO_bottom, *vr_tuning_VHO;

void FileOpenVHO(void){
    //center
    train_vr_vho_center = fopen("train_vr_vho_center.csv", "w");
    train_vr_Input_vho_center = fopen("train_vr_Input_vho_center.csv", "w");
    train_vr_X_vho_center = fopen("train_vr_X_vho_center.csv", "w");
    train_vr_S_ex_vho_center = fopen("train_vr_S_ex_vho_center.csv", "w");
    train_vr_S_inh_from_pv_vho_center = fopen("train_vr_S_inh_from_pv_vho_center.csv", "w");
    train_vr_S_inh_from_som_vho_center = fopen("train_vr_S_inh_from_som_vho_center.csv", "w");
    train_vr_Top_vho_center = fopen("train_vr_Top_vho_center.csv", "w");
    train_vr_Bot_vho_center = fopen("train_vr_Bot_vho_center.csv", "w");
    train_vr_S_vho_center = fopen("train_vr_S_vho_center.csv", "w");

    train_vr_pv_vho_center = fopen("train_vr_pv_vho_center.csv", "w");
    train_vr_Input_pv_vho_center = fopen("train_vr_Input_pv_vho_center.csv", "w");
    train_vr_X_pv_vho_center = fopen("train_vr_X_pv_vho_center.csv", "w");
    train_vr_S_ex_pv_vho_center = fopen("train_vr_S_ex_pv_vho_center.csv", "w");
    
    train_vr_som_vho_center = fopen("train_vr_som_vho_center.csv", "w");
    train_vr_Input_som_vho_center = fopen("train_vr_Input_som_vho_center.csv", "w");
    train_vr_X_som_vho_center = fopen("train_vr_X_som_vho_center.csv", "w");
    train_vr_S_ex_som_vho_center = fopen("train_vr_S_ex_som_vho_center.csv", "w");
    train_vr_S_inh_som_vho_center = fopen("train_vr_S_inh_som_vho_center.csv", "w");
    train_vr_S_som_vho_center = fopen("train_vr_S_som_vho_center.csv", "w");
    //left
    train_vr_vho_left = fopen("train_vr_vho_left.csv", "w");
    train_vr_Input_vho_left = fopen("train_vr_Input_vho_left.csv", "w");
    train_vr_X_vho_left = fopen("train_vr_X_vho_left.csv", "w");
    train_vr_S_ex_vho_left = fopen("train_vr_S_ex_vho_left.csv", "w");
    train_vr_S_inh_vho_left = fopen("train_vr_S_inh_vho_left.csv", "w");
    train_vr_Top_vho_left = fopen("train_vr_Top_vho_left.csv", "w");
    train_vr_Bot_vho_left = fopen("train_vr_Bot_vho_left.csv", "w");
    train_vr_S_vho_left = fopen("train_vr_S_vho_left.csv", "w");

    train_vr_pv_vho_left = fopen("train_vr_pv_vho_left.csv", "w");
    train_vr_Input_pv_vho_left = fopen("train_vr_Input_pv_vho_left.csv", "w");
    train_vr_X_pv_vho_left = fopen("train_vr_X_pv_vho_left.csv", "w");
    train_vr_S_ex_pv_vho_left = fopen("train_vr_S_ex_pv_vho_left.csv", "w");

    train_vr_som_vho_left = fopen("train_vr_som_vho_left.csv", "w");
    train_vr_Input_som_vho_left = fopen("train_vr_Input_som_vho_left.csv", "w");
    train_vr_X_som_vho_left = fopen("train_vr_X_som_vho_left.csv", "w");
    train_vr_S_ex_som_vho_left = fopen("train_vr_S_ex_som_vho_left.csv", "w");
    train_vr_S_inh_som_vho_left = fopen("train_vr_S_inh_som_vho_left.csv", "w");
    //right
    train_vr_vho_right = fopen("train_vr_vho_right.csv", "w");
    train_vr_Input_vho_right = fopen("train_vr_Input_vho_right.csv", "w");
    train_vr_X_vho_right = fopen("train_vr_X_vho_right.csv", "w");
    train_vr_S_ex_vho_right = fopen("train_vr_S_ex_vho_right.csv", "w");
    train_vr_S_inh_vho_right = fopen("train_vr_S_inh_vho_right.csv", "w");
    train_vr_Top_vho_right = fopen("train_vr_Top_vho_right.csv", "w");
    train_vr_Bot_vho_right = fopen("train_vr_Bot_vho_right.csv", "w");
    train_vr_S_vho_right = fopen("train_vr_S_vho_right.csv", "w");

    train_vr_pv_vho_right = fopen("train_vr_pv_vho_right.csv", "w");
    train_vr_Input_pv_vho_right = fopen("train_vr_Input_pv_vho_right.csv", "w");
    train_vr_X_pv_vho_right = fopen("train_vr_X_pv_vho_right.csv", "w");
    train_vr_S_ex_pv_vho_right = fopen("train_vr_S_ex_pv_vho_right.csv", "w");

    train_vr_som_vho_right = fopen("train_vr_som_vho_right.csv", "w");
    train_vr_Input_som_vho_right = fopen("train_vr_Input_som_vho_right.csv", "w");
    train_vr_X_som_vho_right = fopen("train_vr_X_som_vho_right.csv", "w");
    train_vr_S_ex_som_vho_right = fopen("train_vr_S_ex_som_vho_right.csv", "w");
    train_vr_S_inh_som_vho_right = fopen("train_vr_S_inh_som_vho_right.csv", "w");
    //top
    train_vr_vho_top = fopen("train_vr_vho_top.csv", "w");
    train_vr_Input_vho_top = fopen("train_vr_Input_vho_top.csv", "w");
    train_vr_X_vho_top = fopen("train_vr_X_vho_top.csv", "w");
    train_vr_S_ex_vho_top = fopen("train_vr_S_ex_vho_top.csv", "w");
    train_vr_S_inh_vho_top = fopen("train_vr_S_inh_vho_top.csv", "w");
    train_vr_Top_vho_top = fopen("train_vr_Top_vho_top.csv", "w");
    train_vr_Bot_vho_top = fopen("train_vr_Bot_vho_top.csv", "w");
    train_vr_S_vho_top = fopen("train_vr_S_vho_top.csv", "w");

    train_vr_pv_vho_top = fopen("train_vr_pv_vho_top.csv", "w");
    train_vr_Input_pv_vho_top = fopen("train_vr_Input_pv_vho_top.csv", "w");
    train_vr_X_pv_vho_top = fopen("train_vr_X_pv_vho_top.csv", "w");
    train_vr_S_ex_pv_vho_top = fopen("train_vr_S_ex_pv_vho_top.csv", "w");

    train_vr_som_vho_top = fopen("train_vr_som_vho_top.csv", "w");
    train_vr_Input_som_vho_top = fopen("train_vr_Input_som_vho_top.csv", "w");
    train_vr_X_som_vho_top = fopen("train_vr_X_som_vho_top.csv", "w");
    train_vr_S_ex_som_vho_top = fopen("train_vr_S_ex_som_vho_top.csv", "w");
    train_vr_S_inh_som_vho_top = fopen("train_vr_S_inh_som_vho_top.csv", "w");
    //bottom
    train_vr_vho_bottom = fopen("train_vr_vho_bottom.csv", "w");
    train_vr_Input_vho_bottom = fopen("train_vr_Input_vho_bottom.csv", "w");
    train_vr_X_vho_bottom = fopen("train_vr_X_vho_bottom.csv", "w");
    train_vr_S_ex_vho_bottom = fopen("train_vr_S_ex_vho_bottom.csv", "w");
    train_vr_S_inh_vho_bottom = fopen("train_vr_S_inh_vho_bottom.csv", "w");
    train_vr_Top_vho_bottom = fopen("train_vr_Top_vho_bottom.csv", "w");
    train_vr_Bot_vho_bottom = fopen("train_vr_Bot_vho_bottom.csv", "w");
    train_vr_S_vho_bottom = fopen("train_vr_S_vho_bottom.csv", "w");

    train_vr_pv_vho_bottom = fopen("train_vr_pv_vho_bottom.csv", "w");
    train_vr_Input_pv_vho_bottom = fopen("train_vr_Input_pv_vho_bottom.csv", "w");
    train_vr_X_pv_vho_bottom = fopen("train_vr_X_pv_vho_bottom.csv", "w");
    train_vr_S_ex_pv_vho_bottom = fopen("train_vr_S_ex_pv_vho_bottom.csv", "w");

    train_vr_som_vho_bottom = fopen("train_vr_som_vho_bottom.csv", "w");
    train_vr_Input_som_vho_bottom = fopen("train_vr_Input_som_vho_bottom.csv", "w");
    train_vr_X_som_vho_bottom = fopen("train_vr_X_som_vho_bottom.csv", "w");
    train_vr_S_ex_som_vho_bottom = fopen("train_vr_S_ex_som_vho_bottom.csv", "w");
    train_vr_S_inh_som_vho_bottom = fopen("train_vr_S_inh_som_vho_bottom.csv", "w");
    //cross correlation
    bit_VHOcenter = fopen("vr_bit_VHO_center.csv", "w");
    bit_VHOleft = fopen("vr_bit_VHO_left.csv", "w");
    bit_VHOright = fopen("vr_bit_VHO_right.csv", "w");
    bit_VHOtop = fopen("vr_bit_VHO_top.csv", "w");
    bit_VHObottom = fopen("vr_bit_VHO_bottom.csv", "w");
    //LFP
    vr_lfp_vho_center_synapse = fopen("vr_lfp_vho_center_synapse.csv", "w");
    vr_lfp_vho_left_synapse = fopen("vr_lfp_vho_left_synapse.csv", "w");
    vr_lfp_vho_right_synapse = fopen("vr_lfp_vho_right_synapse.csv", "w");
    vr_lfp_vho_top_synapse = fopen("vr_lfp_vho_top_synapse.csv", "w");
    vr_lfp_vho_bottom_synapse = fopen("vr_lfp_vho_bottom_synapse.csv", "w");
    //tuning curve
    vr_tuning_VHO = fopen("vr_tuning_VHO.csv", "w");
    vr_tuning_VHO_center = fopen("vr_tuning_VHO_center.csv", "w");
    vr_tuning_VHO_left = fopen("vr_tuning_VHO_left.csv", "w");
    vr_tuning_VHO_right = fopen("vr_tuning_VHO_right.csv", "w");
    vr_tuning_VHO_top = fopen("vr_tuning_VHO_top.csv", "w");
    vr_tuning_VHO_bottom = fopen("vr_tuning_VHO_bottom.csv", "w");
}

void FileClosevho(void){
    //center
    fclose(train_vr_vho_center);
    fclose(train_vr_Input_vho_center);
    fclose(train_vr_X_vho_center);
    fclose(train_vr_S_ex_vho_center);
    fclose(train_vr_S_inh_from_pv_vho_center);
    fclose(train_vr_S_inh_from_som_vho_center);
    fclose(train_vr_Top_vho_center);
    fclose(train_vr_Bot_vho_center);
    fclose(train_vr_S_vho_center);

    fclose(train_vr_pv_vho_center);
    fclose(train_vr_Input_pv_vho_center);
    fclose(train_vr_X_pv_vho_center);
    fclose(train_vr_S_ex_pv_vho_center);

    fclose(train_vr_som_vho_center);
    fclose(train_vr_Input_som_vho_center);
    fclose(train_vr_X_som_vho_center);
    fclose(train_vr_S_ex_som_vho_center);
    fclose(train_vr_S_inh_som_vho_center);
    fclose(train_vr_S_som_vho_center);
    //left   
    fclose(train_vr_vho_left);
    fclose(train_vr_Input_vho_left);
    fclose(train_vr_X_vho_left);
    fclose(train_vr_S_ex_vho_left);
    fclose(train_vr_S_inh_vho_left);
    fclose(train_vr_Top_vho_left);
    fclose(train_vr_Bot_vho_left);
    fclose(train_vr_S_vho_left);

    fclose(train_vr_pv_vho_left);
    fclose(train_vr_Input_pv_vho_left);
    fclose(train_vr_X_pv_vho_left);
    fclose(train_vr_S_ex_pv_vho_left);

    fclose(train_vr_som_vho_left);
    fclose(train_vr_Input_som_vho_left);
    fclose(train_vr_X_som_vho_left);
    fclose(train_vr_S_ex_som_vho_left);
    fclose(train_vr_S_inh_som_vho_left);
    //right    
    fclose(train_vr_vho_right);
    fclose(train_vr_Input_vho_right);
    fclose(train_vr_X_vho_right);
    fclose(train_vr_S_ex_vho_right);
    fclose(train_vr_S_inh_vho_right);
    fclose(train_vr_Top_vho_right);
    fclose(train_vr_Bot_vho_right);
    fclose(train_vr_S_vho_right);

    fclose(train_vr_pv_vho_right);
    fclose(train_vr_Input_pv_vho_right);
    fclose(train_vr_X_pv_vho_right);
    fclose(train_vr_S_ex_pv_vho_right);

    fclose(train_vr_som_vho_right);
    fclose(train_vr_Input_som_vho_right);
    fclose(train_vr_X_som_vho_right);
    fclose(train_vr_S_ex_som_vho_right);
    fclose(train_vr_S_inh_som_vho_right);
    //top
    fclose(train_vr_vho_top);
    fclose(train_vr_Input_vho_top);
    fclose(train_vr_X_vho_top);
    fclose(train_vr_S_ex_vho_top);
    fclose(train_vr_S_inh_vho_top);
    fclose(train_vr_Top_vho_top);
    fclose(train_vr_Bot_vho_top);
    fclose(train_vr_S_vho_top);

    fclose(train_vr_pv_vho_top);
    fclose(train_vr_Input_pv_vho_top);
    fclose(train_vr_X_pv_vho_top);
    fclose(train_vr_S_ex_pv_vho_top);

    fclose(train_vr_som_vho_top);
    fclose(train_vr_Input_som_vho_top);
    fclose(train_vr_X_som_vho_top);
    fclose(train_vr_S_ex_som_vho_top);
    fclose(train_vr_S_inh_som_vho_top);
    //bottom
    fclose(train_vr_vho_bottom);
    fclose(train_vr_Input_vho_bottom);
    fclose(train_vr_X_vho_bottom);
    fclose(train_vr_S_ex_vho_bottom);
    fclose(train_vr_S_inh_vho_bottom);
    fclose(train_vr_Top_vho_bottom);
    fclose(train_vr_Bot_vho_bottom);
    fclose(train_vr_S_vho_bottom);

    fclose(train_vr_pv_vho_bottom);
    fclose(train_vr_Input_pv_vho_bottom);
    fclose(train_vr_X_pv_vho_bottom);
    fclose(train_vr_S_ex_pv_vho_bottom);

    fclose(train_vr_som_vho_bottom);
    fclose(train_vr_Input_som_vho_bottom);
    fclose(train_vr_X_som_vho_bottom);
    fclose(train_vr_S_ex_som_vho_bottom);
    fclose(train_vr_S_inh_som_vho_bottom);
    //cross correlation
    fclose(bit_VHOcenter);
    fclose(bit_VHOleft);
    fclose(bit_VHOright);
    fclose(bit_VHOtop);
    fclose(bit_VHObottom);
    //LFP
    fclose(vr_lfp_vho_center_synapse);
    fclose(vr_lfp_vho_left_synapse);
    fclose(vr_lfp_vho_right_synapse);
    fclose(vr_lfp_vho_top_synapse);
    fclose(vr_lfp_vho_bottom_synapse);
    //tuning curve
    fclose(vr_tuning_VHO);
    fclose(vr_tuning_VHO_center);
    fclose(vr_tuning_VHO_left);
    fclose(vr_tuning_VHO_right);
    fclose(vr_tuning_VHO_top);
    fclose(vr_tuning_VHO_bottom);
}