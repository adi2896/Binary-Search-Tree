all: program6

program6: program6.o bst.o
	gcc program6.o bst.o -o program6

program6.o: program6.c bst.h
	gcc -c program6.c -o program6.o

bst.o: bst.c bst.h
	gcc -c bst.c -o bst.o

run: all
	./program6

memcheck: all
	valgrind -v ./program6

clean:
	rm -f *.o program6