#include <iostream>
#include "ClueCard.hpp"

int main(int argc, char* argv[]){
    std::cout << "Hello World" << "\n";

    ClueCard testing;

    testing.print();

    std::cout << testing.strCCSTATE[ClueCard::CCSTATE::NOTHING] << "\n";
}