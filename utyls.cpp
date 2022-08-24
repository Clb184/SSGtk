#include "main_libs.h"


void rAdd(FILE*& fp, ADDRESS& add)
{
	
}
/*
void aC(FILE*& fp, uint8_t s)
{

	int var;
	switch (s)
	{
	case (0b0):
		fread(&var, 1, 1, fp);
		break;
	case (0b1):
		fread(&var, 2, 1, fp);
		break;
	case (0b10):
		fread(&var, 4, 1, fp);
		break;
	}
}*/

void rC(FILE*& fp, uint8_t s, bool sign)
{

	int var;
	switch (s)
	{
	case (0b0):
		fread(&var, 1, 1, fp);
		if (!sign)
			printf("%d", (uint8_t)var);
		else
			printf("%d", (int8_t)var);
		break;
	case (0b1):
		fread(&var, 2, 1, fp);
		if (!sign)
			printf("%d", (uint16_t)var);
		else
			printf("%d", (int16_t)var);
		break;
	case (0b10):
		fread(&var, 4, 1, fp);
		if (!sign)
			printf("%d", (uint32_t)var);
		else
			printf("%d", (int32_t)var);
		break;
	}
}

void rStr(FILE*& fp)
{
	std::string str;
	BYTE c;
	str.push_back('"');
	do
	{
		fread(&c, 1, 1, fp);
		if(c)
		str.push_back(c);
	} while (c);
	str.push_back('"');
	std::cout << str;
}

