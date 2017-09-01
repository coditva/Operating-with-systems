
# Add all targets here
BINARIES=send_nudes

all: $(BINARIES)


send_nudes: send_nudes.o
	gcc -o send_nudes send_nudes.o
send_nudes.o: send_nudes.c
	gcc send_nudes.c -c


.PHONY: clean
clean:
	rm -f *.o $(BINARIES)
