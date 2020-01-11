#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CountArgsTest
{
	TEST_CLASS(CountArgsTest)
	{
	public:
		// ===== функция CountArgs
		TEST_METHOD(TypicalTest) {
			const char StringOfCode[MAX_LENGTH] = "count(a);";
			const int WaitingResult = 1;
			int result = CountArgs(StringOfCode);
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(FuncNameIsVariableName) {
			const char StringOfCode[MAX_LENGTH] = "int count = a;";
			const int WaitingResult = -1;
			int result = CountArgs(StringOfCode);
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(WithoutArgs) {
			const char StringOfCode[MAX_LENGTH] = "count()";
			const int WaitingResult = 0;
			int result = CountArgs(StringOfCode);
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(WhiteSpacesIsArgs) {
			const char StringOfCode[MAX_LENGTH] = "count(   )";
			const int WaitingResult = 0;
			int result = CountArgs(StringOfCode);
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(FuncPrototype) {
			const char StringOfCode[MAX_LENGTH] = "void count(int a);";
			const int WaitingResult = 1;
			int result = CountArgs(StringOfCode);
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(FuncDeclare) {
			const char StringOfCode[MAX_LENGTH] = "void count(int a);";
			const int WaitingResult = 1;
			int result = CountArgs(StringOfCode);
			Assert::AreEqual(result, WaitingResult);
		}
	};
}