#include "scl_decode.h"


void SCLDecode(const char* f)
{
	FILE* fp;
	fp = fopen(f, "rb");

	if (fp == NULL)
	{
		printf("An error ocurred while loading file.\n");
		exit(-1);
	}

	readIns(fp);
	fclose(fp);
}

void readIns(FILE*& fp)
{
#define CH rC(fp, 0, true);
#define W rC(fp, 0b1, true);
#define DW rC(fp, 0b10, true);

#define B rC(fp, 0b0, false);
#define UW rC(fp, 0b1, false);
#define UDW rC(fp, 0b11, false);

#define STR rStr(fp);
#define CO printf(", ");


	BYTE cmd;
	while (1)
	{
		fread(&cmd, 1, 1, fp);
		std::cout << "	" << SCLIns[cmd] << " ";
		switch (cmd)
		{
		case 0x00:
			DW	break;
		case 0x01:
			W CO W CO B break;
		case 0x02:
			W	break;
		case 0x03:
			B	break;
		case 0x04:
			return;  break;
		case 0x05:
			W CO W CO B break;
		case 0x08:
			STR break;
		case 0xb:
			B	break;
		case 0xc:
			B	break;
		case 0xe:
			B CO B break;
		case 0x14:
			UW CO UW CO UW break;
		case 0x15:
			B break;
		}
		printf("\n");
#ifdef CLB_DEBUG
		//printf("buffer pos: 0x%x\n\n", lv);
		//if (!isIns)
		//{
		//	//printf("Espacio vacío\n");
		//}
#endif // CLB_DEBUG
	}
}

void rC(FILE*& fp, uint8_t s, bool sign)
{

	int var;
	switch (s)
	{
	case (0b0):
		fread(&var, 1, 1, fp);
		if(!sign)
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
	do
	{
		fread(&c, 1, 1, fp);
		str.push_back(c);
	} while (c != 0x00);
	std::cout << str;
}

