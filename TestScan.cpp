#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <iostream.h>
#include "Scanner.h"
#include <fstream.h>
#include <conio.h>
#include <windows.h>

 int _tmain(int argc, _TCHAR* argv[])
{
	SetConsoleCP(1251); // ���� � ������� � ��������� 1251
	SetConsoleOutputCP(1251); // ����� �� ������� � ��������� 1251. ����� ������ ����� �������� ����� ������� �� Lucida Console ��� Consolas
	Scanner scanner = Scanner();
	std::string filePath = "L://Embarcadero RAD Studio XE8 22.0.19027.8951 Architect//PROJECTS//����� Scanner//TestFile.cpp";
	list<Lexem> lexList = scanner.scan(filePath);

	//=================
	//* test output
	for(list<Lexem>::iterator iter = lexList.begin();
			iter != lexList.end(); ++iter)
	{
		std::cout << "��������: ";
		std::cout << iter->getValue() <<" ";
		std::cout << iter->getLine() << " ";
		std::cout << iter->getPosition() << " ";
		std::cout << iter->getLexType() << std::endl;
	}
	//===============

	list<ErrorMessage> errors = scanner.getErrors();
	std::cout << std::endl;
	for(list<ErrorMessage>::iterator iter = errors.begin();
			iter != errors.end(); ++iter)
	{
		std::cout << iter->getLine() << " ";
		std::cout << iter->getPos() << " ";
		std::cout << iter->getText() << std::endl;
	}
	getch();
	return 0;
}
