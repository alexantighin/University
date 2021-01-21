#pragma once
#include "Persoana.h"

enum class GRAD
{
	NESPECIFICAT = 0,
	ASISTENT = 1,
	CONFERENTIAR = 2,
	DOCTORAND = 3,
	LECTOR = 4,
	PROFESOR = 5
};

class Profesor : public Persoana
{
private:
	Data dataAngajare;
	GRAD grad;
public:
	Profesor();
	Profesor(const char* nume, const char* prenume, Data dataNastere, GEN gen, const char* numeTata, const char* telefon, Data dataAngajare, GRAD grad);
	Profesor(const Profesor& sursa);
	~Profesor();

	Data ReturneazaDataAngajare();
	GRAD ReturneazaGrad();

	void Citire(istream& input);
	void Afisare(ostream& output);
	void AfisareGrad(Profesor* profesor, ostream& output);

	Profesor& operator=(const Profesor& sursa);
	friend istream& operator>>(istream& input, Profesor& student);
	friend ostream& operator<<(ostream& output, Profesor& student);
};