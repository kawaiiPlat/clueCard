#ifndef CLUEELEMENTS_H
#define CLUEELEMENTS_H

#define NUM_CC_ELEMENTS 21
enum CCELEMENTID{
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
const char* const strCCELEMENTID[NUM_CC_ELEMENTS]{
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

/*
class Element{
    public:
        virtual char* getElementName();
            
    protected:
        char* name;
        CCELEMENTID ID;
};

class ccPlayer: public Element{
    ccPlayer(){
    }
    ccPlayer(CCELEMENTID id){
        this->ID = id;
        this->name = &strCCELEMENTID[ID]; 
    }

    char* getElementName(){
        return name;
    }
};
*/

#endif