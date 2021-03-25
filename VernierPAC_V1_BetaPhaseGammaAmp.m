% Copyright (c) 2021 RT-JP All Right Reserved.

t = 1:1:1002;
Fs = 1000;
N = 100;

for centerfreq_AB = 5:5:100
    for centerfreq_CD = 5:5:100
        A = centerfreq_AB - 1;
        B = centerfreq_AB + 1;
        C = centerfreq_CD - (0.4 * centerfreq_CD);
        D = centerfreq_CD + (0.4 * centerfreq_CD);
        bandpassrange_AB = [A B];
        bandpassrange_CD = [C D];
        for i = 1:N
            %vernier Irrelevant
            vircenterfilename = sprintf('vir_lfp_v1_center_data_%d.csv', i);
            vircenterdata{i} = importdata(vircenterfilename);
            %Bandpass
            vircenterpass_AB{i} = bandpass(vircenterdata{i},bandpassrange_AB,Fs);
            vircenterpass_CD{i} = bandpass(vircenterdata{i},bandpassrange_CD,Fs);
            %Hirbert
            vircenterhilbert_AB{i} = hilbert(vircenterpass_AB{i});
            vircenterhilbert_CD{i} = hilbert(vircenterpass_CD{i});
            %Angle and Abs
            vircenterangle{i} = angle(vircenterhilbert_AB{i});
            vircenterabs{i} = abs(vircenterhilbert_CD{i});

            virsabun{i} = vircenterangle{i} - vircenterabs{i};
            virplv{i} = exp(1i*virsabun{i});

            %vernier Rrelevant
            vrcenterfilename = sprintf('vr_lfp_v1_center_data_%d.csv', i);
            vrcenterdata{i} = importdata(vrcenterfilename);
            %Bandpass
            vrcenterpass_AB{i} = bandpass(vrcenterdata{i},bandpassrange_AB,Fs);
            vrcenterpass_CD{i} = bandpass(vrcenterdata{i},bandpassrange_CD,Fs);
            %Hirbert
            vrcenterhilbert_AB{i} = hilbert(vrcenterpass_AB{i});
            vrcenterhilbert_CD{i} = hilbert(vrcenterpass_CD{i});
            %Angle and Abs
            vrcenterangle{i} = angle(vrcenterhilbert_AB{i});
            vrcenterabs{i} = abs(vrcenterhilbert_CD{i});

            vrsabun{i} = vrcenterangle{i} - vrcenterabs{i};
            vrplv{i} = exp(1i*vrsabun{i});
        end
        virplvresult = abs((virplv{1} + virplv{2} + virplv{3} + virplv{4} + virplv{5} + virplv{6} + virplv{7} + virplv{8} + virplv{9} + virplv{10} + virplv{11} + virplv{12} + virplv{13} + virplv{14} + virplv{15} + virplv{16} + virplv{17} + virplv{18} + virplv{19} + virplv{20} + virplv{21} + virplv{22} + virplv{23} + virplv{24} + virplv{25} + virplv{26} + virplv{27} + virplv{28} + virplv{29} + virplv{30} + virplv{31} + virplv{32} + virplv{33} + virplv{34} + virplv{35} + virplv{36} + virplv{37} + virplv{38} + virplv{39} + virplv{40} + virplv{41} + virplv{42} + virplv{43} + virplv{44} + virplv{45} + virplv{46} + virplv{47} + virplv{48} + virplv{49} + virplv{50} + virplv{51} + virplv{52} + virplv{53} + virplv{54} + virplv{55} + virplv{56} + virplv{57} + virplv{58} + virplv{59} + virplv{60} + virplv{61} + virplv{62} + virplv{63} + virplv{64} + virplv{65} + virplv{66} + virplv{67} + virplv{68} + virplv{69} + virplv{70} + virplv{71} + virplv{72} + virplv{73} + virplv{74} + virplv{75} + virplv{76} + virplv{77} + virplv{78} + virplv{79} + virplv{80} + virplv{81} + virplv{82} + virplv{83} + virplv{84} + virplv{85} + virplv{86} + virplv{87} + virplv{88} + virplv{89} + virplv{90} + virplv{91} + virplv{92} + virplv{93} + virplv{94} + virplv{95} + virplv{96} + virplv{97} + virplv{98} + virplv{99} + virplv{100}) / N);
        %virplvresult = abs((virplv{1} + virplv{2} + virplv{3} + virplv{4} + virplv{5} + virplv{6} + virplv{7} + virplv{8} + virplv{9} + virplv{10} + virplv{11} + virplv{12} + virplv{13} + virplv{14} + virplv{15} + virplv{16} + virplv{17} + virplv{18} + virplv{19} + virplv{20}) / N);
        virplvresult_mean = mean(virplvresult);

        vrplvresult = abs((vrplv{1} + vrplv{2} + vrplv{3} + vrplv{4} + vrplv{5} + vrplv{6} + vrplv{7} + vrplv{8} + vrplv{9} + vrplv{10} + vrplv{11} + vrplv{12} + vrplv{13} + vrplv{14} + vrplv{15} + vrplv{16} + vrplv{17} + vrplv{18} + vrplv{19} + vrplv{20} + vrplv{21} + vrplv{22} + vrplv{23} + vrplv{24} + vrplv{25} + vrplv{26} + vrplv{27} + vrplv{28} + vrplv{29} + vrplv{30} + vrplv{31} + vrplv{32} + vrplv{33} + vrplv{34} + vrplv{35} + vrplv{36} + vrplv{37} + vrplv{38} + vrplv{39} + vrplv{40} + vrplv{41} + vrplv{42} + vrplv{43} + vrplv{44} + vrplv{45} + vrplv{46} + vrplv{47} + vrplv{48} + vrplv{49} + vrplv{50} + vrplv{51} + vrplv{52} + vrplv{53} + vrplv{54} + vrplv{55} + vrplv{56} + vrplv{57} + vrplv{58} + vrplv{59} + vrplv{60} + vrplv{61} + vrplv{62} + vrplv{63} + vrplv{64} + vrplv{65} + vrplv{66} + vrplv{67} + vrplv{68} + vrplv{69} + vrplv{70} + vrplv{71} + vrplv{72} + vrplv{73} + vrplv{74} + vrplv{75} + vrplv{76} + vrplv{77} + vrplv{78} + vrplv{79} + vrplv{80} + vrplv{81} + vrplv{82} + vrplv{83} + vrplv{84} + vrplv{85} + vrplv{86} + vrplv{87} + vrplv{88} + vrplv{89} + vrplv{90} + vrplv{91} + vrplv{92} + vrplv{93} + vrplv{94} + vrplv{95} + vrplv{96} + vrplv{97} + vrplv{98} + vrplv{99} + vrplv{100}) / N);
        %vrplvresult = abs((vrplv{1} + vrplv{2} + vrplv{3} + vrplv{4} + vrplv{5} + vrplv{6} + vrplv{7} + vrplv{8} + vrplv{9} + vrplv{10} + vrplv{11} + vrplv{12} + vrplv{13} + vrplv{14} + vrplv{15} + vrplv{16} + vrplv{17} + vrplv{18} + vrplv{19} + vrplv{20}) / N);
        vrplvresult_mean = mean(vrplvresult);
        
        fileID_1 = fopen("Vernier_Irrelevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
        fprintf(fileID_1, "%d %d %.4g \n", centerfreq_AB, centerfreq_CD, virplvresult_mean);
        fclose(fileID_1);

        fileID_2 = fopen("Vernier_Relevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
        fprintf(fileID_2, "%d %d %.4g \n", centerfreq_AB, centerfreq_CD, vrplvresult_mean);
        fclose(fileID_2);
    end
    fileID_1 = fopen("Vernier_Irrelevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
    fprintf(fileID_1, "\n");
    fclose(fileID_1);
    fileID_2 = fopen("Vernier_Relevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
    fprintf(fileID_2, "\n");
    fclose(fileID_2);
end

exit()