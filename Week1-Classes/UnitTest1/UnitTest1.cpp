#include "pch.h"
#include "CppUnitTest.h"
// .. is up a folder
#include "..\Week1-Classes\Chair.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethodSetChairHeight)
		{
			// AAA Convention
			// Arrange - setup the variables we need to test
			double expectedChairHeightInMeters = 2.5;
			Chair chair;

			// Act - call the code we're testing
			chair.setHeightInMeters(expectedChairHeightInMeters);
			double actualChairHeightInMeters = chair.getHeightInMeters();

			// Assert - did we get what we expect
			Assert::AreEqual(expectedChairHeightInMeters, actualChairHeightInMeters);
		}

		TEST_METHOD(TestMethodSetChairHeightNegativeStopsAt0)
		{
			// AAA Convention
			// Arrange - setup the variables we need to test
			double expectedChairHeightInMeters = 0;
			Chair chair;

			// Act - call the code we're testing
			chair.setHeightInMeters(-20);
			double actualChairHeightInMeters = chair.getHeightInMeters();

			// Assert - did we get what we expect
			Assert::AreEqual(expectedChairHeightInMeters, actualChairHeightInMeters);
		}
	};
}
