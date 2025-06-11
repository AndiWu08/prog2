#include "Book.h"

Book::Book(
        const std::string& isbn,
        Genre genre,
        const std::string& title,
        const std::string& publisher,
        unsigned releaseYear
    ) 
    : Publication(title, publisher, releaseYear)
    , m_isbn{isbn}
    , m_genre{genre}
{}

Book::Genre Book::getGenre() {
    return m_genre;
}

const std::string Book::getIdentification() const {
    return m_isbn;
}