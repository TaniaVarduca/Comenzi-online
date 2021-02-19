#include "Shopping.h"
#include "Comanda.h"
#include "Utils.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <string>
#include <iostream>
using namespace std;

//constructor default(fara param)
Shopping::Shopping():Comanda() {
	//this->numeMagazin = NULL;
}

//constructor cu param
Shopping::Shopping(string numeClient, string adresaClient, string lc, int pretTotal, string maga):Comanda(numeClient, adresaClient, pretTotal)
{
	listaCumparaturi = lc;
	//this->numeMagazin = new char[strlen(numeMagazin) + 1];
	//strcpy_s(this->numeMagazin, 1 + strlen(numeMagazin), numeMagazin);
	numeMagazin = maga;
}

Shopping::Shopping(string linie, char delim)
{
	vector<string> tokens = splitLine(linie, delim);
	numeClient = tokens[0];
	adresaClient = tokens[1];
	listaCumparaturi = tokens[2];
	pretTotal = stoi(tokens[3]);
	numeMagazin = tokens[4];
}

//constructor de copiere
Shopping::Shopping(const Shopping& s):Comanda(s) {
	listaCumparaturi = s.listaCumparaturi;
	/*if (s.numeMagazin) {
		this->numeMagazin = new char[strlen(s.numeMagazin) + 1];
		strcpy_s(this->numeMagazin, 1 + strlen(s.numeMagazin), s.numeMagazin);
	}*/
	numeMagazin = s.numeMagazin;
}

//destructor
Shopping::~Shopping() {
	/*if (numeMagazin) delete[]numeMagazin;
	numeMagazin = NULL;*/
}

//getter pentru nume
string Shopping::getNumeMagazin() {
	return this->numeMagazin;
}

string Shopping::getListaCumparaturi() {
	return this->listaCumparaturi;
}

void Shopping::setListaCumparaturi(string lc)
{
	this->listaCumparaturi = lc;
}

//setter pentru nume
void Shopping::setNumeMagazin(string maga)
{
	/*if (this->numeMagazin) {
		delete[] this->numeMagazin;
	}
	this->numeMagazin = new char[strlen(numeMagazin) + 1];
	strcpy_s(this->numeMagazin, strlen(numeMagazin) + 1, numeMagazin);*/
	this->numeMagazin = maga;
}

//suprascrie operatorul "=" pentru un element de tip Shopping
Shopping& Shopping::operator=(const Shopping& a) {
	if (this == &a) return *this; //self-assignment
	/*if (numeClient) delete[] numeClient;
	if (a.numeClient) {
		this->numeClient = new char[strlen(a.numeClient) + 1];
		strcpy_s(numeClient, strlen(a.numeClient) + 1, a.numeClient);
	}
	if (adresaClient) delete[] adresaClient;
	if (a.adresaClient) {
		this->adresaClient = new char[strlen(a.adresaClient) + 1];
		strcpy_s(adresaClient, strlen(a.adresaClient) + 1, a.adresaClient);
	}*/
	numeClient = a.numeClient;
	adresaClient = a.adresaClient;
	listaCumparaturi = a.listaCumparaturi;
	pretTotal = a.pretTotal;
	/*if (numeMagazin) delete[] numeMagazin;
	if (a.numeMagazin) {
		this->numeMagazin = new char[strlen(a.numeMagazin) + 1];
		strcpy_s(numeMagazin, strlen(a.numeMagazin) + 1, a.numeMagazin);
	}*/
	numeMagazin = a.numeMagazin;
	return *this;
}

//operatorul de egalitate
bool Shopping:: operator==(const Shopping& a) {
	return this->numeClient == a.numeClient && this->adresaClient == a.adresaClient && this->pretTotal == a.pretTotal && this->listaCumparaturi == a.listaCumparaturi && this->numeMagazin == a.numeMagazin;
}

string Shopping::toStringDelimiter(char delim)
{
	return numeClient + delim + adresaClient + delim + listaCumparaturi + delim + to_string(pretTotal) + delim + numeMagazin;
}

istream& operator>>(istream& is, Shopping& s) {
	string nume;
	cout << "Nume client: ";
	is >> nume;
	s.setNumeClient(nume);
	//delete[] nume;
	string adresa;
	cout << "Adresa client: ";
	is >> adresa;
	s.setAdresaClient(adresa);
	//delete[] adresa;
	string lc;
	cout << "lista cumparaturi: ";
	is >> lc;
	s.setListaCumparaturi(lc);
	int pret;
	cout << "Pret: ";
	is >> pret;
	s.setPretTotal(pret);
	//string maga = new char[100];
	string maga;
	cout << "nume magazin: ";
	is >> maga;
	s.setNumeMagazin(maga);
	return is;
}

//pt afisare
ostream& operator<<(ostream& os, const Shopping& a)
{
	os << "Nume: " << a.numeClient << " - adresa: " << a.adresaClient << " - cumparaturi: " << a.listaCumparaturi << " - pret: " << a.pretTotal << " - numeMagazin: " << a.numeMagazin;
	return os;
}