#include <cstdio>

const int MAX_LENGTH = 256;
const int MAX_ROWS = 20;


/*! �������� ����������� ������ �������
*	\param[in]: StringOfCode - ������ ���������� ����
*	\param[in]: NameOfFunc - ��� �������
*	\return: ������������ ��������� �������
*	-1 - ������� � ������ �� �������
*	-2 - ������� ������� ���������
*	val - ����� ������ � �������
*/
int	IsRightCallFunc(const char StringOfCode[MAX_LENGTH], const char* NameOfFunc);


/*!
	\param[in]: SourceCode - �������� ���
	\param[out]: InvalidPlace - ����� � ��������� ������� {-1, -1} - ������� �� �������
*/
void SearchInvalidFuncCall(const char SourceCode[MAX_ROWS][MAX_LENGTH], int* InvalidPlace);


int main() {

	return 0;
}