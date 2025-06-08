#include "GameCharacter.h"

int main() {
    GameCharacter c1;
    GameCharacter c2;
    GameCharacter c3 = c1;
    GameCharacter c4 = std::move(c2);

    GameCharacter joker("The Joker", 69, GameCharacter("The Riddler", 20));
    GameCharacter robin("Robin", 75);
    GameCharacter batman("Batman", 100, std::move(robin));

    joker.setBuddy(std::move(c1));

    joker.print();
    batman.print();

    joker.setBuddy(std::move(batman));
    joker.print();
}