#include "Magazine.h"

Magazine::Magazine(
        const std::string& issn,
        const std::string& title,
        const std::string& publisher,
        unsigned releaseYear
    )
    : Publication(title, publisher, releaseYear)
    , m_issn{issn}
{}

const std::string Magazine::getIdentification() const {
    return m_issn;
}
