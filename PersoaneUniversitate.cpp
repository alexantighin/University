#include "PersoaneUniversitate.h"

#define RESET   "\033[0m"
#define RED     "\033[31m"

int PersoaneUniversitate::numarProfesori = 0;
int PersoaneUniversitate::numarStudenti = 0;

PersoaneUniversitate::PersoaneUniversitate()
{
	profesoriUniversitate = nullptr;
	studentiUniversitate = nullptr;
}

PersoaneUniversitate::PersoaneUniversitate(int numarProfesori, istream& inputProfesori, int numarStudenti, istream& inputStudenti)
{
	for (int i = 0; i < numarProfesori; i++)
	{
		AdaugareProfesor(inputProfesori);
	}
	for (int i = 0; i < numarStudenti; i++)
	{
		AdaugareStudent(inputStudenti);
	}
}

PersoaneUniversitate& PersoaneUniversitate::operator=(const PersoaneUniversitate& sursa)
{
	numarProfesori = sursa.numarProfesori;
	numarStudenti = sursa.numarStudenti;
	profesoriUniversitate = new Profesor[sursa.numarProfesori];
	studentiUniversitate = new Student[sursa.numarStudenti];

	for (int i = 0; i < numarProfesori; i++)
	{
		profesoriUniversitate[i] = sursa.profesoriUniversitate[i];
	}
	for (int i = 0; i < numarStudenti; i++)
	{
		studentiUniversitate[i] = sursa.studentiUniversitate[i];
	}
	return *this;
}


/* Profesori */
void PersoaneUniversitate::AdaugareProfesor(istream& input)
{
	numarProfesori++;
	if (numarProfesori -1== 0)
	{
		profesoriUniversitate = new Profesor[numarProfesori];
	}
	else
	{
		Profesor* tempProfesoriUniversitate = new Profesor[numarProfesori - 1];
		for (int i = 0; i < numarProfesori - 1; i++)
		{
			tempProfesoriUniversitate[i] = profesoriUniversitate[i];
		}

		profesoriUniversitate = new Profesor[numarProfesori + 1];
		for (int i = 0; i < (numarProfesori - 1); i++)
		{
			profesoriUniversitate[i] = tempProfesoriUniversitate[i];
		}

		if (tempProfesoriUniversitate != nullptr)
		{
			delete[] tempProfesoriUniversitate;
		}
	}	
	profesoriUniversitate[numarProfesori-1].Citire(input);
}

void PersoaneUniversitate::AfisareProfesori(ostream& output)
{
	if (numarProfesori != 0)
	{
		output << "\n\n\n------------- Lista de profesori (" << numarProfesori << ") -------------";
		for (int i = 1; i <= numarProfesori; i++)
		{
			output << endl << i << ".\t" << profesoriUniversitate[i - 1].ReturneazaNume() << " " << profesoriUniversitate[i - 1].ReturneazaPrenume();
		}
	}
	else
	{
		output << RED << "\nNu exista profesori!" << RESET;
	}
}

void PersoaneUniversitate::AfisareDateProfesori(ostream& output)
{
	if (numarProfesori != 0)
	{
		for (int i = 1; i <= numarProfesori; i++)
		{
			AfisareDateProfesor(i, output);
		}
	}
	else
	{
		output << RED << "\nNu exista profesori!" << RESET;
	}	
}

void PersoaneUniversitate::AfisareDateProfesor(int nrProfesor, ostream& output)
{
	if (numarProfesori != 0)
	{
		if (nrProfesor != 0 && nrProfesor<=numarProfesori)
		{
			profesoriUniversitate[nrProfesor - 1].Afisare(output);
		}
		else
		{
			output << RED << "\nNu exista profesorul cu numarul "<<nrProfesor<<"!"<<RESET;
		}
	}
	else
	{
		output <<RED<< "\nNu exista profesori!"<<RESET;
	}
}

void PersoaneUniversitate::StergereProfesor(int nrProfesor, ostream& output)
{
	if (numarProfesori != 0)
	{
		if (nrProfesor != 0 && nrProfesor<=numarProfesori)
		{
			Profesor* tempProfesoriUniversitate = new Profesor[numarProfesori];
			for (int i = 0; i < numarProfesori; i++)
			{
				tempProfesoriUniversitate[i] = profesoriUniversitate[i];
			}

			delete[] profesoriUniversitate;

			profesoriUniversitate = new Profesor[numarProfesori-1];
			for (int i = 0; i < (numarProfesori - 1); i++)
			{
				if (i >= (nrProfesor - 1))
				{
					profesoriUniversitate[i] = tempProfesoriUniversitate[i+1];
				}
				else
				{
						profesoriUniversitate[i] = tempProfesoriUniversitate[i];
					
				}				
			}
			if (tempProfesoriUniversitate != nullptr)
			{
				delete[] tempProfesoriUniversitate;
			}
			numarProfesori--;
		}
		else
		{
			output << RED << "\nNu exista profesorul cu numarul" << nrProfesor << "!" << RESET;
		}
	}
	else
	{
		output << RED << "\nNu exista profesori!" << RESET;
	}
}



/* Studenti */
void PersoaneUniversitate::AdaugareStudent(istream& input)
{
	numarStudenti++;
	if (numarStudenti - 1 == 0)
	{
		studentiUniversitate = new Student[numarStudenti];
	}
	else
	{
		Student* tempstudentiUniversitate = new Student[numarStudenti - 1];
		for (int i = 0; i < numarStudenti - 1; i++)
		{
			tempstudentiUniversitate[i] = studentiUniversitate[i];
		}

		studentiUniversitate = new Student[numarStudenti + 1];
		for (int i = 0; i < (numarStudenti - 1); i++)
		{
			studentiUniversitate[i] = tempstudentiUniversitate[i];
		}

		if (tempstudentiUniversitate != nullptr)
		{
			delete[] tempstudentiUniversitate;
		}
	}
	studentiUniversitate[numarStudenti - 1].Citire(input);
}

void PersoaneUniversitate::AfisareStudenti(ostream& output)
{
	if (numarStudenti != 0)
	{
		output << "\n\n\n------------- Lista de studenti (" << numarStudenti << ") -------------";
		for (int i = 1; i <= numarStudenti; i++)
		{
			output << endl << i << ".\t" << studentiUniversitate[i - 1].ReturneazaNume() << " " << studentiUniversitate[i - 1].ReturneazaPrenume();
		}
	}
	else
	{
		output << RED << "\nNu exista studenti!" << RESET;
	}
}

void PersoaneUniversitate::AfisareDateStudent(int nrStudent, ostream& output)
{
	if (numarStudenti != 0)
	{
		if (nrStudent != 0 && nrStudent<=numarStudenti)
		{
			studentiUniversitate[nrStudent - 1].Afisare(output);
		}
		else
		{
			output << RED << "\nNu exista studentul cu numarul " << nrStudent << "!" << RESET;
		}
	}
	else
	{
		output << RED << "\nNu exista studenti!" << RESET;
	}
}

void PersoaneUniversitate::AfisareDateStudenti(ostream& output)
{
	if (numarStudenti != 0)
	{
		for (int i = 1; i <= numarStudenti; i++)
		{
			AfisareDateStudent(i, output);
		}
	}
	else
	{
		output << RED << "\nNu exista studenti!" << RESET;
	}	
}

void PersoaneUniversitate::StergereStudent(int nrStudent, ostream& output)
{
	if (numarStudenti != 0)
	{
		if (nrStudent != 0 && nrStudent <= numarStudenti)
		{
			Student* tempStudentiUniversitate = new Student[numarStudenti];
			for (int i = 0; i < numarStudenti; i++)
			{
				tempStudentiUniversitate[i] = studentiUniversitate[i];
			}

			delete[] studentiUniversitate;

			studentiUniversitate = new Student[numarStudenti - 1];
			for (int i = 0; i < (numarStudenti - 1); i++)
			{
				if (i >= (nrStudent - 1))
				{
					studentiUniversitate[i] = tempStudentiUniversitate[i + 1];
				}
				else
				{
					studentiUniversitate[i] = tempStudentiUniversitate[i];
				}
			}
			if (tempStudentiUniversitate != nullptr)
			{
				delete[] tempStudentiUniversitate;
			}
			numarStudenti--;
		}
		else
		{
			output << RED << "\nNu exista studentul cu numarul" << nrStudent << "!" << RESET;
		}
	}
	else
	{
		output << RED << "\nNu exista studenti!" << RESET;
	}
}