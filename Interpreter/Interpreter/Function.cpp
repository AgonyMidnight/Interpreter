#include "Header.h"



void Begin(std::fstream& FIdentity, std::ifstream& FSource, std::fstream& FOut, 
	std::fstream& FOutRPN, std::ifstream& FWorkWord, std::fstream& FNumber,
	std::fstream& FDelimiters, std::fstream& FOperations, std::fstream& FString) {
	//открываем файлы+

	
	FWorkWord.open("WorkWord.txt");
	FIdentity.open("Identity.txt", std::ios::in | std::ios::app); //файл с шифром
	FSource.open("Source.txt");//исходный файл
	FOut.open("Out.txt", std::ios::out);
	FOutRPN.open("FOutRPN.txt", std::ios::out);
	FNumber.open("Number.txt", std::ios::in | std::ios::app);
	FDelimiters.open("Delimiters.txt", std::ios::in);
	FOperations.open("Operations.txt", std::ios::in);
	FString.open("String.txt", std::ios::in | std::ios::app);
	//проверка на наличие
	if ((!FIdentity) || (!FSource)) {
		std::cout << "Files not find! Error!" << std::endl;
		exit(0);
		//return 0;
	}
}

void setMatrix(std::ifstream& Table, std::string (&MyMatrix)[m1][m2]) {
	Table.open("table.txt");
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m2; j++) {
			Table >> MyMatrix[i][j];
		}
	}
}

void Add_word(std::string temp, int I, std::fstream& FOut, std::fstream& FIdentity) { //добавить слово в словарь
	//W++;
	FIdentity.clear();
	FIdentity.seekg(0);
	FIdentity << std::endl << temp << " " << "I" << I;
	FOut << "I" << I << " ";

}


void Add_Number(std::string temp, int K, std::fstream& FOut, std::fstream& FCode) { //добавить число
	//K++;
	FCode.clear();
	FCode.seekg(0);
	FCode << std::endl << temp << " "<< "K" << K ;
	FOut << "K" << K;
}

void Add_String_Const(std::string temp, int S, std::fstream& FOut, std::fstream& FCode) { //добавить строковую константу
	//K++;
	FCode.clear();
	FCode.seekg(0);
	FCode << std::endl << temp << " " << "S" << S;
	FOut << "S" << S;
}

void getP_Two(std::ifstream& WorkWord, std::string parsbuff, std::fstream& FOut, std::fstream& FIdentity,int I) {
	WorkWord.clear();
	WorkWord.seekg(0);
	bool find = false;
	std::string temp = " ";
	while (!WorkWord.eof()) {
		WorkWord >> temp;
		if (parsbuff == temp) {
			WorkWord >> temp;
			FOut << temp<< " ";
			find = true;
		}
	}
	if (find == false) {
		getP_One(FIdentity, parsbuff, FOut, I);
	}
}


void getP_One(std::fstream& FIdentity, std::string parsbuff, std::fstream& FOut, int I) {
	FIdentity.clear();
	FIdentity.seekg(0);
	bool find = false;;
	std::string temp = " ";
	while (!FIdentity.eof()) {
		FIdentity >> temp;
		if (parsbuff == temp) {
			FIdentity >> temp;
			FOut << temp << " ";
			find = true;
		}
	}
	if (find == false) {
		Add_word(parsbuff, I, FOut, FIdentity);
	}
}
void getP_Three(std::fstream& FNumber, std::fstream& FOut, int N, std::string parsBuff) {
	N ++;
	FNumber.clear();
	FNumber.seekg(0);
	FNumber << std::endl << parsBuff << " " << "N" << N;
	FOut << "N" << N << " ";
}

void getP_Four(std::string parsBuff, std::fstream& FDelimiters, std::fstream& FOut) {
	FDelimiters.clear();
	FDelimiters.seekg(0);
	std::string temp;
	while (!FDelimiters.eof()) {
		FDelimiters >> temp;
		if (parsBuff == temp) {
			FDelimiters >> temp;
			FOut << temp << " ";
		}
	}
}

void getP_Five(std::string parsBuff, std::fstream& FOperations, std::fstream& FOut) {
	FOperations.clear();
	FOperations.seekg(0);
	std::string temp;
	while (!FOperations.eof()) {
		FOperations >> temp;
		if (parsBuff == temp) {
			FOperations >> temp;
			FOut << temp<< " ";
		}
	}
}

std::string getP_Six(std::string parsBuff, char element) {
	return parsBuff + element;
}

int getP_Seven(std::string buff, int i, int S, std::fstream& FOut, std::fstream& FString ) {
	std::string temp = "";
	i++;
	for (i; buff[i] != '\''; i++) {
		temp = temp + buff[i];
	}
	FString << temp << " "<< "S" << S<<std::endl;
	FOut << "S" << S << " ";
	return i;
}

std::string getFindDecision(int AnyLexem, int status, std::string(&MyMatrix)[m1][m2]) {
	return MyMatrix[status][AnyLexem];
}

void setF() {
	std::cout << "!!!!!!!!Error!!!!!";
	std::system("pause");
}

int WhatIsIt(char parsbuff, char Book[], char Number []) {
	for (int i = 0; i < 52; i++) {
		if (parsbuff == Book[i]) {
			return 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (parsbuff == Number[i]) {
			return 1;
		}
	}
	if (parsbuff == '.') { return 2; }
	if (parsbuff == '<') { return 3; }
	if (parsbuff == '<') { return 4; }
	if (parsbuff == '+' || parsbuff == '-' || parsbuff == '*' || parsbuff == '^') { return 5; }
	if (parsbuff == '=') { return 6; }
	if (parsbuff == 'e') { return 7; }
	if (parsbuff == '\'') { return 8; }
	if (parsbuff == '/') { return 9; }
	if (parsbuff == ' ' || parsbuff == ',' || parsbuff == ';' || parsbuff == ':' || parsbuff == '('
		|| parsbuff == ')' || parsbuff == '[' || parsbuff == ']' ) { return 10; }
	if (parsbuff == '\n') { return 11; }
	if (parsbuff == '\0') { return 12; }
	if (parsbuff == ':') { return 13; }
	else std::cout << "разделитель не найден";
}
void SemanticOperationOne(char temp, int temp2, std::string move ) {


}