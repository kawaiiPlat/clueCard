#include "./ClueCard.hpp"

ClueCard::playerData::playerData(){
    column = col_t(ClueCard::CARDLEN);
    //set the elements to their appropriate CEIDS
    for(int i = 0; i < NUM_CE_ELEMENTS; i++){
        // https://stackoverflow.com/questions/11452920/how-to-cast-int-to-enum-in-c
        ClueElement::CEIDS id = static_cast<ClueElement::CEIDS>(i);
        column[i].init( id );
    }
}
bool ClueCard::playerData::setPlayer(CCPLAYER player){
    this->player = player;
    return true;
}
const char* ClueCard::playerData::getPlayerName(){
    return ClueCard::playerData::strCCPLAYER[player];
}

ClueCard::ClueCard(){
    // initalize the data for each player
    card = card_t(ClueCard::CARDWIDTH);

    //set the column player "name"
    for(playerData pd : card){
        pd.setPlayer(ClueCard::playerData::CCPLAYER::RED);
    }
}

int ClueCard::print(){
    std::cout << "The players are: \n";
    for(playerData pd : card){
        std::cout << pd.getPlayerName() << ", ";
    }
    std::cout << "\n";

    std::cout << "The card is currently:\n" << "-----------\n";
    for(int i = 0; i < CARDLEN; i++){
        //this is the "player" index
        for(int j = 0; j < CARDWIDTH; j++){
            //this is the "element" index
            std::cout << card[j][i].getElementState() << " ";
        }
        std::cout << "\n";
    }
    std::cout << "-----------\n";
    return 0;
}


// the operator[] overrides that allow syntatically simple access
ClueCard::playerData& ClueCard::operator[](int index){
    return card[index];
}
ClueElement::Element& ClueCard::playerData::operator[](int index){
    return column[index];
}