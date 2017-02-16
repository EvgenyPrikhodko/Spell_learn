#include "stdafx.h"
#include "CppUnitTest.h"
#include <stdexcept> 
#include <iostream>
#include <locale>
#include "..\SLibDateParseToString\SLibDateParseToString.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace SLibDateParseToString;

namespace UnitTestLibDateParseToString
{		
	TEST_CLASS(SLibDateParseToString)
	{
	public:
		
		TEST_METHOD(current_time_NULL)
		{
			wchar_t message[200];
			time_t current_time = time(NULL);;

			std::string  ResultString;

			try
			{
				ResultString = ParseToString::spell(current_time);
			
			}
			catch (const std::exception&)
			{
				_swprintf(message, L"ERROR");
			}
		}


		TEST_METHOD(current_time_DO_ERROR)
		{
			wchar_t message[200];
			time_t current_time = -1;

			std::string  ResultString;

				ResultString = ParseToString::spell(current_time);


				if (ResultString != "Invalid format time_t") {
					
					_swprintf(message, L"ERROR try timre -1 ");
					Assert::Fail(message, LINE_INFO());
				}
					
		}

		TEST_METHOD(current_time_DO_RANDOM)
		{
			wchar_t message[200];
			srand(time(0));
			__int64 m = 5000110110, l = 5544561910;
			__int64 random = ((__int64)rand() / RAND_MAX)*(m - l * rand() * 10) + (rand() << 15) | rand();
			time_t current_time = random;

			std::string  ResultString;

			try
			{
				ResultString = ParseToString::spell(current_time);
			}
			catch (const std::exception&)
			{
				_swprintf(message, L"ERROR");
			}


		}



	};
}