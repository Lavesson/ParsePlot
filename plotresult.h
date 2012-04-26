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

#ifndef _PLOTRESULT_H_
#define _PLOTRESULT_H_

#include <string>

using std::string;

namespace ParsePlot{

/**
 * @file plotresult.h
 * @brief Contains the PlotResult class
 *
 * @class PlotResult
 * @brief Holds information about a single value entry from plotting data
 * @author Eric Lavesson
 * @date 2011-02-05
 * @version 1.0.0-a
 *
 * An instance of PlotResult can be used to flag for NaN and to store a message
 * (usually an error message)
 */
template <typename T>
class PlotResult
{
    public:
        /**
		 * @fn PlotResult(bool aDefined, T aValue, string aMore)
		 * @brief Constructor
		 * @arg @c aDefined Set the defined flag of the result
		 * @arg @c aValue Set the value of the result
		 * @arg @c aMore Set a message with result information */
        PlotResult(bool aDefined, T aValue, string aMore)
            : defined(aDefined), value(aValue), more(aMore) {}

        /**
		 * @fn PlotResult(bool aDefined, T aValue)
		 * @brief Constructor
		 * @arg @c aDefined Set the defined flag of the result
		 * @arg @c aValue Set the value of the result */
        PlotResult(bool aDefined, T aValue)
            : defined(aDefined), value(aValue) {}

        /**
		 * @fn Defined()
		 * @brief Flag whether the number is defined or undefined (NaN)
		 * @return True if this is defined, otherwise false */
        bool Defined() { return defined; }

        /**
		 * @fn Value(T& aValue)
		 * @brief Flag whether the number is defined or undefined (NaN)
		 * @arg @c aValue Reference to get the value stored in this instance
		 * @warning Value is undefined if !Defined() */
        void Value(T& aValue) { aValue = value; }

        /**
		 * @fn More()
		 * @brief Contains a message which can be embedded with the numerical entry
		 * @return String with information message
		 *
		 * There is no specified use of this message more than that you can bundle a
		 * text message with the class instance. This can be general information, or
		 * this could be an error message when the number is undefined. */
        string More() { return more; }

    private:
        bool defined;
        T value;
        string more;
};
}
#endif
