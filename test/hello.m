function hello(num)
fileID = fopen('test_data.csv', 'w');
fwrite(fileID, num)
end