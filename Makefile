CC := gcc
FLAG := -lm

all: test test.c entropy.c

test: test.c entropy.c
	$(CC) -o $@ $^ $(FLAG)

clean:
	rm -f *.o test
