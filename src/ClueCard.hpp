#ifndef CLUECARD_H
#define CLUECARD_H

#include <vector>
#include <iostream>
int clueCardTest();


class ClueCard{
    public:
        ClueCard();
        int print();

        //ClueCard const& operator[](unsigned int i);

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

    private:
        // columns: outer, players
        // rows:    inner, elements
        
        typedef std::vector<CCSTATE> row_t;

        class column{
            public:
                column();
                void setPlayer(CCCHAR player);
                row_t row;
                CCCHAR player;
        };

        typedef column col_t;

        typedef std::vector<column> card_t;
        card_t card; // This will be CARDWIDTH # of columns

};

#endif