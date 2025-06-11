#include "Magazine.h"
#include "Book.h"
#include <string>
#include <iostream>

// to use ""s to convert literal to string
using namespace std::string_literals;

int main() {
    Book b("987-543-210"s,
        Book::Genre::fiction, 
        "Book Title"s, 
        "Book Publisher"s, 
        2022);
    
    Magazine m("987-543-21"s,
        "Magazine Title"s, 
        "Magazine Publisher"s, 
        2022);
    
    std::cout << "In the library: " << b << " " << m << std::endl;

    std::cout << b.getTitle() << " is " << (b.getIsBorrowed() ? "borrowed" : "not borrowed") << std::endl;
    std::cout << m.getTitle() << " is " << (m.getIsBorrowed() ? "borrowed" : "not borrowed") << std::endl;

    b.borrow();

    std::cout << b.getTitle() << " is " << (b.getIsBorrowed() ? "borrowed" : "not borrowed") << std::endl;
    std::cout << m.getTitle() << " is " << (m.getIsBorrowed() ? "borrowed" : "not borrowed") << std::endl;

    m.borrow();
    b.giveBack();

    std::cout << b.getTitle() << " is " << (b.getIsBorrowed() ? "borrowed" : "not borrowed") << std::endl;
    std::cout << m.getTitle() << " is " << (m.getIsBorrowed() ? "borrowed" : "not borrowed") << std::endl;

    std::cout << "The publications are " << (b==m ? "" : "not ") << "the same" << std::endl;
    std::cout << "The publications are " << (b!=m ? "" : "not ") << "different" << std::endl;
}