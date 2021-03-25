% Copyright (c) 2021 RT-JP All Right Reserved.

t = 1:1:1002;
Fs = 1000;
N = 20;

for j = 1:5
    for A = 10:10:100
        bandpassrange = [A-1 A+1];
        for i = 1:N
            %Vernier Irrelevant
            %load file
            vircenterfilename = sprintf('vir_lfp_v1_center_data_%d.csv', i);
            vircenterdata{i} = importdata(vircenterfilename);
            virendfilename = sprintf('vir_lfp_v1_top_data_%d.csv', i);
            virenddata{i} = importdata(virendfilename);
            %bandpass
            vircenterpass{i} = bandpass(vircenterdata{i},bandpassrange,Fs);
            virendpass{i} = bandpass(virenddata{i},bandpassrange,Fs);
            %hilbert
            vircenterhilbert{i} = hilbert(vircenterpass{i});
            virendhilbert{i} = hilbert(virendpass{i});
            %angle
            vircenterangle{i} = angle(vircenterhilbert{i});
            virendangle{i} = angle(virendhilbert{i});
            %isousa
            virplv{i} = vircenterangle{i} - virendangle{i};

            %Vernier Relevant
            %load file
            vrcenterfilename = sprintf('vr_lfp_v1_center_data_%d.csv', i);
            vrcenterdata{i} = importdata(vrcenterfilename);
            vrendfilename = sprintf('vr_lfp_v1_top_data_%d.csv', i);
            vrenddata{i} = importdata(vrendfilename);
            %bandpass
            vrcenterpass{i} = bandpass(vrcenterdata{i},bandpassrange,Fs);
            vrendpass{i} = bandpass(vrenddata{i},bandpassrange,Fs);
            %hilbert
            vrcenterhilbert{i} = hilbert(vrcenterpass{i});
            vrendhilbert{i} = hilbert(vrendpass{i});
            %angle
            vrcenterangle{i} = angle(vrcenterhilbert{i});
            vrendangle{i} = angle(vrendhilbert{i});
            %isousa
            vrplv{i} = vrcenterangle{i} - vrendangle{i};
        end

        virplvresult = abs((virplv{1} + virplv{2} + virplv{3} + virplv{4} + virplv{5} + virplv{6} + virplv{7} + virplv{8} + virplv{9} + virplv{10} + virplv{11} + virplv{12} + virplv{13} + virplv{14} + virplv{15} + virplv{16} + virplv{17} + virplv{18} + virplv{19} + virplv{20}) / N);
        vrplvresult = abs((vrplv{1} + vrplv{2} + vrplv{3} + vrplv{4} + vrplv{5} + vrplv{6} + vrplv{7} + vrplv{8} + vrplv{9} + vrplv{10} + vrplv{11} + vrplv{12} + vrplv{13} + vrplv{14} + vrplv{15} + vrplv{16} + vrplv{17} + vrplv{18} + vrplv{19} + vrplv{20}) / N);

        virplvresult_mean = mean(virplvresult);
        vrplvresult_mean = mean(vrplvresult);
        
        file1name = sprintf('Vernier_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-%d.csv', j);
        fileID_1 = fopen(file1name, "a");
        fprintf(fileID_1, "%.4g \n", virplvresult_mean);
        fclose(fileID_1);

        file2name = sprintf('Vernier_Relevant-phase-difference-Result-bin10Hz-range1Hz-%d.csv', j);
        fileID_2 = fopen(file2name, "a");
        fprintf(fileID_2, "%.4g \n", vrplvresult_mean);
        fclose(fileID_2);

        file3name = sprintf('Vernier_phase-difference-freq-%d.csv', j);
        fileID_3 = fopen(file3name, "a");
        fprintf(fileID_3, "%d\n", A);
        fclose(fileID_3);
    end
end

exit()