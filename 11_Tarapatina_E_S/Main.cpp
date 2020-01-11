#include <cstdio>
#include "func.h"
#include <cstring>
#include <cctype>  


int CountArgs(const char StringOfCode[MAX_LENGTH]){
	char* LBracket = (char*)strchr(StringOfCode, '(');
	char* RBracket = (char*)strrchr(StringOfCode, ')');
	int Args , Spaces;

	Args = 1;//Изначально считаем, что функция имеет один аргумент
	Spaces = 0;//Изначально считаем, что между круглыми скобками нет белых разделителей

	//1.Подсчет аргументов
	if (LBracket != NULL && strcmp(LBracket + 1, RBracket)) {//если между скобок есть пространство
		for (int i = 1; strcmp(LBracket + i, RBracket); i++) {//для каждого символа между скобок
			if (LBracket[i] == ',' || LBracket[i] == '(')//если текущий символ - запятая...
				Args++;//...то увеличить количество аргументов
			if (isspace(LBracket[i]))//если текущий символ - белый разделитель...
				Spaces++;//... то увеличить счетчик разделителей
		}
	}
	//если  пространство между скобками нет или полностью состоит их белых разделителей...
	if (LBracket != NULL && (Spaces == strlen(LBracket) - 2 || (strchr(StringOfCode,';') != NULL && Spaces == strlen(LBracket) - 3)))
		Args = 0;//...то обнулить счетчик аргументов

	if (LBracket == NULL) Args = -1; //если в строка кода - объявление переменной, то количество аргументов равно -1

	return Args;//2. Вернуть количество аргументов
}

void InFuncCount(const char StringOfCode[MAX_LENGTH], int& BraketsCounter){
	//Изначально считаем что в строке одновременно не может быть и {, и }
	//1. Изменяем счетчик фигурных скобок в зависимости от найденной скобки
	if (strstr(StringOfCode, "{") != NULL)//если в строке найдена { ...
		BraketsCounter++;//...то увеличить счетчик фигурных скобок
	if (strstr(StringOfCode, "}") != NULL)//если в строке найдена }...
		BraketsCounter--;//...то уменьшаем счетчик фигурных скобок
}

int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	
	int DeclareCloumn; //там, где объявляется фукнция
	int Bracket;	   //вспомогательная переменная, чтобы не искать объявление фукнции в теле другой функции

	Bracket = 0;		//Изначально считать, что мы не в теле функции
	DeclareCloumn = -1; //изначально считаем, что объявление не найдено
	//Поиск заголовка или объявления функции в коде
	for (int i = 0; i < Rows && DeclareCloumn == -1; i++) {//для каждой строкчки исходного кода

		InFuncCount(SourceCode[i], Bracket);
		char* FindingName;
		FindingName = (char*)strstr(SourceCode[i], SourceFunc);
		char* LBracket = (char*)strchr(SourceCode[i], '(');
		char* RBracket = (char*)strchr(SourceCode[i], ')');


		if (FindingName != NULL && Bracket == 0 && LBracket != NULL && RBracket != NULL)//если мы не внутри функции и в строке есть имя искомой функции и есть пара круглых скобочек
			DeclareCloumn = i;//запомнить номер строки
	}
	return DeclareCloumn;//Вернуть номер строки
}


func ExtractFunc(const char DeclareFunc[MAX_LENGTH], const char Sourcefunc[MAX_LENGTH]) {

	func TargetFunc;

	//Определяем тип функции
	char* type = (char*)strstr(DeclareFunc, "void");
	if (type == NULL)//если тип возвращаемого значения не void...
		TargetFunc.some_return = true;//... то функция возращает значение
	else//...инче
		TargetFunc.some_return = false;//...не возвращаает значение

	strcpy_s(TargetFunc.func_name, Sourcefunc);//Скопировать имя функции

	TargetFunc.params = CountArgs(DeclareFunc);//Посчитать количество аргументов


	return TargetFunc;//Вернуть контейнер функции
}


int HowManyCalls(const char StringOfCode[MAX_LENGTH], const char SourceFunc[MAX_LENGTH]) {
	int Calls = 0;//Изначально считаем, что вызовов фукции не было
	const char* NameOfFunc = StringOfCode;
	//	1. Ищем количество вызовов функции
	while (NameOfFunc = strstr(NameOfFunc, SourceFunc))//Пока существует вхождение функции в строку
	{
		Calls++;//увеличиваем счетчик и ищем следующее вхождение
		NameOfFunc++;
	}
	return Calls;//2.Вернуть количество вызовов функции
}

int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows){
	
	//Определить место определения функции
	int DeclareRow = 0;
	DeclareRow = FindDeclareFunc(SourceCode, SourceFunc, Rows);
	
	//Выделить составляющие функции(возвращает / нет значение, количество аргументов)
	func TargetFunc = ExtractFunc(SourceCode[DeclareRow], SourceFunc);
	
	//Поиск первого неверного вызова исходной функции в main() и других фукнциях...
	bool FoundFunc = false;//Считать, что функция не найдена
	int ErrorRow = -2;
	bool ErrorCall = false;//Считать, что не верных вызово не было
	
	int Brackets = 0;
	for (int i = 0; i < Rows && !ErrorCall; i++) {//	для каждой строчки кода, пока не найден неверный вызов

		InFuncCount(SourceCode[i], Brackets);
		//	если происходит вызов исходной функции
		if (strstr(SourceCode[i], TargetFunc.func_name) != NULL && Brackets > 0) {
			int calls = HowManyCalls(SourceCode[i], TargetFunc.func_name);
			FoundFunc = true;//	считать, что функция найдена
			//	проверяем вызов функции с учетом возвращает значение, правильное количество аргументов
			if (strchr(SourceCode[i], '=') != NULL && !TargetFunc.some_return || CountArgs(SourceCode[i])*calls != TargetFunc.params * calls) {//	если вызов неверный(возвращаемое значение)
				ErrorCall = true;
				ErrorRow = i;//	запомнить номер строки с неверным вызовом
				if (CountArgs(SourceCode[i]) == -1) {
					ErrorCall = false;
					//	считать, что функция не найдена
					ErrorRow = -2;
					FoundFunc = false;
				} 
			}
		}
	}

	if (!ErrorCall && FoundFunc)
		ErrorRow = -1;

	return ErrorRow;//вернуть номер строки({ row } -место ошибки, { -1 } -ошибки нет, { -2 } -не найдена функция)
}


int main() {
	//исходные данные
	char SourceCode[MAX_ROWS][MAX_LENGTH];
	char SourceFunc[MAX_LENGTH];
	int Rows;

	//считывание исходных данных
	scanf("%s\n", &SourceFunc);
	scanf("%d\n", &Rows);

	if (Rows < 1 || Rows > 21) {
		printf("invalid value\n");
		return 0;
	}

	for (int i = 0; i < Rows; i++)
		gets_s(SourceCode[i]);

	int ErrorRow = SearchInvalidFuncCall(SourceCode, SourceFunc, Rows);//поиск неверного вызова функции в строке

	//обработка результата работы функции SearchInvalidFuncCall
	switch (ErrorRow) {
	case -1:
		printf("valid function call\n");
		break;
	case -2:
		printf("no function call\n");
		break;
	default:
		printf("%d", ErrorRow);
	}

	return 0;
}
