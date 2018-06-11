//---------------------------------------------------------------------------
#pragma unmanaged
#ifndef LexemH
#define LexemH

#include <string>
#include <System.hpp>

enum tLex{
lexIdent, lexKeyWord, lexComma, lexColons, lexDblColons, lexSemiColon,
lexLRoundBracket, lexRRoundBracket, lexLSquareBracket, lexRSquareBracket,
lexLFigureBracket, lexRFigureBracket, lexQuestion,
lexAmpersand, lexStar,
lexArithmOp,
//lexTilde, lexPlus, lexMinus, lexDiv, lexMod, lexLShift, lexRShift, lexXor, lexBitOr,
lexMembAcsOp,
//lexArrow, lexDot,
lexLogicOp,
//lexExclam, lexAnd, lexOr,
lexAssgnOp,
//lexEquating, lexPlusEq, lexMinusEq, lexMultEq, lexDivEq, lexAmpersandEq,
//lexModEq, lexLShiftEq, lexRShiftEq, lexXorEq, lexBitOrEq,
lexLAngleBracket, lexRAngleBracket,
lexCompOp,
//lexLessOrEq, lexGreaterOrEq, lexNotEq, lexLessEqGreater, lexEqual,
lexIncrem, lexDecrem,
lexStringConst, lexChar, lexUChar,
lexDecNum, lexOctNum, lexBinNum, lexHexNum, lexNumWithDot, lexHexNumWithDot, lexError
};
//all the types of lexems

class Lexem
{
private:
	tLex lexType;      //type from enumeration tLex
	std::string value;
	unsigned int line;          //line in which Lexem was found
	unsigned int pos;           //position of Lexem

public:
	Lexem(tLex lex, const std::string& val, const int& l, const int& p) :
				lexType(lex), value(val), line(l), pos(p) {};
	AnsiString getLexType();
	AnsiString getValue();
	unsigned int getLine();
	unsigned int getPosition();
};
//---------------------------------------------------------------------------
#endif
