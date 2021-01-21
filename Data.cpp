#include "Data.h"

Data::Data()
{
	zi = 0;
	luna = 0;
	an = 0;
}

Data::Data(int zi, int luna, int an)
{
	this->zi = zi;
	this->luna = luna;
	this->an = an;
}

Data::Data(const Data& sursa)
{
	zi = sursa.zi;
	luna = sursa.luna;
	an = sursa.an;
}

Data::~Data()
{
	zi = NULL;
	luna = NULL;
	an = NULL;
}

int Data::ReturneazaZi()
{
	return zi;
}

int Data::ReturneazaLuna()
{
	return luna;
}

int Data::RetunreazaAn()
{
	return an;
}

void Data::CitireConsola()
{
	cout << "\t- Introduceti ziua: ";
	cin >> zi;
	cout << "\t- Introduceti luna: ";
	cin >> luna;
	cout << "\t- Introduceti anul: ";
	cin >> an;
}

void Data::AfisareConsola()
{
	cout << zi << "." << luna << "." << an;
}

Data& Data::operator=(const Data& sursa)
{
	zi = sursa.zi;
	luna = sursa.luna;
	an = sursa.an;
	return *this;
}

istream& operator>>(istream& input, Data& data)
{
	if (&input == &cin)
	{
		cout << "\t- Introduceti ziua: ";
	}	
	input >> data.zi;
	if (&input == &cin)
	{
		cout << "\t- Introduceti luna: ";
	}
	input >> data.luna;
	if (&input == &cin)
	{
		cout << "\t- Introduceti anul: ";
	}
	input >> data.an;
	return input;
}

ostream& operator<<(ostream& output, Data& data)
{
	output << data.zi << "." << data.luna << "." << data.an;
	return output;
}