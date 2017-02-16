// ConsoleDateParseToString.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#pragma warning(disable : 4996)  
#include <ctime>
#include <iostream>
#include <locale>
#include <string>

#include <random>
#include "..\SLibDateParseToString\SLibDateParseToString.h"


using namespace std;
using namespace SLibDateParseToString;

int main()
{
		srand(time(0));
		__int64 m = 5000110110, l = 5544561910;
		__int64 random = ((__int64)rand() / RAND_MAX)*(m - l * rand()*10) + (rand() << 15) | rand();
		string ResultString;

		locale::global(locale("Russian_Russia.1251"));

		
		time_t current_time = random;
		cout << "current_time :" << current_time << endl;
		ResultString = ParseToString::spell(current_time);
		cout << "DateParseToString RANDOM :" << ResultString << endl;
		
		current_time = time(NULL);
		cout << "current_time : " << current_time << endl;

		ResultString = ParseToString::spell(current_time);
		cout << "DateParseToString NOW :" << ResultString << endl;

	system("pause");
	return 0;
}

