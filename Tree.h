//---------------------------------------------------------------------------
#pragma unmanaged
#ifndef TreeH
#define TreeH

#include "Node.h"
//---------------------------------------------------------------------------

class Tree
{
public:
	Tree();
	void AddNode(std::string &val);
	bool FindNode(std::string &val);
private:
	Node* first;
};

#endif
