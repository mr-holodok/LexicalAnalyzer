//---------------------------------------------------------------------------
#pragma hdrstop

#include "Lexem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


AnsiString Lexem::getLexType()
{
	switch(this->lexType) {
		case lexIdent: return "�������������";
		case lexKeyWord: return "������� �����";
		case lexComma: return "����";
		case lexColons: return "���������";
		case lexDblColons: return "������� ���������";
		case lexSemiColon: return "������ � �����";
		case lexLRoundBracket: return "˳�� ������� �����";
		case lexRRoundBracket: return "����� ������� �����";
		case lexLSquareBracket: return "˳�� ��������� �����";
		case lexRSquareBracket: return "����� ��������� �����";
		case lexLFigureBracket: return "˳�� ������� �����";
		case lexRFigureBracket: return "����� ������� �����";
		case lexQuestion: return "���� �������";
		case lexAmpersand: return "���� ���������";
		case lexStar: return "���� ������";
		case lexArithmOp: return "������������ ��������";
		case lexMembAcsOp: return "�������� �������";
		case lexLogicOp: return "������� ��������";
		case lexAssgnOp: return "�������� ���������";
		case lexLAngleBracket: return "˳�� ������ �����";
		case lexRAngleBracket: return "����� ������ �����";
		case lexCompOp: return "�������� ���������";
		case lexIncrem: return "���������";
		case lexDecrem: return "���������";
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
