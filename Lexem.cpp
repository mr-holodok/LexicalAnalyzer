//---------------------------------------------------------------------------

#pragma hdrstop

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
	switch(this->lexType) {
		case lexIdentif: return "�������������";
		case lexKeyWord: return "������� �����";
		case lexComma: return "����";
		case lexDot: return "������";
		case lexColons: return "���������";
		case lexDblColons: return "������� ���������";
		case lexSemiColon: return "������ � �����";
		case lexLParenthesis: return "˳�� ������� �����";
		case lexRParenthesis: return "����� ������� �����";
		case lexLBracket: return "˳�� ��������� �����";
		case lexRBracket: return "����� ��������� �����";
		case lexLBrace: return "˳�� ������� �����";
		case lexRBrace: return "����� ������� �����";
		case lexQuotes: return "������� �����";
		case lexQuotation: return "�������� �����";
		case lexTilde: return "ҳ����";
		case lexQuestion: return "���� �������";
		case lexPlus: return "���� ����";
		case lexMinus: return "���� ����";
		case lexStar: return "���� ������";
		case lexDiv: return "���� ������";
		case lexEquating: return "���� �������";
		case lexPlusEq: return "��������� � ����������";
		case lexMinusEq: return "³�������� � ����������";
		case lexMultEq: return "�������� � ����������";
		case lexDivEq: return "ĳ����� � ����������";
		case lexEqual: return "���� ������";
		case lexLess: return "���� �����";
		case lexGreater: return "���� �����";
		case lexExclam: return "���� ������";
		case lexLessOrEq: return "����� ��� �������";
		case lexGreaterOrEq: return "������ ��� �������";
		case lexNotEq: return "�� �������";
		case lexLessEqGreater: return "����� ������ ���������";
		case lexIncrem: return "���������";
		case lexDecrem: return "���������";
		case lexArrow: return "������";
		case lexAmpersand: return "���� ���������";
		case lexAmpersandEq: return "������ � � ����������";
		case lexMod: return "������ �� ������";
		case lexModEq: return "������ �� ������ � ����������";
		case lexLShift: return "���� ����";
		case lexRShift: return "���� ������";
		case lexLShiftEq: return "���� ���� � ����������";
		case lexRShiftEq: return "���� ������ � ����������";
		case lexXor: return "���������� ���";
		case lexXorEq: return "���������� ��� � ����������";
		case lexBitOr: return "������ ���";
		case lexBitOrEq: return "������ ��� � ����������";
		case lexAnd: return "������ �";
		case lexOr: return "������ ���";
		case lexStringConst: return "������� ���������";
		case lexChar: return "������";
		case lexUChar: return "������ UTF-8";
		case lexDecNum: return "��������� ���������� �����";
		case lexOctNum: return "³������ ���������� �����";
		case lexBinNum: return "������� ���������� �����";
		case lexHexNum: return "س������������ ���������� �����";
		case lexNumWithDot: return "��������� ���������� ����� �����";
		case lexHexNumWithDot: return "س������������ ����� ���������� �����";
		case lexError: return "������� � ��������";
    }
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
