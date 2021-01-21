#pragma once
#include <iostream>
#include "Student.h"
#include "Profesor.h"

enum class TIP_PERSOANA
{
	STUDENT = 1,
	PROFESOR = 2
};

class PersoaneUniversitate
{
private:
	Profesor* profesoriUniversitate;
	Student* studentiUniversitate;
	static int numarProfesori;
	static int numarStudenti;
public:
	PersoaneUniversitate();
	PersoaneUniversitate(int numarProfesori, istream& inputProfesori, int numarStudenti, istream& inputStudenti);

	void AdaugareProfesor(istream& input);
	void AfisareProfesori(ostream& output);
	void AfisareDateProfesor(int nrProfesor, ostream& output);
	void AfisareDateProfesori(ostream& output);	
	void StergereProfesor(int nrProfesor, ostream& output);

	void AdaugareStudent(istream& input);
	void AfisareStudenti(ostream& output);
	void AfisareDateStudent(int nrStudent, ostream& output);
	void AfisareDateStudenti(ostream& output);
	void StergereStudent(int nrStudent, ostream& output);

	PersoaneUniversitate& operator=(const PersoaneUniversitate& sursa);
};