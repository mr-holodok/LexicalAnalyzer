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
	//========== This hash function NOT SO GOOD!!!============
	static int hashFunction(const std::string &value) {
		int key = value[0];
		for(unsigned char i = 1; i < value.length(); i++)
			key += value[i];
		return key % 99;
	};//============================================

public:
	HashTable();
	void insert(const std::string&);
	bool find(const std::string&);
};

//---------------------------------------------------------------------------
#endif
