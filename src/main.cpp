#include <iostream>
#include "ClueGame.hpp"
//#include "ClueCard.hpp"
//#include "ClueElement.hpp"

int main(int argc, char* argv[]){

    ClueGame game;
    game.print();
    std::cin.get();

    game.update();
    game.update();
    game.update();


}