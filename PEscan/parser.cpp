#include "parser.h"
#include <winnt.h>

string to_hex(const unsigned char* buf, int length, bool upper_case)
{
	ostringstream ret;

	for (string::size_type i = 0; i < length; ++i)
	{
		int z = buf[i] & 0xff;
		ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << z;
	}

	return ret.str();

}

string dec2hex(int dec) {
	ostringstream ret;

	ret << std::uppercase << std::hex << dec;
	return ret.str();
}



/* dos header size is 0x40. doesn't change */
void print_dos_header(const unsigned char* raw)
{
	IMAGE_DOS_HEADER* dos_header = (IMAGE_DOS_HEADER*)malloc(sizeof(IMAGE_DOS_HEADER));
	if (dos_header != 0) {
		memcpy(dos_header, raw, sizeof(IMAGE_DOS_HEADER));
		cout << "emagic : " << dec2hex(dos_header->e_magic) << endl;
	}
	free(dos_header);
}
