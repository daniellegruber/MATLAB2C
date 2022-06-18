x = [1 2; 1 2];
save([fun_name, '_args.mat'], 'x');
%%
load([fun_name, '_args.mat']);
fun_call = extractBetween(fun_text,'function',')');
if iscell(fun_call)
    fun_call = fun_call{1};
end
fun_call = strip([fun_call, ');']);
eval(fun_call)
for i = 1:length(outs_split)
    eval(['disp(',outs_split{i},')'])
end
tmp = strjoin(cellfun(@(x) ['''',x,''''], outs_split,...
    'UniformOutput', false),',');
eval(['save(''',[fun_name, '_outs.mat'''],',' tmp, ');'])