#include <string>
#include "University.h"

University::University(std::string name, Address address, Person* president)
    : m_name{std::move(name)}
    , m_address{std::move(address)}
    , m_president{president}
    , m_faculties{} // als leeres Array initialisieren
{}

const std::string& University::getName() const {
    return m_name;
}

const Address& University::getAddress() const {
    return m_address;
}

Person* University::getPresident() const {
    return m_president;
}

std::size_t University::getFacultyCount() const {
    return sizeof(m_faculties) / sizeof(m_faculties[0]);
}

Faculty* University::getFaculty(std::size_t index) const {
    return m_faculties[index];
}

// add a Faculty
void University::addFaculty(Faculty* faculty) {
    // check if there is still room in the array
    for (size_t i = 0; i < getFacultyCount(); i++)
    {
        if (m_faculties[i] == nullptr)
        {
            m_faculties[i] = faculty;
            break;
        }
    }
}

// remove a Faculty
void University::removeFaculty(Faculty* faculty) {
    for (size_t i = 0; i < getFacultyCount(); i++)
    {
        if (m_faculties[i] == faculty)
        {
            m_faculties[i] == nullptr;
            break;
        }
    }
}

