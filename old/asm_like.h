#include <stdio.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


inline int32_t convCharInt(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4) {
	return c4 << 24 | c3 << 16 | c2 << 8 | c1;
}

inline int16_t convCharInt(uint8_t c1, uint8_t c2) {
	return c2 << 8 | c1;
}

inline uint32_t convCharUInt(uint8_t c1, uint8_t c2, uint8_t c3, uint8_t c4) {
	return c4 << 24 | c3 << 16 | c2 << 8 | c1;
}

inline uint16_t convCharUInt(uint8_t c1, uint8_t c2) {
	return c2 << 8 | c1;
}

inline uint8_t uChar(uint8_t ch)
{
	return ch;
}

inline void getString(char* buffer, int& lv, int& iter, char* chars)
{
	int pos = lv;
	iter = 0;
	while (buffer[lv] != 0x00)
	{
		iter++;
		lv++;
	}
	lv = pos;
	for (int i = 0; i < iter; i++)
	{
		chars[i] = buffer[lv + i];
		chars[i + 1] = 0;
	}
}