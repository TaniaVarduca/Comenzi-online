#include "Comanda.h"
#include <cstddef>
#include <string.h>
#include <ostream>
#include <iostream>
using namespace std;

//constructor default(fara param)
Comanda::Comanda() {
	this->numeClient = "";
	this->adresaClient = "";
	this->pretTotal = 0;
}

//constructor cu param
Comanda::Comanda(string numeClient, string adresaClient, int pretTotal)
{
	/*this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, 1 + strlen(numeClient), numeClient);
	this->adresaClient = new char[strlen(adresaClient) + 1];
	strcpy_s(this->adresaClient, 1 + strlen(adresaClient), adresaClient);*/
	this->numeClient = numeClient;
	this->adresaClient = adresaClient;
	this->pretTotal = pretTotal;
}

//constructor de copiere
Comanda::Comanda(const Comanda& c) {
	/*if (c.numeClient) {
		this->numeClient = new char[strlen(c.numeClient) + 1];
		strcpy_s(this->numeClient, 1 + strlen(c.numeClient), c.numeClient);
	}
	if (c.adresaClient) {
		this->adresaClient = new char[strlen(c.adresaClient) + 1];
		strcpy_s(this->adresaClient, 1 + strlen(c.adresaClient), c.adresaClient);
	}*/
	this->numeClient = c.numeClient;
	this->adresaClient = c.adresaClient;
	this->pretTotal = c.pretTotal;
}

//destructor
Comanda::~Comanda() {
	/*if (numeClient) delete[]numeClient;
	numeClient = NULL;
	if (adresaClient) delete[]adresaClient;
	adresaClient = NULL;*/
}

//getter pentru nume
string Comanda::getNumeClient() {
	return this->numeClient;
}

//getter pentru adresaClient
string Comanda::getAdresaClient() {
	return this->adresaClient;
}

//getter pentru pret
int Comanda::getPretTotal() {
	return this->pretTotal;
}

//setter pentru nume
void Comanda::setNumeClient(string numeClient)
{
	/*if (this->numeClient) {
		delete[] this->numeClient;
	}
	this->numeClient = new char[strlen(numeClient) + 1];
	strcpy_s(this->numeClient, strlen(numeClient) + 1, numeClient);*/
	this->numeClient = numeClient;
}

//setter pentru adresaClient
void Comanda::setAdresaClient(string ac)
{
	/*if (this->adresaClient) {
		delete[] this->adresaClient;
	}
	this->adresaClient = new char[strlen(adresaClient) + 1];
	strcpy_s(this->adresaClient, strlen(adresaClient) + 1, adresaClient);*/
	this->adresaClient = ac;
}

//setter pentru pret
void Comanda::setPretTotal(int pretTotal)
{
	this->pretTotal = pretTotal;
}

////suprascrie operatorul "=" pentru un element de tip Comanda
//Comanda& Comanda::operator=(const Comanda& c) {
//	if (this == &c) return *this; //self-assignment
//	/*if (numeClient) delete[] numeClient;
//	if (c.numeClient) {
//		this->numeClient = new char[strlen(c.numeClient) + 1];
//		strcpy_s(numeClient, strlen(c.numeClient) + 1, c.numeClient);
//	}
//	if (adresaClient) delete[] adresaClient;
//	if (c.adresaClient) {
//		this->adresaClient = new char[strlen(c.adresaClient) + 1];
//		strcpy_s(adresaClient, strlen(c.adresaClient) + 1, c.adresaClient);
//	}*/
//	numeClient = c.numeClient;
//	adresaClient = c.adresaClient;
//	pretTotal = c.pretTotal;
//	return *this;
//}
//
////operatorul de egalitate
//bool Comanda:: operator==(const Comanda& c) {
//	return this->numeClient == c.numeClient && this->adresaClient == c.adresaClient && this->pretTotal == c.pretTotal;
//}
//
//pt afisare
//ostream& operator<<(ostream& os, const Comanda& c)
//{
//	/*os << "Nume - " << c.numeClient << ", adresaClient - " << c.adresaClient << ", pretTotal - " << c.pretTotal;
//	return os;*/
//}