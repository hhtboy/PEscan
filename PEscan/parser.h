#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <Windows.h>

using namespace std;

string to_hex(const unsigned char* buf, int length, bool upper_case);

void print_dos_header(const unsigned char* raw);
