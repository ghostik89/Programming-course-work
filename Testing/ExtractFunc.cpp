#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

/*
	Testing func ExtractFunc(const char DeclareFunc[MAX_LENGTH], const char Sourcefunc[MAX_LENGTH])
	struct func {
	char func_name[MAX_LENGTH]; //имя функции
	bool some_return; //
	int params;
};

*/
namespace ExtractFuncTest
{
	TEST_CLASS(ExtractFuncTest)
	{
	public:
		TEST_METHOD(TypicalTest) {
			const char Declarefunc[MAX_LENGTH] = "void count()";
			const char NameOfFunc[MAX_LENGTH] = "count";
			const func WaitingResult = {"count", false, 0};
			func result = ExtractFunc(Declarefunc, NameOfFunc);
			Assert::IsTrue(result == WaitingResult);
		}

		TEST_METHOD(HaveOneArg) {
			const char Declarefunc[MAX_LENGTH] = "void count(int some)";
			const char NameOfFunc[MAX_LENGTH] = "count";
			const func WaitingResult = { "count", false,1 };
			func result = ExtractFunc(Declarefunc, NameOfFunc);
			Assert::IsTrue(result == WaitingResult);
		}

		TEST_METHOD(HaveMoreOneArg) {
			const char Declarefunc[MAX_LENGTH] = "void count(int some, char ch)";
			const char NameOfFunc[MAX_LENGTH] = "count";
			const func WaitingResult = { "count", false, 2 };
			func result = ExtractFunc(Declarefunc, NameOfFunc);
			Assert::IsTrue(result == WaitingResult);
		}

		TEST_METHOD(ReturSomeValue) {
			const char Declarefunc[MAX_LENGTH] = "int count()";
			const char NameOfFunc[MAX_LENGTH] = "count";
			const func WaitingResult = { "count", true, 0 };
			func result = ExtractFunc(Declarefunc, NameOfFunc);
			Assert::IsTrue(result == WaitingResult);
		}

		TEST_METHOD(OnlyDeclare) {
			const char Declarefunc[MAX_LENGTH] = "void count();";
			const char NameOfFunc[MAX_LENGTH] = "count";
			const func WaitingResult = { "count", false, 0 };
			func result = ExtractFunc(Declarefunc, NameOfFunc);
			Assert::IsTrue(result == WaitingResult);
		}

		TEST_METHOD(MixedTest) {
			const char Declarefunc[MAX_LENGTH] = "int count(int template)";
			const char NameOfFunc[MAX_LENGTH] = "count";
			const func WaitingResult = { "count", true, 1 };
			func result = ExtractFunc(Declarefunc, NameOfFunc);
			Assert::IsTrue(result == WaitingResult);
		}
	};
}