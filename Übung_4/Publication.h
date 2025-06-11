#pragma once
#include <iostream>
#include <string>

class Publication {
    protected:
        std::string m_title;
        std::string m_publisher;
        unsigned m_releaseYear;
        bool m_isBorrowed;
    
    public:
        // Konstruktor
        explicit Publication(const std::string& title,
                    const std::string& publisher,
                    unsigned releaseYear);

        // Getter Methoden
        const std::string getTitle() const;
        const std::string getPublisher() const;
        unsigned getReleaseYear() const;
        bool getIsBorrowed() const;

        // Methoden nach UML / Aufgabenstellung
        void borrow();
        void giveBack();
        virtual const std::string getIdentification() const = 0;
};

// Vergleicht Informationen auf Gleichheit (anhand Information)
// returns true if publications are the same 
bool operator==(const Publication& pub1, const Publication& pub2); 

// Vergleicht Informationen auf Ungleichheit (anhand Information)
// returns true if publications are different 
bool operator!=(const Publication& pub1, const Publication& pub2); 

std::ostream& operator<<(std::ostream& os,const Publication& pub);