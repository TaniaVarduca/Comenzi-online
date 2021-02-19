#pragma once
#include "Serializer.h"
#include "Comanda.h"
#include "Mancare.h"
#include "Shopping.h"
#include "Utils.h"
#include <vector>

class SerializerComanda : public Serializer<Comanda*>
{
public:
	SerializerComanda();
	Comanda* fromString(string, char);
	string toString(Comanda*, char);
	~SerializerComanda();
};

inline SerializerComanda::SerializerComanda()
{
}

inline Comanda* SerializerComanda::fromString(string line, char delim) {
	vector<string> tokens = splitLine(line, delim);
	if (tokens.size() == 4) {
		int i = stoi(tokens[3]);
		Comanda* a = new Mancare(line, delim);
		return a;
	}
	if (tokens.size() == 5) {
		Comanda* a = new Shopping(line, delim);
		return a;
	}
}

inline string SerializerComanda::toString(Comanda* c, char delim) {
	return c->toStringDelimiter(delim);
}

inline SerializerComanda::~SerializerComanda()
{
}
