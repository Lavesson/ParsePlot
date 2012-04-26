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

#ifndef _DEFAULTSCANNER_H_
#define _DEFAULTSCANNER_H_

#include "scanner.h"

namespace ParsePlot {

/**
 *
 * @mainpage Documentation Main Page
 * @brief Use the tabbed interface to browse source files and documentation
 * @author Eric Lavesson
 * @date 2011-09-07
 */

/**
 * @file defaultscanner.h
 * @brief Contains the DefaultScanner class, derived from Scanner.
 *
 * @class DefaultScanner
 * @brief Implements Scanner and performs lexical analysis on an input string
 * @author Eric Lavesson
 * @date 2011-02-11
 * @version 1.0.0-a
 *
 * This is the default Scanner implementation, used widely through the system.
 * If you do not want/need to write your own scanning unit, this is the one to use.
 * It's functionality is basically that of a lexical analyzer. It takes an input string,
 * tokenizes it. Tokens are returned as Token pointers via DefaultScanner::Next().
 */
class DefaultScanner : public Scanner
{
    public:
        /**
		 * @fn ~DefaultScanner()
		 * @brief Destructor */
        ~DefaultScanner();

        /**
		 * @fn Scan(const string &aInput)
		 * @brief Scan and tokenize a text string
		 * @arg @c &aInput The string to scan */
        void Scan(const string &aInput);

        /**
		 * @fn Next()
		 * @brief Returns a pointer to the next Token
		 * @return Pointer to the next Token in the collection */
        Token* Next();

        /**
		 * @fn HasNext()
		 * @brief Determines if there are more tokens in the collection
		 * @return True if more tokens, otherwise false */
        bool HasNext();

    private:

        /**
		 * @fn PushNext()
		 * @brief Tokenize the next part of the string */
        bool PushNext();

        /**
		 * @fn GetTokenType(char tokenPart)
		 * @brief Determines the token type
		 * @arg @c tokenPart A part of the token to determine
		 * @return A ParseToken to determine the type of token */
        ParseToken GetTokenType(char tokenPart);

        /**
		 * @fn ExtractToken(char symStart)
		 * @brief Extracts the next token from the input string
		 * @arg @c symStart The token start symbol - This will be used to the determine the token type
		 * @return A pointer to the newly tokenized Token object */
        Token* ExtractToken(char symStart);


        StringModifier sInput;
        deque<Token*> tokQueue;
        deque<Token*>::iterator current_elem;
};

}

#endif
