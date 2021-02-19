
#pragma once
#include "Comanda.h" 
#include "Mancare.h" 
#include "Shopping.h" 
#include <map>
using namespace std;

template <class T> class Repo
{
protected:
	map<int, T> comenzi;
	int contor;
public:
	Repo();
	Repo(const Repo& r);
	~Repo();
	void addAplicatie(T& a);
	map<int, T> getAll();
	void delAplicatie(int pos);
	void updateAplicatie(T& a, int pos, char* name, int consumMemorieKb, char* statusN);
	int getSize();
};

//constructor fara param
template <class T>  Repo<T>::Repo() {
}

//constuctor de copiere
template <class T> Repo<T>::Repo(const Repo& r) {
	this->comenzi = r.comenzi;
	this->contor = r.contor;
}

//destructorul
template <class T> Repo<T>::~Repo() {
}

//adaugarea unui comenzi
template <class T> void Repo<T>::addAplicatie(T& a) {
	comenzi.insert(pair<int, T>(contor++, a));
}

//returnarea tuturor comenzilor
template <class T> map<int, T> Repo<T>::getAll() {
	return comenzi;
}

//stergerea unei comenzi
template <class T> void Repo<T>::delAplicatie(int pos)
{
	comenzi.erase(pos);
}


//dimensiune map
template <class T> int Repo<T>::getSize() {
	return comenzi.size();
}
