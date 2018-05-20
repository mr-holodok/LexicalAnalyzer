//---------------------------------------------------------------------------
#pragma unmanaged
#ifndef DataItemH
#define DataItemH

#include <string>

class DataItem
{
private:
	std::string value;
	DataItem *next;
public:
	DataItem(const std::string &val) : value(val), next(NULL) {};
	DataItem() : value(NULL), next(NULL) {};
	DataItem* getNext();
	std::string getValue();
	void setNext(DataItem*);
};

//---------------------------------------------------------------------------
#endif
