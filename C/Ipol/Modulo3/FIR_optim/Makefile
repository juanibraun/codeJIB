fir_exe : testfir.o fir.o
	gcc -O2 testfir.o fir.o -o fir_exe
	
fir.o : fir.c
	gcc -O2 -c fir.c
	
testfir.o : testfir.c
	gcc -O2 -c testfir.c
	
clean:
	rm -f *.o