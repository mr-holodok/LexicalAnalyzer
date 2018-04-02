//---------------------------------------------------------------------------

#ifndef LinkedDataListH
#define LinkedDataListH

#include "DataItem.h"
#include <string>

class LinkedDataList
{
private:
	DataItem *first; //pointer to the first element of LinkedList
	DataItem *last;  //pointer to the last element (for addition)

public:
	LinkedDataList() : first(NULL), last(NULL) {};
	void insert(const std::string&);   //adds DataItem at the end of list
	bool find(const std::string&);     //finds value through all list
};

//---------------------------------------------------------------------------
#endif
