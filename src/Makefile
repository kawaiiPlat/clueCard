CC=g++
CFLAGS=-std=c++11 -g -Wall

all:main.out

# $@ is target name, $^ is dependencies
main.out: main.cpp ClueGame.o ClueCard.o ClueElement.o
	$(CC) $(CFLAGS) -o $@ $^

# $< is the first dependency
ClueGame.o: ClueGame.cpp ClueGame.hpp
	$(CC) $(CFLAGS) -c $< 

ClueCard.o: ClueCard.cpp ClueCard.hpp colors.hpp ClueElement.o
	$(CC) $(CFLAGS) -c $<

ClueElement.o: ClueElement.cpp ClueElement.hpp
	$(CC) $(CFLAGS) -c $< 

test:
	./main.out

# rm -f doesn't fail if the file you try to remove doesn't exist
clean:
	rm -f main.out *.o *.gch