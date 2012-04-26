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

#ifndef _TYPES_H_
#define _TYPES_H_

namespace ParsePlot
{
#ifdef OPT_DOUBLE_PRECISION
    typedef double REAL;
#else
    typedef float REAL;
#endif
}

#endif
