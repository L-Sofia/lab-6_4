#include "pch.h"
#include "CppUnitTest.h"
#include "../Project6_4(rec)/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{

			const int size = 15;
			int a[size];
			int Low = 1;
			int High = 40;

			Create(a, size, Low, High, 0);

			for (int i = 0; i < size; i++)
				Assert::IsTrue(a[i] >= Low && a[i] <= High);

		}
	};
}
