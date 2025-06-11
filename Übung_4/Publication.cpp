#include "Publication.h"

Publication::Publication(const std::string& title, const std::string& publisher, unsigned releaseYear)
    : m_title{title}
    , m_publisher{publisher}
    , m_releaseYear{releaseYear}
    , m_isBorrowed{false}
{}

const std::string Publication::getTitle() const {
    return m_title;
}

const std::string Publication::getPublisher() const {
    return m_publisher;
}

unsigned Publication::getReleaseYear() const {
    return m_releaseYear;
}

bool Publication::getIsBorrowed() const {
    return m_isBorrowed;
}

void Publication::borrow() {
    m_isBorrowed = true;
}

void Publication::giveBack() {
    m_isBorrowed = false;
}

bool operator==(const Publication& pub1, const Publication& pub2) {
    return pub1.getIdentification() == pub2.getIdentification();
}

bool operator!=(const Publication& pub1, const Publication& pub2) {
    return pub1.getIdentification() != pub2.getIdentification();
}

std::ostream& operator<<(std::ostream& os,const Publication& pub) {
    os << "Title: " << pub.getTitle() << 
        ", Publisher: " << pub.getPublisher() << 
        ", release Year: " << pub.getReleaseYear();
    return os;
}
