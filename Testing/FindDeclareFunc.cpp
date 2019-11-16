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
		TEST_METHOD(NewTest) {
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
			Assert::AreEqual(result, 0);
		}
		TEST_METHOD(HaveArgsInbrackets) {
			const int Rows = 9;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int count(int b)",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"count(5);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 0;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(MoreBrakets) {
			const int Rows = 13;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"for(i=0;i<23;i++)",
				"{",
				"count(-2);",
				"}",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 0;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(DeclareTwoFunc) {
			const int Rows = 14;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void minus()",
				"{",
				"int b = 0;",
				"}",
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"count(1);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 4;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(UseTwoFunc) {
			const int Rows = 15;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void minus()",
				"{",
				"int b = 0;",
				"}",
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"minus();",
				"count(34);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 4;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(UseMoreOneMainFunc) {
			const int Rows = 11;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"count();",
				"count(40);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 0;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(Recurse) {
			const int Rows = 11;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"count(10);",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"count();",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 0;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(DeclareAfterMain) {
			const int Rows = 12;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count();",
				"int main()",
				"{",
				"int i = 0;",
				"count(40);",
				"return 0;",
				"}",
				"void count()",
				"{",
				"int a = 0;",
				"count(10);",
				"}",
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = FindDeclareFunc(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 0;
			Assert::AreEqual(result, WaitingResult);
		}

	};
}