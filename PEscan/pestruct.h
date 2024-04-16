#pragma once
#include <Windows.h>

struct PE_HEADER 
{
	IMAGE_DOS_HEADER image_dos_header;
	IMAGE_NT_HEADERS64 image_nt_header;
	IMAGE_SECTION_HEADER image_section_headers;
};
