//---------------------------------------------------------------------------

#ifndef LexemH
#define LexemH

#include <string>

enum tLex{
lexIdentif, lexKeyWord, lexComma, lexDot, lexColons, lexDblColons, lexSemiColon,
lexLParenthesis, lexRParenthesis, lexLBracket, lexRBracket, lexLBrace, lexRBrace, lexQuotes,
lexQuotation, lexTilde, lexQuestion, lexPlus, lexMinus, lexStar, lexDiv,
lexEquating, lexPlusEq, lexMinusEq, lexMultEq, lexDivEq, lexEqual,
lexLess, lexGreater, lexExclam, lexLessOrEq, lexGreaterOrEq, lexNotEq, lexLessEqGreater,
lexIncrem, lexDecrem, lexArrow, lexAmpersand, lexAmpersandEq,
lexMod, lexModEq, lexLShift, lexRShift, lexLShiftEq, lexRShiftEq, lexXor,
lexXorEq, lexBitOr, lexBitOrEq, lexAnd, lexOr, lexStringConst, lexChar, lexUChar,
lexDecNum, lexOctNum, lexBinNum, lexHexNum, lexNumWithDot, lexHexNumWithDot, lexError
};
//all the types of lexems

class Lexem
{
private:
	std::string lexType;      //type from enumeration tLex
	std::string value;
	unsigned int line;          //line in which Lexem was found
	unsigned int pos;           //position of Lexem

public:
	__fastcall Lexem(tLex lex, const std::string& val, const int& l, const int& p) :
				lexType(lex), value(val), line(l), pos(p) {};
	tLex getLexType();
	std::string getValue();
	unsigned int getLine();
	unsigned int getPosition();
};
//---------------------------------------------------------------------------
#endif
