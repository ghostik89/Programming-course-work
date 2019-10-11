#pragma once
const int MAX_LENGTH = 256;
const int MAX_ROWS = 20;

struct func {
	char func_name[MAX_LENGTH]; //имя функции
	bool some_return; //
	int params;
};

enum func_prop { RIGHT_CALL = -1, NOT_FOUND = -2, INVALID_CALL = -3};

/*!Проверка на правильность вызова функции в строке кода
*	\param[in]: StringOfCode - строка анализируемого кода
*	\param[in]: NameOfFunc - функция, которая анализируется
*	\return: возвращает правильно ли вызвана функция:
*	RIGHT_CALL - вызова данной функции в строке нету
*	NOT_FOUND - правильный вызов функции
*	INVALID_CALL - место неправильного вызова функции
*/
int	IsRightCallFunc(const char StringOfCode[MAX_LENGTH], func SomeFunc);

/*!Проверка на правильность вызова функции в исходном коде
	\param[in]: SourceCode - исходный код
	\param[in]: func - исходная функция
	\param[in]: Rows - количество строк в исходном коде
	\param[out]: InvalidPlace - место ошибки({row} - место ошибки,{-1} - ошибки нет, {-2} - не найдена функция)
*/
void SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], int InvalidPlace, int Rows);
