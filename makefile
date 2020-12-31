CC=gcc
FLAGS= -Wall -g

all: libmysort.a libmytxt.a isort txtfind
isort: mainsort.o libmysort.a
	$(CC) $(FLAGS) -o isort mainsort.o mysort.o
txtfind: maintxt.o libmytxt.a
	$(CC) $(FLAGS) -o txtfind maintxt.o mytxt.o
libmysort.a: mysort.o
	ar -rcs libmysort.a mysort.c
libmytxt.a: mytxt.o
	ar -rcs libmytxt.a mytxt.c
mysort.o: mysort.c headersort.h
	$(CC) $(FLAGS) -c mysort.c
mytxt.o: mytxt.c headertxt.h
	$(CC) $(FLAGS) -c mytxt.c
mainsort.o: mainsort.c headersort.h
	$(CC) $(FLAGS) -c mainsort.c
maintxt.o: maintxt.c headertxt.h
	$(CC) $(FLAGS) -c maintxt.c

.PHONY: clean all

clean:
	rm -f *.a *.o *.out isort txtfind
