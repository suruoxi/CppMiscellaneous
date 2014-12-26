size = 10000
a=zeros(size,size);

tic 
for i=1:size
    for j=1:size
        a(i,j) = (i+j)/7;
    end
end
toc

tic 
for i=1:size
    for j=1:size
        a(j,i) = (i+j)/5;
    end
end
toc