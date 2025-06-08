#pragma once
#include <string>

class GameCharacter {
    private:
        std::string m_name;
        int m_health;
        GameCharacter* m_buddy;

    public:
        // Constructor
        GameCharacter();

        // Constructor with name and health
        GameCharacter(const std::string& name, int health);

        // Constructor with name health and &&buddy
        GameCharacter(const std::string& name, int health, GameCharacter&& buddy);

        //Setter Methoden
        void setBuddy(GameCharacter&& buddy);

        // Rule of Five -> Destructor, Copy-Constructor, 
        //Copy-Assignment-Constructor, Move Constructor, Move-Assignment-Constructor

        // Destructor
        ~GameCharacter();

        // Copy Constructor
        GameCharacter(const GameCharacter& other);

        // Copy Assignment Constructor
        GameCharacter& operator= (const GameCharacter& other);

        // Move Constructor
        GameCharacter(GameCharacter&&);

        // Move Assignment Constructor
        GameCharacter& operator= (GameCharacter&&);

        // print Character
        void print() const;
};