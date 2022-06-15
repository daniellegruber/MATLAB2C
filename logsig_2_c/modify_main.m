%% Get the main file generated by MATLAB Coder from the examples folder
% we will modify the text in this file by commenting out lines we want to
% replaces and inserting new lines

main_text = fileread(fullfile(codegen_dir, 'examples\main.c'));
lines = splitlines(main_text);
lines2 = lines;

%% Declare variables and specify data types

nargv = length(args_split);
nout = length(outs_split);
arg_classes = cell(1,nargv);
out_classes = cell(1,nout);

insertion = cell(1,4);
insertion{1} = cell(nargv, 1);
insertion{3} = cell(nargv, 1);

for i = 1:nargv
    % determine class of variable using the variables saved in
    % workspace/mat file for testing
    arg_classes{i} = eval(['class(',args_split{i},')']);
    insertion{1}{i} = [arg_classes{i}, ' ', args_split{i}, ';'];

    % if variable is numeric, convert from string to float using atof()
    if strcmp(arg_classes{i},'double')
        insertion{3}{i} = [args_split{i} '= atof(argv[', num2str(i), ']);'];
    end
end

insertion{2} = cell(nout, 1);
for i = nout
    out_classes{i} = eval(['class(',outs_split{i},')']);
    insertion{2}{i} = [out_classes{i}, ' ', outs_split{i}, ';'];
end

%% Determine whether number of arguments is correct
insertion{4} = cell(4,1);
insertion{4}{1} = ['if (argc != ', num2str(nargv + 1), ') {'];
insertion{4}{2} = ['printf(''Expected ', num2str(nargv) , ' arguments: ', args, '\n'');'];
insertion{4}{3} = 'exit(-1);';
insertion{4}{4} = '}';

%% For testing

insertion{5} = cell(5,1);
insertion{5}{1} = 'int i=0;';
insertion{5}{2} = 'printf("\nexe name=%s", argv[0]);';
insertion{5}{3} = 'for (i=1; i< argc; i++) {';
insertion{5}{4} = 'printf("\narg%d=%s", i, argv[i]);';
insertion{5}{5} = ' }';
insertion{5}{6} = 'printf("\nM=%f",M);';

%% Insert declaration of variables and argument number check

comment_idx = {'(void)argc', '(void)argv'};
[lines2, comment_idx] = modify_code(lines2, comment_idx, 'comment');

insert_idx = comment_idx(end);
[lines2, ~] = modify_code(lines2, insert_idx, 'insert', 'insertion', insertion);


%% Make sure to get output of main_cfun_name in main function
insertion = [outs, ' = main_', cfun_name, '(', args, ');'];
comment_idx = ['main_', cfun_name];
segment = {'int main(int argc, char **argv)', 'return'};
[lines2, insert_idx] = modify_code(lines2, comment_idx, 'comment', 'search_segment',segment);
[lines2, ~] = modify_code(lines2, insert_idx, 'insert', 'insertion', insertion);

%% Replace all ... in main_cfun_name(...) and cfun_name(...) with args
comment_lines = contains(lines2,{'//','/*'});

modify_idx = regexp(lines2,['(', cfun_name,'\(\))|', ... 
    cfun_name,'([^', args, '].*\)'],'match','once');
modify_idx = unique(modify_idx(~cellfun(@isempty, modify_idx)));

idx = find(contains(lines2, modify_idx) & ~comment_lines);
str = lines2(idx);
old = [cfun_name,'(.*\)'];
match = regexp(str, old, 'match', 'once');
new = [cfun_name,'(',args,')'];
insertion = strrep(str, match, new);

[lines2, insert_idx] = modify_code(lines2, modify_idx, 'comment');
[lines2, ~] = modify_code(lines2, insert_idx, 'insert', 'insertion', insertion);

%% Specify arg data types in call to static void main_cfun_name()
replace_idx = ['static void main_', cfun_name, '(', args, ')'];

joined_classes = cell(nargv,1);
for i = 1:nargv
    joined_classes{i} = [arg_classes{i}, ' ', args_split{i}];
end
joined_classes = strjoin(joined_classes, ' ,');

replacement = lines2(contains(lines2, replace_idx));
replacement = strrep(replacement, args, joined_classes);
[lines2, ~] = modify_code(lines2, replace_idx, 'replace', 'replacement', replacement);

%% Change void to return type
replace_idx = find(contains(lines2,['static void main_', cfun_name]));
replacement = strrep(lines2(replace_idx), 'static void', ...
    ['static ', out_classes{1}]);

[lines2, ~] = modify_code(lines2, replace_idx, 'replace', 'replacement', replacement);


% actually won't do this because if there are multiple return values might
% be hard, instead just save values

%% Include stdio.h
line = '/* Include files */';
insertion = '#include <stdio.h>';
insert_idx = find(contains(lines2, line));
[lines2, ~] = modify_code(lines2, insert_idx, 'insert', 'insertion', insertion);



%% Make sure to return output of cfun
line = fun_call;
insert_idx = find(contains(lines2,line));
insertion = cell(2,1);
insertion{1} = 'printf("\nl=%f",l);';
insertion{2} = ['return ', outs_split{1}, ';'];
[lines2, ~] = modify_code(lines2, insert_idx, 'insert', 'insertion', insertion);

%% Write to file
% Create a new main.c file in the codegen folder

writetable(cell2table(lines2), fullfile(codegen_dir,'main.txt'), 'WriteVariableNames', false, 'QuoteStrings','none')
movefile(fullfile(codegen_dir,'main.txt'),fullfile(codegen_dir,'main.c'))

%% Helper functions

function [new_code, modify_idx] = modify_code(old_code, modify_idx, modification, varargin)

p = inputParser;

isValidModification = @(x) ismember(x, {'comment', 'insert', 'replace', 'remove'});
isValidIdx = @(x) iscellstr(x) || ischar(x) || isnumeric(x);
isValidSegment = @(x) (iscellstr(x) || isnumeric(x)) && length(x) == 2;
isValidInsert = @(x) iscell(x) || ischar(x);

addRequired(p, 'old_code', @iscellstr);
addRequired(p, 'modify_idx', isValidIdx);
addRequired(p, 'modification', isValidModification)
addOptional(p, 'search_segment', {}, isValidSegment);
addOptional(p, 'insertion', {}, isValidInsert);
addOptional(p, 'replacement', {}, isValidInsert);

parse(p, old_code, modify_idx, modification, varargin{:});

old_code = p.Results.old_code;
modify_idx = p.Results.modify_idx;
modification = p.Results.modification;
search_segment = p.Results.search_segment;
insertion = p.Results.insertion;
replacement = p.Results.replacement;

comment_lines = contains(old_code,{'//','/*'});

% Search segment
if isempty(search_segment)
    if ischar(modify_idx) || iscellstr(modify_idx)
        modify_idx = find(contains(old_code, modify_idx) & ~comment_lines);
    end
    
else
    if iscellstr(search_segment)
        line1 = search_segment{1};
        line2 = search_segment{2};
        idx1 = find(contains(old_code, line1));
        idx2 = find(contains(old_code, line2));
        idx2 = idx2(idx2 > idx1);
        idx2 = idx2(1);
        
    else
        idx1 = search_segment(1);
        idx2 = search_segment(2);
        
    end
        
    modify_idx = find(contains(old_code(idx1:idx2), modify_idx) &...
        ~comment_lines(idx1:idx2)) + idx1 - 1;
end

% Comment out code
if strcmp(modification, 'comment')
    new_code = comment_code(old_code, modify_idx);

% Insert code
elseif strcmp(modification, 'insert')
    new_code = insert_code(old_code, insertion, modify_idx);

% Replace code
elseif strcmp(modification, 'replace')
    new_code = replace_code(old_code, replacement, modify_idx);

% Delete code 
elseif strcmp(modification, 'delete')
    new_code = delete_code(old_code, modify_idx);

end

end

%% Helper functions

% Comment out code
function new_code = comment_code(old_code, comment_idx)
    commented_code = cellfun(@(x) ['//', x], old_code(comment_idx), 'UniformOutput', false);
    new_code = old_code;
    new_code(comment_idx) = commented_code;
end

% Remove code
function new_code = delete_code(old_code, delete_idx)
    new_code = old_code;
    new_code(delete_idx) = {};
end
   

% Indent code based on indentation of previous line
function indented_code = indent_code(prev_line, new_line)
    if length(prev_line) < 3
        indent = {};
    elseif ~isempty(regexp(prev_line(1:3), '//\s', 'match'))
        indent = regexp(prev_line, '\s*', 'match');
        indent = indent{1};
    elseif isempty(regexp(prev_line(1),'\s','match'))
        indent = {};
    else
        indent = regexp(prev_line, '\s*', 'match');
        indent = indent{1};
    end

    if iscell(new_line)
        indented_code = cellfun(@(x) [indent, x], new_line, 'UniformOutput', false);
    else
        indented_code = [indent, new_line];
    end
    
end

% Insert code
function inserted_code = insert_code(old_code, insertion, insert_idx)
    if length(insert_idx) > 1
        inserted_code = old_code;
        for i = 1:length(insert_idx)
            if iscell(insertion{i})
                insertion{i} = vertcat(insertion{i}{:});
            end
            idx = insert_idx(i) + i - 1;
            prev_line = old_code{idx};
            insertion{i} = indent_code(prev_line, insertion{i});
            inserted_code = [inserted_code(1:idx); insertion{i}; inserted_code(idx+1:end)];
        end
    else
        if ~iscellstr(insertion) && ~ischar(insertion)
            insertion = vertcat(insertion{:});
        end
        idx = insert_idx;
        prev_line = old_code{idx};
        insertion = indent_code(prev_line, insertion);
        inserted_code = [old_code(1:idx); insertion; old_code(idx+1:end)];
    end
end

% Replace code
function replaced_code = replace_code(old_code, replacement, replace_idx)
    replaced_code = old_code;
    replaced_code(replace_idx) = replacement;
end
