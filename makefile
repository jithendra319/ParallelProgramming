result.out: thread.c compmul.o
	gcc thread.c compmul.o -o result.out -lpthread
	
compmul.o: compmul.c compmul.h
	gcc -c compmul.c

clean:
	rm -f *.o *.out


