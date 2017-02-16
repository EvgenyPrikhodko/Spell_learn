#include "stdafx.h"
#include "SLibDateParseToString.h"
#include <ctime>
#include <iostream>
#include <locale>
#include <string>
#include <stdexcept>

using namespace std;

namespace SLibDateParseToString
{
	
	string ParseToString::DaysParse(int &days)
	{

		char digitsNumeral[20][15] = { " первое"," второе"," третье"," четвертое"," п€тое"," шестое"," седьмое"," восьмое"," дев€тое"," дес€тое"," одинадцатое"," двенадцатое",
			" тринадцатое"," четырнадцатое"," п€тнадцатое"," шестнадцатое"," семнадцатое"," восемнадцатое"," дев€тнадцатое" };
		char digitsDes[9][15] = { "дес€ть"," двадцать"," тридцать"," сорок"," п€тьдес€т"," шестьдес€т"," семьдес€т"," восемьдес€т"," дев€носто" };
		char digitsDesNumeral[3][15] = { " дес€тое"," двадцатое"," тридцатое" };

		string resultParse;

		int value = days;
		int amount;
		if (value > 31 || value < 0)
		{
			return	resultParse = " Error,  days value; ";
		}
		while (value)
		{

			if (value >= 20 && value < 100)
			{
				amount = value / 10;
				value -= 10 * amount;
				if (value == 0)
				{
					resultParse += digitsDesNumeral[amount - 1];
					break;
				}
				else resultParse += digitsDes[amount - 1];

			}
			if (value < 20)
			{
				resultParse += digitsNumeral[value - 1];
				value = 0;
			}

		}
		return	resultParse;
	}

	string ParseToString::MounthParse(int &mounth)
	{
		char mounthText[12][10] = { " €нвар€"," феврал€"," марта"," апрел€"," ма€"," июн€"," июл€"," августа"," сент€бр€"," окт€бр€"," но€бр€"," декабр€" };
		string resultParse = "";
		int value = mounth;

		if (value > 12 || value < 0)
		{
			return resultParse = " Error,  mounth value; ";
		}
		resultParse = mounthText[value - 1];

		return resultParse;

	}

	string ParseToString::YearParse(int &year)
	{
		char digits[9][8] = { " одна"," две"," три"," четыри"," п€ть"," шесть"," семь"," восемь"," дев€ть" };
		char digits_only[9][10] = { " одна"," двух"," трьох"," четырьох"," п€ти"," шести"," семи"," восеми"," дев€ти" };

		char digitsGenitive[20][16] = { " первого"," второго"," третьего"," четвертого"," п€того"," шестого"," седьмого"," восьмого"," дев€того"," дес€того",
			" одинадцатого"," двенадцатого"," тринадцатого"," четырнадцатого"," п€тнадцатого"," шестнадцатого"," семнадцатого"," восемнадцатого"," дев€тнадцатого" };

		char digitsDes[10][15] = { " дес€ть"," двадцать"," тридцать"," сорок"," п€тьдес€т"," шестьдес€т"," семьдес€т"," восемьдес€т"," дев€носто" };
		char digitsDesGenitive[10][15] = { " дес€того"," двадцатого"," тридцатого"," сорокового"," п€тьдис€того"," шестидес€того"," семидес€того"," восьмидес€тго"," дев€ностого" };

		char digitsHundredth[9][12] = { " сто"," двести"," триста"," четыриста"," п€тьсот"," шестьсот"," семьсот"," восемьсот"," дев€тьсот", };
		char digitsHundredthGenitive[9][18] = { " сотого"," двухсотого"," трьохсотого"," четырьохсотого"," п€тьсотого"," шестьсотого"," семьсотого"," восемьсотого"," деветьсотого", };

		char digitsThousandths[4][11] = { " тыс€ча"," тыс€чи"," тыс€ч"," тыс€чного" };


		string resultParse;

		int amount = 0, value = 0;

		value = year;
		if (value > 10000)
		{
			return resultParse = " Error,  year value; ";
		}
		while (value)
		{

			if (value >= 1000 && value < 10000)
			{
				amount = value / 1000;
				value -= 1000 * amount;
				if (value == 0)
				{
					if (amount == 1)
						resultParse += digitsThousandths[3];
					else
					{
						resultParse += digits_only[amount - 1];
						resultParse += digitsThousandths[3];
					}
					break;
				}
				else
				{
					resultParse += digits[amount - 1];
					if (amount == 1)
						resultParse += digitsThousandths[0];
					if (amount == 2 || amount == 3 || amount == 4)
						resultParse += digitsThousandths[1];
					if (amount == 5 || amount == 6 || amount == 7 || amount == 8 || amount == 9)
						resultParse += digitsThousandths[2];
				}

			}

			if (value >= 100 && value < 1000)
			{
				amount = value / 100;
				value -= 100 * amount;
				if (value == 0)
				{
					resultParse += digitsHundredthGenitive[amount - 1];
					break;
				}
				else
				{
					resultParse += digitsHundredth[amount - 1];
				}

			}

			if (value >= 20 && value < 100)
			{
				amount = value / 10;
				value -= 10 * amount;
				if (value == 0)
				{
					resultParse += digitsDesGenitive[amount - 1];
					break;
				}
				else resultParse += digitsDes[amount - 1];


			}
			if (value < 20)
			{
				resultParse += digitsGenitive[value - 1];
				value = 0;
			}

		}
		resultParse += " года";

		return resultParse;

	}

	string ParseToString::spell(time_t t)
	{
		
		std::locale::global(std::locale("Russian_Russia.1251"));

		if (t == -1)
		{
			return "Invalid format time_t";
		}
		else
		{
			string resultParseTime_tToString;
			int mm = localtime(&t)->tm_mon + 1;
			int yy = localtime(&t)->tm_year + 1900;
			int dd = localtime(&t)->tm_mday;

			resultParseTime_tToString = DaysParse(dd) + MounthParse(mm) + YearParse(yy);

			return resultParseTime_tToString;
		}

	}


}