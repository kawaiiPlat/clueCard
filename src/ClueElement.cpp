#include "ClueElement.hpp"

ClueElement::Element::Element(){};

void ClueElement::Element::init(ClueElement::CEIDS ID){
    this->ID = ID;
    this->name = ClueElement::strCEIDS[ID];
    this->STATE = ClueElement::CESTATE::NOTHING;
};

const char* ClueElement::Element::getStrElementName(){ 
    return ClueElement::strCEIDS[ID];
};
const char* ClueElement::Element::getStrElementState(){ 
    return ClueElement::strCESTATE[STATE];
};
ClueElement::CEIDS ClueElement::Element::getElementID(){ 
    return ID;
};
ClueElement::CESTATE ClueElement::Element::getElementState(){ 
    return STATE;
};
int ClueElement::Element::getNumTimesWasPossible(){
    return numTimesWasPossible;
}

void ClueElement::Element::updateState(ClueElement::CESTATE state){
    if(this->STATE == ClueElement::CESTATE::DOESNTHAVE){
        return;
    }
    this->STATE = state;
    switch(state){
        case ClueElement::CESTATE::NOTHING:
            break;
        case ClueElement::CESTATE::DOESNTHAVE:
            break;
        case ClueElement::CESTATE::POSSIBLE:
            numTimesWasPossible++;
            break;
        case ClueElement::CESTATE::SURE:
            break;
    }
};