#include <ctime>
#include <chrono>
#include <iostream>
#include <vector>
#include <list>
#include <set>

void exerciseA(std::vector<int>& v, int n)
{
	std::chrono::duration<double> totalDuration{ 0 };
	for (int i = 0; i < n; ++i)
	{
		const auto start{ std::chrono::steady_clock::now() }; // Startzeitpunkt
		/* ---- HIER STARTET DIE BEFUELLUNG DES INT-VECTORS ---- */

		int r = std::rand() % n; // Erzeugt einen Zufallswert im Bereich [0,n)

		// finde position für r sodass Werte kleiner sind
		auto pos = std::lower_bound(v.begin(), v.end(), r);
		v.insert(pos, r);		
		

		/* ---- HIER ENDET DIE BEFUELLUNG DES INT-VECTORS ---- */
		const auto end{ std::chrono::steady_clock::now() }; // Endzeitpunkt
		const std::chrono::duration<double> elapsed_seconds{ end - start }; // Zeitdifferenz
		totalDuration += elapsed_seconds;

		// Ausgabe
		//std::cout << "Die Erzeugung des Zufallswertes " << r << " hat " << elapsed_seconds.count() << " Sekunden gedauert.\n";
	}
	std::cout << ">>> Die Erzeugung des gesamten Vectors hat " << totalDuration.count() << " Sekunden gedauert!\n";
	//std::cout << "\tVector: [ ";
	//for (auto val : v)
	//	std::cout << val << ' ';
	//std::cout << "]\n";
}

void exerciseB(std::list<int>& l, int n)
{
	std::chrono::duration<double> totalDuration{ 0 };
	for (int i = 0; i < n; ++i)
	{
		const auto start{ std::chrono::steady_clock::now() }; // Startzeitpunkt
		int r = std::rand() % n;
		/* ---- HIER STARTET DIE BEFUELLUNG DER INT-LISTE ---- */
		
		auto pos = std::lower_bound(l.begin(), l.end(), r);
		l.insert(pos, r);
		

		/* ---- HIER ENDET DIE BEFUELLUNG DER INT-LISTE ---- */
		const auto end{ std::chrono::steady_clock::now() }; // Endzeitpunkt
		const std::chrono::duration<double> elapsed_seconds{ end - start }; // Zeitdifferenz
		totalDuration += elapsed_seconds;

		// Ausgabe
		//std::cout << "Die Erzeugung des Zufallswertes " << r << " hat " << elapsed_seconds.count() << " Sekunden gedauert.\n";
	}
	std::cout << ">>> Die Erzeugung der gesamten Liste hat " << totalDuration.count() << " Sekunden gedauert!\n";
	//std::cout << "\tListe: [ ";
	//for (auto val : l)
	//	std::cout << val << ' ';
	//std::cout << "]\n";
}

void exerciseD(std::vector<int>& v, int n)
{
	std::chrono::duration<double> totalDuration{ 0 };
	for (int i = 0; i < n; ++i)
	{
		const auto start{ std::chrono::steady_clock::now() }; // Startzeitpunkt
		/* ---- HIER STARTET DIE BEFUELLUNG DES INT-VECTORS ---- */
		int r = std::rand() % n; // Erzeugt einen Zufallswert im Bereich [0,n)

		// finde position für r sodass Werte kleiner sind
		auto pos = std::lower_bound(v.begin(), v.end(), r);
		v.insert(pos, r);	

		/* ---- HIER ENDET DIE BEFUELLUNG DES INT-VECTORS ---- */
		const auto end{ std::chrono::steady_clock::now() }; // Endzeitpunkt
		const std::chrono::duration<double> elapsed_seconds{ end - start }; // Zeitdifferenz
		v.shrink_to_fit();
		totalDuration += elapsed_seconds;

		// Ausgabe
		//std::cout << "Die Erzeugung des Zufallswertes " << r << " hat " << elapsed_seconds.count() << " Sekunden gedauert.\n";
	}
	std::cout << ">>> Die Erzeugung des gesamten Vectors hat " << totalDuration.count() << " Sekunden gedauert!\n";
	//std::cout << "\tVector: [ ";
	//for (auto val : v)
	//	std::cout << val << ' ';
	//std::cout << "]\n";
}

void exerciseE(std::multiset<int>& s, int n)
{
	std::chrono::duration<double> totalDuration{ 0 };
	for (int i = 0; i < n; ++i)
	{
		const auto start{ std::chrono::steady_clock::now() }; // Startzeitpunkt
		/* ---- HIER STARTET DIE BEFUELLUNG DES INT-SETS ---- */
		int r = std::rand() % n; // Erzeugt einen Zufallswert im Bereich [0,n)
		
		// sets sind schon sortiert, Position muss nicht ermittelt werden
		s.insert(r);

		/* ---- HIER ENDET DIE BEFUELLUNG DES INT-SETS ---- */
		const auto end{ std::chrono::steady_clock::now() }; // Endzeitpunkt
		const std::chrono::duration<double> elapsed_seconds{ end - start }; // Zeitdifferenz
		totalDuration += elapsed_seconds;

		// Ausgabe
		//std::cout << "Die Erzeugung des Zufallswertes " << r << " hat " << elapsed_seconds.count() << " Sekunden gedauert.\n";
	}
	std::cout << ">>> Die Erzeugung des gesamten Sets hat " << totalDuration.count() << " Sekunden gedauert!\n";
	//std::cout << "\tSet: [ ";
	//for (auto val : s)
	//	std::cout << val << ' ';
	//std::cout << "]\n";
}

int main()
{
	int n = 20000;
	int seed = 42;

	std::srand(seed);   // Initialisiert eine Zufallsumgebung
	std::vector<int> v;
	exerciseA(v, n);

	// Teilaufgabe c
	std::srand(seed);   // Initialisiert eine Zufallsumgebung
	std::vector<int> v2;
	v2.reserve(n);
	exerciseA(v2, n);

	// Initialisiere die Zufallsumgebung erneut, mit demselben Seed,
	// damit dieselben Zufallszahlen erzeugt werden
	std::srand(seed);
	std::list<int> l;
	exerciseB(l, n);

	std::srand(seed);   // Initialisiert eine Zufallsumgebung
	std::vector<int> v3;
	exerciseD(v3, n);

	std::srand(seed);
	std::multiset<int> s;
	exerciseE(s, n);
	
}