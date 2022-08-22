#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct ECLHeader
{
	int enm;
	int* enmSub;
	ECLHeader(int enemy)
	{
		enm = enemy;
		enmSub = new int[enm];
	}
};

inline int32_t EconvCharInt(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4) {
	return c4 << 24 | c3 << 16 | c2 << 8 | c1;
}

static void EclCmd0(char* buffer, int& lv);
static void EclCmd1(char* buffer, int& lv);
static void EclCmd2(char* buffer, int& lv);
static void EclCmd45(char* buffer, int& lv);
static void EclCmd67(char* buffer, int& lv);
static void EclCmd8(char* buffer, int& lv);
static void EclCmd9(char* buffer, int& lv);
static void EclCmdA(char* buffer, int& lv);
static void EclCmdB(char* buffer, int& lv);