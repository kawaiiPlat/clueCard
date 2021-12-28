CC=g++
CFLAGS=-g -Wall

all:main.out

# $@ is target name, $^ is dependencies
main.out: main.cpp ClueCard.o
	$(CC) $(CFLAGS) -o $@ $^

# $< is the first dependency
ClueCard.o: ClueCard.cpp ClueCard.hpp
	$(CC) $(CFLAGS) -c $<

test:
	./main.out

clean:
	rm main.out *.o