%% Directories
work_dir = 'C:\Users\danie\OneDrive\Documents\MATLAB\MATLAB2C\dftfilt2C';
CLion_dir = 'C:\Users\danie\CLionProjects\dftfilt2';

%% Check for run-time issues
coder.screener('dftfilt2_2_c.m')
dftfilt2_test;
codegen dftfilt2_2_c -args {freqs, cycles, srate} -test dftfilt2_test

%% Standalone C/C++ code and compile it to a library specifying code generation options
% This will generate an example main function

% 1. Create a configuration object for a C static library
cfg = coder.config('lib');

% 2. Generate a C static library using the configuration object
codegen -report -config cfg dftfilt2_2_c -args {freqs, cycles, srate}

%% Copy example main files
main_path = fullfile(work_dir, 'codegen/lib/dftfilt2_2_c/examples/main.c');
mainh_path = fullfile(work_dir, 'codegen/lib/dftfilt2_2_c/examples/main.h');
copyfile(main_path, CLion_dir)
copyfile(mainh_path, CLion_dir)

% After this step you have to modify the main files. The example 
% main function declares and initializes data, including dynamically
% allocated data, to zero values. It calls entry-point functions 
% with arguments set to zero values, but it does not use values 
% returned from the entry-point functions.

%% Generate the application
% Create a configuration object for a C standalone executable
cfg = coder.config('exe');

% Generate a C standalone executable using the configuration object
% and the modified main function.
codegen -report -config cfg dftfilt2_2_c main.c main.h

% By default, the code generated for the executable is in the 
% folder codegen/exe/dftfilt2.

%% Package generated code in ZIP file for relocation (flat)
% load('C:\Users\danie\OneDrive\Documents\MATLAB\MATLAB2C\dftfilt2C\codegen\lib\dftfilt2_2_c\buildInfo.mat');
% filename = 'C:\Users\danie\CLionProjects\dftfilt2\dftfilt2';
% packNGo(buildInfo,'fileName',filename);

% buildInfo_dir = fullfile(work_dir, 'codegen\lib\dftfilt2_2_c', 'buildInfo.mat');
% load(buildInfo_dir);
% 
% filename = fullfile(CLion_dir, 'dftfilt2_built.zip');
% packNGo(buildInfo, 'packType', 'flat', 'fileName', filename);
% unzip(filename, CLion_dir)

%% Package generated code in ZIP file for relocation (hierarchical)

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