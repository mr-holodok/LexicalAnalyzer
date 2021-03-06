//---------------------------------------------------------------------------
#pragma hdrstop

#include "Tree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Tree::Tree()
{
	first = NULL;
}

void Tree::AddNode(std::string &val)
{
	if (first == NULL) first = new Node(val);
	else {
		Node *currentNode = first;
		while(val != currentNode->getValue())
			if (val > currentNode->getValue()) {
				if (currentNode->getRightNode() == NULL)
					currentNode->setRightNode(new Node(val));
				currentNode = currentNode->getRightNode();
			}
			else {
				if (currentNode->getLeftNode() == NULL)
					currentNode->setLeftNode(new Node(val));
				currentNode = currentNode->getLeftNode();
			}
	}
}

bool Tree::FindNode(std::string &val)
{
	if (first == NULL) return false;
	Node *currentNode = first;
	while (true) {
		std::string str = currentNode->getValue();
		if (str == val) return true;
		if (val > str) {
			currentNode = currentNode->getRightNode();
			if(currentNode == NULL) return false;
		}
		else if (val < str) {
			currentNode = currentNode->getLeftNode();
			if(currentNode == NULL) return false;
		}
	}
}
