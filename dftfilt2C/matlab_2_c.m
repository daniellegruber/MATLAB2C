%% Useful documentation
% Code generation workflow:
% https://www.mathworks.com/help/coder/code-generation.html?s_tid=CRUX_lftnav

%% Directories
work_dir = 'C:\Users\danie\OneDrive\Documents\MATLAB\MATLAB2C\dftfilt2C';
CLion_dir = 'C:\Users\danie\CLionProjects\dftfilt2';

%% Check for run-time issues
coder.screener('dftfilt2_2_c.m')
dftfilt2_test;
codegen dftfilt2_2_c -args {freqs, cycles, srate} -test dftfilt2_test

%% Standalone C/C++ code and compile it to a library specifying code generation options
% This will generate an example main function
% See this page for an example of generating/using an example main function: 
% https://www.mathworks.com/help/coder/ug/generate-and-modify-an-example-cc-main-function.html

% 1. Create a configuration object for a C static library
cfg = coder.config('lib');

% 2. Generate a C static library using the configuration object
codegen -report -config cfg dftfilt2_2_c -args {freqs, cycles, srate}

%% Copy example main files to modify them
main_path = fullfile(work_dir, 'codegen/lib/dftfilt2_2_c/examples/main.c');
mainh_path = fullfile(work_dir, 'codegen/lib/dftfilt2_2_c/examples/main.h');
copyfile(main_path, CLion_dir)
copyfile(mainh_path, CLion_dir)

% After this step you have to modify the main files. The example 
% main function declares and initializes data, including dynamically
% allocated data, to zero values. It calls entry-point functions 
% with arguments set to zero values, but it does not use values 
% returned from the entry-point functions.

% See this page on the structure of the generated example main file:
% https://www.mathworks.com/help/coder/ug/structure-of-example-cc-main-function.html

%% Generate the application
% Create a configuration object for a C standalone executable
cfg = coder.config('exe');

% Generate a C standalone executable using the configuration object
% and the modified main function.
codegen -report -config cfg dftfilt2_2_c main.c main.h

% By default, the code generated for the executable is in the 
% folder codegen/exe/dftfilt2.

%% Run the application

system('dftfilt2.exe 5 5 256')
%% Package generated code in ZIP file for relocation
% packNGo documentation: https://www.mathworks.com/help/coder/ref/packngo.html

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