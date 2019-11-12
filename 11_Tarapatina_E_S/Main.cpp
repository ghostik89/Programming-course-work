#include <cstdio>
#include "func.h"
#include <cstring>


int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	
	int DeclareCloumn; //���, ��� ����������� �������
	int Bracket;	   //��������������� ����������, ����� �� ������ ���������� ������� � ���� ������ �������

	Bracket = 0;
	DeclareCloumn = -1; //���������� �������, ��� ���������� �� �������
	for (int i = 0; i < Rows; i++) {
		if (!strcmp(SourceCode[i], "{"))
			Bracket++;
		if (!strcmp(SourceCode[i], "}"))
			Bracket--;
		char* FindingName;
		FindingName = (char *)strstr(SourceCode[i], SourceFunc);
		if ((FindingName != NULL || !strcmp(FindingName, SourceCode[i])) && Bracket != 0) {
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

	char* type = (char*)strchr(DeclareFunc, ' ');
	int len = type - DeclareFunc + 1;
	strncpy(type, DeclareFunc, len);
	if (!strcmp(type, "void"))
		TargetFunc.some_return = false;
	else
		TargetFunc.some_return = true;

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
	//DeclareRow = FindDeclareFunc(SourceCode, SourceFunc, Rows);
	//	2. �������� ������������ �������(���������� / ��� ��������, ���������� ����������)
	func TargetFunc;
	//TargetFunc = ExtractFunc(SourceCode[DeclareRow], SourceFunc);
	//	3. ����� ������� ��������� ������ �������� ������� � main() � ������ ��������...
	//	...�������, ��� ������� �� �������
	//	...�������, ��� �� ������ ������ �� ����
	//	��� ������ ������� ����, ���� �� ������ �������� �����
	//	���� ���������� ����� �������� �������
	//	�������, ��� ������� �������
	//	��������� ����� ������� � ������ ���������� ��������, ���������� ���������� ����������
	//	���� ����� ��������
	//	��������� ����� ������ � �������� �������
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
