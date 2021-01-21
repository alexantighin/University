#include <fstream>
#include "Meniu.h"

int main()
{
	ifstream fisierProfesori;
	fisierProfesori.open("Profesori.txt");

	ifstream fisierStudenti;
	fisierStudenti.open("Studenti.txt");

	Meniu meniu(4, fisierProfesori, 5, fisierStudenti);
	meniu.AfisareMeniu();

	fisierProfesori.close();
	fisierStudenti.close();
	return 0;
}