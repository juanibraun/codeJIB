fir_exe : testfir.o fir.o
	gcc testfir.o fir.o -o fir_exe
	
fir.o : fir.c
	gcc -c fir.c
	
testfir.o : testfir.c
	gcc -c testfir.c
	
clean:
	rm -f *.o