//---------------------------------------------------------------------------

#ifndef TreeH
#define TreeH

#include "Node.h"
//---------------------------------------------------------------------------

class Tree
{
public:
	__fastcall Tree();
	void AddNode(std::string &val);
	bool FindNode(std::string &val);
private:
	Node* first;
};

#endif
