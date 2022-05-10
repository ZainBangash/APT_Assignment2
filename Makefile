.default: all

all: scrabble

clean:
	rm -f scrabble.out *.o *.dSYM

scrabble: Tile.o Node.o LinkedList.o Scrabble.o Board.o Player.o TileBag.o main.o
	g++ -Wall -Werror -std=c++14 -g -O -o $@.out $^

%.o: %.cpp
	g++ -Wall -Werror -std=c++14 -g -O -c $^
