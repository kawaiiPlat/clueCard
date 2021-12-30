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
            BLUE,
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
        const char* const strCEIDS[NUM_CE_ELEMENTS]{
            "Red",
            "Green",
            "Yellow",
            "Purple",
            "Blue",
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