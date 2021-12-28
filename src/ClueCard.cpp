#include "./ClueCard.hpp"

ClueCard::column::column(){
    row = row_t(ClueCard::CARDLEN, ClueCard::CCSTATE::NOTHING);
}
ClueCard::ClueCard(){
    card = card_t(ClueCard::CARDWIDTH); // the Columns are 

    //set the column players
}

int ClueCard::print(){
    std::cout << "The card is currently:\n" << "------------\n";
    for(col_t col : card){
        for(CCSTATE state : col.row){
            std::cout << state << " ";
        }
        std::cout << "\n";
    }
    std::cout << "------------\n";
    return 0;
}

/*
//Might need to be a row_t return type?
ClueCard const& ClueCard::operator[](unsigned int i) {
    ClueCard temp = *this;

    return *this;
}
*/