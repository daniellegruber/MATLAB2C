% idx1 = find(contains(main_lines, 'argInit_2x2_real_T(double result[4])'));
% idx2 = find(contains(main_lines, '{'));
% start_idx = idx1(ismember(idx1 + 1, idx2));
% 
% idx3 = find(contains(main_lines, '}'));
% 
% disp(main_lines(idx))
% disp(idx1)
% disp(idx2)
% disp(idx3)

%find(contains(main_lines, 'Function Definitions'))

comment_lines = contains(main_lines,{'//','/*'});

% distinguish between declarations, definitions, and function calls


%regexp(main_lines, ['.*(\<void\>|\<int\>|\<double\>).*',cfun_name,'.*'],'match','once');
fun_declare_define = regexp(main_lines, ['.*[a-zA-Z]+\s',cfun_name,'.*'],'match','once');
fdd_idx = ~cellfun(@isempty, fun_declare_define) & ~comment_lines;
fun_declare_define = fun_declare_define(fdd_idx);
%fun_calls = contains(main_lines, [cfun_name, '('])
fun_calls = regexp(main_lines, ['.*',cfun_name,'\(.*\).*'],'match','once');
fc_idx = ~cellfun(@isempty, fun_calls) & ~fdd_idx & ~comment_lines;
fun_calls = fun_calls(fc_idx);