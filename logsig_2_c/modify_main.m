%class(M)
%cellfun(@class, args2, 'UniformOutput', false)
nargv = length(args_split);
classes = cell(1,nargv);
modify_text = cell(1,4);
modify_text{1} = cell(nargv, 1);
modify_text{3} = cell(nargv, 1);
for i = 1:nargv
    classes{i} = eval(['class(',args_split{i},')']);
    modify_text{1}{i} = [classes{i}, ' ', args_split{i}, ';'];

    if strcmp(classes{i},'double')
        modify_text{3}{i} = [args_split{i} '= atof(argv[', num2str(i), ')'];
    end
end
%%
modify_text{2} = cell(4,1);
modify_text{2}{1} = ['if (argc != ', num2str(nargv + 1), ') {'];
modify_text{2}{2} = ['printf(''Expected ', num2str(nargv) , ' arguments: ', args, '\n'');'];
modify_text{2}{3} = 'exit(-1);';
modify_text{2}{4} = '}';

%%
main_text = fileread(fullfile(codegen_dir, 'examples\main.c'));
lines = splitlines(main_text);
lines2 = lines;

comment_idx = zeros(1, 2);
comment_idx(1) = find(contains(lines2,'(void)argc'));
comment_idx(2) = find(contains(lines2,'(void)argv'));

insertion = vertcat(modify_text{1:3});

commented_code = cellfun(@comment_out, lines2(comment_idx), 'UniformOutput', false);
lines2(comment_idx) = commented_code;

insert_idx = comment_idx(2);
prev_line = lines2{insert_idx};
insertion = cellfun(@(x) indent_code(prev_line, x), insertion, 'UniformOutput', false);

lines2 = insert_code(lines2, insertion, insert_idx);

%%
comment_idx = find(contains(lines2,['main_', cfun_name, '()']));
commented_code = comment_out(lines2{comment_idx});
lines2{comment_idx} = commented_code;

insertion = ['main_', cfun_name, '(', args, ')'];

insert_idx = comment_idx;
prev_line = lines2{insert_idx};
insertion = indent_code(prev_line, insertion);

lines2 = insert_code(lines2, insertion, insert_idx);

%% Write to file

% writecell(lines2, 'new_main.txt')
writetable(cell2table(lines2),'new_main.txt', 'WriteVariableNames', false, 'QuoteStrings','none')
%%
function commented_code = comment_out(line)
    commented_code = ['//', line];
end

function indented_code = indent_code(prev_line, new_line)
    indent = regexp(prev_line, '\s*', 'match');
    indent = indent{1};
%     if contains(prev_line, {'if', 'else', 'for', 'while'})
%         indent = ['  ', indent];
%     end
    indented_code = [indent, new_line];
end

function inserted_code = insert_code(old_code, insertion, insert_idx)
    inserted_code = [old_code(1:insert_idx); insertion; old_code(insert_idx+1:end)];
end
