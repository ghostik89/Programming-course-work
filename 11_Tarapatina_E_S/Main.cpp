#include <cstdio>
#include "func.h"
#include <cstring>

/*!�������� �� ������������ ������ ������� � �������� ����
	\param[in]: SourceCode - �������� ���
	\param[in]: func - �������� �������
	\param[in]: Rows - ���������� ����� � �������� ����
	\return: {row} - ����� ���������� �������
*/
int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	
	int DeclareCloumn = -1; //���������� �������, ��� ���������� �� �������
	bool Bracket = false;
	//�������� ��� ���������� ����
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
			if (strspn(ReturnValue, AllTypes) > 3)//���� ������ ��� ������������� ������� � ������
				DeclareCloumn = i;		
		}
	}
	return DeclareCloumn;
}


/*!�������������� ���������� ������� �� ������ � ��������� func
	\param[in]: DeclareFunc - ���������� �������
	\return: func - ��������� ��� �������
*/
func ExtractFunc(const char DeclareFunc[MAX_LENGTH]) {

}


/*!�������� �� ������������ ������ ������� � �������� ����
	\param[in]: SourceCode - �������� ���
	\param[in]: func - �������� �������
	\param[in]: Rows - ���������� ����� � �������� ����
	\return: ����� ������({row} - ����� ������,{-1} - ������ ���, {-2} - �� ������� �������)
*/
int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows){
	//1. ���������� ����� ����������� �������
	//	2. �������� ������������ �������(���������� / ��� ��������, ���������� ����������)
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
