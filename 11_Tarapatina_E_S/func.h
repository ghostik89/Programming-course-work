#pragma once
const int MAX_LENGTH = 256;
const int MAX_ROWS = 20;

struct func {
	char func_name[MAX_LENGTH]; //имя функции
	bool some_return; //
	int params;
};

//enum func_prop { RIGHT_CALL = -1, NOT_FOUND = -2, INVALID_CALL = -3};

/*!Поиск объявления функции в исходном коде
	\param[in]: SourceCode - исходный код
	\param[in]: func - исходная функция
	\param[in]: Rows - количество строк в исходном коде
	\return: {row} - место объявления функции
*/
int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], int Rows);


/*!Преобразование объявление функции из строки в структуру func
	\param[in]: DeclareFunc - объявление функции
	\return: func - контейнер для функции
*/
func ExtractFunc(const char DeclareFunc[MAX_LENGTH]);


/*!Проверка на правильность вызова функции в исходном коде
	\param[in]: SourceCode - исходный код
	\param[in]: func - исходная функция
	\param[in]: Rows - количество строк в исходном коде
	\return: место ошибки({row} - место ошибки,{-1} - ошибки нет, {-2} - не найдена функция)
*/
int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], int Rows);
