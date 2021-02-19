#pragma once
#include <iostream>
using namespace std;

template<class T> class Serializer
{
public:
	Serializer();
	virtual T fromString(string line, char delim) = 0;
	virtual string toString(T, char) = 0;
	virtual ~Serializer();
};


template<class T> Serializer<T>::Serializer() {
}


template<class T> Serializer<T>::~Serializer() {
}
