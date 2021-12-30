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