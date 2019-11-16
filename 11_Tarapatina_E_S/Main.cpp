#include <csstdio>
#include "func.h"
#include <cstring>


int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	
	int DeclareCloumn; //���, ��� ����������� �������
	int Bracket;	   //��������������� ����������, ����� �� ������ ���������� ������� � ���� ������ �������

	Bracket = 0;
	DeclareCloumn = -1; //���������� �������, ��� ���������� �� �������
	for (int i = 0; i < Rows && DeclareCloumn == -1; i++) {
		if (!strcmp(SourceCode[i], "{"))
			Bracket++;
		if (!strcmp(SourceCode[i], "}"))
			Bracket--;
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

	char* LBracket = (char*)strchr(DeclareFunc, '(');
	char* RBracket = (char*)strchr(DeclareFunc, ')');
	int Args;

	Args = 0;
	if (strcmp(LBracket + 1, RBracket)) {
		Args++;
		for (int i = 0; strcmp(LBracket + i, RBracket); i++)
			if (LBracket[i] == ',')
				Args++;
	}
	TargetFunc.params = Args;

	return TargetFunc;
}


int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows){
	//1. ���������� ����� ����������� �������
	int DeclareRow = 0;
	DeclareRow = FindDeclareFunc(SourceCode, SourceFunc, Rows);
	//	2. �������� ������������ �������(���������� / ��� ��������, ���������� ����������)
	func TargetFunc;
	TargetFunc = ExtractFunc(SourceCode[DeclareRow], SourceFunc);
	//	3. ����� ������� ��������� ������ �������� ������� � main() � ������ ��������...
	//	...�������, ��� ������� �� �������
	bool FoundFunc = false;
	//	...�������, ��� �� ������ ������ �� ����
	bool ErrorCall = false;
	int ErrorRow = -2;
	//	��� ������ ������� ����, ���� �� ������ �������� �����
	int Brackets = 0;
	for (int i = 0; i < Rows && !ErrorCall; i++) {
		if (!strcmp(SourceCode[i], "{"))
			Brackets++;
		if (!strcmp(SourceCode[i], "}"))
			Brackets--;
		//	���� ���������� ����� �������� �������
		if (strstr(TargetFunc.func_name, SourceFunc) != NULL && Brackets > 0) {
			//	�������, ��� ������� �������
			FoundFunc = true;
			//	��������� ����� ������� � ������ ���������� ��������, ���������� ���������� ����������
			//	���� ����� ��������
			//	��������� ����� ������ � �������� �������
		}
	}
	//	4.������� ����� ������({ row } -����� ������, { -1 } -������ ���, { -2 } -�� ������� �������)

	return 6;
}


int main() {

	return 0;
}

func ExtractFunc(const char DeclareFunc[MAX_LENGTH])
{
	return func();
}
