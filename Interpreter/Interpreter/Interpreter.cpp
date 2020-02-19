#include "Header.h"

int W = 20;		//счетчик словаря
int O = 11;		//операторов
int I = 10;		//инициализация
int R = 20;		//разделители
int K = 10;		//константа
int N = 10;		//число
int S = 10;    //строкавая константа
int C = 10;    //Комментарии
int F = 10;    //Процедуры и фуннкции
int G = 10;     //Безусловный переход

extern char Book[53] = { 'q','Q','w','W','e','E','r','R','t','T','y','Y','u',
'U','i','I','o','O','p','P','a','A','s','S','d','D','f','F','g','G','h','H','j','J',
'k','K','l','L','z','Z','x','X','c','C','v','V','b','B','n','N','m','M', '_' };

//словарь цифр
extern char Number[10] = { '0', '1', '2', '3', '4', '5','6','7','8','9' };

//словарь разделителей
//extern char Delimiters[19] = { '<', '>', ',', '.','(',')',';',':','[',']',' ','_', '..','-','"','\'', '{', '}' , '=' };

std::ifstream Table;
std::ifstream FWorkWord;
std::fstream FIdentity;
std::fstream FDelimiters;
std::fstream FOperations;
std::fstream FString;
std::ifstream FSource;
std::fstream FOut;
std::fstream FNumber;
std::fstream FOutRPN;

int main()
{
	Begin(FIdentity, FSource, FOut, FOutRPN, FWorkWord, FNumber,FDelimiters, FOperations, FString);
	std::string MyMatrix[12][13];
	setMatrix(Table, MyMatrix);
	std::string buff="";
	std::string parsBuff = "";
	int status = 0; 
	std::string move = "";
	std::string firstParsMove = "";
	std::string secondParsMove = "";

	while (!FSource.eof()){
		std::getline(FSource, buff);// var := 1 + b
		int status = 0;

		for (int i = 0; i < buff.length(); i++) {
			move = getFindDecision(WhatIsIt(buff[i], Book, Number), status, MyMatrix);
			if ((move.length() <= 2) && (move != "F")) {
				status = stoi(move);
				parsBuff = parsBuff + buff[i];
				continue;
			}
			if (move == "F") {
				setF();
			}
			if (move.length() > 2) {
				if (move[2] == ',') {
					firstParsMove = "";
					secondParsMove = "";
					firstParsMove = firstParsMove + move[0] + move[1];
					status = stoi(firstParsMove);
					for (int j = 3; j < move.length(); j++) {
						secondParsMove = secondParsMove + move[j];
					}
					//parsBuff = parsBuff + buff[i];
				}
				else if(move[1]==','){
					firstParsMove = move[0];
					status = stoi(firstParsMove);
					for (int j = 2; j < move.length(); j++) {
						secondParsMove = secondParsMove + move[j];
					}
					//parsBuff = parsBuff + buff[i];
				}
				if (secondParsMove == "P1"){
					getP_One(FIdentity, parsBuff, FOut,++I);
					//status = 0;
					parsBuff =""; move = ""; firstParsMove = ""; secondParsMove = "";
				
				}
				else if (secondParsMove == "P2") {
					getP_Two(FWorkWord, parsBuff, FOut, FIdentity, ++I);
					//status = 0;
					parsBuff = ""; move = ""; firstParsMove = ""; secondParsMove = "";
					
				}
				else if (secondParsMove == "P3") {
					getP_Three(FNumber, FOut, N, parsBuff);
					//status = 0;
					parsBuff = buff[i]; move = ""; firstParsMove = ""; secondParsMove = "";
					--i; continue;
				}
				else if (secondParsMove == "P4") {
					getP_Four(parsBuff,FDelimiters,FOut);
					//status = 0;
					parsBuff = ""; move = ""; firstParsMove = ""; secondParsMove = "";
					--i; continue;
				}
				else if (secondParsMove == "P5") {
					getP_Five(parsBuff, FOperations, FOut);
					//status = 0;
					parsBuff = buff[i]; move = ""; firstParsMove = ""; secondParsMove = "";
					--i; continue;
				}
				else if (secondParsMove == "P6") {
					parsBuff = getP_Six(parsBuff, buff[i]);
				}
				else if (secondParsMove == "P7") {
					i = getP_Seven(buff, i, ++S , FOut, FString);
					//status = 0;
					parsBuff = buff[i]; move = ""; firstParsMove = ""; secondParsMove = "";
					--i; continue;
				}

			}
		}
	}
	
}

