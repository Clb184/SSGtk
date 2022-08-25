#include "main_libs.h"
#pragma once

void SCLEncode(const char* f1, const char* f2);

void parseSCLIns(FILE*& in, FILE*& out);
void getSCLIns(uint8_t& cmd, FILE*& in);
void getString(FILE*& in, FILE*& out);