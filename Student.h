#pragma once
#include "Persoana.h"

enum class PROGRAM_STUDIU
{
	NESPECIFICAT = 0,
	LICENTA = 1,
	MASTER = 2
};

class Student : public Persoana
{
private:
	int numarMatricol;
	PROGRAM_STUDIU programStudiu;
public:
	Student();
	Student(const char* nume, const char* prenume, Data dataNastere, GEN gen, const char* numeTata, const char* telefon, int numarMatricol, PROGRAM_STUDIU programStudiu);
	Student(const Student& sursa);
	~Student();

	int ReturneazaNumarMatricol();
	PROGRAM_STUDIU ReturneazaProgramStudiu();

	void Citire(istream& input);
	void Afisare(ostream& output);
	void AfisareProgramStudiu(Student* student, ostream& output);

	Student& operator=(const Student& sursa);
	friend istream& operator>>(istream& input, Student& student);
	friend ostream& operator<<(ostream& output, Student& student);
};