#pragma hdrstop
#pragma argsused

#include <iostream.h>
#include "HashTable.h"
#include <fstream.h>
#include <string>

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>

/*==================
 * It is test usage of Hash Table
====================*/

//int xet = 84;
//int val = 84;

 int _tmain(int argc, _TCHAR* argv[])
{
	/*std::string buff;
	int arr[90], arr2[90];
	for(int i = 0; i < 90; i++)
	{
		arr[i] = -1;
		arr[2] = -1;
	}

	int i = 0;

	bool original = false;

	while(!original)
	{

	i = 0;
	ifstream f2;
	f2.open("L://Embarcadero RAD Studio XE8 22.0.19027.8951 Architect//PROJECTS//Scanner//hash.txt");
	if (!f2) {
		std::cout << "File not found!";
	}

	while(!f2.eof()) //loop to end of file. Reads every character
	{
		f2 >> buff;
		arr[i] = hashFunction(buff);
		i++;
	}
	//std::cout << i - 1 << " Written this amount of values." << std::endl;
	f2.close();

	ofstream f1;
	f1.open("L://Embarcadero RAD Studio XE8 22.0.19027.8951 Architect//PROJECTS//Scanner//b.txt");
	for(int j = 0; j < 84; j++)
	{
		f1 << arr[j] << std::endl;
	}
	f1.close();

	for(int j = 0; j < 83; j++)
	{
		int pointer = 0;

		while(pointer < 83 - j)
		{
			if (arr[pointer] > arr[pointer + 1])
			{
				int temp = arr[pointer];
				arr[pointer] = arr[pointer + 1];
				arr[pointer + 1] = temp;
				pointer++;
			}
			else pointer++;
		}
	}

	ofstream f;
	f.open("L://Embarcadero RAD Studio XE8 22.0.19027.8951 Architect//PROJECTS//Scanner//a.txt");
	for(int j = 0; j < 84; j++)
	{
		f << arr[j] << std::endl;
	}
	f.close();


	for(int j = 0; j < 83; j++)
	{
		if(arr[j] == arr[j + 1] && arr[j + 1] == arr[j + 2])
		{val++;
		if(val > 125) {j = 83; break;}
		//if(xet > 125) {std::cout << " Fail. I can't find appropriate number("; break; break;}
		std::cout << val << " We changing this value." << xet << std::endl;
		break;}
		else if(j == 82) original = true;
	}
}

	std::cout << val << " - It is the most approproate value! " << xet;*/

	HashTable hashTable;

	hashTable.insert("alignas");
	hashTable.insert("alignof");
	hashTable.insert("and");
	hashTable.insert("and_eq");
	hashTable.insert("asm");
	hashTable.insert("auto");
	hashTable.insert("bitand");
	hashTable.insert("bitor");
	hashTable.insert("bool");
	hashTable.insert("break");
	hashTable.insert("case");
	hashTable.insert("catch");
	hashTable.insert("char");
	hashTable.insert("char16_t");
	hashTable.insert("char32_t");
	hashTable.insert("class");
	hashTable.insert("compl");
	hashTable.insert("const");
	hashTable.insert("constexpr");
	hashTable.insert("const_cast");
	hashTable.insert("continue");
	hashTable.insert("decltype");
	hashTable.insert("default");
	hashTable.insert("delete");
	hashTable.insert("do");
	hashTable.insert("double");
	hashTable.insert("dynamic_cast");
	hashTable.insert("else");
	hashTable.insert("enum");
	hashTable.insert("explicit");
	hashTable.insert("export");
	hashTable.insert("extern");
	hashTable.insert("false");
	hashTable.insert("float");
	hashTable.insert("for");
	hashTable.insert("friend");
	hashTable.insert("goto");
	hashTable.insert("if");
	hashTable.insert("inline");
	hashTable.insert("int");
	hashTable.insert("long");
	hashTable.insert("mutable");
	hashTable.insert("namespace");
	hashTable.insert("new");
	hashTable.insert("noexcept");
	hashTable.insert("not");
	hashTable.insert("not_eq");
	hashTable.insert("nullptr");
	hashTable.insert("operator");
	hashTable.insert("or");
	hashTable.insert("or_eq");
	hashTable.insert("private");
	hashTable.insert("protected");
	hashTable.insert("public");
	hashTable.insert("register");
	hashTable.insert("reinterpret_cast");
	hashTable.insert("return");
	hashTable.insert("short");
	hashTable.insert("signed");
	hashTable.insert("sizeof");
	hashTable.insert("static");
	hashTable.insert("static_assert");
	hashTable.insert("static_cast");
	hashTable.insert("struct");
	hashTable.insert("switch");
	hashTable.insert("template");
	hashTable.insert("this");
	hashTable.insert("thread_local");
	hashTable.insert("throw");
	hashTable.insert("true");
	hashTable.insert("try");
	hashTable.insert("typedef");
	hashTable.insert("typeid");
	hashTable.insert("typename");
	hashTable.insert("union");
	hashTable.insert("unsigned");
	hashTable.insert("using");
	hashTable.insert("virtual");
	hashTable.insert("void");
	hashTable.insert("volatile");
	hashTable.insert("wchar_t");
	hashTable.insert("while");
	hashTable.insert("xor");
	hashTable.insert("xor_eq");

	std::string buff;
	ifstream f2;
	f2.open("L://Embarcadero RAD Studio XE8 22.0.19027.8951 Architect//PROJECTS//Scanner//hash.txt");
	if (!f2) {
		std::cout << "File not found!";
	}

	while(!f2.eof()) //loop to end of file. Reads every character
	{
		f2 >> buff;
		std::cout << hashTable.find(buff) << std::endl;
	}
	f2.close();

	int a = 0;
	std::cin >> a;
	return 0;
}
