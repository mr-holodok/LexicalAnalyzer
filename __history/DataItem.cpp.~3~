//---------------------------------------------------------------------------
#pragma unmanaged
#pragma hdrstop

#include "stdafx.h"
#include "DataItem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*__fastcall DataItem::DataItem(std::string v)
{
	value = v;
	next = 0;
}

__fastcall DataItem::DataItem()
{
	value = "";
	next = 0;
}*/

/*void DataItem::insert(std::string val)
{
	if(value == "") value = val;
	else {
		DataItem item = goToLast();
		item.*next = DataItem(value);
	}
} */

/*DataItem DataItem::goToLast()
{
	DataItem item = this;
	while(item.next != 0)
		item = item.*next;
	return item;
}*/

/*bool DataItem::find(std::string val)
{
	DataItem item = this;
	while(item != NULL)
	{
		if(item.value == val) return true;
		item = item.*next;
	}
	return false;
} */

DataItem* DataItem::getNext()
{
	return next;
}

std::string DataItem::getValue()
{
	return value;
}

void DataItem::setNext(DataItem *item)
{
	next = item;
}
