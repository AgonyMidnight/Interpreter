#pragma once

#define m1 16	//колличесво строк
#define m2 14	//колличество столбцов

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>

void Begin(std::fstream& FIdentity, std::ifstream& FSource, std::fstream& FOut, 
	std::fstream& FOutRPN, std::ifstream& FWorkWord, std::fstream& FNumber, 
	std::fstream& FDelimiters, std::fstream& FOperations, std::fstream& FString);
void setMatrix(std::ifstream& Table, std::string(&MyMatrix)[m1][m2]);
void Add_word(std::string temp, int I, std::fstream& FOut, std::fstream& FCode);
void Add_Number(std::string temp, int K, std::fstream& FOut, std::fstream& FCode);
void Add_String_Const(std::string temp, int S, std::fstream& FOut, std::fstream& FCode);
void getP_Two(std::ifstream& WorkWord, std::string parsbuff, std::fstream& FOut, std::fstream& FIdentity, int I);
void getP_One(std::fstream& FIdentity, std::string parsbuff, std::fstream& FOut, int I);
void getP_Three(std::fstream& FNumber, std::fstream& FOut, int N, std::string parsBuff);
void getP_Four(std::string parsBuff, std::fstream& FDelimiters, std::fstream& FOut);
void getP_Five(std::string parsBuff, std::fstream& FOperations, std::fstream& FOut);
std::string getP_Six(std::string parsBuff, char element);
int getP_Seven(std::string buff, int i, int S, std::fstream& FOut, std::fstream& FString);
int WhatIsIt(char parsbuff, char Book[], char Number[]);
std::string getFindDecision(int AnyLexem, int status, std::string(&MyMatrix)[m1][m2]);
void setF();

void SemanticOperationOne(char temp,  int temp2);
