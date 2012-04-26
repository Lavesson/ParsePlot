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

#include "stringmodifier.h"

namespace ParsePlot {

const string StringModifier::EMPTY = "";

StringModifier::StringModifier()
{
    this->input = StringModifier::EMPTY;
}

StringModifier::StringModifier(const string &aInput)
{
    SetString(aInput);
}

void StringModifier::push_back(char c)
{
    input.push_back(c);
}

char StringModifier::pop_front()
{
    char c = input[0];
    input = input.substr(1, input.length()-1);
    return c;
}

bool StringModifier::Empty()
{
    return input.empty();
}

char StringModifier::front()
{
    char c = input[0];
    return c;
}

int StringModifier::Length()
{
    return input.length();
}

void StringModifier::SetString(const string &aInput)
{
    input = aInput.c_str();
}

string StringModifier::GetString()
{
    return input;
}

string StringModifier::operator+=(const string &aInput)
{
    input += aInput;
    return input;
}

}
