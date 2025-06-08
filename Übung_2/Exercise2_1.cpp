#include "BankAccount.h"

int main() {
	// Erstellen von Bankkonten
	BankAccount account1("Alice", 500.0, 1234);
	BankAccount account2("Bob", 1000.0, 5678);

	// Kontostände anzeigen
	std::cout << account1.getAccountHolder() << " has a balance of "
		<< account1.getBalance() << " EUR.\n";
	std::cout << account2.getAccountHolder() << " has a balance of "
		<< account2.getBalance() << " EUR.\n";

	double totalBalance{ calculateTotalBalance(account1, account2) };
	std::cout << "Total Balance: " << totalBalance << " EUR.\n";

	int code{ 0 };
	std::cout << "Enter secret code for " << account1.getAccountHolder() << ": ";
	std::cin >> code;

	if (checkSecretCode(account1, code))
		std::cout << "Secret Code correct!\n";
	else
		std::cout << "Secret Code wrong!\n";

	// Test der statischen Methode
	std::cout << "Total number of bank accounts: " << BankAccount::getAccountCount() << "\n";

	return 0;
}