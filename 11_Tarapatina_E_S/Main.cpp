#include <cstdio>

const int MAX_LENGTH = 256;
const int MAX_ROWS = 20;


/*! Проверка првильности вызова функции
*	\param[in]: StringOfCode - строка изучаемого кода
*	\param[in]: NameOfFunc - имя функции
*	\return: Правильность вызванной функции
*	-1 - фукнция в строке не найдена
*	-2 - функция вызвана правильно
*	val - место ошибки в функции
*/
int	IsRightCallFunc(const char StringOfCode[MAX_LENGTH], const char* NameOfFunc);


/*!
	\param[in]: SourceCode - исходный код
	\param[out]: InvalidPlace - место с неверными данными {-1, -1} - функция не найдена
*/
void SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], int* InvalidPlace);


int main() {

	return 0;
}