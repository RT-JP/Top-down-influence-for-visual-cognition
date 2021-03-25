% Copyright (c) 2021 RT-JP All Right Reserved.

t = 1:1:1002;
Fs = 1000;
N = 20;

for j = 1:5
    for A = 10:10:100
        bandpassrange = [A-1 A+1];
        for i = 1:N
            %Bisection Irrelevant
            %load file
            bircenterfilename = sprintf('bir_lfp_v1_center_data_%d.csv', i);
            bircenterdata{i} = importdata(bircenterfilename);
            birsidefilename = sprintf('bir_lfp_v1_right_data_%d.csv', i);
            birsidedata{i} = importdata(birsidefilename);
            %bandpass
            bircenterpass{i} = bandpass(bircenterdata{i},bandpassrange,Fs);
            birsidepass{i} = bandpass(birsidedata{i},bandpassrange,Fs);
            %hilbert
            bircenterhilbert{i} = hilbert(bircenterpass{i});
            birsidehilbert{i} = hilbert(birsidepass{i});
            %angle
            bircenterangle{i} = angle(bircenterhilbert{i});
            birsideangle{i} = angle(birsidehilbert{i});
            %phase-difference
            birplv{i} = bircenterangle{i} - birsideangle{i};

            %Bisection Relevant
            %load file
            brcenterfilename = sprintf('br_lfp_v1_center_data_%d.csv', i);
            brcenterdata{i} = importdata(brcenterfilename);
            brsidefilename = sprintf('br_lfp_v1_right_data_%d.csv', i);
            brsidedata{i} = importdata(brsidefilename);
            %bandpass
            brcenterpass{i} = bandpass(brcenterdata{i},bandpassrange,Fs);
            brsidepass{i} = bandpass(brsidedata{i},bandpassrange,Fs);
            %hilbert
            brcenterhilbert{i} = hilbert(brcenterpass{i});
            brsidehilbert{i} = hilbert(brsidepass{i});
            %angle
            brcenterangle{i} = angle(brcenterhilbert{i});
            brsideangle{i} = angle(brsidehilbert{i});
            %phase-difference
            brplv{i} = brcenterangle{i} - brsideangle{i};
        end

        birplvresult = abs((birplv{1} + birplv{2} + birplv{3} + birplv{4} + birplv{5} + birplv{6} + birplv{7} + birplv{8} + birplv{9} + birplv{10} + birplv{11} + birplv{12} + birplv{13} + birplv{14} + birplv{15} + birplv{16} + birplv{17} + birplv{18} + birplv{19} + birplv{20}) / N);
        brplvresult = abs((brplv{1} + brplv{2} + brplv{3} + brplv{4} + brplv{5} + brplv{6} + brplv{7} + brplv{8} + brplv{9} + brplv{10} + brplv{11} + brplv{12} + brplv{13} + brplv{14} + brplv{15} + brplv{16} + brplv{17} + brplv{18} + brplv{19} + brplv{20}) / N);

        birplvresult_mean = mean(birplvresult);
        brplvresult_mean = mean(brplvresult);
        
        file1name = sprintf('Bisection_Irrelevant-phase-difference-Result-bin10Hz-range1Hz-%d.csv', j);
        fileID_1 = fopen(file1name, "a");
        fprintf(fileID_1, "%.4g \n", birplvresult_mean);
        fclose(fileID_1);

        file2name = sprintf('Bisection_Relevant-phase-difference-Result-bin10Hz-range1Hz-%d.csv', j);
        fileID_2 = fopen(file2name, "a");
        fprintf(fileID_2, "%.4g \n", brplvresult_mean);
        fclose(fileID_2);

        file3name = sprintf('Bisection_phase-difference-freq-%d.csv', j);
        fileID_3 = fopen(file3name, "a");
        fprintf(fileID_3, "%d\n", A);
        fclose(fileID_3);
    end
end

exit()