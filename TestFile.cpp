#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <string>
#include <iostream.h>
#include <conio.h>

 int _tmain(int argc, _TCHAR* argv[])
{
	char* hello = "Hello,";
	std::string world = " world!";

	std::cout<<hello<<world;
	getch();
	return 0;
}
