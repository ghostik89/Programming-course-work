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
	
	int DeclareCloumn; //���, ��� ����������� �������
	int Bracket;	   //��������������� ����������, ����� �� ������ ���������� ������� � ���� ������ �������

	Bracket = 0;
	DeclareCloumn = -1; //���������� �������, ��� ���������� �� �������
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
		/*if (!strcmp(SourceCode[i], "{"))
			Brackets++;
		if (!strcmp(SourceCode[i], "}"))
			Brackets--;*/
		InFuncCount(SourceCode[i], Brackets);
		//	���� ���������� ����� �������� �������
		if (strstr(SourceCode[i], TargetFunc.func_name) != NULL && Brackets > 0) {
			
			FoundFunc = true;//	�������, ��� ������� �������
			//	��������� ����� ������� � ������ ���������� ��������, ���������� ���������� ����������
			if (strchr(SourceCode[i], '=') != NULL && !TargetFunc.some_return || CountArgs(SourceCode[i]) != TargetFunc.params) {//	���� ����� ��������(������������ ��������)
				ErrorCall = true;
				ErrorRow = i + 1;//	��������� ����� ������ � �������� �������
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
			//if (CountArgs(SourceCode[i]) != TargetFunc.params) {//	���� ����� ��������(���������� ����������)
			//		ErrorCall = true;
			//		ErrorRow = i + 1;//	��������� ����� ������ � �������� �������
			//}
		}
	}

	if (!ErrorCall && FoundFunc)
		ErrorRow = -1;

	return ErrorRow;//������� ����� ������({ row } -����� ������, { -1 } -������ ���, { -2 } -�� ������� �������)
}


int main() {

	return 0;
}
