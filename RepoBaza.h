#pragma once
#include <map>
#include <algorithm>
#include <string>
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
	void add(T a);
	map<int, T> getAll();
	void remove(T);
	void update(T, T);
	int size();
	int find(T);
	T get(int);
	virtual void loadFromFile();
	virtual void saveToFile();
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
template <class T> void Repo<T>::add(T a) {
	comenzi.insert(pair<int, T>(contor++, a));
}

//returnarea tuturor comenzilor
template <class T> map<int, T> Repo<T>::getAll() {
	return comenzi;
}

//stergerea unei comenzi
template <class T> void Repo<T>::remove(T a)
{
	int pos = find(a);
	comenzi.erase(pos);
}

template<class T>
inline void Repo<T>::update(T vechi, T nou)
{
	for (auto itr = comenzi.begin(); itr != comenzi.end(); itr++) {
		if (comenzi.find(itr->first)->second == vechi) {
			comenzi[itr->first] = nou;
		}
	}
}

//dimensiune map
template <class T> int Repo<T>::size() {
	return comenzi.size();
}

template<class T>
inline int Repo<T>::find(T a)
{
	int k = 0;
	for (auto itr = comenzi.begin(); itr != comenzi.end(); ++itr) {
		if (itr->second == a)
			return k;
		k++;
	}
	return -1;
}

template<class T>
T Repo<T>::get(int a)
{
	int k = 0;
	for (auto itr = comenzi.begin(); itr != comenzi.end(); ++itr) {
		if (k == a)
			return itr->second;
		k++;
	}
}


template<class T>
inline void Repo<T>::loadFromFile()
{
}

template<class T>
inline void Repo<T>::saveToFile()
{
}
