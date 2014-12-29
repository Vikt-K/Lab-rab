capture: capture.o gradation.o
	gcc -o capture capture.o
	gcc -o gradation gradation.o
capture.o: capture.c
	gcc -c capture.c
gradation.o: gradation.c
	gcc -c gradation.c
clean: *.o
	rm -rf *.o capture
