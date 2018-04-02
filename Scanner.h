//---------------------------------------------------------------------------

#ifndef ScannerH
#define ScannerH

#include "Lexem.h"
#include "HashTable.h"
#include <list>
#include <iostream.h>

class Scanner {

private:
	unsigned int line; //variable, that stores current line, need to localizate errors
	unsigned int pos; //variable, that stores current position in line
	static HashTable hashTable;

	enum states {H, KWorID, Char, EscapeChar, CharEnd, String, NumStartWithDot,
	OctNum, DecNum, HexNum, DecNumDot, OctNumDot};
	states currState;
	void initHashTable();
	void initAuto();

public:
	__fastcall Scanner();
	list<Lexem> scan(const std::string&);
	//method, that get a text of program, and returns the lexem table
	//text will be written from file, so we must create a stream
	//also method must create lexem table and fill it

};


//---------------------------------------------------------------------------
#endif
