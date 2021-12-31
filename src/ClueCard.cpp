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
ClueCard::playerData::CCPLAYER ClueCard::playerData::getPlayer(){
    return player;
}

ClueCard::ClueCard(){
    // initalize the data for each player
    card = card_t(ClueCard::CARDWIDTH);

    //set the column player "name"
    card[0].setPlayer( ClueCard::playerData::CCPLAYER::RED      );
    card[1].setPlayer( ClueCard::playerData::CCPLAYER::GREEN    );
    card[2].setPlayer( ClueCard::playerData::CCPLAYER::YELLOW   );
    card[3].setPlayer( ClueCard::playerData::CCPLAYER::PURPLE   );
    card[4].setPlayer( ClueCard::playerData::CCPLAYER::BLUE     );
    card[5].setPlayer( ClueCard::playerData::CCPLAYER::WHITE    );
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

    std::cout   << "The card is currently:\n";

    //print the top banner
    std::cout   << std::setw(31)
                << std::setfill('-')
                << "\n"
                << std::setw(17)
                << std::setfill(' ')
                << " | ";
    
    for(playerData pd : card){
        char c = *pd.getPlayerName();
        ClueCard::playerData::CCPLAYER player = pd.getPlayer();
        switch(player){
            case ClueCard::playerData::CCPLAYER::RED:
                std::cout << COLOR_RED;
                break;

            case ClueCard::playerData::CCPLAYER::GREEN:
                std::cout << COLOR_GREEN;
                break;

            case ClueCard::playerData::CCPLAYER::YELLOW:
                std::cout << COLOR_YELLOW;
                break;

            case ClueCard::playerData::CCPLAYER::PURPLE:
                std::cout << COLOR_MAGENTA;
                break;

            case ClueCard::playerData::CCPLAYER::BLUE:
                std::cout << COLOR_BLUE;
                break;

            case ClueCard::playerData::CCPLAYER::WHITE:
                std::cout << COLOR_WHITE;
                break;
        }
        std::cout << c << " ";
    }
    std::cout << COLOR_NC "|\n";

    for(int i = 0; i < CARDLEN; i++){
        //this is the "player" index

        //print the titles for each of the rows
        std::cout   << std::setw(0)
                    << std::setfill(' ')
                    << std::right
                    << std::setw(14)
                    << card[0][i].getStrElementName()
                    << " | ";
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

            // print the state out
            std::cout << card[j][i].getElementState() << " ";
                
            //clear the color
            std::cout << COLOR_NC;
        }
        // print the end of line bar
        std::cout << "|\n";
    }
    // print the bottom bar
    std::cout   << std::setw(31)
                << std::setfill('-')
                << "\n";
    return 0;
}


// the operator[] overrides that allow syntatically simple access
ClueCard::playerData& ClueCard::operator[](int index){
    return card[index];
}
ClueElement::Element& ClueCard::playerData::operator[](int index){
    return column[index];
}