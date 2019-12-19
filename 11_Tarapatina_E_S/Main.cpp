#include <cstdio>
#include "func.h"
#include <cstring>
#include <cctype>  


int CountArgs(const char StringOfCode[MAX_LENGTH]){
	char* LBracket = (char*)strchr(StringOfCode, '(');
	char* RBracket = (char*)strchr(StringOfCode, ')');
	int Args , Spaces;

	Args = 0;
	Spaces = 0;
	if (strcmp(LBracket + 1, RBracket)) {
		Args++;
		for (int i = 0; strcmp(LBracket + i, RBracket); i++) {
			if (LBracket[i] == ',')
				Args++;
			if (isspace(LBracket[i]))
				Spaces++;
		}
	}
	if (Spaces == strlen(LBracket) - 2 || (strchr(StringOfCode,';') != NULL && Spaces == strlen(LBracket) - 3))
		Args = 0;

	return Args;
}

void InFuncCount(const char StringOfCode[MAX_LENGTH], int& BraketsCounter){
	if (strstr(StringOfCode, "{") != NULL)
		BraketsCounter++;
	if (strstr(StringOfCode, "}") != NULL)
		BraketsCounter--;
}

int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	
	int DeclareCloumn; //���, ��� ����������� �������
	int Bracket;	   //��������������� ����������, ����� �� ������ ���������� ������� � ���� ������ �������

	Bracket = 0;
	DeclareCloumn = -1; //���������� �������, ��� ���������� �� �������
	for (int i = 0; i < Rows && DeclareCloumn == -1; i++) {

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

	TargetFunc.params = CountArgs(DeclareFunc);


	return TargetFunc;
}


int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows){
	
	//���������� ����� ����������� �������
	int DeclareRow = 0;
	DeclareRow = FindDeclareFunc(SourceCode, SourceFunc, Rows);
	
	//�������� ������������ �������(���������� / ��� ��������, ���������� ����������)
	func TargetFunc = ExtractFunc(SourceCode[DeclareRow], SourceFunc);
	
	//����� ������� ��������� ������ �������� ������� � main() � ������ ��������...
	bool FoundFunc = false;//�������, ��� ������� �� �������
	int ErrorRow = -2;
	bool ErrorCall = false;//�������, ��� �� ������ ������ �� ����
	
	int Brackets = 0;
	for (int i = 0; i < Rows && !ErrorCall; i++) {//	��� ������ ������� ����, ���� �� ������ �������� �����

		InFuncCount(SourceCode[i], Brackets);
		//	���� ���������� ����� �������� �������
		if (strstr(SourceCode[i], TargetFunc.func_name) != NULL && Brackets > 0) {
			
			FoundFunc = true;//	�������, ��� ������� �������
			//	��������� ����� ������� � ������ ���������� ��������, ���������� ���������� ����������
			if (strchr(SourceCode[i], '=') != NULL && !TargetFunc.some_return || CountArgs(SourceCode[i]) != TargetFunc.params) {//	���� ����� ��������(������������ ��������)
				ErrorCall = true;
				ErrorRow = i + 1;//	��������� ����� ������ � �������� �������
			}
		}
	}

	if (!ErrorCall && FoundFunc)
		ErrorRow = -1;

	return ErrorRow;//������� ����� ������({ row } -����� ������, { -1 } -������ ���, { -2 } -�� ������� �������)
}


int main() {
	//�������� ������
	char SourceCode[MAX_ROWS][MAX_LENGTH];
	char SourceFunc[MAX_LENGTH];
	int Rows;

	//���������� �������� ������
	scanf("%s\n", &SourceFunc);
	scanf("%d\n", &Rows);

	for (int i = 0; i < Rows; i++)
		gets_s(SourceCode[i]);

	int ErrorRow = SearchInvalidFuncCall(SourceCode, SourceFunc, Rows);//����� ��������� ������ ������� � ������

	//��������� ���������� ������ ������� SearchInvalidFuncCall
	switch (ErrorRow) {
	case -1:
		printf("valid function call\n");
		break;
	case -2:
		printf("no function call\n");
		break;
	default:
		printf("%d\n", ErrorRow);
	}

	return 0;
}
