#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(Testing)
	{
	public:
		TEST_METHOD(TypicalTest){
			const int Rows = 9;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"count();",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = {"count"};
			const int WaitingResult = -1;
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, -1);
		}
		TEST_METHOD(TypicalTestNotRightCall) {
			const int Rows = 11;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"a = count();",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 9;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(TypicalTestNotFound) {
			const int Rows = 10;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = -2;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(ReturnValue) {
			const int Rows = 11;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int count()",
				"{",
				"int a = 0;",
				"return a;",
				"}",
				"int main()",
				"{",
				"int a = 0;",
				"a = count();",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = -1;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(ReturnNotUseValue){
			const int Rows = 11;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int count()",
				"{",
				"int a = 0;",
				"return a;",
				"}",
				"int main()",
				"{",
				"int a = 0;",
				"count();",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = -1;
			Assert::AreEqual(result, WaitingResult);
		}
	
		TEST_METHOD(HaveArgs) {
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
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = -1;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(HaveArgsNotRight) {
			const int Rows = 9;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int count(int b)",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"count();",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 7;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(InIf) {
			const int Rows = 13 ;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int a = 0;",
				"if(a==0)",
				"{",
				"count();",
				"}",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = -1;
			Assert::AreEqual(result, WaitingResult);
		}
	};
}
