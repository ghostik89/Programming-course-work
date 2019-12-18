#include <cstdio>
#include "func.h"
#include <cstring>


int CountArgs(const char StringOfCode[MAX_LENGTH]){
	char* LBracket = (char*)strchr(StringOfCode, '(');
	char* RBracket = (char*)strchr(StringOfCode, ')');
	int Args;

	Args = 0;
	if (strcmp(LBracket + 1, RBracket)) {
		Args++;
		for (int i = 0; strcmp(LBracket + i, RBracket); i++)
			if (LBracket[i] == ',')
				Args++;
	}

	return Args;
}

void InFuncCount(const char StringOfCode[MAX_LENGTH], int& BraketsCounter){
	if (strstr(StringOfCode, "{") != NULL)
		BraketsCounter++;
	if (strstr(StringOfCode, "}") != NULL)
		BraketsCounter--;
}

int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	
	int DeclareCloumn; //там, где объ€вл€етс€ фукнци€
	int Bracket;	   //вспомогательна€ переменна€, чтобы не искать объ€вление фукнции в теле другой функции

	Bracket = 0;
	DeclareCloumn = -1; //изначально считаем, что объ€вление не найдено
	for (int i = 0; i < Rows && DeclareCloumn == -1; i++) {
		/*if (!strcmp(SourceCode[i], "{"))
			Bracket++;
		if (!strcmp(SourceCode[i], "}"))
			Bracket--;*/
		InFuncCount(SourceCode[i], Bracket);
		char* FindingName;
		FindingName = (char *)strstr(SourceCode[i], SourceFunc);
		if (FindingName != NULL && Bracket == 0) {
			char* LBracket = (char *)strchr(SourceCode[i], '(');
			char* RBracket = (char*)strchr(SourceCode[i], ')');
			if (LBracket != NULL && RBracket != NULL)
				DeclareCloumn = i;
		}
	}
	return DeclareCloumn;
}


func ExtractFunc(const char DeclareFunc[MAX_LENGTH], const char Sourcefunc[MAX_LENGTH]) {

	func TargetFunc;

	char* type = (char*)strstr(DeclareFunc, "void");
	if (type == NULL)
		TargetFunc.some_return = true;
	else
		TargetFunc.some_return = false;

	strcpy_s(TargetFunc.func_name, Sourcefunc);

	/*char* LBracket = (char*)strchr(DeclareFunc, '(');
	char* RBracket = (char*)strchr(DeclareFunc, ')');
	int Args;

	Args = 0;
	if (strcmp(LBracket + 1, RBracket)) {
		Args++;
		for (int i = 0; strcmp(LBracket + i, RBracket); i++)
			if (LBracket[i] == ',')
				Args++;
	}*/
	TargetFunc.params = CountArgs(DeclareFunc);


	return TargetFunc;
}


int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows){
	
	//ќпределить место определени€ функции
	int DeclareRow = 0;
	DeclareRow = FindDeclareFunc(SourceCode, SourceFunc, Rows);
	
	//¬ыделить составл€ющие функции(возвращает / нет значение, количество аргументов)
	func TargetFunc = ExtractFunc(SourceCode[DeclareRow], SourceFunc);
	
	//ѕоиск первого неверного вызова исходной функции в main() и других фукнци€х...
	bool FoundFunc = false;//—читать, что функци€ не найдена
	int ErrorRow = -2;
	bool ErrorCall = false;//—читать, что не верных вызово не было
	
	int Brackets = 0;
	for (int i = 0; i < Rows && !ErrorCall; i++) {//	дл€ каждой строчки кода, пока не найден неверный вызов
		/*if (!strcmp(SourceCode[i], "{"))
			Brackets++;
		if (!strcmp(SourceCode[i], "}"))
			Brackets--;*/
		InFuncCount(SourceCode[i], Brackets);
		//	если происходит вызов исходной функции
		if (strstr(SourceCode[i], TargetFunc.func_name) != NULL && Brackets > 0) {
			
			FoundFunc = true;//	считать, что функци€ найдена
			//	провер€ем вызов функции с учетом возвращает значение, правильное количество аргументов
			if (strchr(SourceCode[i], '=') != NULL && !TargetFunc.some_return || CountArgs(SourceCode[i]) != TargetFunc.params) {//	если вызов неверный(возвращаемое значение)
				ErrorCall = true;
				ErrorRow = i + 1;//	запомнить номер строки с неверным вызовом
			}
			/*char* LBracket = (char*)strchr(SourceCode[i], '(');
			char* RBracket = (char*)strchr(SourceCode[i], ')');
			int Args;

			Args = 0;
			if (strcmp(LBracket + 1, RBracket) && !ErrorCall) {
				Args++;
				for (int i = 0; strcmp(LBracket + i, RBracket); i++)
					if (LBracket[i] == ',')
						Args++;
				
			}*/
			//if (CountArgs(SourceCode[i]) != TargetFunc.params) {//	если вызов неверный(количество аргументов)
			//		ErrorCall = true;
			//		ErrorRow = i + 1;//	запомнить номер строки с неверным вызовом
			//}
		}
	}

	if (!ErrorCall && FoundFunc)
		ErrorRow = -1;

	return ErrorRow;//вернуть номер строки({ row } -место ошибки, { -1 } -ошибки нет, { -2 } -не найдена функци€)
}


int main() {

	return 0;
}
