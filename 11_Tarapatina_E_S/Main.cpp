#include <cstdio>
#include "func.h"
#include <cstring>

/*!Проверка на правильность вызова функции в исходном коде
	\param[in]: SourceCode - исходный код
	\param[in]: func - исходная функция
	\param[in]: Rows - количество строк в исходном коде
	\return: {row} - место объявления функции
*/
int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	
	int DeclareCloumn = -1; //изначально считаем, что объявление не найдено
	bool Bracket = false;
	//подумать над выявлением типа
	const char AllTypes[] = "constunsignedintfloatdoublecharvoid";

	for (int i = 0; i < Rows; i++) {
		if (!strcmp(SourceCode[i], "{"))
			Bracket = true;
		if (!strcmp(SourceCode[i], "}"))
			Bracket = false;
		char* FindingName;
		FindingName = (char *)strstr(SourceCode[i], SourceFunc);
		if (FindingName != NULL && !Bracket) {
			char* ReturnValue;
			int len = strlen(SourceCode[i]) - strlen(FindingName);
			strncpy(ReturnValue, SourceCode[i], len);
			if (strspn(ReturnValue, AllTypes) > 3)//если найден тип возвращаемого значени и скобки
				DeclareCloumn = i;		
		}
	}
	return DeclareCloumn;
}


/*!Преобразование объявление функции из строки в структуру func
	\param[in]: DeclareFunc - объявление функции
	\return: func - контейнер для функции
*/
func ExtractFunc(const char DeclareFunc[MAX_LENGTH]) {

}


/*!Проверка на правильность вызова функции в исходном коде
	\param[in]: SourceCode - исходный код
	\param[in]: func - исходная функция
	\param[in]: Rows - количество строк в исходном коде
	\return: место ошибки({row} - место ошибки,{-1} - ошибки нет, {-2} - не найдена функция)
*/
int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows){
	//1. Определить место определения функции
	//	2. Выделить составляющие функции(возвращает / нет значение, количество аргументов)
	//	3. Поиск первого неверного вызова исходной функции в main() и других фукнциях...
	//	...Считать, что функция не найдена
	//	...Считать, что не верных вызово не было
	//	для каждой строчки кода, пока не найден неверный вызов
	//	если происходит вызов исходной функции
	//	считать, что функция найдена
	//	проверяем вызов функции с учетом возвращает значение, правильное количество аргументов
	//	если вызов неверный
	//	запомнить номер строки с неверным вызовом
	//	4.вернуть номер строки({ row } -место ошибки, { -1 } -ошибки нет, { -2 } -не найдена функция)

	return 6;
}


int main() {

	return 0;
}

func ExtractFunc(const char DeclareFunc[MAX_LENGTH])
{
	return func();
}
