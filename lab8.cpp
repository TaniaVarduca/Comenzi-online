#include "RepoBaza.h"
#include "Comanda.h"
#include "Shopping.h"
#include "RepoCSV.h"
#include "RepoCustom.h"
#include "tests.h"
#include "Service.h"
#include "UI.h"
#include <iostream>
using namespace std;

int main()
{
    tests();
    cout << "Alegeti tipul de fisier: " << endl;
    cout << "1. CSV" << endl;
    cout << "2. Custom" << endl;
    cout << "Introduceti 1 sau 2: ";
    int opt; cin >> opt; cout << endl;
	Repo<Comanda*>* repo = new Repo<Comanda*>;
	SerializerComanda* s = new SerializerComanda;
	if (opt == 1) {
		repo = new RepoCSV<Comanda*>("comenzi.csv", s);
		repo->loadFromFile();
	}
	else {
		repo = new RepoCustom<Comanda*>("comenzi.txt", s);
		repo->loadFromFile();
	}

	Repo<User>* repoU = new Repo<User>;
	Service serv(repo, repoU);
	UI ui(serv);
	ui.run();
    
    return 0;
}
