//---------------------------------------------------------------------------

#ifndef NodeH
#define NodeH

#include <string>
//---------------------------------------------------------------------------

class Node
{
public:
	__fastcall Node(std::string &val);
	void setLeftNode(Node *d);
	void setRightNode(Node *d);
	Node* getLeftNode();
	Node* getRightNode();
	std::string getValue();
private:
	Node *right, *left;
	std::string value;
};

#endif
