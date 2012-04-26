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

#ifndef _PARSER_H_
#define _PARSER_H_

#include <string>
namespace ParsePlot {

class Scanner;

using std::string;

/**
 * @file parser.h
 * @brief Contains an abstract base class used for parser implementations.
 *
 * @class Parser
 * @brief Abstract base class for parser implementations.
 * @author Eric Lavesson
 * @date 2011-01-27
 * @version 1.0.0-a
 * @warning The typename MUST be a numerical type (float/double/int...)
 * Inherit this class and overload the Parse function to
 * write your own parser implementation.
 */
template <typename T>
class Parser
{
	public:
		/**
		 * @fn Parser(string aName, string aVersion)
		 * @brief Constructor
		 * @arg @c aName Parser name
		 * @arg @c aVersion Parser version0
		*/
		Parser(string aName, string aVersion)
			: name(aName), version(aVersion) {}

		/** @brief Destructor */
		virtual ~Parser() {};

		/**
		 * @fn GetVersion()
		 * @brief Get version string.
		 * @return the string containing the version of this parser.
		 * Set this string via the base constructor. */
		string GetVersion() { return version; }

		/**
		 * @fn GetName()
		 * @brief Get name string
		 * @return the string containing the name of this parser.
		 * Set this string via the base constructor. */
		string GetName() { return name; }

		/**
		 *  @fn Parse(string expr, T& result, string& err);
		 *	@brief Parse a string as a mathematical expression.
		 *  @arg @c expr The expression to parse
		 *  @arg @c result The result from the parsing
		 *  @arg @c err If parsing failed, this string contains an error message
		 *  @return true if parsed correctly or false if string can't be parsed (input error).
		 *	@pre:  T is numeric
		 *  @post: expr is parsed and passed via result. */
		virtual bool Parse(string expr, T& result, string& err)=0;

    protected:
        Scanner *scanner;

	private:
		string name;
		string version;
};
}

#endif
