#include "pestruct.h"
#include <stdio.h>


unsigned char initPe(PE_HEADER* peHeader, const char* fileName)
{
	FILE* pFile = NULL;
	fopen_s(&pFile, fileName, "rb");

	if (pFile == NULL) {
		return 0;
	}

	fread(peHeader, 0x40, 1, pFile);

	fclose(pFile);
}
