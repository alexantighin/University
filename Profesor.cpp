#include "Profesor.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define MAGENTA "\033[35m"

Profesor::Profesor():Persoana()
{
	grad = GRAD::NESPECIFICAT;
}

Profesor::Profesor(const char* nume, const char* prenume, Data dataNastere, GEN gen, const char* numeTata, const char* telefon, Data dataAngajare, GRAD grad) : Persoana(nume, prenume, dataNastere, gen, numeTata, telefon)
{
	this->dataAngajare = dataAngajare;
	this->grad = grad;
}

Profesor::Profesor(const Profesor& sursa):Persoana(sursa)
{
	dataAngajare = sursa.dataAngajare;
	grad = sursa.grad;
}

Profesor::~Profesor()
{
	/*cout << RED "\nS-a apelat deconstructorul pentru Profesor - ";
	if (nume != nullptr && prenume != nullptr)
	{
		cout << nume << " " << prenume;
	}
	else
	{
		cout << "Nespecificat";
	}
	cout << " - cu succes." << RESET;*/
}

Data Profesor::ReturneazaDataAngajare()
{
	return dataAngajare;
}

GRAD Profesor::ReturneazaGrad()
{
	return grad;
}

void Profesor::Citire(istream& input)
{
	if (&input == &cin)
	{
		cout << "\n___________ Citire Profesor ___________\n";		
	}

	Persoana::Citire(input);
	if (&input == &cin)
	{
		cout << "- Introduceti data angajarii\n";
	}
	input >> dataAngajare;

	int optiuneGrad;
	if (&input == &cin)
	{
		cout << "- Introduceti gradul profesorului (1-ASISTENT | 2-CONFERENTIAR | 3-DOCTORAND | 4-LECTOR | 5-PROFESOR): ";
	}
	input >> optiuneGrad;
	switch (optiuneGrad)
	{
	case 1:
		grad = GRAD::ASISTENT;
		break;
	case 2:
		grad = GRAD::CONFERENTIAR;
		break;
	case 3:
		grad = GRAD::DOCTORAND;
		break;
	case 4:
		grad = GRAD::LECTOR;
		break;
	case 5:
		grad = GRAD::PROFESOR;
		break;
	default:
		grad = GRAD::NESPECIFICAT;
		break;
	}
	input.ignore(100, '\n');
}

void Profesor::Afisare(ostream& output)
{
	output << MAGENTA << "\n--------------------------------------------" << RESET;
	Persoana::Afisare(output);
	output << MAGENTA << "\n-> Data angajarii \t" << dataAngajare;
	output << "\n-> Grad: \t";
	AfisareGrad(this, output);
	output << MAGENTA << "\n--------------------------------------------" << RESET;
}

void Profesor::AfisareGrad(Profesor* profesor, ostream& output)
{
	output << "\t";
	if (profesor->grad == GRAD::ASISTENT)
	{
		output << "Asistent";
	}
	else if (profesor->grad == GRAD::CONFERENTIAR)
	{
		output << "Conferentiar";
	}
	else if (profesor->grad == GRAD::DOCTORAND)
	{
		output << "Doctorand";
	}
	else if (profesor->grad == GRAD::LECTOR)
	{
		output << "Lector";
	}
	else if (profesor->grad == GRAD::PROFESOR)
	{
		output << "Profesor";
	}
	else
	{
		output << "Nespecificat";
	}
}

Profesor& Profesor::operator=(const Profesor& sursa)
{
	Persoana::operator=(sursa);
	dataAngajare = sursa.dataAngajare;
	grad = sursa.grad;
	return *this;
}

istream& operator>>(istream& input, Profesor& profesor)
{
	if (&input == &cin)
	{
		cout << "\n___________ Citire Profesor ___________\n";
	}

	profesor.Persoana::Citire(input);
	if (&input == &cin)
	{
		cout << "- Introduceti data angajarii\n";
	}
	input >> profesor.dataAngajare;

	int optiuneGrad;
	if (&input == &cin)
	{
		cout << "- Introduceti gradul profesorului (1-ASISTENT | 2-CONFERENTIAR | 3-DOCTORAND | 4-LECTOR | 5-PROFESOR): ";
	}
	input >> optiuneGrad;
	switch (optiuneGrad)
	{
	case 1:
		profesor.grad = GRAD::ASISTENT;
		break;
	case 2:
		profesor.grad = GRAD::CONFERENTIAR;
		break;
	case 3:
		profesor.grad = GRAD::DOCTORAND;
		break;
	case 4:
		profesor.grad = GRAD::LECTOR;
		break;
	case 5:
		profesor.grad = GRAD::PROFESOR;
		break;
	default:
		profesor.grad = GRAD::NESPECIFICAT;
		break;
	}
	return input;
}

ostream& operator<<(ostream& output, Profesor& profesor)
{
	output << MAGENTA << "\n--------------------------------------------" << RESET;
	profesor.Persoana::Afisare(output);
	output << MAGENTA << "\n-> Data angajarii \t" << profesor.dataAngajare;
	output << "\n-> Grad: \t";
	profesor.Profesor::AfisareGrad(&profesor, output);
	output << MAGENTA << "\n--------------------------------------------" << RESET;
	return output;
}