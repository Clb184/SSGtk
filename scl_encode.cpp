#include "scl_encode.h"


void SCLEncode(const char* f1, const char* f2)
{
	FILE* in;
	FILE* out;
	in = fopen(f1, "r");

	if (in == NULL)
	{
		printf("An error ocurred while loading file.\n");
		exit(-1);
	}

	out = fopen(f2, "wb");
	parseSCLIns(in, out);
}


#define CH fscanf(in, "%d", &par); fwrite(&par, 1, 1, out);
#define W fscanf(in, "%d", &par); fwrite(&par, 2, 1, out);
#define DW fscanf(in, "%d", &par); fwrite(&par, 4, 1, out);

#define B fscanf(in, "%d", &upar); fwrite(&upar, 1, 1, out);
#define UW fscanf(in, "%d", &upar); fwrite(&upar, 2, 1, out);
#define UDW fscanf(in, "%d", &upar); fwrite(&upar, 4, 1, out);

#define STR getString(in, out);
#define CO fscanf(in, "%s", &par);

void parseSCLIns(FILE*& in, FILE*& out)
{
	BYTE cmd;
	int par = 0;
	DWORD upar = 0;
	while (!feof(in))
	{
		getSCLIns(cmd, in);
		fwrite(&cmd, 1, 1, out);
		switch (cmd)
		{
		case 0x00:
			UDW	break;
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
	}
}


#define CH rC(fp, 0, true);
#define W rC(fp, 0b1, true);
#define DW rC(fp, 0b10, true);

#define B rC(fp, 0b0, false);
#define UW rC(fp, 0b1, false);
#define UDW rC(fp, 0b10, false);

#define STR rStr(fp);
#define CO printf(", ");

void getSCLIns(uint8_t& cmd, FILE*& in)
{
	//
	
	//int p1, p2, p3;
	char line[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, comma;
	fscanf(in, "%s", line);
	
	std::string ins = line;
	for (InsMap::iterator it = SCLIns.begin(); it != SCLIns.end(); ++it)
	{
		if (it->second == ins)
		{
			cmd = it->first;

#ifdef CLB_DEBUG	
			std::cout << it->second;
#endif
			return;
		}
	}
	
}

void getString(FILE*& in, FILE*& out) 
{
	BYTE ch;
	std::string str;
	do{
		fread(&ch, 1, 1, in);
		if (!(ch == ' ' || ch == '"'))
		{
			printf("An error ocurred (MSG)...\n");
			exit(-1);
		}
	} while (ch != '"');
	do {

		fread(&ch, 1, 1, in);
		if (ch == '"')
		{
			fputs(str.c_str(), out);
			fputc(0x00, out);
		}
		else
		{
			str.push_back(ch);
		}
	} while (ch != '"');
}