#include "scl_decode.h"
#include "ecl_decode.h"
//#include "asm_ecl.cpp"

void prntUse()
{
	printf("Usage: KOG_SCL.exe input\n");
	exit(-1);
}

#ifdef CLB_DEBUG
int main()
{

	int number_1 = 3;
	char mode;
	std::string fName;
	std::cout << "Mode (E / S): "; std::cin >> mode;
	std::cout << "Nombre del archivo: "; std::cin >> fName;
	switch (mode)
	{
	case 'E':
		//ECLDecode(buffer, lSize); break;
	case 'S':
		SCLDecode(fName.c_str()); break;
	}
	//system("pause");
}
#endif

#ifndef CLB_DEBUG

int main(int argc, char* argv[])
{
	std::string par;
	par = argv[1];

	if(par == "sd")
	{
		//printf("\n%s, file: %s\n", argv[1], argv[2]);
		SCLDecode(argv[2]);
	}
	else if(par == "sc")
	{
		printf("Still working\n"); prntUse();
	}
	else if (par == "ed")
	{
		printf("Still working\n"); prntUse();
	}
	else if (par == "ec")
	{
		printf("Still working\n"); prntUse();
	}
	else
	{
		prntUse();
	}
}
#endif // !