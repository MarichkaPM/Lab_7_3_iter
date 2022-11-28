#include "pch.h"
#include "CppUnitTest.h"
#include <ObjIdl.h>
#include "../Laboratorna 7_3/Lab 7_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestfor73
{
	TEST_CLASS(UnitTestfor73)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int result;
			int count = 0;
			int mas[3][3] =
			{
				{-1, 0, -6},
				{4, 0, -2},
				{-7, -8, 0}
			};
			int* pa[3] = {mas[0], mas[1], mas[2]};
			Count(pa, 3, 3, count);
			result = count;
			Assert::AreEqual(result, 5)	
		}
	};
}
