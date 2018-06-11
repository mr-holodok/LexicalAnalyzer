//---------------------------------------------------------------------------
#pragma unmanaged
#ifndef HashTableH
#define HashTableH

#include <string>
#include "LinkedDataList.h"

class HashTable
{
private:
	const static int size = 100;
	LinkedDataList hashArray[size];
	static int hashFunction(const std::string &value) {
		int key = value[0];
		for(unsigned int i = 1; i < value.length(); i++)
			key += value[i];
		return key % 99;
	};

public:
	HashTable();
	void insert(const std::string&);
	bool find(const std::string&);
};

//---------------------------------------------------------------------------
#endif
