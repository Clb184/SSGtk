#include "main_libs.h"
void rC(FILE*& fp, uint8_t s, bool);
void rStr(FILE*& fp);
static std::map<uint8_t, std::string> SCLIns =
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

void SCLDecode(const char* f);
void readIns(FILE*& fp);
