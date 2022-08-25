#include "ecl_decode.h"


void ECLDecode(const char* f)
{
	FILE* fp;
	ECLHeader header;

	fp = fopen(f, "rb");
	if (fp == NULL)
	{
		printf("An error ocurred while opening file.\n");
		exit(-1);
	}

	fread(&header, sizeof(uint32_t), 1, fp );
	
	header.enmSub = new uint32_t[header.enm];
	fread(&header.enmSub[0], sizeof(uint32_t), header.enm, fp);

	ADDRESS sub;
	ADDRESS lab;
	getECLHeaderAdd(header, sub);
	getECLAddress(fp, sub, lab);
	int i = 0;
	for (ADDRESS::iterator it = sub.begin();  it != sub.end(); ++it)
	{
		it->second = i;
		i++;
	}

	readECLIns(fp, sub, lab, header.enm);

	printf("\n\nEnemy{\n");
	for (int i = 0; i < header.enm ; i++)
	{
		std::cout << "	Sub" << sub[header.enmSub[i]] << ", //" << i << "\n";
	}
	printf("}");
	fclose(fp);
}

#define AnotherOp
void readECLIns(FILE*& fp, ADDRESS sub, ADDRESS lab, uint32_t enm)
{
	DWORD add = 0x00000000;
	fseek(fp, 0, SEEK_END);
	QWORD epos = ftell(fp);
	rewind(fp);
	fseek(fp, sizeof(int) * (enm + 1), SEEK_SET);
	QWORD pos = ftell(fp);
	BYTE cmd, reg = 0x00;


	#define REG fread(&reg, 1, 1, fp); printf("[%d]", reg); pos++;

	#define CH rC(fp, 0b0, true); pos++;
	#define W rC(fp, 0b1, true); pos+=2;
	#define DW rC(fp, 0b10, true); pos +=4;
	
	#define B rC(fp, 0b0, false); pos++;
	#define UW rC(fp, 0b1, false); pos+=2;
	#define UDW rC(fp, 0b10, false); pos+=4;
	

	#define SUB fread(&add, 4, 1, fp); std::cout << "Sub" << sub[add]; pos +=4;
	#define LAB fread(&add, 4, 1, fp); printf("Lab_%d", lab[add]); pos +=4;


	while (pos < epos)
	{
		if (sub.find(pos) != sub.end())
		{
			/*
			if (sub[pos] == 52)
			{
				int a = 0;
			}*/
			printf("\n\n@Sub%d:", sub[pos]);
		}
		if (lab.find(pos) != lab.end())
		{
			printf("\n.Lab_%d:", lab[pos]);
		}

		fread(&cmd, 1, 1, fp); pos++;
		std::cout << "\n	" << ECLIns[cmd] << " ";
		switch (cmd)
		{
		case 0x00: UDW CO UDW break;
		case 0x02: LAB break;
		case 0x03: LAB CO UW break;
		case 0x04: SUB break;
		case 0x06: LAB CO UDW break;
		case 0x07: LAB CO UDW break;
		case 0x08: LAB CO LAB CO LAB CO LAB break;
		case 0x09: LAB break;
		case 0x0A: LAB CO UDW break;
		case 0x0B: LAB CO UDW break;
		case 0x0C: LAB CO B CO UDW break;
		case 0x0D: B break;
				   
		case 0x10: UW break;
		case 0x11: UW break;
		case 0x12: UW break;
		case 0x13: CH CO UW break;
		case 0x14: DW CO DW CO CH CO UW break;
		case 0x15: DW CO B CO B CO UW break;
		case 0x16: DW CO B CO B CO UW break;
		case 0x17: W CO UW break;
		case 0x18: W CO UW break;
		case 0x19: W CO W CO UW break;
		case 0x1A: UW break;
		case 0x1B: UW break;
		case 0x1C: UW break;
		case 0x1D: CH CO W break;
		case 0x1E: W CO W CO UW break;
		case 0x1F: CH break;
				   
		case 0x20: B break;
		case 0x21: CH break;
		case 0x24: DW break;
		case 0x25: DW break;
		case 0x26: W CO W break;
		case 0x27: W CO W break;
		case 0x2E: W break;
				   
		case 0x41: B break;
		case 0x42: W CO W break;
		case 0x43: B break;
		case 0x44: B CO B break;
		case 0x45: CH CO CH break;
		case 0x46: B CO B break;
		case 0x47: CH CO CH break;
		case 0x48: B CO CH break;
		case 0x49: CH CO CH break;
		case 0x4A: B break;
		case 0x4B: B break;
		case 0x4C: B break;
		case 0x4D: CH break;
		case 0x4E: B break;
		case 0x54: B break;
				   
		case 0x61: B break;
		case 0x62: DW break;
		case 0x63: DW break;
		case 0x64: DW break;
		case 0x65: B CO B break;
		case 0x66: CH CO CH break;
		case 0x67: B break;
		case 0x68: CH break;
		case 0x69: DW break;
		case 0x6A: DW break;
		case 0x6B: B break;
		case 0x6C: B break;
		case 0x6D: DW break;
		case 0x70: W CO W break;
				   
		case 0x81: B break;
		case 0x82: B break;
		case 0x83: B break;
		case 0x84: B CO CH break;
				   
		case 0xA0: B CO B break;
		case 0xA1: B break;
		case 0xA2: B break;
		case 0xA3: B break;
		case 0xA4: W CO W CO B break;
		case 0xA5: W CO W CO CH CO B break;
		case 0xA6: W CO W break;
		case 0xA7: B break;
		case 0xA8: B break;
		case 0xA9: B break;
		case 0xAA: B break;
		case 0xAB: DW break;
		case 0xAC: B CO DW break;
		case 0xAD: B break;
		case 0xAE: W CO W CO CH break;
				   
		case 0xB0: REG CO REG break;
		case 0xB1: REG CO DW break;
		case 0xB2: REG CO REG break;
		case 0xB3: REG CO REG break;
		case 0xB4: REG CO REG break;
		case 0xB5: REG CO REG break;
		case 0xB6: REG CO DW break;
		case 0xB7: REG break;
		case 0xB8: REG CO REG break;
		case 0xB9: REG CO DW break;
		case 0xBA: LAB break;
		case 0xBB: LAB break;
		case 0xBC: REG break;
		case 0xBD: REG break;
		case 0xBE: LAB break;
		}

	}
}

#define CH rC(fp, 0, true);
#define W rC(fp, 0b1, true);
#define DW rC(fp, 0b10, true);

#define B rC(fp, 0b0, false);
#define UW rC(fp, 0b1, false);
#define UDW rC(fp, 0b11, false);

void getECLHeaderAdd(ECLHeader header, ADDRESS& sub)
{
	for (int i = 0; i < header.enm; i++)
	{
		if (sub.find(header.enmSub[i]) == sub.end())
		{
			sub.insert({ header.enmSub[i], header.enmSub[i]});
		}
	}
}

void getECLAddress(FILE* fp, ADDRESS& sub, ADDRESS& lab)
{

	DWORD address;
	BYTE cmd = 0;
	BYTE eInsCont[20];

	DWORD lv = 0;

#define GSADD fread(&address, 4, 1, fp); if (sub.find(address) == sub.end()){sub.insert({ address, address });}lv +=4; //rAdd(fp, sub); lv+=4;
#define GLADD fread(&address, 4, 1, fp); if (lab.find(address) == lab.end()){lab.insert({ address, address });}lv +=4; //rAdd(fp, lab); lv+=4;

#define AC(x) fread(&eInsCont[0], x, 1, fp); lv+= x;

	while (!feof(fp))
	{

		fread(&cmd, 1, 1, fp);
		lv++;
		switch (cmd)
		{
		case 0x00: /*fseek(fp, -1, SEEK_SET); address = lv; if (sub.find(address) == sub.end()) { sub.insert({address, address}); }
				 fseek(fp, 1, SEEK_SET); */ AC(8) break;
		case 0x02: GLADD break;
		case 0x03: GLADD AC(2)  break;
		case 0x04: GSADD 
			break;
		case 0x06: GLADD AC(4) break;
		case 0x07: GLADD AC(4) break;
		case 0x08: GLADD GLADD GLADD GLADD break;
		case 0x09: GLADD break;
		case 0x0A: GLADD AC(4) break;
		case 0x0B: GLADD AC(4) break;
		case 0x0C: GLADD AC(5) break;
		case 0x0D: AC(1) break;
				    
		case 0x10: AC(2) break;
		case 0x11: AC(2) break;
		case 0x12: AC(2) break;
		case 0x13: AC(3) break;
		case 0x14: AC(0xb) break;
		case 0x15: AC(8) break;
		case 0x16: AC(8) break;
		case 0x17: AC(4) break;
		case 0x18: AC(4) break;
		case 0x19: AC(6) break;
		case 0x1A: AC(2) break;
		case 0x1B: AC(2) break;
		case 0x1C: AC(2) break;
		case 0x1D: AC(3) break;
		case 0x1E: AC(6) break;
		case 0x1F: AC(1) break;
				    
		case 0x20: AC(1) break;
		case 0x21: AC(1) break;
		case 0x24: AC(4) break;
		case 0x25: AC(4) break;
		case 0x26: AC(4) break;
		case 0x27: AC(4) break;
		case 0x2E: AC(2) break;
				    
		case 0x41: AC(1) break;
		case 0x42: AC(4) break;
		case 0x43: AC(1) break;
		case 0x44: AC(2) break;
		case 0x45: AC(2) break;
		case 0x46: AC(2) break;
		case 0x47: AC(2) break;
		case 0x48: AC(2) break;
		case 0x49: AC(2) break;
		case 0x4A: AC(1) break;
		case 0x4B: AC(1) break;
		case 0x4C: AC(1) break;
		case 0x4D: AC(1) break;
		case 0x4E: AC(1) break;
		case 0x54: AC(1) break;
				    
		case 0x61: AC(1) break;
		case 0x62: AC(4) break;
		case 0x63: AC(4) break;
		case 0x64: AC(4) break;
		case 0x65: AC(2) break;
		case 0x66: AC(2) break;
		case 0x67: AC(1) break;
		case 0x68: AC(1) break;
		case 0x69: AC(4) break;
		case 0x6A: AC(4) break;
		case 0x6B: AC(1) break;
		case 0x6C: AC(1) break;
		case 0x6D: AC(4) break;
		case 0x70: AC(4) break;
				    
		case 0x81: AC(1) break;
		case 0x82: AC(1) break;
		case 0x83: AC(1)  break;
		case 0x84: AC(2) break;
				    
		case 0xA0: AC(2) break;
		case 0xA1: AC(1) break;
		case 0xA2: AC(1) break;
		case 0xA3: AC(1) break;
		case 0xA4: AC(5) break;
		case 0xA5: AC(6) break;
		case 0xA6: AC(4) break;
		case 0xA7: AC(1) break;
		case 0xA8: AC(1) break;
		case 0xA9: AC(1) break;
		case 0xAA: AC(1) break;
		case 0xAB: AC(4) break;
		case 0xAC: AC(5) break;
		case 0xAD: AC(1) break;
		case 0xAE: AC(5) break;
				    
		case 0xB0: AC(2) break;
		case 0xB1: AC(5) break;
		case 0xB2: AC(2) break;
		case 0xB3: AC(2) break;
		case 0xB4: AC(2) break;
		case 0xB5: AC(2) break;
		case 0xB6: AC(5) break;
		case 0xB7: AC(1) break;
		case 0xB8: AC(2) break;
		case 0xB9: AC(5) break;
		case 0xBA: GLADD break;
		case 0xBB: GLADD break;
		case 0xBC: AC(1) break;
		case 0xBD: AC(1) break;
		case 0xBE: GLADD break;
		}

#ifdef CLB_DEBUG
		if (feof(fp))
		{
			printf("\nEnd of file.\n");
		}
#endif // 

	}
}