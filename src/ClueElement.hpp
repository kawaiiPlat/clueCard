#ifndef CLUEELEMENTS_H
#define CLUEELEMENTS_H

namespace ClueElement{

        // enum for the possible element-player states
        // and c-style string descriptors for them
        #define NUM_CE_STATES 4
        enum CESTATE{
            NOTHING,
            DOESNTHAVE,
            POSSIBLE,
            SURE
        };
        const char* const strCESTATE[NUM_CE_STATES] = {
            "Nothing",
            "Doesn't Have",
            "Possible",
            "Sure"
        };

        // enum for all the clue elements
        // and c-style string descriptors for them
        #define NUM_CE_ELEMENTS 21
        enum CEIDS{
            RED,
            GREEN,
            YELLOW,
            PURPLE,
            CYAN,
            WHITE,
            CANDLESTICK,
            KNIFE,
            PIPE,
            REVOLVER,
            ROPE,
            WRENCH,
            KITCHEN,
            BALLROOM,
            CONSERVATORY,
            DININGROOM,
            BILLIARDROOM,
            LIBRARY,
            STUDY,
            HALL,
            LOUNGE
        };

        const int NUM_CE_CHARACTERS = 6;
        const int IDX_CE_CHARACTERS = 0;

        const int NUM_CE_WEAPONS = 6;
        const int IDX_CE_WEAPONS = 6;

        const int NUM_CE_ROOMS = 9;
        const int IDX_CE_ROOMS = 12;

        const char* const strCEIDS[NUM_CE_ELEMENTS]{
            "Red",
            "Green",
            "Yellow",
            "Purple",
            "Cyan",
            "White",
            "Candlestick",
            "Knife",
            "Pipe",
            "Revolver",
            "Rope",
            "Wrench",
            "Kitchen",
            "Ballroom",
            "Conservatory",
            "Dining Room",
            "Billiard Room",
            "Library",
            "Study",
            "Hall",
            "Lounge"
        };

    class Element{
        public:
            const char* getStrElementName();
            const char* getStrElementState();
            ClueElement::CEIDS getElementID();
            ClueElement::CESTATE getElementState();
            int getNumTimesWasPossible();

            void updateState(ClueElement::CESTATE state);

            Element();
            void init(ClueElement::CEIDS ID);

        private:
            const char* name;
            int numTimesWasPossible = 0;
            ClueElement::CESTATE STATE;
            ClueElement::CEIDS ID;
    };

}
#endif