#pragma once
#include <iostream>
using namespace std;

class Data
{
private:
	int zi, luna, an;
public:
	Data();
	Data(int zi, int luna, int an);
	Data(const Data& sursa);
	~Data();
	int ReturneazaZi();
	int ReturneazaLuna();
	int RetunreazaAn();
	void CitireConsola();
	void AfisareConsola();
	Data& operator=(const Data& sursa);
	friend istream& operator>>(istream& input, Data& data);
	friend ostream& operator<<(ostream& output, Data& data);
};