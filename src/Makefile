CC=g++
CFLAGS=-std=c++11 -g -Wall

all:main.out

# $@ is target name, $^ is dependencies
main.out: main.cpp ClueCard.o
	$(CC) $(CFLAGS) -o $@ $^

# $< is the first dependency
ClueCard.o: ClueCard.cpp ClueCard.hpp ClueElements.o
	$(CC) $(CFLAGS) -c $<

ClueElements.o: ClueElements.cpp ClueElements.hpp
	$(CC) $(CFLAGS) -c $<

test:
	./main.out

clean:
	rm main.out *.o