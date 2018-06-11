//---------------------------------------------------------------------------
#pragma unmanaged
#pragma hdrstop

#include "stdafx.h"
#include "ErrorMessage.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
ErrorMessage::ErrorMessage(unsigned int l, unsigned int p, char* msg)
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
	message = "Unrecognized lexem!";
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
std::string ErrorMessage::getText()
{
	return message;
}
//---------------------------------------------------------------------------
