#include "pch.h"
#include "CppUnitTest.h"
#include "..//11_Tarapatina_E_S/func.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace isFullMatchingNameTest
{
	TEST_CLASS(CommentedFuncTest)
	{
	public:

		TEST_METHOD(typical_test)
		{
			const char functionName[MAX_LENGTH] = "punk";
			const char stringOfCode[MAX_LENGTH] = "void punk();";

			const bool waitingResult = true;
			bool result = isFullMatchingName(functionName, stringOfCode);
			Assert::AreEqual(result, waitingResult);
		}

		TEST_METHOD(name_has_space_from_back)
		{
			const char functionName[MAX_LENGTH] = "punk";
			const char stringOfCode[MAX_LENGTH] = "void punk ();";

			const bool waitingResult = true;
			bool result = isFullMatchingName(functionName, stringOfCode);
			Assert::AreEqual(result, waitingResult);
		}

		TEST_METHOD(name_has_no_space_from_front)
		{
			const char functionName[MAX_LENGTH] = "punk";
			const char stringOfCode[MAX_LENGTH] = "punk();";

			const bool waitingResult = false;
			bool result = isFullMatchingName(functionName, stringOfCode);
			Assert::AreEqual(result, waitingResult);
		}

		TEST_METHOD(name_has_no_space_from_front_but_has_space_from_back)
		{
			const char functionName[MAX_LENGTH] = "punk";
			const char stringOfCode[MAX_LENGTH] = "punk ();";

			const bool waitingResult = false;
			bool result = isFullMatchingName(functionName, stringOfCode);
			Assert::AreEqual(result, waitingResult);
		}

		TEST_METHOD(string_contains_few_func_name)
		{
			const char functionName[MAX_LENGTH] = "punk";
			const char stringOfCode[MAX_LENGTH] = "punk(); punk();";

			const bool waitingResult = true;
			bool result = isFullMatchingName(functionName, stringOfCode);
			Assert::AreEqual(result, waitingResult);
		}
		TEST_METHOD(string_does_not_contain_name)
		{
			const char functionName[MAX_LENGTH] = "punk";
			const char stringOfCode[MAX_LENGTH] = "no_name();";

			const bool waitingResult = false;
			bool result = isFullMatchingName(functionName, stringOfCode);
			Assert::AreEqual(result, waitingResult);
		}
	};
}