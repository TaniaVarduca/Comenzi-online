#pragma once
#include <ostream>
#include "Comanda.h"
//#include <vector>;
using namespace std;

class Mancare: public Comanda {
private:
	//vector <string> listaPreparate;
	string listaPreparate;
public:
	Mancare();
	Mancare(string, string, string, int);
	Mancare(string, char);
	Mancare(const Mancare& c);
    ~Mancare();
	//vector <string> getListaPreparate();
	string getListaPreparate();
	void setListaPreparate(string);
	Mancare& operator=(const Mancare& c);
	bool operator==(const Mancare& c);
	string toStringDelimiter(char);
	friend istream& operator>>(istream& is, Mancare& c);
	friend ostream& operator<<(ostream& os, const Mancare& c);
};
