#define EXIT_SUCCESS 0

#include "Scrabble.h"


int main(void) {
    Scrabble game = Scrabble("ScrabbleTiles.txt");
    game.run();

    return EXIT_SUCCESS;
}
