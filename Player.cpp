#include "Player.h"



// runs all validation code, if it gets too long move sections into individual methods
bool Player::validate(vector<PlacedTile> tilesPlaced) {
    bool valid = true;
    WordDirection wDir;

    // check tiles are not placed on top of one another
    for (PlacedTile t : tilesPlaced) {
        if (board->tileExists(t.x, t.y)) {
            valid = false;
        }
    }

    // check all tiles placed are in the same row or column
    if (tilesPlaced.size() > 1) {
        int row = tilesPlaced[0].y;
        int col = tilesPlaced[0].x;

        if (row == tilesPlaced[1].y) {
            wDir = Vertical;
        } else {
            wDir = Horizontal;
        }

        switch(wDir) {
        case Vertical:
            for (PlacedTile t : tilesPlaced) {
                if (t.y != row) {
                    valid = false;
                }
            }
            break;

        case Horizontal:
            for (PlacedTile t : tilesPlaced) {
                if (t.x != col) {
                    valid = false;
                }
            }
            break;

        }
    }

    return valid;

};

// returns true when the player has a specific tile in their hand
bool hasTile {


};
