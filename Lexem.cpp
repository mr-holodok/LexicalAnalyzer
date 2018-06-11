//---------------------------------------------------------------------------
#pragma hdrstop

#include "Lexem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


AnsiString Lexem::getLexType()
{
	switch(this->lexType) {
		case lexIdent: return "Ідентифікатор";
		case lexKeyWord: return "Ключове слово";
		case lexComma: return "Кома";
		case lexColons: return "Двокрапка";
		case lexDblColons: return "Подвійна двокрапка";
		case lexSemiColon: return "Крапка з комою";
		case lexLRoundBracket: return "Ліва кругова дужка";
		case lexRRoundBracket: return "Права кругова дужка";
		case lexLSquareBracket: return "Ліва квадратна дужка";
		case lexRSquareBracket: return "Права квадратна дужка";
		case lexLFigureBracket: return "Ліва фігурна дужка";
		case lexRFigureBracket: return "Права фігурна дужка";
		case lexQuestion: return "знак питання";
		case lexAmpersand: return "Знак амперсанд";
		case lexStar: return "Знак зірочка";
		case lexArithmOp: return "Арифметичний оператор";
		case lexMembAcsOp: return "Оператор доступу";
		case lexLogicOp: return "Логічний оператор";
		case lexAssgnOp: return "Оператор присвоєння";
		case lexLAngleBracket: return "Ліва кутова дужка";
		case lexRAngleBracket: return "Права кутова дужка";
		case lexCompOp: return "Оператор порівняння";
		case lexIncrem: return "Інкремент";
		case lexDecrem: return "Декремент";
		case lexStringConst: return "Рядкова константа";
		case lexChar: return "Символ";
		case lexUChar: return "Символ UTF-8";
		case lexDecNum: return "Десяткове константне число";
		case lexOctNum: return "Вісімкове константне число";
		case lexBinNum: return "Бінарне константне число";
		case lexHexNum: return "Шістнадцяткове константне число";
		case lexNumWithDot: return "Десяткове константне дійсне число";
		case lexHexNumWithDot: return "Шістнадцяткове дійсне константне число";
		case lexError: return "Лексема з помилкою";
	}
}

AnsiString Lexem::getValue()
{
	return this->value.c_str();
}

unsigned int Lexem::getLine()
{
	return this->line;
}

unsigned int Lexem::getPosition()
{
	return this->pos;
}
