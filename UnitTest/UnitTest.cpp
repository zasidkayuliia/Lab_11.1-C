#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_11.1 C/Lab_11.1 C.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* testString1 = "aabbcc";

			Assert::AreEqual(3, countNeighboringPairs(testString1));

		}
	};
}
