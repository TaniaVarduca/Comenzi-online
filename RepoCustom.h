#pragma once
#include "RepoBaza.h"
#include <fstream>
#include "SerializerComanda.h"
using namespace std;

template <class T> class RepoCustom :public Repo<T>
{
protected:
	const char* fileName;
	Serializer<T>* s;
public:
	RepoCustom();
	RepoCustom(const char*, Serializer<T>*);
	void loadFromFile();
	void saveToFile();
	~RepoCustom();
};

template<class T>
inline RepoCustom<T>::RepoCustom() :Repo<T>()
{
}

template<class T>
inline RepoCustom<T>::RepoCustom(const char* fName, Serializer<T>* serializer)
{
	fileName = fName;
	s = serializer;
}

template<class T>
inline void RepoCustom<T>::loadFromFile()
{
	string line;
	ifstream f(fileName);
	while (getline(f, line)) {
		Repo<T>::add(s->fromString(line, '/'));
	}
	f.close();
}

template<class T>
inline void RepoCustom<T>::saveToFile()
{
	ofstream f(fileName);
	map<int, T> t = Repo<T>::comenzi;
	for (auto itr = t.begin(); itr != t.end(); ++itr) {
		f << s->toString(itr->second, '/') << endl;
	}
	f.close();
}

template<class T>
inline RepoCustom<T>::~RepoCustom()
{
}
