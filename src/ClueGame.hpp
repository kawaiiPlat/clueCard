#ifndef CLUEGAME_H
#define CLUEGAME_H

#include <iostream>
#include <iomanip>

#include "colors.hpp"
#include "ClueCard.hpp"
#include "ClueElement.hpp"

#define CLEAR_SCREEN        "\e[2;J" 
#define MOVE_TO_TOP_LEFT    "\e[0;0;H"
// the 28 depends on the length of the card message
#define MOVE_TO_MESSAGE_POS "\e[28;0;H"

// this should be private I think, but there are access errors currently if it's set to private
class ClueGame: public ClueCard{
    public:
        ClueGame();
        void print();
        void update(ClueCard::playerData::CCPLAYER player, std::vector<ClueElement::CEIDS> guess);
        bool isGameOver();

    protected:
    int roundCounter;
    bool gameOver = false;

};

#endif