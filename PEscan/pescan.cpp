#include <iostream>
#include <fstream>

#include "pescan.h"

using namespace std;

void help() {
	std::cout << "usage : ./PEscan \"filename\"\n";
}



int main(int argv, char* argc[]) {
	// �Է� ���� ó��
	if (argv < 2) {
		help();
		return 0;
	}

	// ���� �����鼭 ����ü �����ϱ�
	PE_HEADER* peHeader = new PE_HEADER;
	initPe(peHeader, argc[1]);

	// Dos header ���
	cout << peHeader->image_dos_header.e_magic;

	// NT header ���

}