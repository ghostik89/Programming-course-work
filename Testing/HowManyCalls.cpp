#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace HowManyCallsTest
{
	TEST_CLASS(HowManyCallsTest)
	{
	public:
		// ===== функция CountArgs
		TEST_METHOD(TypicalTest) {
			const char StringOfCode[MAX_LENGTH] = "count();";
			const char FuncName[MAX_LENGTH] = "count";
			int result = HowManyCalls(StringOfCode, FuncName);
			const int WaitingResult = 1;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(FuncWithVariable) {
			const char StringOfCode[MAX_LENGTH] = "int a = count() + count();";
			const char FuncName[MAX_LENGTH] = "count";
			int result = HowManyCalls(StringOfCode, FuncName);
			const int WaitingResult = 2;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(FuncInVariable) {
			const char StringOfCode[MAX_LENGTH] = "int a = count() + count();";
			const char FuncName[MAX_LENGTH] = "count";
			int result = HowManyCalls(StringOfCode, FuncName);
			const int WaitingResult = 2;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(NotFuncsInString) {
			const char StringOfCode[MAX_LENGTH] = "int a = 0;";
			const char FuncName[MAX_LENGTH] = "count";
			int result = HowManyCalls(StringOfCode, FuncName);
			const int WaitingResult = 0;
			Assert::AreEqual(result, WaitingResult);
		}
	};
}