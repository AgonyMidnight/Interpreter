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
std::fstream FIdentity;//
std::fstream FDelimiters;
std::fstream FOperations;
std::fstream FString;//
std::ifstream FSource;
std::fstream FOut; //
std::fstream FNumber;//
std::fstream FOutRPN;

int main()
{
	system("del Out.txt");
	system("del Number.txt");
	system("del String.txt");
	system("del Identity.txt");
	Begin(FIdentity, FSource, FOut, FOutRPN, FWorkWord, FNumber,FDelimiters, FOperations, FString);
	std::string MyMatrix[m1][m2];
	setMatrix(Table, MyMatrix);
	std::string buff="";
	std::string parsBuff = "";
	int status = 0; 
	std::string move = "";
	std::string firstParsMove = "";
	std::string secondParsMove = "";

	bool dve_tochki = false;

	while (!FSource.eof()){
		std::getline(FSource, buff);// var := 1 + b;
		int status = 0;

		for (int i = 0; i < buff.length() || parsBuff != ""; i++) {
			move = getFindDecision(WhatIsIt(buff[i], Book, Number), status, MyMatrix);
			
			if ((move.length() <= 2) && (move != "F") && (move != "Z")) {
				status = stoi(move);
				parsBuff = parsBuff + buff[i];
				continue;
			}
			if (move == "F") {
				setF();
			}
			if (move == "Z") { std::cout << "U are sun"; FOut.close();  system("Out.txt");exit(0); }
	
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
					
					parsBuff = buff[i]; move = ""; firstParsMove = ""; secondParsMove = "";
					if (status == 0) { parsBuff = ""; }
					
				}
				else if (secondParsMove == "P3") {
					/////ПРОВЕРИТЬ!!!!!111111111!!!!!!!!!!!!!!!ВАЖНААА!ааАААаааа!!11111ОДИН!!!АДЫН!!!!
					if (firstParsMove == "15") {	//исправлени косяка с 7.
						parsBuff.resize(parsBuff.size() - 1);
						dve_tochki = true;
					}
					
					getP_Three(FNumber, FOut, ++N, parsBuff);
					//status = 0;
					parsBuff = buff[i]; move = ""; 
					//туточки?

					if (firstParsMove == "11" || status == 14 || status == 7) {	//исправление косяка с двумя подряд разделителями
						i++;	
					}

					firstParsMove = ""; secondParsMove = "";
					if (status == 16) i++; //от сглаза двух палочек
					--i; continue;
				}
				else if (secondParsMove == "P4") {
					if (firstParsMove == "0" && dve_tochki == true) {
						parsBuff += '.';
						dve_tochki = false;
						i++;
					}
					
					getP_Four(parsBuff,FDelimiters,FOut);
					//status = 0;
					parsBuff = ""; move = ""; firstParsMove = ""; secondParsMove = "";
					if (status == 14 || status == 7) i++;	//исправление косяка с := после пробела
					--i; continue;
					
				}
				else if (secondParsMove == "P5") {
					getP_Five(parsBuff, FOperations, FOut);
					//status = 0;
					parsBuff = buff[i]; move = ""; firstParsMove = ""; secondParsMove = "";
					if (!(status == 1 || status == 2 || status == 3))  //траблы с двойной буквой
						--i;
					continue;
					//тут?) при 3

				}
				else if (secondParsMove == "P6") {
					parsBuff = getP_Six(parsBuff, buff[i]);
					move = ""; firstParsMove = ""; secondParsMove = "";
				}
				else if (secondParsMove == "P7") {
					i = getP_Seven(buff, i, ++S , FOut, FString);
					//status = 0;
					parsBuff = ""; move = ""; firstParsMove = ""; secondParsMove = "";
					//--i; 
					continue;
				}

			}
		}
		FOut << std::endl;
	}
	FOut.close();
	FIdentity.close();
	FNumber.close();
	FString.close();

	std::cout << "U R sun" << std::endl;
	system("Out.txt");
	system("Number.txt");
	//system("String.txt");
	//system("Identity.txt");
}

