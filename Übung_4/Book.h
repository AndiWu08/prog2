#pragma once
#include "Publication.h"

class Book : public Publication {
    public:
        enum Genre {
            fiction,
            nonfiction,
            periodical,
            biograpy,
            children
        };

        // construct Publication and construct Book
        explicit Book(
            const std::string& isbn,
            Genre genre,
            const std::string& title,
            const std::string& publisher,
            unsigned releaseYear
        );

        // returns ISBN of book
        const std::string getIdentification() const override;

        // returns genre of book
        Genre getGenre();

    protected:
        const std::string m_isbn;
        Genre m_genre;
};