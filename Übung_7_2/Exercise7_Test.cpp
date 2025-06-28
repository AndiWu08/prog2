#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <cstring>
#include <algorithm>

char* chResult(const char* ch, unsigned size) {
    std::cout << "-- character array --\n";
    //Größe ausgeben
    std::cout << "Grosse von character-array: " << size << "\t";

    // mit "Hello" vergleichen
    bool isEqual = size == 5 ? memcmp(ch, "Hello", 5) == 0 : false;
    std::cout << "Vergleich mit 'Hello': " << std::boolalpha << isEqual << "\t";

    // mit "Howdy" vergleichen - was kommt zuerst im Lexikon?
    auto compResult = memcmp(ch, "Howdy", std::min(size, 5u));
    if (compResult < 0)
    {
        std::cout << "kommt vor Howdy\n";
    }
    else if (compResult > 0)
    {
        std::cout << "kommt nach Howdy\n";
    }
    else    // compResult == 0
    {
        std::cout << "Beide sind gleich\n";
    }
    
    // in andere Variable kopieren
    char* newCh = new char[size];
    memcpy(newCh, ch, size);
    return newCh;
}

std::vector<char> vecResult(const std::vector<char>& vec) {
    std::cout << "\n-- vector --\n";
    // Größe ausgeben
    std::cout << "grosse vector: " << vec.size() << "\t";

    // Vergleich mit "Hello"
    std::vector hello{{'H', 'e', 'l', 'l', 'o'}};
    std::cout << "Vergleich mit 'Hello': " << std::boolalpha << (hello == vec) << "\t";

    // Alphabet "Howdy"
    std::vector howdy{{'H', 'o', 'w', 'd', 'y'}};
    auto compResult = vec <=> howdy;

    if (compResult < 0)
    {
        std::cout << "kommt vor Howdy\n";
    }
    else if (compResult > 0)
    {
        std::cout << "kommt nach Howdy\n";
    }
    else    // compResult == 0
    {
        std::cout << "Beide sind gleich\n";
    }
    

    // Kopie zurückgeben
    std:: vector copy(vec);
    return copy;
}

std::string strResult(const std::string& str) {
    std::cout << "\n-- string --\n";
    // Größe ausgeben
    std::cout << "grosse vector: " << str.length() << "\t";

    // Vergleich mit "Hello"
    std::cout << "Vergleich mit 'Hello': " << std::boolalpha << (str == "Hello") << "\t";

    // Alphabet "Howdy"
    auto compResult = str <=> "Howdy";

    if (compResult < 0)
    {
        std::cout << "kommt vor Howdy\n";
    }
    else if (compResult > 0)
    {
        std::cout << "kommt nach Howdy\n";
    }
    else    // compResult == 0
    {
        std::cout << "Beide sind gleich\n";
    }

    // Kopie zurückgeben
    auto copy = str;
    return copy;
}

std::list<char> listResult(const std::list<char>& l) {
    std::cout << "\n-- list --\n";
    // Größe ausgeben
    std::cout << "grosse vector: " << l.size() << "\t";

    // Vergleich mit "Hello"
    std::list hello{{'H', 'e', 'l', 'l', 'o'}};
    std::cout << "Vergleich mit 'Hello': " << std::boolalpha << (l == hello) << "\t";

    // Alphabet "Howdy"
    std::list howdy{{'H', 'o', 'w', 'd', 'y'}};
    auto compResult = l <=> howdy;

    if (compResult < 0)
    {
        std::cout << "kommt vor Howdy\n";
    }
    else if (compResult > 0)
    {
        std::cout << "kommt nach Howdy\n";
    }
    else    // compResult == 0
    {
        std::cout << "Beide sind gleich\n";
    }

    // Kopie zurückgeben
    std::list copy(l);
    return copy;
}

void iB(int* i, unsigned size) {
    std::cout << "\n-- integer array --\n";
    //Größe ausgeben
    std::cout << "Grosse von integer array: " << size << "\n";
    
    // in andere Variable umgekehrt kopieren
    auto copy = new int[size];
    // ursprüngliches array umgekehrt iterieren und in neues Element einfügen
    for (int origin = size-1, idxCopy = 0; idxCopy < size; --origin, ++idxCopy)
    {
        copy[idxCopy] = i[origin];
    }
    std::cout << "neues array: ";
    for (int j = 0; j < size; j++)
    {
        std::cout << copy[j] << " ";
    }
    std::cout << "\n";
    
    int originalIdx = 0;
    int copyIdx = 0;   

    for (int k = 0; k < size; k++)
    {
        if (i[k] == 4)
        {
            originalIdx = k;
        }
        if (copy[k] == 4)
        {
            copyIdx = k;
        }
    }
    std::cout << "alte Position von 4: " << originalIdx << " neue Position 4: " << copyIdx;   
    delete[] copy; 
}

void vecB(const std::vector<int>& vec) {
    std::cout << "\n-- integer vector --\n";
    std::cout << "grosse vector: " << vec.size() << "\n";

    // vector kopieren und reihenfolge umdrehen
    auto copy(vec);
    std::reverse(copy.begin(), copy.end());
    
    std::cout << "kopie:" << "\n";
    for (const auto& val : copy)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // position von 4 ausgeben
    std::cout << "alte Position von 4: " << std::find(vec.begin(), vec.end(), 4) - vec.begin() 
    << " neue Position 4: " << std::find(copy.begin(), copy.end(), 4) - copy.begin();
}

void vecB(const std::list<int>& l) {
    std::cout << "\n-- integer list --\n";
    std::cout << "grosse vector: " << l.size() << "\n";

    // vector kopieren und reihenfolge umdrehen
    auto copy(l);
    std::reverse(copy.begin(), copy.end());
    
    std::cout << "kopie:" << "\n";
    for (const auto& val : copy)
    {
        std::cout << val << " ";
    }
    std::cout << "\n";

    // position von 4 ausgeben
    auto it = std::find(l.begin(), l.end(), 4);
    std::cout << "alte Position von 4: ";
    if (it != l.end())
        std::cout << std::distance(l.begin(), it);
    else
        std::cout << "nicht gefunden";
    
    auto itCopy = std::find(copy.begin(), copy.end(), 4);
    std::cout << " alte Position von 4: ";
    if (itCopy != copy.end())
        std::cout << std::distance(copy.begin(), itCopy);
    else
        std::cout << "nicht gefunden";
}

void strB(const std::string& str) {
    std::cout << "\n-- string --\n";
    std::cout << "grosse string: " << str.size() << "\n";

    // umgedrehte Kopie
    std::string copy = str;
    std::reverse(copy.begin(), copy.end());
    std::cout << "Kopie: " << copy << "\n";

    // position von 4 ausgeben
    auto it = std::find(str.begin(), str.end(), '4');
    std::cout << "alte Position von 4: ";
    if (it != str.end())
        std::cout << std::distance(str.begin(), it);
    else
        std::cout << "nicht gefunden";
    
    auto itCopy = std::find(copy.begin(), copy.end(), '4');
    std::cout << " alte Position von 4: ";
    if (itCopy != copy.end())
        std::cout << std::distance(copy.begin(), itCopy);
    else
        std::cout << "nicht gefunden";
}

int main() {
    // a)
    char ch[] = "Hello";
    std::vector<char> v{'H', 'e', 'l', 'l', 'o'};
    std::string str{"Hello"};
    std::list<char> l{'H', 'e', 'l', 'l', 'o'};


    auto charResult = chResult(ch, 5);
    delete[] charResult;

    auto vResult = vecResult(v);

    auto sResult = strResult(str);

    auto lResult = listResult(l);

    // b)
    int i[] = {1,2,3,4,5};
    std::vector<int> v2 = {1,2,3,4,5};
    std::list<int> l2 = {1,2,3,4,5};
    std::string s2 = "12345";

    iB(i, 5);
    vecB(v2);
    strB(s2);
}