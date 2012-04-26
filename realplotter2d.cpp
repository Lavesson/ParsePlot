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

#include "realplotter2d.h"
#include "parser.h"
#include <map>

using std::map;
using std::pair;

namespace ParsePlot {

const char RealPlotter2D::X_LABEL('x');
const char RealPlotter2D::Y_LABEL('y');

RealPlotter2D::RealPlotter2D(Parser<REAL>* aParser)
    : Plotter<REAL>(aParser, CreatePlotMap(), Y_LABEL) {}

RealPlotter2D::PlotMap RealPlotter2D::CreatePlotMap()
{
    // Create PlotSet X
    PlotSet<REAL> plot_x(X_MIN, X_MAX, X_STEP);

    // Create a map, add the PlotSet and return it
    map< char,PlotSet<REAL> > pMap;
    pMap.insert( pair< char,PlotSet<REAL> >(X_LABEL, plot_x) );

    return pMap;
}

// TODO: Add cleanup
bool RealPlotter2D::Plot(ResultMap& result, string expr)
{
    PlotResultVector values, def;
    REAL max, min, step, current, res;
    bool defined;
    string err;
    PlotSet<REAL> p;

    this->GetPlotSet(X_LABEL, p);

    max = p.GetMax();
    min = p.GetMin();
    step = p.GetStep();

    while (current < max)
    {
        defined = parser->Parse(expr, res, err);

        values.push_back( PlotResult<REAL>(defined, res, err) );
        def.push_back( PlotResult<REAL>(defined, current) );

        current += step;
    };

    // Insert values into map
    result.insert( pair<char, PlotResultVector >(X_LABEL, def) );
    result.insert( pair<char, PlotResultVector >(Y_LABEL, values) );
    return true;
}

string RealPlotter2D::Format(const string& input, REAL indVar)
{
    // TODO: Implement
    return input;
}

}
