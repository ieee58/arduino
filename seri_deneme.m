delete(instrfindall);
s = serial('COM3')
fclose(s)
fopen(s)
fprintf(s,'*IDN?')
tic
for i=1:1000
    
if i>1    
    abs= fscanf(s);
    pk2pk(i) = fscanf(s,'%e',14);
end
end
toc
fclose(s)