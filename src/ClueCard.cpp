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

// updateCard should be called with playerWhoShowed == -1 to indicate no one showed (in this case the game is over)
void ClueCard::updateCard(int playerWhoShowed, std::vector<ClueElement::CEIDS> whatWasSuggested){
    assert(whatWasSuggested.size() == 3); // there should always be 3 items
    if(playerWhoShowed < 0){
        // game is over, mark all three sure
    }
    if(playerWhoShowed >= CARDWIDTH){
        //invalid range, throw error
        throw std::out_of_range("updateCard: Recieved an impossible player index");
    }

    // std::cout << "The player is: " << playerWhoShowed << "\n";
    // std::cout << "What was suggested: ";
    // update the values to be possible
    for(ClueElement::CEIDS ID : whatWasSuggested){
        card[playerWhoShowed][(int)ID].updateState(ClueElement::CESTATE::POSSIBLE);
        // std::cout << ID << ": " << ClueElement::strCEIDS[ID] << ", state is ";
        // std::cout << card[playerWhoShowed][(int)ID].getStrElementState();
        // std::cout << " | ";
    }
    std::cout << "\n";

};

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

            int numPos = card[j][i].getNumTimesWasPossible();
            if(numPos == 0){
                std::cout << COLOR_BLACK;
            } else if(numPos == 1){
                std::cout << COLOR_YELLOW;
            } else if(numPos == 2){
                std::cout << COLOR_BLUE;
            } else if(numPos > 2){
                std::cout << COLOR_GREEN;
            }

            std::cout << card[j][i].getElementState() << " ";
                
            //clear the color
            std::cout << COLOR_NC;
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