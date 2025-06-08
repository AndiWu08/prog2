#include <iostream>

int main()
{
    std::cout << "how many pennies do you have? " << std::endl;
	unsigned pennies;
    std::cin >> pennies;

    std::cout << "how many nickels do you have? " << std::endl;
    unsigned nickels;
    std::cin >> nickels;

    std::cout << "how many dimes do you have? " << std::endl;
    unsigned dimes;
    std::cin >> dimes;

    std::cout << "how many quarters do you have? " << std::endl;
    unsigned quarters;
    std::cin >> quarters;

    std::cout << "how many half dollars do you have? " << std::endl;
    unsigned half_dollars;
    std::cin >> half_dollars;

    std::cout << "how many dollars do you have? " << std::endl;
    unsigned dollars;
    std::cin >> dollars;
    
    std::cout << "\nYou have: \n";
    std::cout << pennies << ((pennies == 1) ? " penny" : " pennies") << std::endl;
    std::cout << nickels << ((nickels == 1) ? " nickel" : " nickels") << std::endl;
    std::cout << dimes << ((dimes == 1) ? " dime" : " dimes") << std::endl;
    std::cout << quarters << ((quarters == 1) ? " quarter" : " quartes") << std::endl;
    std::cout << half_dollars << ((half_dollars == 1) ? " half dollar" : " half dollars") << std::endl;
    std::cout << dollars << ((dollars == 1) ? " dollar" : " dollars") << std::endl;

    double total_usd = pennies*0.01 + nickels*0.05 + dimes*0.1 + quarters*0.25 + half_dollars*0.5 + dollars;
    std::cout << "total USD: $" << total_usd << std::endl;

    std::cout << "Where do you want to travel?" << std::endl;
    std::cout << "0: Germany, 1: England, 2: South Africa, 3: Japan" << std::endl;
    int destination;
    std::cin >> destination;

    double dest_currency;
    switch (destination)
    {
    case 0: // Germany
        dest_currency = total_usd*1.14;
        std::cout << "in EUR: " << dest_currency << std::endl;
        break;
    case 1: // England
        dest_currency = total_usd*0.74;
        std::cout << "in Pound: " << dest_currency << std::endl;
        break;
    case 2: // Sout Africa
        dest_currency = total_usd*17.86;
        std::cout << "in EUR: " << dest_currency << std::endl;
        break;
    case 3: //Japan
        dest_currency = total_usd*142.9;
        std::cout << "in Yen: " << dest_currency << std::endl;
        break;

    default:
        break;
    }
}