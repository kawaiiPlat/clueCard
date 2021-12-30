#include "./ClueCard.hpp"

ClueCard::playerData::playerData(){
    column = col_t(ClueCard::CARDLEN, ClueCard::CCSTATE::NOTHING);
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

    std::cout << "The card is currently:\n" << "------------\n";
    for(int i = 0; i < CARDLEN; i++){
        //this is the "player" index
        for(int j = 0; j < CARDWIDTH; j++){
            //this is the "element" index
            std::cout << card[j][i] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "------------\n";
    return 0;
}


// the operator[] overrides that allow syntatically simple access
ClueCard::playerData &ClueCard::operator[](int index){
    return card[index];
}
ClueCard::CCSTATE &ClueCard::playerData::operator[](int index){
    return column[index];
}