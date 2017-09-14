all: do_something


do_something: do_something.c
	gcc -g -o do_something.o do_something.c -lpthread

.PHONY: clean
clean:
	rm -f *.o $(BINARIES)
