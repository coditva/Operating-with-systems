
# Add all targets here
all: simple_fork


# A simple fork example
simple_fork: simple_fork.o
	gcc -o simple_fork simple_fork.o

simple_fork.o: simple_fork.c
	gcc simple_fork.c -c


.PHONY: clean
clean:
	rm -f *.o simple_fork
