//---------------------------------------------------------------------------

#ifndef ErrorMessageH
#define ErrorMessageH

#include <string>
//---------------------------------------------------------------------------

class ErrorMessage
{
public:
	__fastcall ErrorMessage(unsigned int l, unsigned int p, char* msg);
	__fastcall ErrorMessage(unsigned int l, unsigned int p);
private:
	unsigned int pos, line;
	char* message;
};

#endif
