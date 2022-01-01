#include "ClueGame.hpp"


ClueGame::ClueGame(){
    // the base class' argumentless constructor is called automatically
};

void ClueGame::print(){
    std::cout << CLEAR_SCREEN;
    std::cout << MOVE_TO_TOP_LEFT;
    ClueCard::print();
    std::cout << MOVE_TO_MESSAGE_POS "Round #" << roundCounter << "\n";
    std::cout << "\n";
}

void ClueGame::printGetElementMessage(int START_IDX, int NUM_OF_TYPE, std::string message){
    std::cout << message << "\n";
    for(int i = 0; i < NUM_OF_TYPE; i++){
        std::cout << i << ": " << ClueElement::strCEIDS[START_IDX+i];
        // dont print the bar for the last option
        if(i-1 != NUM_OF_TYPE){
            std::cout << " | ";
        }
    }
    std::cout << "\n";
}
ClueElement::CEIDS ClueGame::getElement(int START_IDX, int NUM_OF_TYPE, std::string message){

    print();
    printGetElementMessage(START_IDX, NUM_OF_TYPE, message);
    bool gettingInput = true;
    int result;

    // loop until good input
    while(gettingInput){
        std::string temp;
        getline(std::cin, temp);
        try{
            result = std::stoi(temp);

            if(result < NUM_OF_TYPE && result >= 0){
                gettingInput = false;
            } else {
                throw std::out_of_range("bad val");
            }

        } catch (std::logic_error& e){
            print();
            printGetElementMessage(START_IDX, NUM_OF_TYPE, message);
            std::cout << "Please choose a number between 0 and " << NUM_OF_TYPE - 1 << "\n";
        }
    }
    return static_cast<ClueElement::CEIDS>(START_IDX+result);
}
void ClueGame::update(){
    roundCounter += 1;

    std::vector<ClueElement::CEIDS> guess;
    guess.push_back(getElement(ClueElement::IDX_CE_ROOMS      ,ClueElement::NUM_CE_ROOMS       , "Select A Room: ")     );
    guess.push_back(getElement(ClueElement::IDX_CE_WEAPONS    ,ClueElement::NUM_CE_WEAPONS     , "Select A Weapon: ")   );
    guess.push_back(getElement(ClueElement::IDX_CE_CHARACTERS ,ClueElement::NUM_CE_CHARACTERS  , "Select A Character: "));

    updateCard(currentPlayer, guess);
    //todo update currentPlayer
    ClueGame::print();

    std::cout << MOVE_TO_MESSAGE_POS << "Press Enter to advance, or 'q' and Enter to end the game:\n";
    std::string line;
    getline(std::cin, line);

    if(line == "q"){
        gameOver = true;
    }

}
bool ClueGame::isGameOver(){
    return gameOver;
}

void ClueGame::printPickPlayerMessage(){
    std::cout << "Pick a player:\n";
    for(int i = 0; i < CARDWIDTH; i++){
        std::cout << i << ": " << card[0].getPlayerName(static_cast<ClueCard::playerData::CCPLAYER>(i));
        if(i-1 != CARDWIDTH){
            std::cout << " | ";
        }
    }
    std::cout << "\n";
}
void ClueGame::pickPlayer(){
    printPickPlayerMessage();
    bool gettingInput = true;
    int result;

    // loop until good input
    while(gettingInput){
        std::string temp;
        getline(std::cin, temp);
        try{
            result = std::stoi(temp);

            if(result < CARDWIDTH && result >= 0){
                gettingInput = false;
                ourPlayer = static_cast<ClueCard::playerData::CCPLAYER>(result);
            } else {
                throw std::out_of_range("bad val");
            }

        } catch (std::logic_error& e){
            print();
            printPickPlayerMessage();
            std::cout << "Please choose a number between 0 and " << CARDWIDTH - 1 << "\n";
        }
    }
    return;
}
// this is provided as an alternative to calling ClueGame::update()
// and checking ClueGame::isGameOver()
// to allow a game to be run with one line
void ClueGame::start(){
    
    pickPlayer();
    while(!gameOver){
        update();
    }
    std::cout << "Thanks for playing\n";
}