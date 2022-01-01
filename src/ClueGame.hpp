#ifndef CLUEGAME_H
#define CLUEGAME_H

#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "colors.hpp"
#include "ClueCard.hpp"
#include "ClueElement.hpp"

#define CLEAR_SCREEN        "\e[2;J" 
#define MOVE_TO_TOP_LEFT    "\e[0;0;H"
// the 28 depends on the length of the card message
#define MOVE_TO_MESSAGE_POS "\e[28;0;H"
#define SAVE_CURSOR_POS "\e[s"
#define RESTORE_CURSOR_POS "\e[u"

// this should be private I think, but there are access errors currently if it's set to private
class ClueGame: public ClueCard{
    public:
        ClueGame();
        void print();
        void start();
        void pickPlayer();
        void update();
        bool isGameOver();

    protected:
    //random choice of starter
    ClueCard::playerData::CCPLAYER currentPlayer = ClueCard::playerData::CCPLAYER::RED;
    ClueCard::playerData::CCPLAYER ourPlayer = ClueCard::playerData::CCPLAYER::GREEN;
    int roundCounter = 0;
    bool gameOver = false;
    ClueElement::CEIDS getElement(int START_IDX, int NUM_OF_TYPE, std::string message);
    void printGetElementMessage(int START_IDX, int NUM_OF_TYPE, std::string message);
    void printPickPlayerMessage();

};

#endif