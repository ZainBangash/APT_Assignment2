.default: all

all: scrabble

clean:
	rm -rf scrabble.out *.o *.dSYM

scrabble: Tile.o Node.o LinkedList.o scrabble.o Board.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@.out $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
