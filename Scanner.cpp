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
	initAuto();
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

	//if(tree) delete tree;
	tree = Tree();

	Errors.clear();

	//std::string str = "";
	char ch;              //character for reading of each symbol
	std::string val;      //string for lexems longer than 1 symbol
	bool passThrough = false;
	tLex numState;   //for suffix number states to detect what type number had

	do //loop to end of file. Reads every character
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
				else if (ch ==  85 || ch == 76 || ch == 117) {
					val = ch;
					currState = UCharOrID;
					pos++;
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
					val = ch;
					pos++;
				}
				else if (ch >= 49 && ch <= 57) {
					currState = Num;
					val = ch;
					pos++;
				}
				else if (ch == '.') {
					val = ch;
					ch = file.peek();

					if (isdigit(ch) || ch == 'e' || ch == 'E') {
						currState = NumWithDot;
					}
					else {
						lexList.push_back(Lexem(lexDot, val, line, pos));
					}
					pos++;
				}
				else if (ch == ':') {
					val = ch;
					ch = file.peek();

					if (ch == ':') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexDblColons, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexColons, val, line, pos));
					}
					pos++;
				}
				else if (ch == '+') {
					val = ch;
					ch = file.peek();

					if (ch == '+') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexIncrem, val, line, pos - 1));
					}
					else if (ch == '=')
					{
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexPlusEq, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexPlus, val, line, pos));
					}
					pos++;
				}
				else if (ch == '-') {
					val = ch;
					ch = file.peek();

					if (ch == '-') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexDecrem, val, line, pos - 1));
					}
					else if (ch == '=')
					{
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexMinusEq, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexMinus, val, line, pos));
					}
					pos++;
				}
				else if (ch == '!') {
					val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexNotEq, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexExclam, val, line, pos));
					}
					pos++;
				}
				else if (ch == '*') {
                	val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexMultEq, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexStar, val, line, pos));
					}
					pos++;
				}
				else if (ch == '&') {
					val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexAmpersandEq, val, line, pos - 1));
					}
					else if (ch == '&') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexAnd, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexAmpersand, val, line, pos));
					}
					pos++;
				}
				else if (ch == '/') {
					val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexDivEq, val, line, pos - 1));
					}
					else if (ch == '/') {
						val += ch;
						file.get();
						pos++;
						currState = LineComment;
					}
					else if (ch == '*') {
						val += ch;
						file.get();
						pos++;
						currState = WideComment;
					}
					else {
						lexList.push_back(Lexem(lexDiv, val, line, pos));
					}
					pos++;
				}
				else if (ch == '%') {
					val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexModEq, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexMod, val, line, pos));
					}
					pos++;
				}
				else if (ch == '<') {
					val = ch;
					currState = Less;
				}
				else if (ch == '>') {
					val = ch;
					currState = Greater;
				}
				else if (ch == '=') {
					val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexEqual, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexEquating, val, line, pos));
					}
					pos++;
				}
				else if (ch == '^') {
					val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexXorEq, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexXor, val, line, pos));
					}
					pos++;
				}
				else if (ch == '|') {
					val = ch;
					ch = file.peek();

					if (ch == '=') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(lexBitOrEq, val, line, pos - 1));
					}
					else {
						lexList.push_back(Lexem(lexBitOr, val, line, pos));
					}
					pos++;
				}
				else if (ch == '#') {
					currState = Directive;
				}
				else {
					val += ch;
					Errors.push_back(ErrorMessage(line, pos));
					lexList.push_back(Lexem(lexError, val, line, pos));
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
					else {
						bool already = tree.FindNode(val);
						if(!already) tree.AddNode(val);
						lexList.push_back(Lexem(lexIdentif, val, line, pos - val.length()));
					}
					currState = H;
				}
				break;
			}
			case UCharOrID: {
				ch = file.peek();

				if (ch == '8' && val == "u") {
					val += ch;
					file.get();
					pos++;
					ch = file.peek();
					if (ch == '\'') {
						val += ch;
						file.get();
						pos++;
						currState = UCharEnd;
					}
					else {
						currState = KWorID;
					}
				}
				else if (ch == '\'') {
					val += ch;
					file.get();
					pos++;
					currState = UCharEnd;
				}
				else {
					currState = KWorID;
                }
				break;
			}
			case UCharEnd: {  // State for end of UTF-8 Char
				ch = file.peek();

				while (ch != '\'') {
					val += ch;
					file.get();
					pos++;
					ch = file.peek();
				}
				if (ch == '\'' && val.length() > 6) {
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						Errors.push_back(ErrorMessage(line, pos, "UTF-8 Character is too long!"));
						currState = H;
				}
				else if (ch == '\'') {
						lexList.push_back(Lexem(lexUChar, val, line, pos - val.length()));
						Errors.push_back(ErrorMessage(line, pos, "Warning: multi-character constant!"));
						currState = H;
				}
				else if (ch == file.eof()) {
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						Errors.push_back(ErrorMessage(line, pos, "Expected a quotation \" ' \" to end a char!"));
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

				if (ch == 'n' || ch == 't' || ch == 'r' || ch == '\'' || ch == '\"' || ch == 'v' ||
					ch == '?' || ch == '\\' || ch == '0' || ch == 'a' || ch == 'b' || ch == 'f') {
					val += ch;
					currState = CharEnd;
					pos++;
				}
				else {
					val += ch;
					Errors.push_back(ErrorMessage(line, pos, "Expected an escape char!"));
					pos++;
					currState = ErrorCharEnd;
				}
				break;
			}
			case ErrorCharEnd: {  // State for error end of Char
				ch = file.peek();

				if (ch == '\'') {
					file.get();
					lexList.push_back(Lexem(lexError, val, line, pos - 3));
					pos++;
					currState = H;
				}
				else {
					lexList.push_back(Lexem(lexError, val, line, pos - 3));
					Errors.push_back(ErrorMessage(line, pos, "Expected a quotation \" ' \" to end a char!"));
					currState = H;
				}
				pos++;
				break;
			}
			case CharEnd: {  // State for end of Char
				ch = file.peek();

				if (ch == '\'') {
					file.get();
					lexList.push_back(Lexem(lexChar, val, line, pos - val.length()));
					pos++;
					currState = H;
				}
				else {
					while (ch != '\'') {
						val += ch;
						file.get();
						pos++;
						ch = file.peek();
					}
					if (ch == '\'' && val.length() > 4) {
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						Errors.push_back(ErrorMessage(line, pos, "Character is too long!"));
						currState = H;
					}
					else if (ch == '\'') {
						lexList.push_back(Lexem(lexChar, val, line, pos - val.length()));
						Errors.push_back(ErrorMessage(line, pos, "Warning: multi-character constant!"));
						currState = H;
					}
					else if (ch == file.eof()) {
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						Errors.push_back(ErrorMessage(line, pos, "Expected a quotation \" ' \" to end a char!"));
						currState = H;
					}
				}
				break;
			}
			case String: {
				ch = file.get();

				while (!(ch == '\"' &&
					val[val.length() - 1] != '\\')) {//check if double quotes is really end of string
													 //not the escape character
					val += ch;
					pos++;
					ch = file.get();
				}
				currState = H;
				lexList.push_back(Lexem(lexStringConst, val, line, pos - val.length()));
				pos++;
				break;
			}
			case NumStartsWithZero: {
				ch = file.peek();

				if (isdigit(ch) && ch != '0' && ch != '8' && ch != '9') {
					currState = OctNum;
					ch = file.get();
					val += ch;
					pos++;
				}
				else if(isdigit(ch)) {
					if (ch == '0') {
						Errors.push_back(ErrorMessage(line, pos, "Uncorrect octal value!"));
						while (isdigit(ch)) {
							val += ch;
							pos++;
							file.get();
							ch = file.peek();
						}
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
					else if (ch == '8' || ch != '9') {
						Errors.push_back(ErrorMessage(line, pos, "Expected an octal number!"));
						while (isdigit(ch)) {
							val += ch;
							pos++;
							file.get();
							ch = file.peek();
						}
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
				}
				else if (ch == '.') {
					currState = NumWithDot;
					ch = file.get();
					val += ch;
					pos++;
				}
				else if (ch == 'x' || ch == 'X') {
					currState = HexNum;
					ch = file.get();
					val += ch;
					pos++;
				}
				else if (ch == 'b' || ch == 'B') {
					currState = BinNum;
					ch = file.get();
					val += ch;
					pos++;
				}
				else {
                   lexList.push_back(Lexem(lexDecNum, val, line, pos));
				   currState = H;
				}
				break;
			}
			case Num: {
				ch = file.peek();
				passThrough = false;

				while(isdigit(ch) || ch == '.' || ch == 'e' || ch == 'E') {
					if (isdigit(ch)) {
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						currState = NumWithDot;
						passThrough = true;
						file.get();
						val += ch;
						pos++;
						break;
					}
					else if (ch == 'e' || ch == 'E')
					{
						currState = NumWithExp;
						passThrough = true;
						file.get();
						val += ch;
						pos++;
						break;
					}
				}
				if(!passThrough) {
					numState = lexDecNum;
					currState = NumSuf;
				}
				break;

			}
			case NumSuf: {
				ch = file.peek();

				if (ch == 'L' || ch == 'l') {
						val += ch;
						file.get();
						pos++;
						currState = NumSufL1;
				}
				else if (ch == 'u' || ch == 'U') {
						val += ch;
						file.get();
						pos++;
						currState = NumSufU1;
                }
				else {
					lexList.push_back(Lexem(numState, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case NumSufL1 : {
				ch = file.peek();

				if (ch == 'l' || ch == 'L') {
					val += ch;
					file.get();
					pos++;
					currState = NumSufL2;
				}
				else if (ch == 'u' || ch == 'U') {
					val += ch;
					file.get();
					lexList.push_back(Lexem(numState, val, line, pos - val.length()));
					pos++;
					currState = H;
				}
				else {
					lexList.push_back(Lexem(numState, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case NumSufL2 : {
                ch = file.peek();

				if (ch == 'u' || ch == 'U') {
					val += ch;
					file.get();
					lexList.push_back(Lexem(numState, val, line, pos - val.length()));
					pos++;
					currState = H;
				}
				else {
					lexList.push_back(Lexem(numState, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case NumSufU1 : {
                ch = file.peek();

				if (ch == 'l' || ch == 'L') {
					val += ch;
					file.get();
					ch = file.peek();
					pos++;
					if (ch == 'l' || ch == 'L') {
						val += ch;
						file.get();
						pos++;
						lexList.push_back(Lexem(numState, val, line, pos - val.length()));
					}
					else
						lexList.push_back(Lexem(numState, val, line, pos - val.length()));
				}
				else
					lexList.push_back(Lexem(numState, val, line, pos - val.length()));
				currState = H;
				break;
            }
			case NumWithDot: {
				ch = file.peek();
				passThrough = false;

				while(isdigit(ch) || ch == '.' || ch == 'e' || ch == 'E') {
					if (isdigit(ch)) {
						//if (val[0] == '.')
						//	val = '0' + val;
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						passThrough = true;
						Errors.push_back(ErrorMessage(line, pos, "Too many decimal points!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isdigit(ch) || ch == 'e' || ch == 'E' || ch == '.');
						if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
							val += ch;
							file.get();
							pos++;
						}
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
					else if (ch == 'e' || ch == 'E')
					{
						passThrough = true;
						if (val.length() == 1 && val[0] == '.') {
							Errors.push_back(ErrorMessage(line, pos, "Expected a mantis!"));
							do {
								val += ch;
								file.get();
								pos++;
								ch = file.peek();
							} while (isdigit(ch) || ch == 'e' || ch == 'E' || ch == '.');
							if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
								val += ch;
								file.get();
								pos++;
							}
							lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
							currState = H;
						}
						else {
							currState = NumWithExp;
							file.get();
							val += ch;
							pos++;
							break;
						}
					}
				}
				if (!passThrough) {
					if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
						val += ch;
						file.get();
						pos++;
					}
					lexList.push_back(Lexem(lexNumWithDot, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case NumWithExp: {
				ch = file.peek();

				if(ch == '-' || ch == '+' || isdigit(ch)) {
					currState = NumWithExpMan;
					file.get();
					val += ch;
					pos++;
				}
				else {
					Errors.push_back(ErrorMessage(line, pos, "Expected an exponent!"));
					file.get();
					val += ch;
					lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
					pos++;
					currState = H;
				}
				break;
			}
			case NumWithExpMan: {
				ch = file.peek();
				passThrough = false;

				while(isdigit(ch) || ch == '.') {
					if (isdigit(ch)) {
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						passThrough = true;
						if (val.find(".") != -1)
							Errors.push_back(ErrorMessage(line, pos, "Too many decimal points!"));
						else
							Errors.push_back(ErrorMessage(line, pos, "Decimal point is not allowed here!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isdigit(ch) || ch == 'e' || ch == 'E' || ch == '.');
						if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
							val += ch;
							file.get();
							pos++;
						}
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
				}
				if (!isdigit(val[val.length() - 1])) {
					Errors.push_back(ErrorMessage(line, pos, "Expected an exponent!"));
					if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
						val += ch;
						file.get();
						pos++;
					}
					lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
					currState = H;
				}
				else if (!passThrough) {
					if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
						val += ch;
						file.get();
						pos++;
					}
					lexList.push_back(Lexem(lexNumWithDot, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case OctNum: {
				ch = file.peek();
				passThrough = false;

				while (isdigit(ch) || ch == '.') {
					if(ch == '8' || ch == '9') {
						passThrough = true;
						Errors.push_back(ErrorMessage(line, pos, "Expected an octal value!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isdigit(ch));
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
					else if (ch == '.') {
						passThrough = true;
						Errors.push_back(ErrorMessage(line, pos, "Decimal point is not allowed here!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isdigit(ch) || ch == '.');
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
					else {
						val += ch;
						file.get();
						ch = file.peek();
						pos++;
					}
				}
				if (!passThrough) {
					numState = lexOctNum;
					currState = NumSuf;
				}
				break;
			}
			case HexNum: {
				passThrough = false;
				ch = file.peek();

				if (!isxdigit(ch) && ch != '.' && ch != 'p' && ch != 'P') {
					passThrough = true;
					Errors.push_back(ErrorMessage(line, pos, "Expected a hex value!"));
					lexList.push_back(Lexem(lexError, val, line, pos - 2));
				}

				while (isxdigit(ch) || ch == '.' || ch == 'p' || ch == 'P') {
					if (isxdigit(ch)) {
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						passThrough = true;
						file.get();
						val += ch;
						pos++;
						currState = HexNumWithDot;
						break;
					}
					else if (ch == 'p' || ch == 'P') {
						passThrough = true;
						file.get();
						val += ch;
						pos++;
						currState = HexNumWithExp;
						break;
					}
				}
				if (!passThrough) {
					numState = lexHexNum;
					currState = NumSuf;
				}
				break;
			}
			case HexNumWithDot: {
				ch = file.peek();
				passThrough = false;

				while(isxdigit(ch) || ch == '.' || ch == 'p' || ch == 'P') {
					if (isxdigit(ch)) {
						//if (val[0] == '.')
						//	val = '0' + val;
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						passThrough = true;
						Errors.push_back(ErrorMessage(line, pos, "Too many decimal points!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isxdigit(ch) || ch == 'p' || ch == 'P' || ch == '.');
                        if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
							val += ch;
							file.get();
							pos++;
						}
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
					else if (ch == 'p' || ch == 'P')
					{
						passThrough = true;
						if (val.length() == 3 && val[2] == '.') {
							Errors.push_back(ErrorMessage(line, pos, "Expected a mantis!"));
							do {
								val += ch;
								file.get();
								pos++;
								ch = file.peek();
							} while (isxdigit(ch) || ch == 'p' || ch == 'P' || ch == '.');
							if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
								val += ch;
								file.get();
								pos++;
							}
							lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
							currState = H;
						}
						else {
							currState = HexNumWithExp;
							file.get();
							val += ch;
							pos++;
							break;
						}
					}
				}
				if (!passThrough) {
					if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
						val += ch;
						file.get();
						pos++;
					}
					lexList.push_back(Lexem(lexHexNumWithDot, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case HexNumWithExp: {
				ch = file.peek();

				if(ch == '-' || ch == '+' || isxdigit(ch)) {
					currState = HexNumWithExpMan;
					file.get();
					val += ch;
					pos++;
				}
				else {
					Errors.push_back(ErrorMessage(line, pos, "Expected an exponent!"));
					file.get();
					val += ch;
					lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
					pos++;
					currState = H;
				}
				break;
			}
			case HexNumWithExpMan: {
				ch = file.peek();
				passThrough = false;

				while(isxdigit(ch) || ch == '.') {
					if (isxdigit(ch)) {
						file.get();
						val += ch;
						pos++;
						ch = file.peek();
					}
					else if (ch == '.') {
						passThrough = true;
						if (val.find(".") != -1)
							Errors.push_back(ErrorMessage(line, pos, "Too many decimal points!"));
						else
							Errors.push_back(ErrorMessage(line, pos, "Decimal point is not allowed here!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isxdigit(ch) || ch == 'p' || ch == 'P' || ch == '.');
						if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
							val += ch;
							file.get();
							pos++;
						}
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
				}
				if (!isxdigit(val[val.length() - 1])) {
					Errors.push_back(ErrorMessage(line, pos, "Expected an exponent!"));
					if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
						val += ch;
						file.get();
						pos++;
					}
					lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
					currState = H;
				}
				else if (!passThrough) {
                    if (ch == 'L' || ch == 'l' || ch == 'F' || ch == 'f') {
						val += ch;
						file.get();
						pos++;
					}
					lexList.push_back(Lexem(lexHexNumWithDot, val, line, pos - val.length()));
					currState = H;
				}
				break;
			}
			case BinNum: {
				ch = file.peek();
				passThrough = false;

				while (isdigit(ch) || ch == '.') {
					if(ch != '0' && ch != '1') {
						passThrough = true;
						Errors.push_back(ErrorMessage(line, pos, "Expected a binary value!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isdigit(ch));
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
					else if (ch == '.') {
						passThrough = true;
						Errors.push_back(ErrorMessage(line, pos, "Decimal point is not allowed here!"));
						do {
							val += ch;
							file.get();
							ch = file.peek();
							pos++;
						} while (isdigit(ch) || ch == '.');
						lexList.push_back(Lexem(lexError, val, line, pos - val.length()));
						currState = H;
					}
					else {
						val += ch;
						file.get();
						ch = file.peek();
						pos++;
					}
				}
				if (!passThrough) {
                    numState = lexBinNum;
					currState = NumSuf;
				}
				break;
			}
			case LineComment: {
				do {
					ch = file.get();
				} while (ch != '\n');
				line++;
				pos = 1;
				currState = H;
				break;
			}
			case WideComment: {
				do {
					ch = file.get();
					pos++;
					if (ch == '\n') {
						line++;
						pos = 1;
					}
					else if (ch == file.eof()) {
						Errors.push_back(ErrorMessage(line, pos, "Expected end of comment!"));
					}
				} while (ch != '*');
				currState = WideCommentEnd;
				break;
			}
			case WideCommentEnd: {
				ch = file.get();
				if (ch == '/') {
					currState = H;
					pos++;
				}
				else if (ch == file.eof()) {
					Errors.push_back(ErrorMessage(line, pos, "Expected end of comment!"));
				}
				else {
					currState = WideComment;
					pos++;
				}
			}
			case Less: {
				ch = file.peek();

				if (ch == '=') {
					val += ch;
					file.get();
					pos++;
					currState = LessEq;
				}
				else if (ch == '<') {
					val += ch;
					file.get();
					pos++;
					currState = LeftShift;
				}
				else {
					lexList.push_back(Lexem(lexLess, val, line, pos - 1));
					currState = H;
				}
				break;
			}
			case LessEq: {
				ch = file.peek();

				if (ch == '>') {
					val += ch;
					file.get();
					pos++;
					lexList.push_back(Lexem(lexLessEqGreater, val, line, pos - 2));
				}
				else {
					lexList.push_back(Lexem(lexLessOrEq, val, line, pos - 1));
				}
				pos++;
				currState = H;
				break;
			}
			case LeftShift: {
				ch = file.peek();

				if (ch == '=') {
					val += ch;
					file.get();
					pos++;
					lexList.push_back(Lexem(lexLShiftEq, val, line, pos - 2));
				}
				else {
					lexList.push_back(Lexem(lexLShift, val, line, pos - 1));
				}
				pos++;
				currState = H;
				break;
			}
			case Greater: {
				ch = file.peek();

				if (ch == '=') {
					val += ch;
					file.get();
					pos++;
					lexList.push_back(Lexem(lexGreaterOrEq, val, line, pos - 1));
					pos++;
					currState = H;
				}
				else if (ch == '>') {
					val += ch;
					file.get();
					pos++;
					currState = RightShift;
				}
				else {
					lexList.push_back(Lexem(lexGreater, val, line, pos - 1));
					currState = H;
                }
				break;
			}
			case RightShift: {
				ch = file.peek();

				if (ch == '=') {
					val += ch;
					file.get();
					pos++;
					lexList.push_back(Lexem(lexRShiftEq, val, line, pos - 2));
				}
				else {
					lexList.push_back(Lexem(lexRShift, val, line, pos - 1));
				}
				pos++;
				currState = H;
				break;
			}
			case Directive: {
				char prevChar;
				do {
					prevChar = ch;
					ch = file.get();
					if (ch == '\\') {
						line++;
					}
				} while (ch != '\n' && prevChar != '\\');
				line++;
				pos = 1;
			}
		}
	} while(!file.eof());
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

list<ErrorMessage> Scanner::getErrors()
{
	return Errors;
}
