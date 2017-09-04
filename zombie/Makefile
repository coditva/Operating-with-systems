
# Add all targets here
BINARIES=zombie

all: $(BINARIES)


zombie: zombie.o
	gcc -o zombie zombie.o
zombie.o: zombie.c
	gcc zombie.c -c


.PHONY: clean
clean:
	rm -f *.o $(BINARIES)
