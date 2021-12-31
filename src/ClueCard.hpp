#ifndef CLUECARD_H
#define CLUECARD_H

#include <vector>
#include <iostream>
#include <cassert> //for assertions
// uncomment the line below to disable assertions, doesn't seem to actually disable?
//#define NDEBUG
#include <iomanip>

#include "colors.hpp" // preprocessor macros to put color codes into std::cout

#include "ClueElement.hpp"

class ClueCard{
    public:
        ClueCard();
        int print();
        void updateCard(int playerWhoShowed, std::vector<ClueElement::CEIDS> whatWasSuggested);

        static const int CARDLEN   = 21;
        static const int CARDWIDTH = 6;



        // playerData: player's color + 
        //             a column of data on what elements they may have
        using col_t = std::vector<ClueElement::Element>;

        class playerData{
            public:
                // Enum for the player IDs
                enum CCPLAYER{
                    RED,
                    GREEN,
                    YELLOW,
                    PURPLE,
                    CYAN,
                    WHITE
                };
            private:
                // c-style character string names
                const char* const strCCPLAYER[CARDWIDTH]{
                    "Red",
                    "Green",
                    "Yellow",
                    "Purple",
                    "Cyan",
                    "White"
                };
                CCPLAYER player;
            public:
                playerData();
                bool setPlayer(CCPLAYER player);

                col_t column;
                const char* getPlayerName();
                CCPLAYER getPlayer();

                ClueElement::Element& operator[](int);
        };

        playerData& operator[](int);


        using card_t = std::vector<playerData>;
        // the card data can be accessed with [column][row], aka [player][element]
        card_t card; // This will be CARDWIDTH # of columns
};

#endif