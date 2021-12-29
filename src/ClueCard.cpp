#include "./ClueCard.hpp"

ClueCard::playerData::playerData(){
    column = col_t(ClueCard::CARDLEN, ClueCard::CCSTATE::NOTHING);
}
bool ClueCard::playerData::setPlayer(CCCHAR player){
    this->player = player;
    return true;
}

ClueCard::ClueCard(){
    card = card_t(ClueCard::CARDWIDTH); // the Columns are 

    //set the column players
}

int ClueCard::print(){
    std::cout << "The card is currently:\n" << "------------\n";
    for(int i = 0; i < CARDLEN; i++){
        //this is the "down" index
        for(int j = 0; j < CARDWIDTH; j++){
            // this is the "across" index
            std::cout << card[j][i] << " ";
        }
        std::cout << "\n";
    }
    std::cout << "------------\n";
    return 0;
}

ClueCard::playerData &ClueCard::operator[](int index){

    return card[index];
}
ClueCard::CCSTATE &ClueCard::playerData::operator[](int index){
    return column[index];
}