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

 int _tmain(int argc, _TCHAR* argv[])
{
	Scanner scanner = Scanner();
	std::string filePath = "L://Embarcadero RAD Studio XE8 22.0.19027.8951 Architect//PROJECTS//Scanner//test.txt";
	list<Lexem> lexList = scanner.scan(filePath);

	//=================
	//* test output
	for(list<Lexem>::iterator iter = lexList.begin();
			iter != lexList.end(); ++iter)
	{
		std::cout << iter->getValue() << " ";
		std::cout << iter->getLine() << " ";
		std::cout << iter->getPosition() << " ";
		std::cout << iter->getLine() << " ";
		std::cout << iter->getLexType() << std::endl;
	}
	//===============

	//std::cout << sizeof(filePath);

	int b = 011;
	std::cout << b;

	//double c = 1.;
    //char cc = 'dhh ';
	int a = 0;
	std::cin >> a;
	return 0;
}