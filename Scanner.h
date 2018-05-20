//---------------------------------------------------------------------------
#pragma unmanaged
#ifndef ScannerH
#define ScannerH

#include "Lexem.h"
#include "HashTable.h"
#include "Tree.h"
#include "ErrorMessage.h"
#include <list>
//#include <iostream.h>

class Scanner {

private:
	unsigned int line; //variable, that stores current line, need to localizate errors
	unsigned int pos; //variable, that stores current position in line
	static HashTable hashTable;
	Tree tree;
	list<ErrorMessage> Errors;


	enum states {H, KWorID, UCharOrID, U8CharOrID, UCharEnd, Char, EscapeChar, ErrorCharEnd,
	CharEnd, String, NumStartsWithZero, Num, NumSuf, NumSufL1, NumSufL2,
	NumSufU1, NumSufU2, FloatSuf, SufEndCheck, NumWithDot, NumWithExp,
	NumWithExpSign, NumWithExpMan, OctNum, HexNum, HexNumWithDot, HexNumWithExp,
	HexNumWithExpSign, HexNumWithExpMan, BinNum, Dot, Colon, Plus, Minus, Assign,
	Amp, Div, Or, LineComment, WideComment, WideCommentEnd, Less, LessEq, LeftShift,
	Greater, RightShift, Directive, F, ErrorLexemEnd };
	states currState;
	void initHashTable();
	void initAuto();
	bool isCharAllowed(char ch);

public:
	Scanner();
	list<Lexem> scan(const std::string&);
	list<ErrorMessage> getErrors();
	//method, that get a text of program, and returns the lexem table
	//text will be written from file, so we must create a stream
	//also method must create lexem table and fill it

};


//---------------------------------------------------------------------------
#endif
