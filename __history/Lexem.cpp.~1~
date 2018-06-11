//---------------------------------------------------------------------------
#pragma unmanaged
#pragma hdrstop

#include "stdafx.h"
#include "Lexem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

/*__fastcall Lexem::Lexem(tLex type, std::string value, int line, int pos)
{
	this->lexType = type;
	this->value = value;
	this->line = line;
	this->pos = pos;
}*/

std::string Lexem::getLexType()
{
	std::string s;
	switch(this->lexType) {
		case lexIdent: { std::string s ("Ідентифікатор"); return s;}
		case lexKeyWord: { std::string s ("Ключове слово"); return s; }
		case lexComma: { std::string s ("Кома"); return s; }
		case lexColons: { std::string s ("Двокрапка"); return s; }
		case lexDblColons: { std::string s ("Подвійна двокрапка"); return s; }
		case lexSemiColon: { std::string s ("Крапка з комою"); return s; }
		case lexLRoundBracket: { std::string s ("Ліва кругова дужка"); return s; }
		case lexRRoundBracket: { std::string s ("Права кругова дужка"); return s; }
		case lexLSquareBracket: { std::string s ("Ліва квадратна дужка"); return s; }
		case lexRSquareBracket: { std::string s ("Права квадратна дужка"); return s; }
		case lexLFigureBracket: { std::string s ("Ліва фігурна дужка"); return s; }
		case lexRFigureBracket: { std::string s ("Права фігурна дужка"); return s; }
		case lexQuestion: { std::string s ("знак питання"); return s; }
		case lexAmpersand: { std::string s ("Знак амперсанд"); return s; }
		case lexStar: { std::string s ("Знак зірочка"); return s; }
		case lexArithmOp: { std::string s ("Арифметичний оператор"); return s; }
		case lexMembAcsOp: { std::string s ("Оператор доступу"); return s; }
		case lexLogicOp: { std::string s ("Логічний оператор"); return s; }
		case lexAssgnOp: { std::string s ("Оператор присвоєння"); return s; }
		case lexLAngleBracket: { std::string s ("Ліва кутова дужка"); return s; }
		case lexRAngleBracket: { std::string s ("Права кутова дужка"); return s; }
		case lexCompOp: { std::string s ("Оператор порівняння"); return s; }
		case lexIncrem: { std::string s ("Інкремент"); return s; }
		case lexDecrem: { std::string s ("Декремент"); return s; }
		case lexStringConst: { std::string s ("Рядкова константа"); return s; }
		case lexChar: { std::string s ("Символ"); return s; }
		case lexUChar: { std::string s ("Символ UTF-8"); return s; }
		case lexDecNum: { std::string s ("Десяткове константне число"); return s; }
		case lexOctNum: { std::string s ("Вісімкове константне число"); return s; }
		case lexBinNum: { std::string s ("Бінарне константне число"); return s; }
		case lexHexNum: { std::string s ("Шістнадцяткове константне число"); return s; }
		case lexNumWithDot: { std::string s ("Десяткове константне дійсне число"); return s; }
		case lexHexNumWithDot: { std::string s ("Шістнадцяткове дійсне константне число"); return s; }
		case lexError: { std::string s ("Лексема з помилкою"); return s; }
	}
	return s;
}

std::string Lexem::getValue()
{
	return this->value;
}

unsigned int Lexem::getLine()
{
	return this->line;
}

unsigned int Lexem::getPosition()
{
	return this->pos;
}
