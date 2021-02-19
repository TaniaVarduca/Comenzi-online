#pragma once
#include <ostream>
using namespace std;

class Comanda {
protected:
	string numeClient;
	string adresaClient;
	int pretTotal;
public:
	Comanda();
	Comanda(string, string, int);
	Comanda(const Comanda& c);
	virtual ~Comanda();
	string getNumeClient();
	string getAdresaClient();
	int getPretTotal();
	void setNumeClient(string numeClient);
	void setAdresaClient(string adresaClient);
	void setPretTotal(int pretTotal);
	//Comanda& operator=(const Comanda& c);
	//bool operator==(const Comanda& c);
	//friend ostream& operator<<(ostream& os, const Comanda& c);
	virtual string toStringDelimiter(char) = 0;
};
