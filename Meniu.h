#pragma once
#include "PersoaneUniversitate.h"

class Meniu
{
private:
	PersoaneUniversitate persoaneUniversitate;
	void AfisareMeniuPrincipal();
	void MeniuProfesori();
	void AfisareMeniuProfesori();
	void MeniuStudenti();
	void AfisareMeniuStudenti();
public:
	Meniu(int numarProfesori, istream& inputProfesori, int numarStudenti, istream& inputStudenti);
	void AfisareMeniu();
};