//#pragma once
#pragma warning(disable : 4996)  
#include <string>
#include <ctime>
#include <locale>


namespace SLibDateParseToString
{
	class ParseToString
	{

	public:
		static std::string spell(time_t t);

	private:
		static std::string DaysParse(int &days);

		static std::string MounthParse(int &mounth);

		static std::string YearParse(int &year);

	};

	
}