#pragma once
#include <ostream>
#include "Comanda.h"
//#include <vector>;
using namespace std;

class Shopping : public Comanda {
private:
	string listaCumparaturi;
	string numeMagazin;
public:
	Shopping();
	Shopping(string, string, string, int, string);
	Shopping(string, char);
	Shopping(const Shopping& c);
	~Shopping();
	string getListaCumparaturi();
	void setListaCumparaturi(string);
	string getNumeMagazin();
	void setNumeMagazin(string);
	Shopping& operator=(const Shopping& c);
	bool operator==(const Shopping& c);
	string toStringDelimiter(char);
	friend istream& operator>>(istream& is, Shopping& s);
	friend ostream& operator<<(ostream& os, const Shopping& c);
};
