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
            %bisection Irrelevant
            bircenterfilename = sprintf('bir_lfp_v1_center_data_%d.csv', i);
            bircenterdata{i} = importdata(bircenterfilename);
            %Bandpass
            bircenterpass_AB{i} = bandpass(bircenterdata{i},bandpassrange_AB,Fs);
            bircenterpass_CD{i} = bandpass(bircenterdata{i},bandpassrange_CD,Fs);
            %Hirbert
            bircenterhilbert_AB{i} = hilbert(bircenterpass_AB{i});
            bircenterhilbert_CD{i} = hilbert(bircenterpass_CD{i});
            %Angle and Abs
            bircenterangle{i} = angle(bircenterhilbert_AB{i});
            bircenterabs{i} = abs(bircenterhilbert_CD{i});

            birsabun{i} = bircenterangle{i} - bircenterabs{i};
            birplv{i} = exp(1i*birsabun{i});

            %bisection Rrelevant
            brcenterfilename = sprintf('br_lfp_v1_center_data_%d.csv', i);
            brcenterdata{i} = importdata(brcenterfilename);
            %Bandpass
            brcenterpass_AB{i} = bandpass(brcenterdata{i},bandpassrange_AB,Fs);
            brcenterpass_CD{i} = bandpass(brcenterdata{i},bandpassrange_CD,Fs);
            %Hirbert
            brcenterhilbert_AB{i} = hilbert(brcenterpass_AB{i});
            brcenterhilbert_CD{i} = hilbert(brcenterpass_CD{i});
            %Angle and Abs
            brcenterangle{i} = angle(brcenterhilbert_AB{i});
            brcenterabs{i} = abs(brcenterhilbert_CD{i});

            brsabun{i} = brcenterangle{i} - brcenterabs{i};
            brplv{i} = exp(1i*brsabun{i});
        end
        
        birplvresult = abs((birplv{1} + birplv{2} + birplv{3} + birplv{4} + birplv{5} + birplv{6} + birplv{7} + birplv{8} + birplv{9} + birplv{10} + birplv{11} + birplv{12} + birplv{13} + birplv{14} + birplv{15} + birplv{16} + birplv{17} + birplv{18} + birplv{19} + birplv{20} + birplv{21} + birplv{22} + birplv{23} + birplv{24} + birplv{25} + birplv{26} + birplv{27} + birplv{28} + birplv{29} + birplv{30} + birplv{31} + birplv{32} + birplv{33} + birplv{34} + birplv{35} + birplv{36} + birplv{37} + birplv{38} + birplv{39} + birplv{40} + birplv{41} + birplv{42} + birplv{43} + birplv{44} + birplv{45} + birplv{46} + birplv{47} + birplv{48} + birplv{49} + birplv{50} + birplv{51} + birplv{52} + birplv{53} + birplv{54} + birplv{55} + birplv{56} + birplv{57} + birplv{58} + birplv{59} + birplv{60} + birplv{61} + birplv{62} + birplv{63} + birplv{64} + birplv{65} + birplv{66} + birplv{67} + birplv{68} + birplv{69} + birplv{70} + birplv{71} + birplv{72} + birplv{73} + birplv{74} + birplv{75} + birplv{76} + birplv{77} + birplv{78} + birplv{79} + birplv{80} + birplv{81} + birplv{82} + birplv{83} + birplv{84} + birplv{85} + birplv{86} + birplv{87} + birplv{88} + birplv{89} + birplv{90} + birplv{91} + birplv{92} + birplv{93} + birplv{94} + birplv{95} + birplv{96} + birplv{97} + birplv{98} + birplv{99} + birplv{100}) / N);
        birplvresult_mean = mean(birplvresult);

        brplvresult = abs((brplv{1} + brplv{2} + brplv{3} + brplv{4} + brplv{5} + brplv{6} + brplv{7} + brplv{8} + brplv{9} + brplv{10} + brplv{11} + brplv{12} + brplv{13} + brplv{14} + brplv{15} + brplv{16} + brplv{17} + brplv{18} + brplv{19} + brplv{20} + brplv{21} + brplv{22} + brplv{23} + brplv{24} + brplv{25} + brplv{26} + brplv{27} + brplv{28} + brplv{29} + brplv{30} + brplv{31} + brplv{32} + brplv{33} + brplv{34} + brplv{35} + brplv{36} + brplv{37} + brplv{38} + brplv{39} + brplv{40} + brplv{41} + brplv{42} + brplv{43} + brplv{44} + brplv{45} + brplv{46} + brplv{47} + brplv{48} + brplv{49} + brplv{50} + brplv{51} + brplv{52} + brplv{53} + brplv{54} + brplv{55} + brplv{56} + brplv{57} + brplv{58} + brplv{59} + brplv{60} + brplv{61} + brplv{62} + brplv{63} + brplv{64} + brplv{65} + brplv{66} + brplv{67} + brplv{68} + brplv{69} + brplv{70} + brplv{71} + brplv{72} + brplv{73} + brplv{74} + brplv{75} + brplv{76} + brplv{77} + brplv{78} + brplv{79} + brplv{80} + brplv{81} + brplv{82} + brplv{83} + brplv{84} + brplv{85} + brplv{86} + brplv{87} + brplv{88} + brplv{89} + brplv{90} + brplv{91} + brplv{92} + brplv{93} + brplv{94} + brplv{95} + brplv{96} + brplv{97} + brplv{98} + brplv{99} + brplv{100}) / N);
        brplvresult_mean = mean(brplvresult);
        
        fileID_1 = fopen("Bisection_Irrelevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
        fprintf(fileID_1, "%d %d %.4g \n", centerfreq_AB, centerfreq_CD, birplvresult_mean);
        fclose(fileID_1);

        fileID_2 = fopen("Bisection_Relevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
        fprintf(fileID_2, "%d %d %.4g \n", centerfreq_AB, centerfreq_CD, brplvresult_mean);
        fclose(fileID_2);
    end
    fileID_1 = fopen("Bisection_Irrelevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
    fprintf(fileID_1, "\n");
    fclose(fileID_1);
    fileID_2 = fopen("Bisection_Relevant-BetaPhase-GammaAmp-Result-V1.csv", "a");
    fprintf(fileID_2, "\n");
    fclose(fileID_2);
end

exit()