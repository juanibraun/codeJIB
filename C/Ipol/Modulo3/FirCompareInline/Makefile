fir_exe : testfir.o fir.o 
	gcc -g testfir.o fir.o -o fir_exe
	
fir.o : fir.c
	gcc -g -c fir.c
	
testfir.o : testfir.c
	gcc -g -c testfir.c

	
clean:
	rm -f *.o