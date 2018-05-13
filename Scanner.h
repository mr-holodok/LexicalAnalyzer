//---------------------------------------------------------------------------

#ifndef ScannerH
#define ScannerH

#include "Lexem.h"
#include "HashTable.h"
#include "Tree.h"
#include "ErrorMessage.h"
#include <list>
#include <iostream.h>

class Scanner {

private:
	unsigned int line; //variable, that stores current line, need to localizate errors
	unsigned int pos; //variable, that stores current position in line
	static HashTable hashTable;
	Tree tree;
	list<ErrorMessage> Errors;


	enum states {H, KWorID, UCharOrID, UCharEnd, Char, EscapeChar, CharEnd, ErrorCharEnd, String, NumStartsWithDot,
	NumStartsWithZero, OctNum, DecNum, HexNum, BinNum, NumWithDot, Num, NumWithExp, NumSuf, NumSufU1, NumSufL1, NumSufL2,
	HexNumWithExpMan, HexNumWithDot, HexNumWithExp, NumWithExpMan, LineComment,
	WideComment, WideCommentEnd, Less, LessEq, LeftShift, Greater, RightShift, Directive };
	states currState;
	void initHashTable();
	void initAuto();

public:
	__fastcall Scanner();
	list<Lexem> scan(const std::string&);
	list<ErrorMessage> getErrors();
	//method, that get a text of program, and returns the lexem table
	//text will be written from file, so we must create a stream
	//also method must create lexem table and fill it

};


//---------------------------------------------------------------------------
#endif
