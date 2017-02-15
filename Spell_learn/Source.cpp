#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <locale>

int main()
{


	std::locale::global(std::locale("Russian_Russia.1251"));

	std::time_t t = std::time(NULL);
	struct tm * ptr;
	std::time(&t);
	ptr = std::localtime(&t);
	char mbstr[100];


	if (std::strftime(mbstr, sizeof(mbstr), "%A %B %Y", ptr)) {
		std::cout << mbstr << '\n';
	}


	return 0;
}