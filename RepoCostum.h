#pragma once
#include "RepoBaza.h"
#include <fstream>
using namespace std;

template <class T> class RepoCostum :public Repo<T>
{
protected:
	const char* fileName;
public:
	RepoCostum();
	RepoCostum(const char*);
	void loadFromFile();
	void saveToFile();
	~RepoCostum();
};

template<class T>
inline RepoCostum<T>::RepoCostum() :Repo<T>()
{
}

template<class T>
inline RepoCostum<T>::RepoCostum(const char* fName) 
{
	fileName = fName;
}

template<class T>
inline void RepoCostum<T>::loadFromFile()
{
	string line;
	ifstream f(fileName);
	while (getline(f, line)) {
		T ob(line, '/');
		Repo<T>::add(ob);
	}
}

template<class T>
inline void RepoCostum<T>::saveToFile()
{
	ofstream f(fileName);
	map<int, T> t = Repo<T>::comenzi;
	for (auto itr = t.begin(); itr != t.end(); ++itr) {
		f << itr->second.toStringDelimiter('/') << endl;
	}
}

template<class T>
inline RepoCostum<T>::~RepoCostum()
{
}
