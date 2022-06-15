main_fun_text = extractBetween(main_text,'int main(int argc, char **argv)', 'return');
main_fun_text = splitlines(main_fun_text);

%idx = contains(main_fun_text, ['main_', cfun_name]);
remove = ['main_', cfun_name];
[main_fun_text, comment_idx] = comment_code(main_fun_text, remove);

insertion = [outs, ' = main_', cfun_name, '(', args, ')'];
insert_idx = comment_idx;
if iscell(insertion)
    for i = 1:length(insert_idx)
        main_fun_text = insert_code(main_fun_text, insertion{i}, insert_idx(i) + i - 1);
    end
else
    main_fun_text = insert_code(main_fun_text, insertion, insert_idx);
end

%%
% line1 = 'int main(int argc, char **argv)';
% line2 = 'return';
% idx1 = find(contains(lines2, line1));
% idx2 = find(contains(lines2, line2));
% idx2 = idx2(idx2 > idx1);
% idx2 = idx2(1);
% 
% remove = ['main_', cfun_name];
% comment_idx = find(contains(lines2(idx1:idx2),remove)) + idx1;
% [main_fun_text, comment_idx] = comment_out(main_fun_text, remove);

comment_line = ['main_', cfun_name];
segment = {'int main(int argc, char **argv)', 'return'};
% [lines2, comment_idx] = comment_code(lines2, comment_line, 'search_segment',segment);
[lines2, modify_idx] = modify_code(lines2, comment_line, 'comment', 'search_segment',segment);
[lines2, modify_idx] = modify_code(lines2, modify_idx, 'insert', 'insertion', insertion);
%% Helper functions

function [new_code, modify_idx] = modify_code(old_code, modify_idx, modification, varargin)

p = inputParser;

isValidModification = @(x) ismember(x, {'comment', 'insert', 'replace', 'remove'});
isValidIdx = @(x) ischar(x) || isnumeric(x);
isValidSegment = @(x) (iscellstr(x) || isnumeric(x)) && length(x) == 2;
isValidInsert = @(x) iscellstr(x) || ischar(x);

addRequired(p, 'old_code',@iscellstr);
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

% Search segment
if isempty(search_segment)
    if ischar(modify_idx)
        modify_idx = find(contains(old_code, modify_idx));
    end
    
else
    if iscellstr(search_segment)
        line1 = search_segment{1};
        line2 = search_segment{2};
        idx1 = find(contains(old_code, line1));
        idx2 = find(contains(old_code, line2));
        idx2 = idx2(idx2 > idx1);
        idx2 = idx2(1);
        modify_idx = find(contains(old_code(idx1:idx2), modify_idx)) + idx1 - 1;
    else
        idx1 = search_segment(1);
        idx2 = search_segment(2);
        modify_idx = find(contains(old_code(idx1:idx2), modify_idx)) + idx1 - 1;
    end
        
end

% Comment out code
if strcmp(modification, 'comment')
    new_code = comment_code(old_code, modify_idx);

% Insert code
elseif strcmp(modification, 'insert')
    new_code = insert_code(old_code, insertion, modify_idx);

% Replace code
elseif strcmp(modification, 'replace')
    new_code = insert_code(old_code, replacement, modify_idx);

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
    indent = regexp(prev_line, '\s*', 'match');
    indent = indent{1};

    if iscell(new_line)
        indented_code = cellfun(@(x) [indent, x], new_line, 'UniformOutput', false);
    else
        indented_code = [indent, new_line];
    end
end

% Insert code
function inserted_code = insert_code(old_code, insertion, insert_idx)
    prev_line = old_code{insert_idx};
    insertion = indent_code(prev_line, insertion);
    inserted_code = [old_code(1:insert_idx); insertion; old_code(insert_idx+1:end)];
end

% Replace code
function replaced_code = replace_code(old_code, old_line, new_line)
    replace_idx = find(contains(old_code, old_line));
    old_line = old_code{replace_idx};
    new_line = indent_code(old_line, new_line);
    replaced_code = old_code;
    if ~iscell(new_line)
        new_line = {new_line};
    end
    replaced_code(replace_idx) = new_line;
end
