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
#include "Tree.h"

 int _tmain(int argc, _TCHAR* argv[])
{
	Tree tree = Tree();
	std::string str = "int";
	tree.AddNode(str);
	str = "float";
	tree.AddNode(str);
	str = "kok";
	tree.AddNode(str);
	str = "kek";
	tree.AddNode(str);
	str= "lol";
	tree.AddNode(str);

	str = "kol";
	tree.FindNode(str);
	str = "kek";
	tree.FindNode(str);
	str = "float";
	tree.FindNode(str);
	return 0;
}
