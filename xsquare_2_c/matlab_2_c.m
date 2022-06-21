%% Useful documentation
% Code generation workflow:
% https://www.mathworks.com/help/coder/code-generation.html?s_tid=CRUX_lftnav

fun_name = 'xsquare';
cfun_name = [fun_name, '_2_c'];
test_name = [fun_name, '_test'];

%% Directories
work_dir = fullfile('C:\Users\danie\OneDrive\Documents\MATLAB\MATLAB2C',...
    cfun_name);
codegen_dir = fullfile(work_dir, 'codegen\lib', cfun_name);
CLion_dir = fullfile('C:\Users\danie\CLionProjects', cfun_name);
if ~exist(CLion_dir, 'dir')
   mkdir(CLion_dir)
end
cd(work_dir)

%% Extract arguments using regexp
fun_text = fileread([cfun_name, '.m']);
args = regexp(fun_text, '(?<=\()[^)]*(?=\))', 'match', 'once');
args_split = strtrim(strsplit(args, ','));

%% Extract outputs using regexp
outs = extractBetween(fun_text,'function','=');
if iscell(outs)
    outs = outs{1};
end
outs = unique(regexprep(outs, {'[', ']'}, ''));
outs_split = strtrim(strsplit(outs, ','));

%% Check for run-time issues
coder.screener([cfun_name, '.m'])
eval(test_name);
eval(['codegen ', cfun_name, ' -args {', args, '} -test ', test_name])

%% Standalone C/C++ code and compile it to a library specifying code generation options
% This will generate an example main function
% See this page for an example of generating/using an example main function: 
% https://www.mathworks.com/help/coder/ug/generate-and-modify-an-example-cc-main-function.html

% 1. Create a configuration object for a C static library
cfg = coder.config('lib');

% 2. Generate a C static library using the configuration object
eval(['codegen -report -config cfg ', cfun_name, ' -args {', args, '}'])

%% Copy example main files to modify them
main_path = fullfile(codegen_dir, 'examples/main.c');
mainh_path = fullfile(codegen_dir, 'examples/main.h');
copyfile(main_path, CLion_dir)
copyfile(mainh_path, CLion_dir)
copyfile(main_path, codegen_dir)
copyfile(mainh_path, codegen_dir)


%% Copy fun mfile to codegen folder
copyfile(fullfile(work_dir, [cfun_name, '.m']), codegen_dir)

%% Automatically modify main file
% After this step you have to modify the main files. The example 
% main function declares and initializes data, including dynamically
% allocated data, to zero values. It calls entry-point functions 
% with arguments set to zero values, but it does not use values 
% returned from the entry-point functions.

% See this page on the structure of the generated example main file:
% https://www.mathworks.com/help/coder/ug/structure-of-example-cc-main-function.html

% You can skip this step if you want to do it manually. If you do it
% automatically, at least check that everything "worked" correctly and that
% you don't have to make any more changes.

modify_main;

%% Generate the application
% Create a configuration object for a C standalone evalutable
cfg = coder.config('exe');

% Generate a C standalone evalutable using the configuration object
% and the modified main function.
% codegen -report -config cfg dftfilt2_2_c main.c main.h
cd(codegen_dir)
%eval(['codegen -report -config cfg ', cfun_name,' -args {', args, '} main.c main.h'])
eval(['codegen -report -config cfg ', cfun_name,' -args {', 'x', '} main.c main.h'])
% By default, the code generated for the evalutable is in the 
% folder codegen/exe/cfun_name.

%% Run the application

system([cfun_name,'.exe {1, 1, 2, 2}'])

%%
load('buildInfo.mat')
%myBuildInfo = RTW.BuildInfo;
addTMFTokens(buildInfo, ...
             '|>CUSTOM_OUTNAME<|', [cfun_name,'.exe'], 'LINK_INFO');
%% Package generated code in ZIP file for relocation
% packNGo documentation: https://www.mathworks.com/help/coder/ref/packngo.html

buildInfo_dir = fullfile(codegen_dir, 'buildInfo.mat');
load(buildInfo_dir);

filename = fullfile(work_dir, [fun_name, '_built.zip']);
packNGo(buildInfo, 'packType', 'hierarchical', 'fileName', filename);

unzip(filename, CLion_dir)

filename = fullfile(CLion_dir, 'sDirFiles.zip');
unzip(filename, CLion_dir)
delete(filename)

filename = fullfile(CLion_dir, 'mlrFiles.zip');
unzip(filename, CLion_dir)
delete(filename)