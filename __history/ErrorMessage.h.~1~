//---------------------------------------------------------------------------
#pragma unmanaged
#ifndef ErrorMessageH
#define ErrorMessageH

#include <string>
//---------------------------------------------------------------------------

class ErrorMessage
{
public:
	ErrorMessage(unsigned int l, unsigned int p, char* msg);
	ErrorMessage(unsigned int l, unsigned int p);
	unsigned int getLine();
	unsigned int getPos();
	std::string getText();
private:
	unsigned int pos, line;
	char* message;
};

#endif
