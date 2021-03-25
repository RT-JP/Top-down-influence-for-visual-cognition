/* Copyright (c) 2021 RT-JP All Right Reserved. */
//vir = vernier irrelevant
//train = Training

//Train task VHO center
FILE *train_vir_vho_center, *train_vir_Input_vho_center, *train_vir_X_vho_center, *train_vir_S_ex_vho_center, *train_vir_S_inh_from_pv_vho_center, *train_vir_S_inh_from_som_vho_center, *train_vir_Top_vho_center, *train_vir_Bot_vho_center, *train_vir_S_vho_center;
FILE *train_vir_pv_vho_center, *train_vir_Input_pv_vho_center, *train_vir_X_pv_vho_center, *train_vir_S_ex_pv_vho_center, *train_vir_S_inh_pv_vho_center, *train_vir_S_pv_vho_center;
FILE *train_vir_som_vho_center, *train_vir_Input_som_vho_center, *train_vir_X_som_vho_center, *train_vir_S_ex_som_vho_center, *train_vir_S_inh_som_vho_center, *train_vir_S_som_vho_center;
//Train task VHO left
FILE *train_vir_vho_left, *train_vir_Input_vho_left, *train_vir_X_vho_left, *train_vir_S_ex_vho_left, *train_vir_S_inh_vho_left, *train_vir_Top_vho_left, *train_vir_Bot_vho_left, *train_vir_S_vho_left;
FILE *train_vir_pv_vho_left, *train_vir_Input_pv_vho_left, *train_vir_X_pv_vho_left, *train_vir_S_ex_pv_vho_left, *train_vir_S_inh_pv_vho_left, *train_vir_S_pv_vho_left;
FILE *train_vir_som_vho_left, *train_vir_Input_som_vho_left, *train_vir_X_som_vho_left, *train_vir_S_ex_som_vho_left, *train_vir_S_inh_som_vho_left, *train_vir_S_som_vho_left;
//Train task VHO right
FILE *train_vir_vho_right, *train_vir_Input_vho_right, *train_vir_X_vho_right, *train_vir_S_ex_vho_right, *train_vir_S_inh_vho_right, *train_vir_Top_vho_right, *train_vir_Bot_vho_right, *train_vir_S_vho_right;
FILE *train_vir_pv_vho_right, *train_vir_Input_pv_vho_right, *train_vir_X_pv_vho_right, *train_vir_S_ex_pv_vho_right, *train_vir_S_inh_pv_vho_right, *train_vir_S_pv_vho_right;
FILE *train_vir_som_vho_right, *train_vir_Input_som_vho_right, *train_vir_X_som_vho_right, *train_vir_S_ex_som_vho_right, *train_vir_S_inh_som_vho_right, *train_vir_S_som_vho_right;
//Train task VHO top
FILE *train_vir_vho_top, *train_vir_Input_vho_top, *train_vir_X_vho_top, *train_vir_S_ex_vho_top, *train_vir_S_inh_vho_top, *train_vir_Top_vho_top, *train_vir_Bot_vho_top, *train_vir_S_vho_top;
FILE *train_vir_pv_vho_top, *train_vir_Input_pv_vho_top, *train_vir_X_pv_vho_top, *train_vir_S_ex_pv_vho_top, *train_vir_S_inh_pv_vho_top, *train_vir_S_pv_vho_top;
FILE *train_vir_som_vho_top, *train_vir_Input_som_vho_top, *train_vir_X_som_vho_top, *train_vir_S_ex_som_vho_top, *train_vir_S_inh_som_vho_top, *train_vir_S_som_vho_top;
//Train task VHO bottom
FILE *train_vir_vho_bottom, *train_vir_Input_vho_bottom, *train_vir_X_vho_bottom, *train_vir_S_ex_vho_bottom, *train_vir_S_inh_vho_bottom, *train_vir_Top_vho_bottom, *train_vir_Bot_vho_bottom, *train_vir_S_vho_bottom;
FILE *train_vir_pv_vho_bottom, *train_vir_Input_pv_vho_bottom, *train_vir_X_pv_vho_bottom, *train_vir_S_ex_pv_vho_bottom, *train_vir_S_inh_pv_vho_bottom, *train_vir_S_pv_vho_bottom;
FILE *train_vir_som_vho_bottom, *train_vir_Input_som_vho_bottom, *train_vir_X_som_vho_bottom, *train_vir_S_ex_som_vho_bottom, *train_vir_S_inh_som_vho_bottom, *train_vir_S_som_vho_bottom;
//cross correlation
FILE *bit_VHOcenter, *bit_VHOleft, *bit_VHOright,  *bit_VHOtop, *bit_VHObottom;
//LFP
FILE *vir_lfp_vho_center_synapse, *vir_lfp_vho_left_synapse, *vir_lfp_vho_right_synapse, *vir_lfp_vho_top_synapse, *vir_lfp_vho_bottom_synapse;
//VHO tuning curve
FILE *vir_tuning_VHO_center, *vir_tuning_VHO_left, *vir_tuning_VHO_right, *vir_tuning_VHO_top, *vir_tuning_VHO_bottom, *vir_tuning_VHO;

void FileOpenVHO(void){
    //center
    train_vir_vho_center = fopen("train_vir_vho_center.csv", "w");
    train_vir_Input_vho_center = fopen("train_vir_Input_vho_center.csv", "w");
    train_vir_X_vho_center = fopen("train_vir_X_vho_center.csv", "w");
    train_vir_S_ex_vho_center = fopen("train_vir_S_ex_vho_center.csv", "w");
    train_vir_S_inh_from_pv_vho_center = fopen("train_vir_S_inh_from_pv_vho_center.csv", "w");
    train_vir_S_inh_from_som_vho_center = fopen("train_vir_S_inh_from_som_vho_center.csv", "w");
    train_vir_Top_vho_center = fopen("train_vir_Top_vho_center.csv", "w");
    train_vir_Bot_vho_center = fopen("train_vir_Bot_vho_center.csv", "w");
    train_vir_S_vho_center = fopen("train_vir_S_vho_center.csv", "w");

    train_vir_pv_vho_center = fopen("train_vir_pv_vho_center.csv", "w");
    train_vir_Input_pv_vho_center = fopen("train_vir_Input_pv_vho_center.csv", "w");
    train_vir_X_pv_vho_center = fopen("train_vir_X_pv_vho_center.csv", "w");
    train_vir_S_ex_pv_vho_center = fopen("train_vir_S_ex_pv_vho_center.csv", "w");
    train_vir_S_inh_pv_vho_center = fopen("train_vir_S_inh_pv_vho_center.csv", "w");
    train_vir_S_pv_vho_center = fopen("train_vir_S_pv_vho_center.csv", "w");

    train_vir_som_vho_center = fopen("train_vir_som_vho_center.csv", "w");
    train_vir_Input_som_vho_center = fopen("train_vir_Input_som_vho_center.csv", "w");
    train_vir_X_som_vho_center = fopen("train_vir_X_som_vho_center.csv", "w");
    train_vir_S_ex_som_vho_center = fopen("train_vir_S_ex_som_vho_center.csv", "w");
    train_vir_S_inh_som_vho_center = fopen("train_vir_S_inh_som_vho_center.csv", "w");
    train_vir_S_som_vho_center = fopen("train_vir_S_som_vho_center.csv", "w");
    //left
    train_vir_vho_left = fopen("train_vir_vho_left.csv", "w");
    train_vir_Input_vho_left = fopen("train_vir_Input_vho_left.csv", "w");
    train_vir_X_vho_left = fopen("train_vir_X_vho_left.csv", "w");
    train_vir_S_ex_vho_left = fopen("train_vir_S_ex_vho_left.csv", "w");
    train_vir_S_inh_vho_left = fopen("train_vir_S_inh_vho_left.csv", "w");
    train_vir_Top_vho_left = fopen("train_vir_Top_vho_left.csv", "w");
    train_vir_Bot_vho_left = fopen("train_vir_Bot_vho_left.csv", "w");
    train_vir_S_vho_left = fopen("train_vir_S_vho_left.csv", "w");

    train_vir_pv_vho_left = fopen("train_vir_pv_vho_left.csv", "w");
    train_vir_Input_pv_vho_left = fopen("train_vir_Input_pv_vho_left.csv", "w");
    train_vir_X_pv_vho_left = fopen("train_vir_X_pv_vho_left.csv", "w");
    train_vir_S_ex_pv_vho_left = fopen("train_vir_S_ex_pv_vho_left.csv", "w");
    train_vir_S_inh_pv_vho_left = fopen("train_vir_S_inh_pv_vho_left.csv", "w");
    train_vir_S_pv_vho_left = fopen("train_vir_S_pv_vho_left.csv", "w");

    train_vir_som_vho_left = fopen("train_vir_som_vho_left.csv", "w");
    train_vir_Input_som_vho_left = fopen("train_vir_Input_som_vho_left.csv", "w");
    train_vir_X_som_vho_left = fopen("train_vir_X_som_vho_left.csv", "w");
    train_vir_S_ex_som_vho_left = fopen("train_vir_S_ex_som_vho_left.csv", "w");
    train_vir_S_inh_som_vho_left = fopen("train_vir_S_inh_som_vho_left.csv", "w");
    train_vir_S_som_vho_left = fopen("train_vir_S_som_vho_left.csv", "w");
    //right
    train_vir_vho_right = fopen("train_vir_vho_right.csv", "w");
    train_vir_Input_vho_right = fopen("train_vir_Input_vho_right.csv", "w");
    train_vir_X_vho_right = fopen("train_vir_X_vho_right.csv", "w");
    train_vir_S_ex_vho_right = fopen("train_vir_S_ex_vho_right.csv", "w");
    train_vir_S_inh_vho_right = fopen("train_vir_S_inh_vho_right.csv", "w");
    train_vir_Top_vho_right = fopen("train_vir_Top_vho_right.csv", "w");
    train_vir_Bot_vho_right = fopen("train_vir_Bot_vho_right.csv", "w");
    train_vir_S_vho_right = fopen("train_vir_S_vho_right.csv", "w");

    train_vir_pv_vho_right = fopen("train_vir_pv_vho_right.csv", "w");
    train_vir_Input_pv_vho_right = fopen("train_vir_Input_pv_vho_right.csv", "w");
    train_vir_X_pv_vho_right = fopen("train_vir_X_pv_vho_right.csv", "w");
    train_vir_S_ex_pv_vho_right = fopen("train_vir_S_ex_pv_vho_right.csv", "w");
    train_vir_S_inh_pv_vho_right = fopen("train_vir_S_inh_pv_vho_right.csv", "w");
    train_vir_S_pv_vho_right = fopen("train_vir_S_pv_vho_right.csv", "w");

    train_vir_som_vho_right = fopen("train_vir_som_vho_right.csv", "w");
    train_vir_Input_som_vho_right = fopen("train_vir_Input_som_vho_right.csv", "w");
    train_vir_X_som_vho_right = fopen("train_vir_X_som_vho_right.csv", "w");
    train_vir_S_ex_som_vho_right = fopen("train_vir_S_ex_som_vho_right.csv", "w");
    train_vir_S_inh_som_vho_right = fopen("train_vir_S_inh_som_vho_right.csv", "w");
    train_vir_S_som_vho_right = fopen("train_vir_S_som_vho_right.csv", "w");
    //top
    train_vir_vho_top = fopen("train_vir_vho_top.csv", "w");
    train_vir_Input_vho_top = fopen("train_vir_Input_vho_top.csv", "w");
    train_vir_X_vho_top = fopen("train_vir_X_vho_top.csv", "w");
    train_vir_S_ex_vho_top = fopen("train_vir_S_ex_vho_top.csv", "w");
    train_vir_S_inh_vho_top = fopen("train_vir_S_inh_vho_top.csv", "w");
    train_vir_Top_vho_top = fopen("train_vir_Top_vho_top.csv", "w");
    train_vir_Bot_vho_top = fopen("train_vir_Bot_vho_top.csv", "w");
    train_vir_S_vho_top = fopen("train_vir_S_vho_top.csv", "w");

    train_vir_pv_vho_top = fopen("train_vir_pv_vho_top.csv", "w");
    train_vir_Input_pv_vho_top = fopen("train_vir_Input_pv_vho_top.csv", "w");
    train_vir_X_pv_vho_top = fopen("train_vir_X_pv_vho_top.csv", "w");
    train_vir_S_ex_pv_vho_top = fopen("train_vir_S_ex_pv_vho_top.csv", "w");
    train_vir_S_inh_pv_vho_top = fopen("train_vir_S_inh_pv_vho_top.csv", "w");
    train_vir_S_pv_vho_top = fopen("train_vir_S_pv_vho_top.csv", "w");

    train_vir_som_vho_top = fopen("train_vir_som_vho_top.csv", "w");
    train_vir_Input_som_vho_top = fopen("train_vir_Input_som_vho_top.csv", "w");
    train_vir_X_som_vho_top = fopen("train_vir_X_som_vho_top.csv", "w");
    train_vir_S_ex_som_vho_top = fopen("train_vir_S_ex_som_vho_top.csv", "w");
    train_vir_S_inh_som_vho_top = fopen("train_vir_S_inh_som_vho_top.csv", "w");
    train_vir_S_som_vho_top = fopen("train_vir_S_som_vho_top.csv", "w");
    //bottom
    train_vir_vho_bottom = fopen("train_vir_vho_bottom.csv", "w");
    train_vir_Input_vho_bottom = fopen("train_vir_Input_vho_bottom.csv", "w");
    train_vir_X_vho_bottom = fopen("train_vir_X_vho_bottom.csv", "w");
    train_vir_S_ex_vho_bottom = fopen("train_vir_S_ex_vho_bottom.csv", "w");
    train_vir_S_inh_vho_bottom = fopen("train_vir_S_inh_vho_bottom.csv", "w");
    train_vir_Top_vho_bottom = fopen("train_vir_Top_vho_bottom.csv", "w");
    train_vir_Bot_vho_bottom = fopen("train_vir_Bot_vho_bottom.csv", "w");
    train_vir_S_vho_bottom = fopen("train_vir_S_vho_bottom.csv", "w");

    train_vir_pv_vho_bottom = fopen("train_vir_pv_vho_bottom.csv", "w");
    train_vir_Input_pv_vho_bottom = fopen("train_vir_Input_pv_vho_bottom.csv", "w");
    train_vir_X_pv_vho_bottom = fopen("train_vir_X_pv_vho_bottom.csv", "w");
    train_vir_S_ex_pv_vho_bottom = fopen("train_vir_S_ex_pv_vho_bottom.csv", "w");
    train_vir_S_inh_pv_vho_bottom = fopen("train_vir_S_inh_pv_vho_bottom.csv", "w");
    train_vir_S_pv_vho_bottom = fopen("train_vir_S_pv_vho_bottom.csv", "w");

    train_vir_som_vho_bottom = fopen("train_vir_som_vho_bottom.csv", "w");
    train_vir_Input_som_vho_bottom = fopen("train_vir_Input_som_vho_bottom.csv", "w");
    train_vir_X_som_vho_bottom = fopen("train_vir_X_som_vho_bottom.csv", "w");
    train_vir_S_ex_som_vho_bottom = fopen("train_vir_S_ex_som_vho_bottom.csv", "w");
    train_vir_S_inh_som_vho_bottom = fopen("train_vir_S_inh_som_vho_bottom.csv", "w");
    train_vir_S_som_vho_bottom = fopen("train_vir_S_som_vho_bottom.csv", "w");
    //cross correlation
    bit_VHOcenter = fopen("vir_bit_VHO_center.csv", "w");
    bit_VHOleft = fopen("vir_bit_VHO_left.csv", "w");
    bit_VHOright = fopen("vir_bit_VHO_right.csv", "w");
    bit_VHOtop = fopen("vir_bit_VHO_top.csv", "w");
    bit_VHObottom = fopen("vir_bit_VHO_bottom.csv", "w");
    //LFP
    vir_lfp_vho_center_synapse = fopen("vir_lfp_VHO_center_synapse.csv", "w");
    vir_lfp_vho_left_synapse = fopen("vir_lfp_VHO_left_synapse.csv", "w");
    vir_lfp_vho_right_synapse = fopen("vir_lfp_VHO_right_synapse.csv", "w");
    vir_lfp_vho_top_synapse = fopen("vir_lfp_VHO_top_synapse.csv", "w");
    vir_lfp_vho_bottom_synapse = fopen("vir_lfp_VHO_bottom_synapse.csv", "w");
    //tuning curve
    vir_tuning_VHO = fopen("vir_tuning_VHO.csv", "w");
    vir_tuning_VHO_center = fopen("vir_tuning_VHO_center.csv", "w");
    vir_tuning_VHO_left = fopen("vir_tuning_VHO_left.csv", "w");
    vir_tuning_VHO_right = fopen("vir_tuning_VHO_right.csv", "w");
    vir_tuning_VHO_top = fopen("vir_tuning_VHO_top.csv", "w");
    vir_tuning_VHO_bottom = fopen("vir_tuning_VHO_bottom.csv", "w");
}

void FileCloseVHO(void){
    //center
    fclose(train_vir_vho_center);
    fclose(train_vir_Input_vho_center);
    fclose(train_vir_X_vho_center);
    fclose(train_vir_S_ex_vho_center);
    fclose(train_vir_S_inh_from_pv_vho_center);
    fclose(train_vir_S_inh_from_som_vho_center);
    fclose(train_vir_Top_vho_center);
    fclose(train_vir_Bot_vho_center);
    fclose(train_vir_S_vho_center);

    fclose(train_vir_pv_vho_center);
    fclose(train_vir_Input_pv_vho_center);
    fclose(train_vir_X_pv_vho_center);
    fclose(train_vir_S_ex_pv_vho_center);
    fclose(train_vir_S_inh_pv_vho_center);
    fclose(train_vir_S_pv_vho_center);

    fclose(train_vir_som_vho_center);
    fclose(train_vir_Input_som_vho_center);
    fclose(train_vir_X_som_vho_center);
    fclose(train_vir_S_ex_som_vho_center);
    fclose(train_vir_S_inh_som_vho_center);
    fclose(train_vir_S_som_vho_center);
    //left
    fclose(train_vir_vho_left);
    fclose(train_vir_Input_vho_left);
    fclose(train_vir_X_vho_left);
    fclose(train_vir_S_ex_vho_left);
    fclose(train_vir_S_inh_vho_left);
    fclose(train_vir_Top_vho_left);
    fclose(train_vir_Bot_vho_left);
    fclose(train_vir_S_vho_left);

    fclose(train_vir_pv_vho_left);
    fclose(train_vir_Input_pv_vho_left);
    fclose(train_vir_X_pv_vho_left);
    fclose(train_vir_S_ex_pv_vho_left);
    fclose(train_vir_S_inh_pv_vho_left);
    fclose(train_vir_S_pv_vho_left);

    fclose(train_vir_som_vho_left);
    fclose(train_vir_Input_som_vho_left);
    fclose(train_vir_X_som_vho_left);
    fclose(train_vir_S_ex_som_vho_left);
    fclose(train_vir_S_inh_som_vho_left);
    fclose(train_vir_S_som_vho_left);
    //right
    fclose(train_vir_vho_right);
    fclose(train_vir_Input_vho_right);
    fclose(train_vir_X_vho_right);
    fclose(train_vir_S_ex_vho_right);
    fclose(train_vir_S_inh_vho_right);
    fclose(train_vir_Top_vho_right);
    fclose(train_vir_Bot_vho_right);
    fclose(train_vir_S_vho_right);

    fclose(train_vir_pv_vho_right);
    fclose(train_vir_Input_pv_vho_right);
    fclose(train_vir_X_pv_vho_right);
    fclose(train_vir_S_ex_pv_vho_right);
    fclose(train_vir_S_inh_pv_vho_right);
    fclose(train_vir_S_pv_vho_right);

    fclose(train_vir_som_vho_right);
    fclose(train_vir_Input_som_vho_right);
    fclose(train_vir_X_som_vho_right);
    fclose(train_vir_S_ex_som_vho_right);
    fclose(train_vir_S_inh_som_vho_right);
    fclose(train_vir_S_som_vho_right);
    //top
    fclose(train_vir_vho_top);
    fclose(train_vir_Input_vho_top);
    fclose(train_vir_X_vho_top);
    fclose(train_vir_S_ex_vho_top);
    fclose(train_vir_S_inh_vho_top);
    fclose(train_vir_Top_vho_top);
    fclose(train_vir_Bot_vho_top);
    fclose(train_vir_S_vho_top);

    fclose(train_vir_pv_vho_top);
    fclose(train_vir_Input_pv_vho_top);
    fclose(train_vir_X_pv_vho_top);
    fclose(train_vir_S_ex_pv_vho_top);
    fclose(train_vir_S_inh_pv_vho_top);
    fclose(train_vir_S_pv_vho_top);

    fclose(train_vir_som_vho_top);
    fclose(train_vir_Input_som_vho_top);
    fclose(train_vir_X_som_vho_top);
    fclose(train_vir_S_ex_som_vho_top);
    fclose(train_vir_S_inh_som_vho_top);
    fclose(train_vir_S_som_vho_top);
    //bottom
    fclose(train_vir_vho_bottom);
    fclose(train_vir_Input_vho_bottom);
    fclose(train_vir_X_vho_bottom);
    fclose(train_vir_S_ex_vho_bottom);
    fclose(train_vir_S_inh_vho_bottom);
    fclose(train_vir_Top_vho_bottom);
    fclose(train_vir_Bot_vho_bottom);
    fclose(train_vir_S_vho_bottom);

    fclose(train_vir_pv_vho_bottom);
    fclose(train_vir_Input_pv_vho_bottom);
    fclose(train_vir_X_pv_vho_bottom);
    fclose(train_vir_S_ex_pv_vho_bottom);
    fclose(train_vir_S_inh_pv_vho_bottom);
    fclose(train_vir_S_pv_vho_bottom);

    fclose(train_vir_som_vho_bottom);
    fclose(train_vir_Input_som_vho_bottom);
    fclose(train_vir_X_som_vho_bottom);
    fclose(train_vir_S_ex_som_vho_bottom);
    fclose(train_vir_S_inh_som_vho_bottom);
    fclose(train_vir_S_som_vho_bottom);
    //cross correlation
    fclose(bit_VHOcenter);
    fclose(bit_VHOleft);
    fclose(bit_VHOright);
    fclose(bit_VHOtop);
    fclose(bit_VHObottom);
    //LFP
    fclose(vir_lfp_vho_center_synapse);
    fclose(vir_lfp_vho_left_synapse);
    fclose(vir_lfp_vho_right_synapse);
    fclose(vir_lfp_vho_top_synapse);
    fclose(vir_lfp_vho_bottom_synapse);
    //tuning curve
    fclose(vir_tuning_VHO);
    fclose(vir_tuning_VHO_center);
    fclose(vir_tuning_VHO_left);
    fclose(vir_tuning_VHO_right);
    fclose(vir_tuning_VHO_top);
    fclose(vir_tuning_VHO_bottom);
}