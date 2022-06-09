%% save vars for test file (comment out)

% freqs = 5;
% cycles = 5;
% srate = 256;
% save('dftfilt2.mat', 'freqs', 'cycles', 'srate')

%% load vars and run test

load('dftfilt2.mat')
wav = dftfilt2(5, 5, 256); wav = wav{1};
abs = linspace(-floor(length(wav)),floor(length(wav)), length(wav));
figure; plot(abs, real(wav))

%% other testing examples (comment out)

% wav1 = dftfilt2(5, 5, 256); wav1 = wav1{1};
% abs1 = linspace(-floor(length(wav1)),floor(length(wav1)), length(wav1));
% figure; plot(abs1, real(wav1), 'b');
% 
% wav2 = dftfilt2(5, 3, 256); wav2 = wav2{1};
% abs2 = linspace(-floor(length(wav2)),floor(length(wav2)), length(wav2)); 
% hold on; plot(abs2, real(wav2), 'r');
% 
% wav3 = dftfilt2(5, 1.4895990, 256); wav3 = wav3{1};
% abs3 = linspace(-floor(length(wav3)),floor(length(wav3)), length(wav3)); 
% hold on; plot(abs3, real(wav3), 'g');
% 
% wav4 = dftfilt2(5, 8.73, 256); wav4 = wav4{1};
% abs4 = linspace(-floor(length(wav4)),floor(length(wav4)), length(wav4)); 
% hold on; plot(abs4, real(wav4), 'm');
     
%% other testing examples (comment out)

% freqs = exp(linspace(0,log(10),10));
% win = dftfilt2(freqs, [3 3], 256, 'linear', 'sinus');
% win = dftfilt2(freqs, [3 3], 256, 'linear', 'morlet');
% 
% freqs = [12.0008   13.2675   14.5341   15.8007   17.0674   18.3340   19.6007   20.8673   22.1339   23.4006   24.6672   25.9339   27.2005 28.4671   29.7338   31.0004   32.2670   33.5337   34.8003   36.0670   37.3336   38.6002   39.8669   41.1335   42.4002   43.6668 44.9334   46.2001   47.4667 ...
%          48.7334   50.0000];
% 
% win = dftfilt2(freqs, [3 12], 256, 'linear'); size(win)
% 
% winsize = 0;
% for index = 1:length(win)
%     winsize = max(winsize,length(win{index}));
% end
% allwav = zeros(winsize, length(win));
% for index = 1:length(win)
%     wav1 = win{index};
%     abs1 = linspace(-(length(wav1)-1)/2,(length(wav1)-1)/2, length(wav1));
%     allwav(abs1+(winsize+1)/2,index) = wav1(:);
% end
% figure; imagesc(imag(allwav));