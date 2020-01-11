#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace InFuncCountTest
{
	TEST_CLASS(InFuncCountTest)
	{
	public:
		// ===== функция CountArgs
		TEST_METHOD(TypicalTest) {
			const char StringOfCode[MAX_LENGTH] = "{";
			int Brackets = 0;
			const int WaitingResult = 1;
			InFuncCount(StringOfCode, Brackets);
			Assert::AreEqual(Brackets, WaitingResult);
		}

		TEST_METHOD(RightBracket) {
			const char StringOfCode[MAX_LENGTH] = "}";
			int Brackets = 0;
			const int WaitingResult = -1;
			InFuncCount(StringOfCode, Brackets);
			Assert::AreEqual(Brackets, WaitingResult);
		}

		TEST_METHOD(WithoutBrackets) {
			const char StringOfCode[MAX_LENGTH] = "int m = 0;";
			int Brackets = 2;
			const int WaitingResult = 2;
			InFuncCount(StringOfCode, Brackets);
			Assert::AreEqual(Brackets, WaitingResult);
		}

		TEST_METHOD(OtherBrackets) {
			const char StringOfCode[MAX_LENGTH] = "int main()";
			int Brackets = 3;
			const int WaitingResult = 3;
			InFuncCount(StringOfCode, Brackets);
			Assert::AreEqual(Brackets, WaitingResult);
		}

		TEST_METHOD(WithWhiteSpaces) {
			const char StringOfCode[MAX_LENGTH] = "		{";
			int Brackets = 4;
			const int WaitingResult = 5;
			InFuncCount(StringOfCode, Brackets);
			Assert::AreEqual(Brackets, WaitingResult);
		}
	};
}