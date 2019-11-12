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
			const int WaitingResult = -1;
			int result = SearchInvalidFuncCall(SourceCode, NameOfFunc, Rows);
			Assert::AreEqual(result, -1);
		}
	};
}