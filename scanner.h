/*
This file is part of the ParsePlot library

ParsePlot is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

ParsePlot is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser Public License for more details.

You should have received a copy of the GNU Lesser Public License
along with ParsePlot.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _SCANNER_H_
#define _SCANNER_H_

/**
 * @file scanner.h
 * @brief Contains classes and enums specific to the scanner part of the parser.
 *
 * Contains the scanner main class (Scanner), the token enum (ParseToken) and
 * the Token class. These classes/enums are the ones that makes up the scanner
 * part of the parser.
 **/

#include <string>
#include <deque>
#include "stringmodifier.h"

using std::string;
using std::deque;

namespace ParsePlot {
/**
 * @enum ParseToken
 * @brief Tokens used by the parser
 * @author Eric Lavesson
 * @date 2011-02-05
 * @version 1.0.0-a
 *
 * This enum is rarely used outside of the API. It's main use would be if you are trying to write
 * your own parser implementation and plan on using the existing Scanner.
 */
enum ParseToken
{
    TOK_OPERATOR,       // Operator token
    TOK_NUMERIC,        // Numeric token
    TOK_LPAREN,         // Left parenthesis token
    TOK_RPAREN,         // Right parenthesis token
    TOK_FUNC,           // Function token
    TOK_SEPARATOR,      // Function separator token
    TOK_CONST,          // Constant expression token
    TOK_UNMATCHED,      // Any unmatched token
};

/**
 * @enum ScanCharacters
 * @brief Characters used by the Scanner
 * @author Eric Lavesson
 * @date 2011-02-09
 * @version 1.0.0-a
 *
 * This enum contains ASCII codes to characters frequently used by the Scanner for token recognition.
 */
enum ScanCharacters
{
    NUM_OFFSET = 48,
    NUM_RANGE  = 9,
    NUM_DECIMAL_POINT = 46,
    LPAREN = 40,
    RPAREN = 41,
    OP_MULT = 42,
    OP_ADD = 43,
    OP_SUB = 45,
    OP_DIV = 47,
};

/**
 * @class Token
 * @brief Contains token data
 * @author Eric Lavesson
 * @date 2011-02-05
 * @version 1.0.0-a
 *
 * This class is used mainly by the Scanner class as well as instances of
 * concrete Parser classes. There is generally no need to create an instance of
 * this class unless you're writing your own parser implementation and plan on
 * using the existing Scanner.
 */
class Token
{
    public:
        Token(ParseToken aPt, string aStr);
        ParseToken GetToken();
        string GetValue();

    private:
        string str;
        ParseToken pt;
};

/**
 * @class Scanner
 * @brief Scans and tokenizes a string before parsing begins
 * @author Eric Lavesson
 * @date 2011-02-05
 * @version 1.0.0-a
 *
 * Abstract base class for lexical analysis scanner.
 */
class Scanner
{
    public:
        virtual void Scan(const string &aInput)=0;
        virtual Token* Next()=0;
        virtual bool HasNext()=0;
        virtual ~Scanner() {};
};

}

#endif
