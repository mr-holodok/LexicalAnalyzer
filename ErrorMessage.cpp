//---------------------------------------------------------------------------
#pragma hdrstop

#include "ErrorMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
ErrorMessage::ErrorMessage(unsigned int l, unsigned int p, AnsiString msg)
{
	line = l;
	pos = p;
	message = msg;
}
//---------------------------------------------------------------------------
ErrorMessage::ErrorMessage(unsigned int l, unsigned int p)
{
	line = l;
	pos = p;
	message = "����������� �������!";
}
//---------------------------------------------------------------------------
unsigned int ErrorMessage::getLine()
{
	return line;
}
//---------------------------------------------------------------------------
unsigned int ErrorMessage::getPos()
{
	return pos;
}
//---------------------------------------------------------------------------
AnsiString ErrorMessage::getText()
{
	return message;
}
//---------------------------------------------------------------------------
