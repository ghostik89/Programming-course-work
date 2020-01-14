#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MainFunc
{
	TEST_CLASS(MainFunc)
	{
	public:
		// ===== Основная функция
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

		TEST_METHOD(InCondition) {
			const int Rows = 10;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int punk();",
				"int main()",
				"{",
				"int a = punk() + 10;",
				"return 0;",
				"}",
				"int punk()",
				"{",
				"return 5;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "punk" };
			const int WaitingResult = -1;
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, WaitingResult);
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
			const int WaitingResult = 6;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(TypicalTestNotFound) {
			const int Rows = 10;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int count()",
				"{",
				"int a =  0;",
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
			const int WaitingResult = 6;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(InIf) {
			const int Rows = 13 ;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
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
		TEST_METHOD(InFor) {
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
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 9;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(InWhile) {
			const int Rows = 14;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"a = 1;",
				"}",
				"int main()",
				"{",
				"int a = 0;",
				"while(a<10)",
				"{",
				"count(a);",
				"}",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 10;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(InDoWhile) {
			const int Rows = 13;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int a = 0;",
				"do",
				"{",
				"count();",
				"}while(a<10);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = -1;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(InIfElse) {
			const int Rows = 17;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int a = 0;",
				"if(a==0)",
				"{",
				"a=1;",
				"}",
				"else",
				"{",
				"count(5);",
				"}",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 13;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(DeclareTwoFunc) {
			const int Rows = 14;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"void minus()",
				"{",
				"int b = 0;",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"count(1);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 11;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(UseTwoFunc) {
			const int Rows = 15;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"void minus()",
				"{",
				"int b = 0;",
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
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 12;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(UseOneFunc) {
			const int Rows = 14;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"void minus()",
				"{",
				"int b = 0;",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"minus();",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = -2;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(UseMoreOne) {
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
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 8;
			Assert::AreEqual(result, WaitingResult);
		}
		TEST_METHOD(ErrorMoreOne) {
			const int Rows = 11;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"count(10);",
				"count(40);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 7;
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
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 3;
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
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 4;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(UsingInUsersFunc) {
			const int Rows = 13;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"void minus()",
				"{",
				"count(10);",
				"}",
				"int main()",
				"{",
				"int i = 0;",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 6;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(FormatedCode) {
			const int Rows = 13;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"	int a = 0;",
				"}",
				"int main()",
				"{",
				"	int i = 0;",
				"   for(i; i < 23; i++)",
				"   {",
				"		count(-2);",
				"	}",
				"	return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 9;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(InSwitchCase) {
			const int Rows = 17;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int a = 0;",
				"switch (a)",
				"{",
				"case 0:",
				"a = count();",
				"break;",
				"default:",
				"a++;",
				"}",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			const int WaitingResult = 10;
			Assert::AreEqual(result, WaitingResult);
		}

		TEST_METHOD(OnlySpaceInArgs) {
			const int Rows = 9;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"count(      );",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			const int WaitingResult = -1;
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, -1);
		}

		//not added tests
		TEST_METHOD(FuncAndIntHaveOneName) {
			const int Rows = 9;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"void count()",
				"{",
				"int a = 0;",
				"}",
				"int main()",
				"{",
				"int count;",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			const int WaitingResult = -2;
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, -2);
		}
		TEST_METHOD(FuncCallTwiceInOneLine) {
			const int Rows = 10;
			const char SourceCode[Rows][MAX_LENGTH] = {
				"int count(int a, int b)",
				"{",
				"return 1;",
				"}",
				"int main()",
				"{",
				"int a;",
				"a = count(4,5) + count(1);",
				"return 0;",
				"}"
			};
			const char NameOfFunc[MAX_LENGTH] = { "count" };
			const int WaitingResult = 7;
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, WaitingResult);
		}
	};
}
