#include "Mancare.h"
#include "Comanda.h"
#include "Utils.h"
#include <cstddef>
#include <string>
#include <ostream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

//constructor default(fara param)
Mancare::Mancare():Comanda() {
}

Mancare::Mancare(string numeClient, string adresaClient, string lp, int pretTotal):Comanda(numeClient, adresaClient, pretTotal)
{
	listaPreparate = lp;
}

Mancare::Mancare(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	numeClient = tokens[0];
	adresaClient = tokens[1];
	listaPreparate = tokens[2];
	pretTotal = stoi(tokens[3]);
}

Mancare::Mancare(const Mancare& m):Comanda(m)
{
	listaPreparate = m.listaPreparate;
}

//destructor
Mancare::~Mancare() {
}

//getter pentru listaPreparate
//vector<string> Mancare::getListaPreparate() {
//	return this->listaPreparate;
//}

string Mancare::getListaPreparate()
{
	return this->listaPreparate;
}

void Mancare::setListaPreparate(string lp)
{
	this->listaPreparate = lp;
}

//suprascrie operatorul "=" pentru un element de tip Mancare
Mancare& Mancare::operator=(const Mancare& m) {
	if (this == &m) return *this; //self-assignment
	/*if (numeClient) delete[] numeClient;
	if (m.numeClient) {
		this->numeClient = new char[strlen(m.numeClient) + 1];
		strcpy_s(numeClient, strlen(m.numeClient) + 1, m.numeClient);
	}
	if (adresaClient) delete[] adresaClient;
	if (m.adresaClient) {
		this->adresaClient = new char[strlen(m.adresaClient) + 1];
		strcpy_s(adresaClient, strlen(m.adresaClient) + 1, m.adresaClient);
	}*/
	numeClient = m.numeClient;
	adresaClient = m.adresaClient;
	pretTotal = m.pretTotal;
	listaPreparate = m.listaPreparate;
	return *this;
}

//operatorul de egalitate
bool Mancare:: operator==(const Mancare& m) {
	return this->numeClient == m.numeClient && adresaClient == m.adresaClient && this->pretTotal == m.pretTotal;
}

string Mancare::toStringDelimiter(char delim)
{
	return numeClient + delim + adresaClient + delim + listaPreparate + delim + to_string(pretTotal);
}

istream& operator>>(istream& is, Mancare& m) {
	string nume;
	cout << "Nume client: ";
	is >> nume;
	m.setNumeClient(nume);
	//delete[] nume;
	string adresa;
	cout << "Adresa client: ";
	is >> adresa;
	m.setAdresaClient(adresa);
	//delete[] adresa;
	string lp;
	cout << "lista preparate: ";
	is >> lp;
	m.setListaPreparate(lp);
	int pret;
	cout << "Pret: ";
	is >> pret;
	m.setPretTotal(pret);
	return is;
}

//pt afisare
ostream& operator<<(ostream& os, const Mancare& m)
{
	os << "Nume: " << m.numeClient << " - adresa: " << m.adresaClient << " - listaPreparate: " << m.listaPreparate << " - pret: " << m.pretTotal;
	return os;
}