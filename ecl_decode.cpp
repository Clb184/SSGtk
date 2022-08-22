#include "ecl_decode.h"


static void ECLDecode(char* buffer, long lSize)
{
	int lv = 0;
	ECLHeader header(EconvCharInt(buffer[0], buffer[1], buffer[2], buffer[3]));
	lv += (header.enm + 1) * sizeof(int);


	
	while (lv < lSize)
	{
		unsigned char chara = buffer[lv];

		bool ins95 = (chara >= 0x90 && chara <= 0x9f);

			EclCmd0(buffer, lv);
			EclCmd1(buffer, lv);
			EclCmd2(buffer, lv);
			EclCmd45(buffer, lv);
			EclCmd67(buffer, lv);
			EclCmd8(buffer, lv);
			EclCmd9(buffer, lv);
			EclCmdA(buffer, lv);
			EclCmdB(buffer, lv);
			printf("\n");
	}
}


static void EclCmd0(char* buffer, int& lv)
{
	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0x00:
		printf("SETUP"); lv += 0x9;
		break;
	case 0x01:
		printf("END"); lv++;
		break;
	case 0x02:
		printf("JMP"); lv += 0x5;
		break;
	case 0x03:
		printf("LOOP"); lv += 0x7;
		break;
	case 0x04:
		printf("CALL"); lv += 0x5;
		break;
	case 0x05:
		printf("RET"); lv++;
		break;
	case 0x06:
		printf("JHPL"); lv += 0x9;
		break;
	case 0x07:
		printf("JHPS"); lv += 0x9;
		break;
	case 0x08:
		printf("JDIF"); lv += 0x11;
		break;
	case 0x09:
		printf("JDSB"); lv += 0x5;
		break;
	case 0x0a:
		printf("JFCL"); lv += 0x9;
		break;
	case 0x0b:
		printf("JFCS"); lv += 0x9;
		break;
	case 0x0c:
		printf("STI"); lv += 0xa;
		break;
	case 0x0d:
		printf("CLI"); lv += 0x2;
		break;
	default:
		break;
	}
}
static void EclCmd1(char* buffer, int& lv)
{

	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0x10:
		printf("NOP"); lv += 0x3;
		break;
	case 0x11:
		printf("NOPSC"); lv += 0x3;
		break;
	case 0x12:
		printf("MOV"); lv += 0x3;
		break;
	case 0x13:
		printf("ROL"); lv += 0x4;
		break;
	case 0x14:
		printf("LROL"); lv += 0xc;
		break;
	case 0x15:
		printf("WAVX"); lv += 0x9;
		break;
	case 0x16:
		printf("WAVY"); lv += 0x9;
		break;
	case 0x17:
		printf("MXA"); lv += 0x5;
		break;
	case 0x18:
		printf("MYA"); lv += 0x5;
		break;
	case 0x19:
		printf("MXYA"); lv += 0x7;
		break;
	case 0x1a:
		printf("MXS"); lv += 0x3;
		break;
	case 0x1b:
		printf("MYS"); lv += 0x3;
		break;
	case 0x1c:
		printf("MXYS"); lv += 0x3;
		break;
	case 0x1d:
		printf("ACC"); lv += 0x4;
		break;
	case 0x1e:
		printf("ACCXYA"); lv += 0x7;
		break;
	case 0x1f:
		printf("GRAX"); lv += 0x2;
		break;
	default:
		break;
	}
}
static void EclCmd2(char* buffer, int& lv)
{

	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0x20:
		printf("DEGA"); lv += 0x2;
		break;
	case 0x21:
		printf("DEGR"); lv += 0x2;
		break;
	case 0x22:
		printf("DEGX"); lv++;
		break;
	case 0x23:
		printf("DEGS"); lv++;
		break;
	case 0x24:
		printf("SPDA"); lv += 0x5;
		break;
	case 0x25:
		printf("SPDR"); lv += 0x5;
		break;
	case 0x26:
		printf("XYA"); lv += 0x5;
		break;
	case 0x27:
		printf("XYR"); lv += 0x5;
		break;
	case 0x28:
		printf("DEGXU"); lv++;
		break;
	case 0x29:
		printf("DEGXD"); lv++;
		break;
	case 0x2a:
		printf("DEGEX"); lv++;
		break;
	case 0x2b:
		printf("XYS"); lv++;
		break;
	case 0x2c:
		printf("DEGX2"); lv++;
		break;
	case 0x2d:
		printf("XYRND"); lv++;
		break;
	case 0x2e:
		printf("XYL"); lv += 0x3;
		break;
	default:
		break;
	}
}
static void EclCmd45(char* buffer, int& lv)
{

	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0x40:
		printf("TAMA"); lv++;
		break;
	case 0x41:
		printf("TAUTO"); lv += 0x2;
		break;
	case 0x42:
		printf("TXYR"); lv += 0x5;
		break;
	case 0x43:
		printf("TCMD"); lv += 0x2;
		break;
	case 0x44:
		printf("TDEGA"); lv += 0x3;
		break;
	case 0x45:
		printf("TDEGR"); lv += 0x3;
		break;
	case 0x46:
		printf("TNUMA"); lv += 0x3;
		break;
	case 0x47:
		printf("TNUMR"); lv += 0x3;
		break;
	case 0x48:
		printf("TSPDA"); lv += 0x3;
		break;
	case 0x49:
		printf("TSPDR"); lv += 0x3;
		break;
	case 0x4a:
		printf("TOPT"); lv += 0x2;
		break;
	case 0x4b:
		printf("TTYPE"); lv += 0x2;
		break;
	case 0x4c:
		printf("TCOL"); lv += 0x2;
		break;
	case 0x4d:
		printf("TVDEG"); lv += 0x2;
		break;
	case 0x4e:
		printf("TREP"); lv += 0x2;
		break;
	case 0x4f:
		printf("TDEGS"); lv++;
		break;
	case 0x50:
		printf("TDEGE"); lv++;
		break;
	case 0x51:
		printf("TAMA2"); lv++;
		break;
	case 0x52:
		printf("TCLR"); lv++;
		break;
	case 0x53:
		printf("TAMAL"); lv++;
		break;
	case 0x54:
		printf("T2ITEM"); lv += 0x2;
		break;
	case 0x55:
		printf("TAMAEX"); lv++;
		break;
	default:
		break;
	}
}
static void EclCmd67(char* buffer, int& lv)
{

	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0x60:
		printf("LASER"); lv++;
		break;
	case 0x61:
		printf("LCMD"); lv += 0x2;
		break;
	case 0x62:
		printf("LLA"); lv += 0x5;
		break;
	case 0x63:
		printf("LLR"); lv += 0x5;
		break;
	case 0x64:
		printf("LL2"); lv += 0x5;
		break;
	case 0x65:
		printf("LDEGA"); lv += 0x3;
		break;
	case 0x66:
		printf("LDEGR"); lv += 0x3;
		break;
	case 0x67:
		printf("LNUMA"); lv += 0x2;
		break;
	case 0x68:
		printf("LNUMR"); lv += 0x2;
		break;
	case 0x69:
		printf("LSPDA"); lv += 0x5;
		break;
	case 0x6a:
		printf("LSPDR"); lv += 0x5;
		break;
	case 0x6b:
		printf("LCOL"); lv += 0x2;
		break;
	case 0x6c:
		printf("LTYPE"); lv += 0x2;
		break;
	case 0x6d:
		printf("LWA"); lv += 0x5;
		break;
	case 0x6e:
		printf("LDEGS"); lv++;
		break;
	case 0x6f:
		printf("LDEGE"); lv++;
		break;
	case 0x70:
		printf("LXY"); lv += 0x5;
		break;
	case 0x71:
		printf("LASER2"); lv++;
		break;
	default:
		break;
	}
}
static void EclCmd8(char* buffer, int& lv)
{

	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0x80:
		printf("LLSET"); lv++;
		break;
	case 0x81:
		printf("LLOPEN"); lv += 0x2;
		break;
	case 0x82:
		printf("LLCLOSE"); lv += 0x2;
		break;
	case 0x83:
		printf("LLCLOSEL"); lv += 0x2;
		break;
	case 0x84:
		printf("LLDEGR"); lv += 0x3;
		break;
	case 0x85:
		printf("HLASER"); lv++;
		break;
	default:
		break;
	}
}
static void EclCmd9(char* buffer, int& lv)
{
	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0x90:
		printf("DRAW_ON"); lv++;
		break;
	case 0x91:
		printf("DRAW_OFF"); lv++;
		break;
	case 0x92:
		printf("CLIP_ON"); lv++;
		break;
	case 0x93:
		printf("CLIP_OFF"); lv++;
		break;
	case 0x94:
		printf("DAMAGE_ON"); lv++;
		break;
	case 0x95:
		printf("DAMAGE_OFF"); lv++;
		break;
	case 0x96:
		printf("HITSB_ON"); lv++;
		break;
	case 0x97:
		printf("HITSB_OFF"); lv++;
		break;
	case 0x98:
		printf("RLCHG_ON"); lv++;
		break;
	case 0x99:
		printf("RLCHG_OFF"); lv++;
		break;
	default:
		break;
	}
}
static void EclCmdA(char* buffer, int& lv)
{

	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0xa0:
		printf("ANM"); lv += 0x3;
		break;
	case 0xa1:
		printf("PSE"); lv += 0x2;
		break;
	case 0xa2:
		printf("INT"); lv += 0x2;
		break;
	case 0xa3:
		printf("EXDEGD"); lv += 0x2;
		break;
	case 0xa4:
		printf("ENEMYSET"); lv += 0x6;
		break;
	case 0xa5:
		printf("ENEMYSETD"); lv += 0x7;
		break;
	case 0xa6:
		printf("HITXY"); lv += 0x5;
		break;
	case 0xa7:
		printf("ITEM"); lv += 0x2;
		break;
	case 0xa8:
		printf("STG4EFC"); lv += 0x2;
		break;
	case 0xa9:
		printf("ANMEX"); lv += 0x2;
		break;
	case 0xaa:
		printf("BITLASER"); lv += 0x2;
		break;
	case 0xab:
		printf("BITATTACK"); lv += 0x5;
		break;
	case 0xac:
		printf("BITCMD"); lv += 0x6;
		break;
	case 0xad:
		printf("BOSSSET"); lv += 0x2;
		break;
	case 0xae:
		printf("CEFC"); lv += 0x6;
		break;
	case 0xaf:
		printf("STG3EFC"); lv += 0x1;
		break;
	default:
		break;
	}
}
static void EclCmdB(char* buffer, int& lv)
{

	unsigned char chara = buffer[lv];
	switch (chara)
	{
	case 0xb0:
		printf("MOVR"); lv += 0x3;
		break;
	case 0xb1:
		printf("MOVC"); lv += 0x6;
		break;
	case 0xb2:
		printf("ADD"); lv += 0x3;
		break;
	case 0xb3:
		printf("SUB"); lv += 0x3;
		break;
	case 0xb4:
		printf("SINL"); lv += 0x3;
		break;
	case 0xb5:
		printf("COSL"); lv += 0x3;
		break;
	case 0xb6:
		printf("MOD"); lv += 0x6;
		break;
	case 0xb7:
		printf("RND"); lv += 0x2;
		break;
	case 0xb8:
		printf("CMPR"); lv += 0x3;
		break;
	case 0xb9:
		printf("CMPC"); lv += 0x6;
		break;
	case 0xba:
		printf("JL"); lv += 0x5;
		break;
	case 0xbb:
		printf("JS"); lv += 0x5;
		break;
	case 0xbc:
		printf("INC"); lv += 0x2;
		break;
	case 0xbd:
		printf("DEC"); lv += 0x2;
		break;
	case 0xbe:
		printf("JEQ"); lv += 0x5;
		break;
	default:
		break;
	}
}