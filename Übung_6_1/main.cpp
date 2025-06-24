#include <iostream>
#include <cstdint>

void func(uint64_t param) {
    std::cout << "counter: " << param << " Stack-Adresse: " << &param  << std::endl;

    // rekursiver Aufrug
    func(param + 1);
}

void func2(uint64_t param) {
    char wasteOfSpace[1042];
    wasteOfSpace[0] = static_cast<char>(param); // Use the array
    std::cout << "counter: " << param << " Stack-Adresse: " << &param  << std::endl;

    // rekursiver Aufrug
    func2(param + 1);
}

int main() {
    //func(0);
    func2(0);
}

