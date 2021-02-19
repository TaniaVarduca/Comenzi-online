#include "UI.h"
#include <vector>;
#include <sstream>
#include "Exceptie.h"
#include <iostream>
using namespace std;


//afisare meniu
void UI::printMenu()
{
	cout << endl;
	cout << "1. Afisare comenzi" << endl;
	cout << "2. Cautare dupa nume client" << endl;
	cout << "3. Adaugare comanda de tip mancare" << endl;
	cout << "4. Adaugare comanda de tip shopping" << endl;
	cout << "5. Logout" << endl;
	cout << "6. Inchidere aplicatie" << endl;
}

int UI::login()
{
	string user, pass;
	u.setUserName(user);
	u.setPassword(pass);
	cout << "Dati user: ";
	cin >> user;
	cout << "Parola: ";
	cin >> pass;
	return s.login(user, pass);
}

void UI::logout()
{
	s.logout(u.getUserName(), u.getPassword());
	cout << "Logout efectuat cu succes! La revedere!" << endl;
}



void UI::allComenzi()
{
	map<int, Comanda*> m = s.getAllComenzi();
	map<int, Comanda*>::iterator itr;
	cout << endl << "Comenzile sunt: " << endl;
	for (itr = m.begin(); itr != m.end(); ++itr) {
		cout << "cheia: " << itr->first << ", comanda: " << (*itr->second).toStringDelimiter('-') << endl;
	}
}

void UI::addMancare()
{
	try {
		string nume, adresa, preparate; int pret;
		cout << "Nume client: "; cin >> nume;
		cout << "Adresa client: "; cin >> adresa;
		cout << "Lista preparate: "; cin >> preparate; if (preparate == "-") preparate = "";
		cout << "Pret total: "; cin >> pret;
		Mancare m(nume, adresa, preparate, pret);
		s.validareMancare(m);
		Comanda* c = new Mancare(m);
		s.addComanda(c);
	}
	catch (ValidationException exc) {
		cout << "Exceptie: " << exc.what() << endl;
	}
}

void UI::addShopping()
{
	try {
		string nume, adresa, cumparaturi, magazin; int pret;
		cout << "Nume client: "; cin >> nume;
		cout << "Adresa client: "; cin >> adresa;
		cout << "Lista cumparaturi: "; cin >> cumparaturi; if (cumparaturi == "-") cumparaturi = "";
		cout << "Pret total: "; cin >> pret;
		cout << "Nume magazin: "; cin >> magazin;
		Shopping sho(nume, adresa, cumparaturi, pret, magazin);
		s.validareShopping(sho);
		Comanda* c = new Shopping(sho);
		s.addComanda(c);
	}
	catch (ValidationException exc) {
		cout << "Exceptie: " << exc.what() << endl;
	}
}

void UI::cautareDupaNume()
{
	string nume;
	cout << "Dati numele clientului: "; cin >> nume;
	map<int, Comanda*> m = s.comandaDupaNumeClient(nume);
	map<int, Comanda*>::iterator itr;
	cout << endl;
	for (itr = m.begin(); itr != m.end(); ++itr) {
		cout << (*itr->second).toStringDelimiter('-') << endl;
	}
}

UI::UI()
{
}


UI::UI(Service& ss)
{
	s = ss;
}

void UI::run()
{
	bool k = true;
	Service s;
	int rez = login();
	if (rez) {
		cout << "Autentificare cu succes!" << endl;
		while (k)
		{
			printMenu();
			int option = 0;
			cin >> option;
			if (option == 1)
			{
				allComenzi();
				continue;
			}
			if (option == 2) {
				cautareDupaNume();
				continue;
			}
			if (option == 3) {
				addMancare();
				continue;
			}
			if (option == 4) {
				addShopping();
				continue;
			}
			if (option == 5) {
				logout();
				k = false;
			}
			if (option == 6) {
				k = false;
			}
		}
	}
	else
		cout << "User sau parola incorecte..." << endl;
}

UI::~UI()
{
}