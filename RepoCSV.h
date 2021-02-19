#pragma once
#include "RepoBaza.h"
#include <fstream>
#include "SerializerComanda.h"
using namespace std;

template  <class T> class RepoCSV : public Repo<T>
{
protected:
	const char* fileName;
	Serializer<T>* s;
public:
	RepoCSV();
	RepoCSV(const char*, Serializer<T>*);
	void loadFromFile();
	void saveToFile();
	~RepoCSV();
};
template<class T>
RepoCSV<T>::RepoCSV():Repo<T>()
{
}

template<class T>
inline RepoCSV<T>::RepoCSV(const char* fName, Serializer<T>* serializer) 
{
	fileName = fName;
	s = serializer;
}

template<class T>
void RepoCSV<T>::loadFromFile()
{
	string line;
	ifstream f(fileName);
	while (getline(f, line)) {
		Repo<T>::add(s->fromString(line, ','));
	}
	f.close();
}

template<class T>
void RepoCSV<T>::saveToFile()
{
	ofstream f(fileName);
	map<int, T> t = Repo<T>::comenzi;
	for (auto itr = t.begin(); itr != t.end(); ++itr) {
		f << s->toString(itr->second, ',') << endl;
	}
	f.close();
}

template<class T>
RepoCSV<T>::~RepoCSV()
{
}
