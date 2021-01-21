#pragma once
#include "Data.h"

enum class GEN
{
	NESPECIFICAT = 0,
	FEMININ = 1,
	MASCULIN = 2
};

class Persoana
{
protected:
	char* nume;
	char* prenume;
	Data dataNastere;
	GEN gen;
	char* numeTata;
	char* telefon;
	Persoana();
	Persoana(const char* nume, const char* prenume, Data dataNastere, GEN gen, const char* numeTata, const char* telefon);
	Persoana(const Persoana& sursa);	
public:		
	~Persoana();

	char* ReturneazaNume();
	char* ReturneazaPrenume();
	Data ReturneazaDataNasterii();
	GEN ReturneazaGen();
	char* ReturneazaNumeTata();
	char* ReturneazaTelefon();

	void Citire(istream& input);
	void Afisare(ostream& output);
	void AfisareGen(ostream& output);

	Persoana& operator=(const Persoana& sursa);	
};