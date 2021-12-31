#include <iostream>
#include "ClueGame.hpp"
//#include "ClueCard.hpp"
//#include "ClueElement.hpp"

int main(int argc, char* argv[]){

    std::vector<ClueElement::CEIDS> guess;
    guess.push_back(ClueElement::CEIDS::DININGROOM);
    guess.push_back(ClueElement::CEIDS::CANDLESTICK);
    guess.push_back(ClueElement::CEIDS::RED);
    ClueCard::playerData::CCPLAYER player = ClueCard::playerData::CCPLAYER::RED;

    ClueGame game;
    game.print();
    std::cin.get();
    game.updateCard(player, guess);
    game.updateCard(player, guess);
    game.updateCard(player, guess);
    game.print();

}