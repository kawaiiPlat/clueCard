#include "ClueGame.hpp"


ClueGame::ClueGame(){
    // the base class' argumentless constructor is called automatically
    roundCounter = 10;
};

void ClueGame::print(){
    std::cout << CLEAR_SCREEN;
    std::cout << MOVE_TO_TOP_LEFT;
    ClueCard::print();
    std::cout << MOVE_TO_MESSAGE_POS "Round #" << roundCounter << "\n";
    std::cout << "\n";
}
void ClueGame::update(ClueCard::playerData::CCPLAYER player, std::vector<ClueElement::CEIDS> guess){
    roundCounter += 1;
    updateCard(player, guess);
}
bool ClueGame::isGameOver(){
    return gameOver;
}