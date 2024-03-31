#include "pch.h"
#include "CppUnitTest.h"
#include "../lab3.1/Student.h"
#include "../lab3.1/Man.h"
#include "../lab3.1/Student.cpp"
#include "../lab3.1/Man.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest31
{
	TEST_CLASS(UnitTest31)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Man person("John", 20, "Male", 70.5);
			Student student(person, 1); // Починаємо з рівня навчання 1

			// Act
			student.increaseYearOfStudy(); // Збільшуємо рівень навчання на один

			// Assert
			Assert::AreEqual(2, student.getYearOfStudy());
		}
	};
}
