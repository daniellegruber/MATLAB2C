%%
main_text = fileread(fullfile(codegen_dir, 'examples\main.c'));
lines = splitlines(main_text);
lines2 = lines;

%%
nargv = length(args_split);
classes = cell(1,nargv);
modify_text = cell(1,4);
modify_text{1} = cell(nargv, 1);
modify_text{3} = cell(nargv, 1);
for i = 1:nargv
    classes{i} = eval(['class(',args_split{i},')']);
    modify_text{1}{i} = [classes{i}, ' ', args_split{i}, ';'];

    if strcmp(classes{i},'double')
        modify_text{3}{i} = [args_split{i} '= atof(argv[', num2str(i), ']);'];
    end
end
%%
modify_text{2} = cell(4,1);
modify_text{2}{1} = ['if (argc != ', num2str(nargv + 1), ') {'];
modify_text{2}{2} = ['printf(''Expected ', num2str(nargv) , ' arguments: ', args, '\n'');'];
modify_text{2}{3} = 'exit(-1);';
modify_text{2}{4} = '}';

%% Replace all ... in main_cfun_name(...) and cfun_name(...) with args
remove = regexp(lines2,[cfun_name,'([^', args, '].*\)'],'match','once');
remove = unique(remove(~cellfun(@isempty, remove)));

idx = find(contains(lines2, remove));
str = lines2(idx);
old = [cfun_name,'(.*\)'];
match = regexp(str, old, 'match', 'once');
new = [cfun_name,'(',args,')'];
insertion = strrep(str, match, new);

[lines2, comment_idx] = comment_out(lines2, remove);

insert_idx = comment_idx;
if iscell(insertion)
    for i = 1:length(insert_idx)
        lines2 = insert_code(lines2, insertion{i}, insert_idx(i) + i - 1);
    end
else
    lines2 = insert_code(lines2, insertion, insert_idx);
end
%%

remove = {'(void)argc', '(void)argv'};
[lines2, comment_idx] = comment_out(lines2, remove);

insertion = vertcat(modify_text{1:3});
insert_idx = comment_idx(end);
lines2 = insert_code(lines2, insertion, insert_idx);

%%
% remove = ['main_', cfun_name, '()'];
% [lines2, comment_idx] = comment_out(lines2, remove);
% 
% insertion = ['main_', cfun_name, '(', args, ')'];
% insert_idx = comment_idx;
% lines2 = insert_code(lines2, insertion, insert_idx);

%% 
% remove = ['static void main_', cfun_name,'(void)'];
% [lines2, comment_idx] = comment_out(lines2, remove);
% 
% insertion = ['static void main_', cfun_name,'(', args, ')'];
% insert_idx = comment_idx;
% lines2 = insert_code(lines2, insertion, insert_idx);



%% Write to file

writetable(cell2table(lines2), fullfile(codegen_dir,'main.txt'), 'WriteVariableNames', false, 'QuoteStrings','none')
movefile(fullfile(codegen_dir,'main.txt'),fullfile(codegen_dir,'main.c'))
%%
function [new_code, comment_idx] = comment_out(old_code, line)
    comment_idx = find(contains(old_code, line));
    commented_code = cellfun(@(x) ['//', x], old_code(comment_idx), 'UniformOutput', false);
    new_code = old_code;
    new_code(comment_idx) = commented_code;
end

function indented_code = indent_code(prev_line, new_line)
    indent = regexp(prev_line, '\s*', 'match');
    indent = indent{1};

    if iscell(new_line)
        indented_code = cellfun(@(x) [indent, x], new_line, 'UniformOutput', false);
    else
        indented_code = [indent, new_line];
    end
end

function inserted_code = insert_code(old_code, insertion, insert_idx)
    prev_line = old_code{insert_idx};
    insertion = indent_code(prev_line, insertion);
    inserted_code = [old_code(1:insert_idx); insertion; old_code(insert_idx+1:end)];
end
