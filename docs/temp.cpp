//Заглушка возвращает ожидаемые выходные данные 
int HowManyCalls(const char StringOfCode[MAX_LENGTH], const char SourceFunc[MAX_LENGTH]) {
	int Calls = 1;
	return Calls;
}
//Заглушка возвращает ожидаемые выходные данные
int CountArgs(const char StringOfCode[MAX_LENGTH]){
	int Args = 0;
	return Args;
}
//Заглушка возвращает ожидаемые выходные данные
int FindDeclareFunc(const char SourceCode[MAX_ROWS][MAX_LENGTH], const char SourceFunc[MAX_LENGTH], const int Rows) {
	int DeclareCloumn = 0;
	return DeclareCloumn;
}
//Заглушка возвращает ожидаемые выходные данные
func ExtractFunc(const char DeclareFunc[MAX_LENGTH], const char Sourcefunc[MAX_LENGTH]) {
	func TargetFunc;
	TargetFunc.some_return = false;
	strcpy_s(TargetFunc.func_name, Sourcefunc);
	TargetFunc.params = CountArgs(DeclareFunc);
	return TargetFunc;
}





