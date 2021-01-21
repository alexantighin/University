#include <iostream>
#include "Functii.h"

char* CopiereText(char* sursa)
{
	char* destinatie;

	if (sursa != nullptr)
	{
		destinatie = new char[strlen(sursa) + 1];
		strcpy_s(destinatie, strlen(sursa) + 1, sursa);
	}
	else
	{
		destinatie = nullptr;
	}
	return destinatie;
}

char* CopiereText(const char* sursa)
{
	char* destinatie;

	if (sursa != nullptr)
	{
		destinatie = new char[strlen(sursa) + 1];
		strcpy_s(destinatie, strlen(sursa) + 1, sursa);
	}
	else
	{
		destinatie = nullptr;
	}
	return destinatie;
}