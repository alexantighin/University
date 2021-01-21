#include "Persoana.h"
#include "Functii.h"

Persoana::Persoana()
{
	nume = nullptr;
	prenume= nullptr;
	gen = GEN::NESPECIFICAT;
	numeTata= nullptr;
	telefon = nullptr;	
}

Persoana::Persoana(const char* nume, const char* prenume, Data dataNastere, GEN gen, const char* numeTata, const char* telefon)
{
	this->nume = CopiereText(nume);
	this->prenume = CopiereText(prenume);
	this->dataNastere = dataNastere;
	this->gen = gen;
	this->numeTata = CopiereText(numeTata);
	this->telefon = CopiereText(telefon);
}

Persoana::~Persoana()
{	
	if (nume != nullptr)
	{
		delete[] nume;
	}
	if (prenume != nullptr)
	{
		delete[] prenume;
	}
	gen = GEN::NESPECIFICAT;
	if (numeTata != nullptr)
	{
		delete[] numeTata;
	}
	if (telefon != nullptr)
	{
		delete[] telefon;
	}
}

Persoana::Persoana(const Persoana& sursa)
{
	nume = CopiereText(sursa.nume);
	prenume = CopiereText(sursa.prenume);
	dataNastere = sursa.dataNastere;
	gen = sursa.gen;
	numeTata = CopiereText(sursa.numeTata);
	telefon = CopiereText(sursa.telefon);	
}


char* Persoana::ReturneazaNume()
{
	return nume;
}

char* Persoana::ReturneazaPrenume()
{
	return prenume;
}

Data Persoana::ReturneazaDataNasterii()
{
	return dataNastere;
}

GEN Persoana::ReturneazaGen()
{
	return gen;
}

char* Persoana::ReturneazaNumeTata()
{
	return numeTata;
}

char* Persoana::ReturneazaTelefon()
{
	return telefon;
}

void Persoana::Citire(istream& input)
{
	char buffer[100];
	if (&input == &cin)
	{
		cout << "- Introduceti numele: ";
	}	
	input.getline(buffer, 100);
	nume=CopiereText(buffer);

	if (&input == &cin)
	{
		cout << "- Introduceti prenumele: ";
	}
	input.getline(buffer, 100);
	prenume=CopiereText(buffer);

	if (&input == &cin)
	{
		cout << "- Introduceti data nasterii\n";
	}
	input >> dataNastere;

	int optiuneGen;
	if (&input == &cin)
	{
		cout << "- Introduceti genul persoanei (1-FEMININ | 2-MASCULIN): ";
	}
	input >> optiuneGen;
	switch (optiuneGen)
	{
	case 1:
		gen = GEN::FEMININ;
		break;
	case 2:
		gen = GEN::MASCULIN;
		break;
	default:
		gen = GEN::NESPECIFICAT;
		break;
	}
	input.ignore(100, '\n');
	if (&input == &cin)
	{
		cout << "- Introduceti numele tatalui: ";
	}
	input.getline(buffer, 100);
	numeTata=CopiereText(buffer);

	if (&input == &cin)
	{
		cout << "- Introduceti numarul de telefon: ";
	}
	input.getline(buffer, 100);
	telefon=CopiereText(buffer);	
}

void Persoana::Afisare(ostream& output)
{	
	output << "\n-> Nume: \t\t";
	if (nume != nullptr)
	{
		output << nume;
	}
	else
	{
		output << "Nespecificat";
	}
	output << "\n-> Prenume: \t\t";
	if (prenume != nullptr)
	{
		output << prenume;
	}
	else
	{
		output << "Nespecificat";
	}
	output << "\n-> Data nasterii: \t";
	output << dataNastere;
	output << "\n-> Gen: \t\t";
	AfisareGen(output);
	output << "\n-> Numele tatalui: \t";
	if (numeTata != nullptr)
	{
		output << numeTata;
	}
	else
	{
		output << "Nespecificat";
	}
	output << "\n-> Telefon: \t\t";
	if (telefon != nullptr)
	{
		output << telefon;
	}
	else
	{
		output << "Nespecificat";
	}	
}

void Persoana::AfisareGen(ostream& output)
{
	if(gen == GEN::MASCULIN)
	{
		output << "Masculin";
	}
	else if(gen == GEN::FEMININ)
	{
		output << "Feminin";
	}
	else
	{
		output << "Nespecificat";
	}
}

Persoana& Persoana::operator=(const Persoana& sursa)
{
	nume = CopiereText(sursa.nume);
	prenume = CopiereText(sursa.prenume);
	dataNastere = sursa.dataNastere;
	gen = sursa.gen;
	numeTata = CopiereText(sursa.numeTata);
	telefon = CopiereText(sursa.telefon);
	return *this;
}