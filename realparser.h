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

#ifndef _REALPARSER_H_
#define _REALPARSER_H_

/**
 * @file realparser.h
 * @brief Contains the implementation of RealParser, which is a concrete Parser class. */

#include "types.h"
#include "scanner.h"
#include "parser.h"

namespace ParsePlot {

/**
 * @class RealParser
 * @brief A concrete parser to handle real numbers. */
class RealParser : public Parser<REAL>
{
    public:
        /**
		 * @fn RealParser()
		 * @brief Constructor */
        RealParser();

        /**
		 * @fn Parse(string expr, REAL& result, string& err)
		 * @brief Parses a given expression and stores the result and an error string
		 * @arg @c expr The expression to parse.
		 * @arg @c result The result holder reference.
		 * @arg @c err A reference to the error string.
		 * @return True if parsed, otherwise false*/
        bool Parse(string expr, REAL& result, string& err);
};

}

#endif
