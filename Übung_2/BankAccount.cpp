#include "BankAccount.h"

// statische Variable BankAccount Zähler
int BankAccount::s_accountCount = {0};

// Konstruktor mit Parametern
BankAccount::BankAccount(const std::string accountHolder, double initialBalance, unsigned secretCode) 
    : m_accountHolder(accountHolder),
    m_accountBalance(initialBalance),
    m_secretCode(secretCode)
{    
    if (m_accountBalance < 0)
    {
        m_accountBalance =0;
        std::cout << "initial balance can't be negative" << std::endl;
    }
    ++s_accountCount;
}

// Destruktor
BankAccount::~BankAccount() {
    --s_accountCount;
}

// Getter Methoden
std::string  BankAccount::getAccountHolder()  const {
    return m_accountHolder;
}

double  BankAccount::getBalance()  const {
    return m_accountBalance;
}

// deposit money
void BankAccount::deposit(double amount) {
    if (amount > 0)
    {
        m_accountBalance += amount;
    }
    else
    {
        std::cout << "Einzahlung muss positiv sein" << std::endl;
    }
}

// withdraw money
void BankAccount::withdraw(double amount) {
    if ((amount > 0) && (amount <= m_accountBalance))
    {
        m_accountBalance -= amount;
    }
    else
    {
        std::cout << "ungültige Auszahlung" << std::endl;
    }
}

int BankAccount::getAccountCount() {
    return s_accountCount;
}

bool checkSecretCode(const BankAccount& account, int code) {
    return account.m_secretCode == code;  
}