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

	readSCLIns(fp);
	fclose(fp);
}

void readSCLIns(FILE*& fp)
{


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
