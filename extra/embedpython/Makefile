CC = gcc
LD = gcc

INC = /usr/include/python2.4/
LDLIBS = -lpython2.4

embed_in_c: embed_in_c.o
	$(LD) $(LDLIBS) embed_in_c.o -o embed_in_c

embed_in_c.o: embed_in_c.c
	$(CC) -c -I $(INC) embed_in_c.c -o embed_in_c.o

run_func: run_func.o
	$(LD) $(LDLIBS) run_func.o -o run_func

run_func.o: run_func.c
	$(CC) -c -I $(INC) run_func.c -o run_func.o

clean:
	rm *.o

