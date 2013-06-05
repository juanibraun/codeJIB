size = 1000;
s = sprand(size,size,0.2);
a = full(a);


inFile = fopen('s9.txt','w');
fprintf(inFile,'%d %d\n',size,size);
 for i=1:size
      for j=1:size
          if i==j
              fprintf(inFile,'%d ',0);
          else
            fprintf(inFile,'%d ',round(1000*a(i,j))); 
          end
      end
      fprintf(inFile,'\n');
 end
 fclose(inFile);