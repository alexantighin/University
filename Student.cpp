#include "Student.h"
#include "Functii.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"

Student::Student():Persoana()
{
	numarMatricol = 0;
	programStudiu = PROGRAM_STUDIU::NESPECIFICAT;
}

Student::Student(const char* nume, const char* prenume, Data dataNastere, GEN gen, const char* numeTata, const char* telefon, int numarMatricol, PROGRAM_STUDIU programStudiu) : Persoana(nume, prenume, dataNastere, gen, numeTata, telefon)
{
	this->numarMatricol = numarMatricol;
	this->programStudiu = programStudiu;
}

Student::Student(const Student& sursa):Persoana(sursa)
{
	numarMatricol = sursa.numarMatricol;
	programStudiu = sursa.programStudiu;
}

Student::~Student()
{
	/*cout << RED "\nS-a apelat deconstructorul pentru Student - ";
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

int Student::ReturneazaNumarMatricol()
{
	return numarMatricol;
}

PROGRAM_STUDIU Student::ReturneazaProgramStudiu()
{
	return programStudiu;
}

void Student::Citire(istream& input)
{
	if (&input == &cin)
	{
		cout << "\n___________ Citire Student ___________\n";
	}
	
	Persoana::Citire(input);
	if (&input == &cin)
	{
		cout << "- Introduceti numarul matricol: ";
	}
	input >> numarMatricol;

	int optiuneProgramStudiu;
	if (&input == &cin)
	{
		cout << "- Introduceti genul persoanei (1-LICENTA  | 2-MASTER): ";
	}
	input >> optiuneProgramStudiu;
	switch (optiuneProgramStudiu)
	{
	case 1:
		programStudiu = PROGRAM_STUDIU::LICENTA;
		break;
	case 2:
		programStudiu = PROGRAM_STUDIU::MASTER;
		break;
	default:
		programStudiu = PROGRAM_STUDIU::NESPECIFICAT;
		break;
	}
	input.ignore(100, '\n');
}

void Student::Afisare(ostream& output)
{
	output << CYAN << "\n--------------------------------------------" << RESET;
	Persoana::Afisare(output);
	output <<CYAN<< "\n-> Numar matricol: \t" << numarMatricol;
	output << "\n-> Program studiu: \t";
	AfisareProgramStudiu(this, output);
	output << CYAN << "\n--------------------------------------------"<<RESET;
}

void Student::AfisareProgramStudiu(Student* student, ostream& output)
{
	if (student->programStudiu == PROGRAM_STUDIU::LICENTA)
	{
		output << "Licenta";
	}
	else if (student->programStudiu == PROGRAM_STUDIU::MASTER)
	{
		output << "Master";
	}
	else
	{
		output << "Nespecificat";
	}
}
Student& Student::operator=(const Student& sursa)
{
	Persoana::operator=(sursa);
	numarMatricol = sursa.numarMatricol;
	programStudiu = sursa.programStudiu;
	return *this;
}

istream& operator>>(istream& input, Student& student)
{
	if (&input == &cin)
	{
		cout << "\n___________ Citire Student ___________\n";
	}

	student.Persoana::Citire(input);
	if (&input == &cin)
	{
		cout << "- Introduceti numarul matricol: ";
	}
	input >> student.numarMatricol;

	int optiuneProgramStudiu;
	if (&input == &cin)
	{
		cout << "- Introduceti genul persoanei (1-LICENTA  | 2-MASTER): ";
	}
	input >> optiuneProgramStudiu;
	switch (optiuneProgramStudiu)
	{
	case 1:
		student.programStudiu = PROGRAM_STUDIU::LICENTA;
		break;
	case 2:
		student.programStudiu = PROGRAM_STUDIU::MASTER;
		break;
	default:
		student.programStudiu = PROGRAM_STUDIU::NESPECIFICAT;
		break;
	}
	return input;
}

ostream& operator<<(ostream& output, Student& student)
{
	output << CYAN << "\n--------------------------------------------" << RESET;
	student.Persoana::Afisare(output);
	output << CYAN << "\n-> Numar matricol: \t" << student.numarMatricol;
	output << "\n-> Program studiu: \t";
	student.Student::AfisareProgramStudiu(&student,output);
	output << CYAN << "\n--------------------------------------------" << RESET;
	return output;
}