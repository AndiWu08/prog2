#pragma once
#include <string>
#include "Address.h"
#include "Person.h"

// Vorwärtsdeklaration für Fakultät
class Faculty;

class University {
    private:
        std::string m_name;
        Address m_address;
        Person* m_president;
        Faculty* m_faculties[5];

    public:
        // Konstruktor
        // Addresse wird verschoben, 
        //faculties als leeres Array initialisiert,
        // pointer auf president (muss existieren Multiplizität 1)
        University(std::string name, Address address, Person* president);

        // getter methods
        const std::string& getName() const;
        const Address& getAddress() const;
        Person* getPresident() const;
        std::size_t getFacultyCount() const;
        Faculty* getFaculty(std::size_t index) const;

        // add a Faculty
        void addFaculty(Faculty* faculty);

        // remove a Faculty
        void removeFaculty(Faculty* faculty);
};