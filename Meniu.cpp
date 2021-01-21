#include "Meniu.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define CYAN    "\033[36m"
#define YELLOW  "\033[33m"
#define MAGENTA "\033[35m"

Meniu::Meniu(int numarProfesori, istream& inputProfesori, int numarStudenti, istream& inputStudenti)
{
	PersoaneUniversitate persoaneUniversitate(numarProfesori, inputProfesori, numarStudenti, inputStudenti);
	this->persoaneUniversitate = persoaneUniversitate;
}

void Meniu::AfisareMeniu()
{
	while (1)
	{		
		AfisareMeniuPrincipal();

		int selectieMeniuPrincipal;
		cin >> selectieMeniuPrincipal;

		switch (selectieMeniuPrincipal)
		{
		case 1:
			MeniuProfesori();
			break;
		case 2:
			MeniuStudenti();
			break;
		case 0:
			return;
			break;			
		default:
			cout <<RED<< "\t-> Optiunea introdusa nu este valida! Alege alta."<<RESET;
		}
	}
}

void Meniu::AfisareMeniuPrincipal()
{
	cout <<YELLOW<< "\n\n\t\t- MENIU PRINCIPAL - "<<RESET;
	cout << "\n\t_____________________________________";
	cout << "\n\t\t1. Meniu Profesori";
	cout << "\n\t\t2. Meniu Studenti";
	cout << "\n\t\t0. Inchide";
	cout << "\n\t_____________________________________";
	cout << "\n\tOptiunea dorita: ";
}

void Meniu::MeniuProfesori()
{
	while (1)
	{		
		AfisareMeniuProfesori();

		int selectieMeniu;
		cin >> selectieMeniu;
		switch (selectieMeniu)
		{
		case 1:
			persoaneUniversitate.AfisareProfesori(cout);
			break;
		case 2:
			persoaneUniversitate.AfisareDateProfesori(cout);
			break;
		case 3:
			cout << "\t\tIntroduceti numarul profesorului dorit: ";
			int nrProfesorAfisare;
			cin >> nrProfesorAfisare;
			persoaneUniversitate.AfisareDateProfesor(nrProfesorAfisare, cout);
			break;
		case 4:
			cin.ignore(100, '\n');
			persoaneUniversitate.AdaugareProfesor(cin);
			break;
		case 5:
			cout << "\t\tIntroduceti numarul profesorului dorit: ";
			int nrProfesorSters;
			cin >> nrProfesorSters;
			persoaneUniversitate.StergereProfesor(nrProfesorSters, cout);
			break;
		case 0:
			return;
			break;
		default:
			cout << RED << "\t\t-> Optiunea introdusa nu este valida! Alege alta." << RESET;
		}
	}
}

void Meniu::AfisareMeniuProfesori()
{
	cout <<MAGENTA<< "\n\n\t\t\t- MENIU PROFESORI - "<<RESET;
	cout << "\n\t\t_____________________________________";
	cout << "\n\t\t\t1. Afisare Profesori";
	cout << "\n\t\t\t2. Afisare Detalii Profesori (Toti)";
	cout << "\n\t\t\t3. Afisare Detalii Profesor";
	cout << "\n\t\t\t4. Adauga Profesor";
	cout << "\n\t\t\t5. Sterge Profesor";
	cout << "\n\t\t\t0. Inapoi";
	cout << "\n\t\t_____________________________________";
	cout << "\n\t\tOptiunea dorita: ";
}

void Meniu::MeniuStudenti()
{
	while (1)
	{		
		AfisareMeniuStudenti();

		int selectieMeniu;
		cin >> selectieMeniu;
		switch (selectieMeniu)
		{
		case 1:
			persoaneUniversitate.AfisareStudenti(cout);
			break;
		case 2:
			persoaneUniversitate.AfisareDateStudenti(cout);
			break;
		case 3:
			cout << "\t\tIntroduceti numarul profesorului dorit: ";
			int nrStudentAfisare;
			cin >> nrStudentAfisare;
			persoaneUniversitate.AfisareDateStudent(nrStudentAfisare, cout);
			break;
		case 4:
			cin.ignore(100, '\n');
			persoaneUniversitate.AdaugareStudent(cin);
			break;
		case 5:
			cout << "\t\tIntroduceti numarul profesorului dorit: ";
			int nrStudentSters;
			cin >> nrStudentSters;
			persoaneUniversitate.StergereStudent(nrStudentSters, cout);
			break;
		case 0:
			return;
			break;
		default:
			cout << RED << "\t\t-> Optiunea introdusa nu este valida! Alege alta." << RESET;
		}
	}
}

void Meniu::AfisareMeniuStudenti()
{
	cout <<CYAN<< "\n\n\t\t\t- MENIU STUDENTI - "<<RESET;
	cout << "\n\t\t_____________________________________";
	cout << "\n\t\t\t1. Afisare Studenti";
	cout << "\n\t\t\t2. Afisare Detalii Studenti (Toti)";
	cout << "\n\t\t\t3. Afisare Detalii Student";
	cout << "\n\t\t\t4. Adauga Student";
	cout << "\n\t\t\t5. Sterge Student";
	cout << "\n\t\t\t0. Inapoi";
	cout << "\n\t\t_____________________________________";
	cout << "\n\t\tOptiunea dorita: ";
}