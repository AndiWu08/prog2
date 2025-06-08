#pragma once
#include <iostream>
#include <string>

class BankAccount
{
// TEILAUFGABE A
private:
	std::string  m_accountHolder;	// Name des Kontoinhabers
	double  m_accountBalance;	// Kontostand
	int  m_secretCode;	// Geheimer Code des Kontos

public:
	/// Getter fuer den Kontoinhaber
	std::string  getAccountHolder()  const;

	/// Getter fuer den Kontostand
	double  getBalance()  const;

// TEILAUFGABE B
public:
	/// Konstruktor mit Parametern
	BankAccount(const std::string accountHolder, double initialBalance,
				   unsigned secretCode);

	/// Destruktor
	~BankAccount();

// TEILAUFGABE C
public:
	/// Methode, um Geld einzuzahlen
	void deposit(double depositMoney);

	/// Methode, um Geld abzuheben
	void withdraw(double withdrawMoney);

// TEILAUFGABE D
private:
	static int s_accountCount;	 // Statische Variable zur Zaehlung der Bankkonten

public:
	/// Gibt die Anzahl aller Bankkonten zurueck
	static int getAccountCount();

// TEILAUFGABE E
public:
	/// Freundfunktion: Ueberprueft den geheimen Code eines Kontos
	friend bool checkSecretCode(const BankAccount& account, int code);
};

// TEILAUFGABE F
/// Berechnet die Summe der Guthaben zweier Konten
inline double calculateTotalBalance(BankAccount& acc1, BankAccount& acc2)
{
	return acc1.getBalance() + acc2.getBalance();
}