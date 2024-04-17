#include <iostream>
#include <fstream>

#include "pescan.h"

using namespace std;

void help() {
	std::cout << "usage : ./PEscan \"filename\"\n";
}



int main(int argv, char* argc[]) {
	// 입력 에러 처리
	if (argv < 2) {
		help();
		return 0;
	}

	// 파일 읽으면서 구조체 생성하기
	PE_HEADER* peHeader = new PE_HEADER;
	initPe(peHeader, argc[1]);

	// Dos header 출력
	cout << peHeader->image_dos_header.e_magic;

	// NT header 출력

}