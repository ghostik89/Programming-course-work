#include <cstdio>
#include "func.h"

/*!�������� �� ������������ ������ ������� � �������� ����
	\param[in]: SourceCode - �������� ���
	\param[in]: func - �������� �������
	\param[in]: Rows - ���������� ����� � �������� ����
	\return: {row} - ����� ���������� �������
*/
int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], int Rows);





/*!�������� �� ������������ ������ ������� � �������� ����
	\param[in]: SourceCode - �������� ���
	\param[in]: func - �������� �������
	\param[in]: Rows - ���������� ����� � �������� ����
	\return: ����� ������({row} - ����� ������,{-1} - ������ ���, {-2} - �� ������� �������)
*/
int SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], int Rows){
	//1. ���������� ����� ����������� �������
	//	2. �������� ������������ �������(���������� / ��� ��������, ���������� ����������)
	//	3. ����� ������� ��������� ������ �������� ������� � main() � ������ ��������...
	//	...�������, ��� ������� �� �������
	//	...�������, ��� �� ������ ������ �� ����
	//	��� ������ ������� ����, ���� �������� �������� �����
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