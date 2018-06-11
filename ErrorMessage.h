//---------------------------------------------------------------------------
#pragma unmanaged
#ifndef ErrorMessageH
#define ErrorMessageH

#include <string>
#include <System.hpp>
//---------------------------------------------------------------------------

class ErrorMessage
{
public:
	ErrorMessage(unsigned int l, unsigned int p, AnsiString msg);
	ErrorMessage(unsigned int l, unsigned int p);
	unsigned int getLine();
	unsigned int getPos();
	AnsiString getText();
private:
	unsigned int pos, line;
	AnsiString message;
};

#endif
