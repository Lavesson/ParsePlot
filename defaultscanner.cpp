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

#include "defaultscanner.h"
#include "stringmodifier.h"

namespace ParsePlot{

/* ------ Scanner implementation ------ */

DefaultScanner::~DefaultScanner()
{
    if (!tokQueue.empty())
    {
        deque<Token*>::iterator it;

        for (it=tokQueue.begin(); it!=tokQueue.end(); ++it)
        {
            delete *it;
        }
    }
}

void DefaultScanner::Scan(const string &aInput)
{
    // Make a deep copy of the string
    sInput.SetString(aInput);

    // Push all tokens to the queue
    while (PushNext()) {};

    current_elem = tokQueue.begin();
}

Token* DefaultScanner::Next()
{
    return *(current_elem++);
}

bool DefaultScanner::PushNext()
{
    // Get start symbol of next token
    char c = sInput.pop_front();
    tokQueue.push_back( ExtractToken(c) );

    // Return true if there are more characters in the stream
    if (sInput.Length() >= 1)
        return true;
    else
        return false;
}

Token* DefaultScanner::ExtractToken(char symStart)
{
    StringModifier sm;
    ParseToken current = GetTokenType(symStart);
    sm.push_back(symStart);

    while ( GetTokenType(sInput.front()) == current && !sInput.Empty() )
    {
        sm.push_back(sInput.pop_front());
    }

    return new Token(current, sm.GetString());
}

ParseToken DefaultScanner::GetTokenType(char tokenPart)
{
    if ( (tokenPart >= NUM_OFFSET && tokenPart <= NUM_OFFSET + NUM_RANGE) || tokenPart == NUM_DECIMAL_POINT )
        return TOK_NUMERIC;
    else if (tokenPart == LPAREN)
        return TOK_LPAREN;
    else if (tokenPart == RPAREN)
        return TOK_RPAREN;
    else if (tokenPart == OP_MULT || tokenPart == OP_ADD || tokenPart == OP_SUB || tokenPart == OP_DIV)
        return TOK_OPERATOR;
    else
        return TOK_UNMATCHED;
}

bool DefaultScanner::HasNext()
{
    return ( current_elem != tokQueue.end() );
}

/* ------ Token implementation ------ */

Token::Token(ParseToken aPt, string aStr)
{
    pt = aPt;
    str = aStr;
}

ParseToken Token::GetToken()
{
    return this->pt;
}

string Token::GetValue()
{
    return this->str;
}

}
