#pragma once

#include <stdio.h>
#include <iostream>
#include <map>

//#include "scl_decode.h"
//#include "ecl_decode.h"


#define CH rC(fp, 0, true);
#define W rC(fp, 0b1, true);
#define DW rC(fp, 0b10, true);

#define B rC(fp, 0b0, false);
#define UW rC(fp, 0b1, false);
#define UDW rC(fp, 0b10, false);

#define STR rStr(fp);
#define CO printf(", ");

typedef uint64_t QWORD;
typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef uint8_t BYTE;

typedef std::map<uint8_t, std::string> InsMap;
typedef std::map <uint32_t, uint32_t> ADDRESS;

//void aC(FILE*& fp, uint8_t s);
void rC(FILE*& fp, uint8_t s, bool);
void rAdd(FILE*& fp, ADDRESS&);
void rStr(FILE*& fp);


static InsMap SCLIns =
{
	{0x00, "TIME"},
	{0x01, "ENEMY"},
	{0x02, "SSP"},
	{0x03, "EFC"},
	{0x04, "END"},
	{0x05, "BOSS"},
	{0x06, "MWOPEN"},
	{0x07, "MWCLOSE"},
	{0x08, "MSG"},
	{0x09, "KEY"},
	{0x0a, "NPG"},
	{0x0b, "FACE"},
	{0x0c, "MUSIC"},
	{0x0d, "BOSSDEAD"},
	{0x0e, "LOADFACE"},
	{0x0f, "WAITEX"},
	{0x10, "STAGECLEAR"},
	{0x11, "MAPPALETTE"},
	{0x12, "GAMECLEAR"},
	{0x13, "DELENEMY"},
	{0x14, "ENEMYPALETTE"},
	{0x15, "STAFF"},
	{0x16, "EXTRACLEAR"}
};

static InsMap ECLIns =
{
	//
	{0x00, "SETUP"},
	{0x01, "END"},
	{0x02, "JMP"},
	{0x03, "LOOP"},
	{0x04, "CALL"},
	{0x05, "RET"},
	{0x06, "JHPL"},
	{0x07, "JHPS"},
	{0x08, "JDIF"},
	{0x09, "JDSB"},
	{0x0A, "JFCL"},
	{0x0B, "JFCS"},
	{0x0C, "STI"},
	{0x0D, "CLI"},
//

	{0x10, "NOP"},
	{0x11, "NOPSC"},
	{0x12, "MOV"},
	{0x13, "ROL"},
	{0x14, "LROL"},
	{0x15, "WAVX"},
	{0x16, "WAVY"},
	{0x17, "MXA"},
	{0x18, "MYA"},
	{0x19, "MXYA"},
	{0x1A, "MXS"},
	{0x1B, "MYS"},
	{0x1C, "MXYS"},
	{0x1D, "ACC"},
	{0x1E, "ACCXYA"},
	{0x1F, "GRAX"},
//
	{0x20, "DEGA"},
	{0x21, "DEGR"},
	{0x22, "DEGX"},
	{0x23, "DEGS"},
	{0x24, "SPDA"},
	{0x25, "SPDR"},
	{0x26, "XYA"},
	{0x27, "XYR"},
	{0x28, "DEGXU"},
	{0x29, "DEGXD"},
	{0x2A, "DEGEX"},
	{0x2B, "XYS"},
	{0x2C, "DEGX2"},
	{0x2D, "XYRND"},
	{0x2E, "XYL"},
//
	{0x40, "TAMA"},
	{0x41, "TAUTO"},
	{0x42, "XYR"},
	{0x43, "TCMD"},
	{0x44, "TDEGA"},
	{0x45, "TDEGR"},
	{0x46, "TNUMA"},
	{0x47, "TNUMR"},
	{0x48, "TSPDA"},
	{0x49, "SPDR"},
	{0x4A, "TOPT"},
	{0x4B, "TTYPE"},
	{0x4C, "TCOL"},
	{0x4D, "TVDEG"},
	{0x4E, "TREP"},
	{0x4F, "TDEGS"},
	{0x50, "TDEGE"},
	{0x51, "TAMA2"},
	{0x52, "TCLR"},
	{0x53, "TAMAL"},
	{0x54, "TT2ITEM"},
	{0x55, "TAMAEX"},
//

	{0x60, "LASER"},
	{0x61, "LCMD"},
	{0x62, "LLA"},
	{0x63, "LLR"},
	{0x64, "LL2"},
	{0x65, "LDEGA"},
	{0x66, "LDEGR"},
	{0x67, "LNUMA"},
	{0x68, "LNUMR"},
	{0x69, "LSPDA"},
	{0x6A, "LSPDR"},
	{0x6B, "LCOL"},
	{0x6C, "LTYPE"},
	{0x6D, "LWA"},
	{0x6E, "LDEGS"},
	{0x6F, "LDEGE"},
	{0x70, "LXY"},
	{0x71, "LASER2"},
//
	{0x80, "LLSET"},
	{0x81, "LLOPEN"},
	{0x82, "LLCLOSE"},
	{0x83, "LLCLOSEL"},
	{0x84, "LLDEGR"},
	{0x85, "HLASER"},
//

	{0x90, "DRAW_ON" },
	{0x91, "DRAW_OFF" },
	{0x92, "CLIP_ON" },
	{0x93, "CLIP_OFF" },
	{0x94, "DAMAGE_ON" },
	{0x95, "DAMAGE_OFF" },
	{0x96, "HITSB_ON" },
	{0x97, "HITSB_OFF" },
	{0x98, "RLCHG_ON" },
	{0x99, "RLCHG_OFF" },
//

	{0xA0, "ANM" },
	{0xA1, "PSE" },
	{0xA2, "INT" },
	{0xA3, "EXDEGD" },
	{0xA4, "ENEMYSET" },
	{0xA5, "ENEMYSETD" },
	{0xA6, "HITXY" },
	{0xA7, "ITEM" },
	{0xA8, "STG4EFC" },
	{0xA9, "ANMEX" },
	{0xAA, "BITLASER" },
	{0xAB, "BITATTACK" },
	{0xAC, "BITCMD" },
	{0xAD, "BOSSSET" },
	{0xAE, "CEFC" },
	{0xAF, "STG3EFC" },
//

	{0xB0, "MOVR" },
	{0xB1, "MOVC" },
	{0xB2, "ADD" },
	{0xB3, "SUB" },
	{0xB4, "SINL" },
	{0xB5, "COSL" },
	{0xB6, "MOD" },
	{0xB7, "RND" },
	{0xB8, "CMPR" },
	{0xB9, "CMPC" },
	{0xBA, "JL" },
	{0xBB, "JS" },
	{0xBC, "INC" },
	{0xBD, "DEC" },
	{0xBE, "JEQ" }
};