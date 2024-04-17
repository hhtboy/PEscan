#pragma once
#include <Windows.h>

struct PE_HEADER 
{
	IMAGE_DOS_HEADER image_dos_header;
	IMAGE_NT_HEADERS64 image_nt_header;
	IMAGE_SECTION_HEADER* pimage_section_headers;
};


/* open pe file and initialize PE_HEADER */
unsigned char initPe(PE_HEADER* peHeader, const char* fileName);
