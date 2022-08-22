#include "asm_like.h"


static void SCLDecode(char* buffer, long lSize)
{
	int lv = 0, iter = 0;

	int dw[4];
	short int w[4];
	char b[4];
	char strname[256];


	char instname[256];
	char * getName;
	while (lv < lSize)
	{
		unsigned char pos = buffer[lv];
		bool isIns = (pos >= 0x00 && pos <= 0x16);

		if(isIns)
			printf("	");
		iter = 0;
		switch (uChar(buffer[lv]))
		{ 
		case 0x00:
			dw[0] = convCharUInt(buffer[lv + 1], buffer[lv + 2], buffer[lv + 3], buffer[lv + 4]);
			printf("TIME %d\n", dw[0]);
			lv += 0x5;	break;
		case 0x01:
			w[0] = convCharUInt(buffer[lv + 1], buffer[lv + 2]);
			w[1] = convCharUInt(buffer[lv + 3], buffer[lv + 4]);
			b[0] = buffer[lv + 5];
			printf("ENEMY %d, %d, %d\n", w[0], w[1], b[0]);
			lv += 0x6;	break;
		case 0x02:
			w[0] = convCharUInt(buffer[lv + 1], buffer[lv + 2]);
			printf("SSP %d\n", w[0]);
			lv += 0x3;	break;
		case 0x03:
			b[0] = buffer[lv + 1];
			printf("EFC %d\n", b[0]);
			lv += 0x2;	break;
		case 0x04:
			printf("END\n");
			lv++;	break;
		case 0x05:
			w[0] = convCharUInt(buffer[lv + 1], buffer[lv + 2]);
			w[1] = convCharUInt(buffer[lv + 3], buffer[lv + 4]);
			b[0] = buffer[lv + 5];
			printf("BOSS %d, %d, %d\n", w[0], w[1], b[0]);
			lv += 0x6;	break;
		case 0x06:
			printf("MWOPEN\n");
			lv++;	break;
		case 0x07:
			printf("MWCLOSE\n");
			lv++;	break;
		case 0x08:
			lv++;
			getString(buffer, lv, iter, strname);
			printf("MSG \"%s\"\n", strname);
			lv += 0x1 + iter;	break;
		case 0x0a:
			printf("NPG\n");
			lv++; break;
		case 0xb:
			b[0] = buffer[lv + 1];
			printf("FACE %d\n", b[0]);
			lv += 0x2;	break;
		case 0xc:
			b[0] = buffer[lv + 1];
			printf("MUSIC %d\n", b[0]);
			lv += 0x2;	break;
		case 0x0d:
			printf("BOSSDEAD\n");
			lv++; break;
		case 0xe:
			b[0] = buffer[lv + 1];
			b[1] = buffer[lv + 2];
			printf("LOADFACE %d, %d\n", b[0], b[1]);
			lv += 0x3;	break;
		case 0xf:
			printf("WAITEX\n");
			lv++;	break;
		case 0x10:
			printf("STAGECLEAR\n");
			lv++;	break;
		case 0x11:
			printf("MAPPALETTE\n");
			lv++;	break;
		case 0x12:
			printf("GAMECLEAR\n");
			lv++;	break;
		case 0x13:
			printf("DELENEMY\n");
			lv++;	break;
		case 0x14:
			w[0] = convCharUInt(buffer[lv + 1], buffer[lv + 2]);
			w[1] = convCharUInt(buffer[lv + 3], buffer[lv + 4]);
			w[2] = convCharUInt(buffer[lv + 5], buffer[lv + 6]);
			printf("ENEMYPALETTE %d, %d, %d\n", w[0], w[1], w[2]);
			lv += 0x7;	break;
		case 0x15:
			printf("STAFF %d\n", uChar(buffer[lv + 1]));
			lv += 0x2; break;
		case 0x16:
			printf("EXTRACLEAR\n");
			lv++; break;
		default:
			if (lv < lSize - 1)
			{
				lv++;	
			}
			break;
		}
#ifdef CLB_DEBUG
		//printf("buffer pos: 0x%x\n\n", lv);
		//if (!isIns)
		//{
		//	//printf("Espacio vacío\n");
		//}
#endif // CLB_DEBUG
	}
}



