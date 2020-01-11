#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace FindDeclareTest
{
	TEST_CLASS(FindDeclareTest)
	{
	public:
		// ===== функция FindDeclareFunc
		TEST_METHOD(TypicalTest) {
			const int Rows = 9;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"count();",
				"return 0;"
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			const int WaitingResult = 0;
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(DeclareAfterMain) {
			const int Rows = 9;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count();",
				"int main()",
				"{",
				"int a = 0;",
				"return 0;"
				"}"
				"void count()",
				"{",
				"int a = 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			const int WaitingResult = 0;
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(DeclareTwoFuncs) {
			const int Rows = 14;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count();",
				"int main()",
				"{",
				"int a = 0;",
				"return 0;"
				"}"
				"void count()",
				"{",
				"int a = 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			const int WaitingResult = 0;
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, WaitingResult);
		}
	};
}