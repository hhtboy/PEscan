#include <iostream>
#include <fstream>

#include "parser.h"

using namespace std;

void help() {
	std::cout << "usage : ./PEscan \"filename\"\n";
}

bool check_pe(const string& raw) {
	if (raw.rfind("4D5A", 0) == 0) return true;
	else return false;
}

void parse_pe(const unsigned char* raw) {
	print_dos_header(raw);
}

int main(int argv, char* argc[]) {
	// 입력 에러 처리
	if (argv < 2) {
		help();
		return 0;
	}

	std::ifstream fin(argc[1], std::ios_base::in | std::ios_base::binary);
	fin.seekg(0, fin.end);
	int file_size = (int)fin.tellg();
	cout << "file size : " << file_size << endl;
	fin.seekg(0, fin.beg);

	unsigned char* buffer = new unsigned char[file_size];
	fin.read((char*)buffer, file_size);
	fin.close();
	
	string hex_data = to_hex(buffer, file_size, true);

	if (!check_pe(hex_data)) {
		cout << "this is not a pe format file!\n";
		return 0;
	}
	else {
		parse_pe(buffer);
	}

	delete[] buffer;
}