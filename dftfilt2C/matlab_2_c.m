%% Check for run-time issues
% coder.screener('dftfilt2_2_c.m')
% dftfilt2_test;
% codegen dftfilt2_2_c -args {freqs, cycles, srate} -test dftfilt2_test

%% Generate C code
% cfg = coder.config('lib', 'ecoder', false);
% codegen -config cfg dftfilt2_2_c.m -args {freqs, cycles, srate} -report

%% Simpler generation, can use this if you already screened
codegen -report -config:lib dftfilt2_2_c -args {freqs, cycles, srate}

%% Package generated code in ZIP file for relocation (flat)
% load('C:\Users\danie\OneDrive\Documents\MATLAB\MATLAB2C\dftfilt2C\codegen\lib\dftfilt2_2_c\buildInfo.mat');
% filename = 'C:\Users\danie\CLionProjects\dftfilt2\dftfilt2';
% packNGo(buildInfo,'fileName',filename);

% work_dir = 'C:\Users\danie\OneDrive\Documents\MATLAB\MATLAB2C\dftfilt2C';
% CLion_dir = 'C:\Users\danie\CLionProjects\dftfilt2_flat';
% 
% buildInfo_dir = fullfile(work_dir, 'codegen\lib\dftfilt2_2_c', 'buildInfo.mat');
% load(buildInfo_dir);
% 
% filename = fullfile(CLion_dir, 'dftfilt2_built.zip');
% packNGo(buildInfo, 'packType', 'flat', 'fileName', filename);
% unzip(filename, CLion_dir)

%% Package generated code in ZIP file for relocation (hierarchical)
work_dir = 'C:\Users\danie\OneDrive\Documents\MATLAB\MATLAB2C\dftfilt2C';
CLion_dir = 'C:\Users\danie\CLionProjects\dftfilt2';

buildInfo_dir = fullfile(work_dir, 'codegen\lib\dftfilt2_2_c', 'buildInfo.mat');
load(buildInfo_dir);

filename = fullfile(work_dir, 'dftfilt2_built.zip');
packNGo(buildInfo, 'packType', 'hierarchical', 'fileName', filename);

unzip(filename, CLion_dir)

filename = fullfile(CLion_dir, 'sDirFiles.zip');
unzip(filename, CLion_dir)
delete(filename)

filename = fullfile(CLion_dir, 'mlrFiles.zip');
unzip(filename, CLion_dir)
delete(filename)