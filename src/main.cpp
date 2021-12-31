#include <iostream>
#include "ClueCard.hpp"
#include "ClueElement.hpp"

int main(int argc, char* argv[]){
    std::cout << "Hello World" << "\n";

    ClueCard testing;

    testing.print();

    std::vector<ClueElement::CEIDS> guess;
    guess.push_back(ClueElement::CEIDS::DININGROOM);
    guess.push_back(ClueElement::CEIDS::CANDLESTICK);
    guess.push_back(ClueElement::CEIDS::RED);
    ClueCard::playerData::CCPLAYER player = ClueCard::playerData::CCPLAYER::RED;
    testing.updateCard(player, guess);
    testing.updateCard(player, guess);
    testing.updateCard(player, guess);

    testing.print();
}