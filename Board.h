// Recognized as "include guards"
// Prevent the board header file from being used more than once
#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Riddle.h"
#include "Characters.h"
#include "UsefulFunctions.h"

class Board {
    private:
        // Static in this context: Belongs to the class, not each object
        static const int _BOARD_SIZE = 52;
        static const int _MAX_PLAYERS = 2;

        // Composition!
        Tile _tiles[2][_BOARD_SIZE];

        int _player_count;
        int _player_position[_MAX_PLAYERS];
    int _player_lane[_MAX_PLAYERS]; // which physical lane (0 or 1) each logical player uses

        void initializeTiles(int player_index, int pathNum);
        bool isPlayerOnTile(int player_index, int pos);
        void displayTile(int player_index, int pos);

    public:
        // Default Constructor
        Board(bool same);

        void initializeBoard(bool sameBoard);
    void assignPlayerToLane(int logicalPlayer, int laneIndex);
        void displayTrack(int player_index);
        void displayBoard();
        bool movePlayer(int player_index);
        bool movePlayerBack(int player_index);
        // Recall we can use const for getter functions
        int getPlayerPosition(int player_index) const;
        char getTileColor(int player_index) const;
        void setTileColorGreen(int player_index);
};

#endif