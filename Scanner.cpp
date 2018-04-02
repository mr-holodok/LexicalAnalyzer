//---------------------------------------------------------------------------
#pragma hdrstop

#include "Scanner.h"
#include <fstream.h>
#include <string>
#include <iterator>
//---------------------------------------------------------------------------
#pragma package(smart_init)

HashTable Scanner::hashTable = HashTable();

__fastcall Scanner::Scanner()
{
	//if(hashTable == NULL)
	initHashTable();
	/*==============
	The hash table must be initialized ONLY 1 TIME!
	==============*/
}

list<Lexem> Scanner::scan(const std::string& path)
{
	//================================
	char *filePath = new char[path.length() + 1];
	std::strcpy(filePath, path.c_str());
	//for opening file required char* instead of string

	ifstream file; //file that contains text of program
	file.open(filePath);
	if (!file) {
		std::cout << "File not found!";
	}
	//this is test opening
	//final functions will be realized in other method or class
	//================================*/

	list<Lexem> lexList;
	initAuto();

	//std::string str = "";
	char ch;              //character for reading of each symbol
	std::string val;      //string for lexems longer than 1 symbol
	bool breaker = false; //variable for loop break

	while(!file.eof()) //loop to end of file. Reads every character
	{
		switch(currState)
		{
			case H : {
				ch = file.get();  //getting symbol
				val.clear();

				if (ch == ' ') {
					pos++;
					continue;
				}
				else if ((ch >= 65 && ch <= 90) || ch == 95 || (ch >= 97 && ch <= 122)) {
					val = ch;
					currState = KWorID;
					pos++;
				}
				else if (ch == ';') {
					val = ch;
					lexList.push_back(Lexem(lexSemiColon, val, line, pos));
					pos++;
				}
				else if (ch == '\t') {
					pos+=3;
					continue;
				}
				else if (ch == '\r') continue;
				else if (ch == '\n') {
					line++;
					pos = 1;
					continue;
				}
				else if (ch == '(') {
					val = ch;
					lexList.push_back(Lexem(lexLParenthesis, val, line, pos));
					pos++;
				}
				else if (ch == ')') {
					val = ch;
					lexList.push_back(Lexem(lexRParenthesis, val, line, pos));
					pos++;
				}
				else if (ch == '[') {
					val = ch;
					lexList.push_back(Lexem(lexLBracket, val, line, pos));
					pos++;
				}
				else if (ch == ']') {
                    val = ch;
					lexList.push_back(Lexem(lexRBracket, val, line, pos));
					pos++;
				}
				else if (ch == '{') {
					val = ch;
					lexList.push_back(Lexem(lexLBrace, val, line, pos));
					pos++;
				}
				else if (ch == '}') {
                    val = ch;
					lexList.push_back(Lexem(lexRBrace, val, line, pos));
					pos++;
				}
				else if (ch == ',') {
                    val = ch;
					lexList.push_back(Lexem(lexComma, val, line, pos));
					pos++;
				}
				else if (ch == '?') {
					val = ch;
					lexList.push_back(Lexem(lexQuestion, val, line, pos));
					pos++;
				}
				else if	(ch == '~') {
					val = ch;
					lexList.push_back(Lexem(lexTilde, val, line, pos));
					pos++;
				}
				else if (ch == '\'') {
					currState = Char;
					pos++;
				}
				else if (ch == '\"') {
					currState = String;
					pos++;
				}
				else if (ch == '0') {
					currState = NumStartsWithZero;
					val += ch;
					pos++;
				}
				else if (ch >= 49 && ch <= 57) {
					currState = Num;
					val += ch;
					pos++;
				}

				break;
			}
			case KWorID: {      //Key word or identifier
				ch = file.peek();

				if((ch >= 48 && ch <= 57) || (ch >= 65 && ch <= 90) ||
							ch == 95 || (ch >= 97 && ch <= 122)) {
					val += ch;
					pos++;
					file.get();
				}
				else {
					bool keyWord = hashTable.find(val);
					if(keyWord)
						lexList.push_back(Lexem(lexKeyWord, val, line, pos - val.length()));
					else
						lexList.push_back(Lexem(lexName, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case Char: {
				ch = file.get();

				if (ch != '\\')
					currState = CharEnd;
				else
					currState = EscapeChar;
				val = ch;
				pos++;
				break;
			}
			case EscapeChar: {    // State for escape sequence characters
				ch = file.get();

				if (ch == 'n' || ch == 't' || ch == 'r' || ch == '\'' || ch == '\"' ||
					ch == '?' || ch == '\\' || ch == '0' || ch == 'a' || ch == 'b' || ch == 'f') {
					val += ch;
					currState = CharEnd;
					pos++;
				}
				else
				//!!!!!!Error=====================================================>
					currState = H;
				//================================================================
				break;
			}
			case CharEnd: {  // State for end of Char
				ch = file.get();

				if (ch == '\'') {
					lexList.push_back(Lexem(lexChar, val, line, pos - val.length() - 2));
					currState = H;
				}
				else
				//========ERROR!+++++====================================================>
					  currState = H;
				//========================================================================
				pos++;
				break;
			}
			case String: {
				ch = file.get();

				/*if (ch == '\"' &&
					val[val.length() - 1] != '\\') { //check if double quotes is really end of string
													 //not the escape character
					currState = H;
					lexList.push_back(Lexem(lexStringConst, val, line, pos - val.length() - 2));
				}
				else
					val += ch;*/

				while (!(ch == '\"' &&
					val[val.length() - 1] != '\\')) {//check if double quotes is really end of string
													 //not the escape character
					val += ch;
					pos++;
					ch = file.get();
				}
				currState = H;
				lexList.push_back(Lexem(lexStringConst, val, line, pos - val.length() - 2));
				pos++;
				break;
			}
			case NumStartsWithZero: {
				ch = file.peek();

				if (isdigit(ch))
					currState = OctNum;
				else if (ch == '.')
				   currState = DecNumWithDot;
				else if (ch == 'x' || ch == 'X')
				   currState = HexNum;
				else {
                   lexList.push_back(Lexem(lexDecNum, val, line, pos));
				   currState = H;
				}
				break;
			}
			case Num: {
				ch = file.peek();
				breaker = false;

				while(!breaker) {
					if (isdigit(ch)) {
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						breaker = true;
						currState = DecNumWithDot;
						file.get();
						val += ch;
						pos++;
					}
					else {
						lexList.push_back(Lexem(lexDecNum, val, line, pos - val.lenght()));
						breaker = true;
						currState = H;
					}
				}
			}
			case DecNumWithDot: {
				ch = file.peek();
				breaker = false;

				while(!breaker) {
					if (isdigit(ch)) {
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						breaker = true;
						currState = H;
						//=============================================
						//Error Handler
						//===============================================
					}
					else {
						lexList.push_back(Lexem(lexDecNumWithDot, val, line, pos - val.lenght()));
						breaker = true;
						currState = H;
                    }
				}
			}
			/*case NumStartsWithDot: {
				ch = file.peek();

				if (isdigit(ch) && ch != '8' && ch != '9')
					currState = OctNum;
				else if (isdigit(ch))
					currState = DecNum;
				else if (ch == 'X' || ch == 'x')
					currState = HexNum;
				else if (ch == '.')
					currState = DecNumDot;
				else {
					lexList.push_back(Lexem(lexDecNum, val, line, pos--));
					currState = H;
					break;
				}
				//==============Check this part of code! Is break works correctly?+++++=========>
				val += ch;
				file.get();
				pos++;
				break;
			}*/
			case OctNum: {
				ch = file.peek();

				while (isdigit(ch) || ch == '.') {
					if(ch == '8' || ch == '9') {
						//===================================================
						//Eror Handler
						//===================================================
					}
					else if (ch == '.') {
                        //===================================================
						//Eror Handler
						//===================================================
					}
					else {
						val += ch;
						file.get();
						ch = file.peek();
					}
				}
				lexList.push_back(Lexem(lexOctNum, val, line, pos - val.length()));
				currState = H;
				break;
			}



		}
	}
	return lexList;
}

void Scanner::initAuto()
{
	line = 1;
	pos = 1;
	currState = H;
}

void Scanner::initHashTable()
{
	hashTable.insert("alignas");
	hashTable.insert("alignof");
	hashTable.insert("and");
	hashTable.insert("and_eq");
	hashTable.insert("asm");
	hashTable.insert("auto");
	hashTable.insert("bitand");
	hashTable.insert("bitor");
	hashTable.insert("bool");
	hashTable.insert("break");
	hashTable.insert("case");
	hashTable.insert("catch");
	hashTable.insert("char");
	hashTable.insert("char16_t");
	hashTable.insert("char32_t");
	hashTable.insert("class");
	hashTable.insert("compl");
	hashTable.insert("const");
	hashTable.insert("constexpr");
	hashTable.insert("const_cast");
	hashTable.insert("continue");
	hashTable.insert("decltype");
	hashTable.insert("default");
	hashTable.insert("delete");
	hashTable.insert("do");
	hashTable.insert("double");
	hashTable.insert("dynamic_cast");
	hashTable.insert("else");
	hashTable.insert("enum");
	hashTable.insert("explicit");
	hashTable.insert("export");
	hashTable.insert("extern");
	hashTable.insert("false");
	hashTable.insert("float");
	hashTable.insert("for");
	hashTable.insert("friend");
	hashTable.insert("goto");
	hashTable.insert("if");
	hashTable.insert("inline");
	hashTable.insert("int");
	hashTable.insert("long");
	hashTable.insert("mutable");
	hashTable.insert("namespace");
	hashTable.insert("new");
	hashTable.insert("noexcept");
	hashTable.insert("not");
	hashTable.insert("not_eq");
	hashTable.insert("nullptr");
	hashTable.insert("operator");
	hashTable.insert("or");
	hashTable.insert("or_eq");
	hashTable.insert("private");
	hashTable.insert("protected");
	hashTable.insert("public");
	hashTable.insert("register");
	hashTable.insert("reinterpret_cast");
	hashTable.insert("return");
	hashTable.insert("short");
	hashTable.insert("signed");
	hashTable.insert("sizeof");
	hashTable.insert("static");
	hashTable.insert("static_assert");
	hashTable.insert("static_cast");
	hashTable.insert("struct");
	hashTable.insert("switch");
	hashTable.insert("template");
	hashTable.insert("this");
	hashTable.insert("thread_local");
	hashTable.insert("throw");
	hashTable.insert("true");
	hashTable.insert("try");
	hashTable.insert("typedef");
	hashTable.insert("typeid");
	hashTable.insert("typename");
	hashTable.insert("union");
	hashTable.insert("unsigned");
	hashTable.insert("using");
	hashTable.insert("virtual");
	hashTable.insert("void");
	hashTable.insert("volatile");
	hashTable.insert("wchar_t");
	hashTable.insert("while");
	hashTable.insert("xor");
	hashTable.insert("xor_eq");
}
