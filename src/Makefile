CC=g++
CFLAGS=-std=c++11 -g -Wall

all:main.out

# $@ is target name, $^ is dependencies
main.out: main.cpp ClueCard.o ClueElement.o
	$(CC) $(CFLAGS) -o $@ $^

# $< is the first dependency
ClueCard.o: ClueCard.cpp ClueCard.hpp ClueElement.o
	$(CC) $(CFLAGS) -c $<

ClueElement.o: ClueElement.cpp ClueElement.hpp
	$(CC) $(CFLAGS) -c $< 

test:
	./main.out

// rm -f doesn't fail if the file you try to remove doesn't exist
clean:
	rm -f main.out *.o *.gch