#pragma once
#include "Publication.h"

class Magazine : public Publication {
    public:
        // construct Publication and construct Book
        explicit Magazine(
            const std::string& issn,
            const std::string& title,
            const std::string& publisher,
            unsigned releaseYear
        );

        const std::string getIdentification() const override;
    
    protected:
        std::string m_issn;
};