//---------------------------------------------------------------------------

#pragma hdrstop

#include "LinkedDataList.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void LinkedDataList::insert(const std::string &val)
{
	if(last == 0) //if pointer to last object not defined
	{
		first = new DataItem(val);
		last = first;
	}
	else
	{
		(*last).setNext(new DataItem(val));
		last = (*last).getNext();
	}
}

bool LinkedDataList::find(const std::string &val)
{
	DataItem *item = first;
	while (item != 0)
	{
		if((*item).getValue() == val) return true;
		item = (*item).getNext();
	}
	return false;
}
