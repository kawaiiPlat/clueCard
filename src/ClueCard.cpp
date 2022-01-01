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
const char* ClueCard::playerData::getPlayerName(CCPLAYER target){
    return ClueCard::playerData::strCCPLAYER[(int)target];
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
    card[4].setPlayer( ClueCard::playerData::CCPLAYER::CYAN     );
    card[5].setPlayer( ClueCard::playerData::CCPLAYER::WHITE    );
}

// updateCard should be called with playerWhoShowed == NONE to indicate no one showed (in this case the game is over)
void ClueCard::updateCard(ClueCard::playerData::CCPLAYER activePlayer, ClueCard::playerData::CCPLAYER playerWhoShowed, std::vector<ClueElement::CEIDS> whatWasSuggested){
    assert(whatWasSuggested.size() == 3); // there should always be 3 items
    if(playerWhoShowed >= CARDWIDTH){
        //invalid range, throw error
        throw std::out_of_range("updateCard: Recieved an impossible player index");
    }


    if(playerWhoShowed == ClueCard::playerData::CCPLAYER::NONE){
        // The player was No One, therefore the game is over
        // mark the whole row of each element as SURE
        for(int i = 0; i < CARDWIDTH; i++){
            for(ClueElement::CEIDS ID : whatWasSuggested){
                card[i][(int)ID].updateState(ClueElement::CESTATE::SURE);
            }
        }
    } else {
        // update the values to be possible
        for(int i = (int)activePlayer; i <= activePlayer + playerWhoShowed; i++){
            int idx = i % CARDWIDTH;
            for(ClueElement::CEIDS ID : whatWasSuggested){
                card[idx][(int)ID].updateState(ClueElement::CESTATE::POSSIBLE);
            }
        }
    }
    std::cout << "\n";

};


void ClueCard::print(ClueCard::playerData::CCPLAYER activePlayer){

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

            case ClueCard::playerData::CCPLAYER::CYAN:
                std::cout << COLOR_CYAN ;
                break;

            case ClueCard::playerData::CCPLAYER::WHITE:
                std::cout << COLOR_WHITE;
                break;
            case ClueCard::playerData::CCPLAYER::NONE:
                // the compiler requests that this be handled, and now it is
                break;
        }
        std::cout << c << COLOR_NC " ";
    }
    std::cout << "|\n";

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

            ClueElement::CESTATE elementState = card[j][i].getElementState();
            switch (elementState){
                case ClueElement::CESTATE::NOTHING:
                    std::cout << COLOR_BRIGHT_BLACK;
                    break;
                case ClueElement::CESTATE::DOESNTHAVE:
                    std::cout << COLOR_BLACK;
                    break;
                case ClueElement::CESTATE::POSSIBLE:
                    std::cout << COLOR_CYAN;
                    break;
                case ClueElement::CESTATE::SURE:
                    std::cout << COLOR_GREEN;
                    break;
            }
            
            // if the player who's column we're on is actively guessing, mark them with background color
            if(card[j].getPlayer() == activePlayer){
                std::cout << COLOR_MAGENTAB;
            }

            // print the state out
            // and clear the color
            std::cout << card[j][i].getNumTimesWasPossible() << COLOR_NC << " ";
        }
        // print the end of line bar
        std::cout << "|\n";
    }
    // print the bottom bar
    std::cout   << std::setw(31)
                << std::setfill('-')
                << "\n";
}


// the operator[] overrides that allow syntatically simple access
ClueCard::playerData& ClueCard::operator[](int index){
    return card[index];
}
ClueElement::Element& ClueCard::playerData::operator[](int index){
    return column[index];
}