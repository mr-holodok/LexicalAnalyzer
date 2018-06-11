//---------------------------------------------------------------------------
#pragma unmanaged
#pragma hdrstop

#include "stdafx.h"
#include "HashTable.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

HashTable::HashTable() {}

bool HashTable::find(const std::string &value)
{
	int index = hashFunction(value);
	LinkedDataList *list = &hashArray[index];
	return (*list).find(value);
}

void HashTable::insert(const std::string &value)
{
	int index = hashFunction(value);
	LinkedDataList *list = &hashArray[index];
	(*list).insert(value);
}
