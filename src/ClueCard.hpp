#ifndef CLUECARD_H
#define CLUECARD_H

#include <vector>
#include <iostream>
#include "ClueElements.hpp"

class ClueCard{
    public:
        ClueCard();
        int print();

        static const int CARDLEN   = 21;
        static const int CARDWIDTH = 6;

        // enum for the possible element-player states
        // and c-style string descriptors for them
        enum CCSTATE{
            NOTHING,
            POSSIBLE,
            SURE
        };
        const char* const strCCSTATE[3] = {
            "Nothing",
            "Possible",
            "Sure",
        };


        // playerData: player's color + 
        //             a column of data on what elements they may have
        using col_t = std::vector<CCSTATE>;

        class playerData{
            public:
                // Enum for the player IDs
                enum CCPLAYER{
                    RED,
                    GREEN,
                    YELLOW,
                    PURPLE,
                    BLUE,
                    WHITE
                };
            private:
                // c-style character string names
                const char* const strCCPLAYER[CARDWIDTH]{
                    "Red",
                    "Green",
                    "Yellow",
                    "Purple",
                    "Blue",
                    "White"
                };
            public:
                playerData();
                bool setPlayer(CCPLAYER player);
                col_t column;
                CCPLAYER player;
                const char* getPlayerName();
                CCSTATE& operator[](int);
        };

        playerData& operator[](int);


        using card_t = std::vector<playerData>;
        // the card data can be accessed with [column][row], aka [player][element]
        card_t card; // This will be CARDWIDTH # of columns
};

#endif