#include "main_libs.h"

struct ECLHeader
{
	uint32_t enm;
	uint32_t* enmSub;
};

void ECLDecode(const char* f);

void getECLAddress(FILE*, ADDRESS&, ADDRESS&);
void getECLHeaderAdd(ECLHeader, ADDRESS&);
void readECLIns(FILE*& fp, ADDRESS, ADDRESS, uint32_t);