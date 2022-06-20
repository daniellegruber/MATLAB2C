% write a function indexed_element_2_pointer that
% replaces x with p_x or let x = *p_x, x[0] = *p_x, x[1] = *(p_x + 1), x[2] = *(p_x + 2)...

function ptr_idx = arr_2_ptr_idx(str, arr, ptr)

%str = 'x[20]';
%offset = regexp(str, '\[\d*\]', 'match', 'once');
%offset = regexp(str, '(?<=\[)\d*(?=\])', 'match', 'once');
offset = regexp(str, ['(?<=', arr, '\[)\d*(?=\])'], 'match', 'once');
ptr_idx = ['*(', ptr, ' + ', offset, ')'];

end