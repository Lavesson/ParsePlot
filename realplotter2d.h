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

#ifndef _REALPLOTTER2D_H_
#define _REALPLOTTER2D_H_

#include "plotter.h"
#include "plotset.h"
#include "plotresult.h"
#include "types.h"
#include <string>

using std::string;

namespace ParsePlot {

template <typename T>
class Parser;

class RealPlotter2D : public Plotter<REAL>
{
    public:
        typedef vector< PlotResult<REAL> > PlotResultVector;
        typedef map<char, PlotResultVector > ResultMap;
        typedef map<char, PlotSet<REAL> > PlotMap;

        static const char X_LABEL, Y_LABEL;
        RealPlotter2D(Parser<REAL>* aParser);

    private:
        PlotMap CreatePlotMap();
        bool Plot(ResultMap& result, string expr);
        string Format(const string& input, REAL indVar);

        static const REAL X_MIN = -10.0;
        static const REAL X_MAX = 10.0;
        static const REAL X_STEP = 3.0;
};

}

#endif
