#include <iostream>
#include "GameCharacter.h"

// standard Cosntructor
GameCharacter::GameCharacter()
    : m_name{"Unknown"},
    m_health{100},
    m_buddy{nullptr}
{
    std::cout << "Default Constructor called" << std::endl;
}

// Parameterized Constructor with name and health
GameCharacter::GameCharacter(const std::string& name, int health) 
    : m_name{name},
    m_health{health},
    m_buddy{nullptr}
{
    std::cout << "parameterized constructor called for " << m_name << std::endl;
}

// Parameterized Constructor with name, health and buddy
GameCharacter::GameCharacter(const std::string& name, int health, GameCharacter&& buddy)
    : m_name{name},
    m_health{health},
    m_buddy{new GameCharacter(std::move(buddy))}  // move existing Game Charecter inside this to make it buddy of this  
{
    std::cout << "Parameterized Constructor called for " << m_name << std::endl;
}

void GameCharacter::setBuddy(GameCharacter&& buddy) {
    // check if buddy is itself
    if (this != &buddy)
    {
        // delete old buddy if one exists
        delete m_buddy; 
        m_buddy = new GameCharacter(std::move(buddy));
        std::cout << "set new buddy " << buddy.m_name << " for " << m_name << std::endl;
    }
    
}

// Destructor
GameCharacter::~GameCharacter() {
    std::cout << "Destructor called for " << m_name << std::endl;
    delete m_buddy;
}

// Copy Constructor
GameCharacter::GameCharacter(const GameCharacter& other) 
    : m_name{other.m_name}, 
    m_health{other.m_health},
    m_buddy{nullptr}
{
    std::cout << "Copy Constructor called for " << m_name << std::endl;

    if (other.m_buddy)
    {
        m_buddy = new GameCharacter(*other.m_buddy);
    }
    
}

// Copy Assignment Constructor
GameCharacter& GameCharacter::operator=(const GameCharacter& other) {
    if (this != &other)
    {
        std::cout << "Copy Assignment Constructor called for " << other.m_name << std::endl;
        m_name = other.m_name;
        m_health = other.m_health;
        // delete old buddy
        delete m_buddy;

        // set buddy to buddy of other or nullptr if none exists
        m_buddy = other.m_buddy 
        ? new GameCharacter(*other.m_buddy)
        : nullptr;
    }
    return *this;
}

// Move Constructor
GameCharacter::GameCharacter(GameCharacter&& other) 
    : m_name{other.m_name}, 
    m_health{other.m_health},
    m_buddy{other.m_buddy}
{
    other.m_buddy = nullptr;
    std::cout << "Move Constructor called for " << m_name << std::endl;
}

GameCharacter& GameCharacter::operator=(GameCharacter&& other) {

    if (this != &other)
    {
        std::cout << "Move Assignment Constructor called for " << other.m_name << std::endl;
        delete m_buddy;
        m_name = other.m_name;
        m_health = other.m_health;
        m_buddy = other.m_buddy;

        other.m_buddy = nullptr;
    }
    return *this;
}

void GameCharacter::print() const {
    std::cout << "------" << std::endl;  
    std::cout << "Character Name: " << m_name << std::endl;
    std::cout << "Current Health: " << m_health << std::endl;

    if (m_buddy)
    {
        std::cout << "buddy of " << m_name << ": " << m_buddy->m_name << std::endl;
        m_buddy->print();
    } else {
        std::cout << "no buddy of " << m_name << " exists." << std::endl;
    }
}