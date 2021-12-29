#ifndef CLUECARD_H
#define CLUECARD_H

#include <vector>
#include <iostream>
int clueCardTest();


class ClueCard{
    public:
        ClueCard();
        int print();

        static const int CARDLEN   = 21;
        static const int CARDWIDTH = 6;

        enum CCSTATE{
            NOTHING,
            POSSIBLE,
            SURE
        };

        enum CCCHAR{
            RED,
            GREEN,
            YELLOW,
            PURPLE,
            BLUE,
            WHITE
        };

        enum CCWEAPON{
            CANDLESTICK,
            KNIFE,
            PIPE,
            REVOLVER,
            ROPE,
            WRENCH
        };

        enum CCROOM{
            Kitchen,
            Ballroom,
            Conservatory,
            DiningRoom,
            BilliardRoom,
            Library,
            Study,
            Hall,
            Lounge
        };


        // playerData: player's color + 
        //             a column of data on what elements they may have
        using col_t = std::vector<CCSTATE>;

        class playerData{
            public:
                playerData();
                bool setPlayer(CCCHAR player);
                col_t column;
                CCCHAR player;
                CCSTATE& operator[](int);
        };

        playerData& operator[](int);


        using card_t = std::vector<playerData>;
        // the card data can be accessed with [column][row], aka [player][element]
        card_t card; // This will be CARDWIDTH # of columns
};

#endif