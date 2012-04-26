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

#ifndef _PLOTTER_H_
#define _PLOTTER_H_

#include "plotset.h"
#include "plotresult.h"
#include <string>
#include <map>
#include <vector>

using std::vector;
using std::string;
using std::map;

namespace ParsePlot{

// Forward declarations
template <typename T>
class Parser;

/**
 * @file plotter.h
 * @brief Contains an abstract base class used for plotter implementations.
 *
 * @class Plotter
 * @brief Abstract base class for plotter implementations.
 * @author Eric Lavesson
 * @date 2011-01-27
 * @version 1.0.0-a
 */
template <typename T>
class Plotter
{
	public:
        /**
		 * @fn Plotter(Parser<T>* aParser, map< char, PlotSet<T> > aPlotMap)
		 * @brief Constructor
		 * @arg @c aParser Pointer to concrete parser instance
		 * @arg @c aPlotMap A std::map containing axis labels and a PlotSet instance for each independent axis
		 * @arg @c dependent Axis label for the dependent axis
		 */
		Plotter(Parser<T>* aParser, map< char, PlotSet<T> > aPlotMap, char dependent)
			: parser(aParser), plotMap(aPlotMap) {}

        /** @brief Destructor */
		virtual ~Plotter() {}

       /**
		 *  @fn Plot(map<char, vector<T> >&)
		 *	@brief Create plot data for all axes
		 *  @arg @c result The result from the plot session
		 *  @arg @c expr The mathematical expression to plot
		 *  @return True if plot session ran correctly. False if a problem occured.
		 *	@pre:  T is numeric
		 *  @post: Plot data is stored in the result reference.
		 *
		 *  This function should be implemented as to return a map with one plot result per axis. A plot session
		 *  with N independent axes (PlotSet instances to constructor) should return N+1 vectors in the result map
		 *  (N for the independent axes, one for the dependent axis) */
		virtual bool Plot(map<char, vector< PlotResult<T> > >& result, string expr)=0;

        /**
		 *  @fn GetPlotSet(char label, PlotSet<T>& plot)
		 *	@brief Get a PlotSet object for a specific axis
		 *  @arg @c label Identifying axis label
		 *  @arg @c plot PlotSet reference object
		 *  @return True if found and returned. False if not found.
		 *  @warning The value of plot is undefined when false is returned */
		virtual bool GetPlotSet(char label, PlotSet<T>& plot)
		{
            typename map< char, PlotSet<T> >::iterator it = plotMap.find(label);

		    if (it == plotMap.end())
                return false;

            plot = it->second;
            return true;
		}

        /**
		 *  @fn SetPlotSet(char label, const PlotSet<T>& plot)
		 *	@brief Set/Change a PlotSet object for a specific existing axis
		 *  @arg @c label Identifying axis label
		 *  @arg @c plot New PlotSet object
		 *  @return True if found and changed. False if not found. */
		virtual bool SetPlotSet(char label, const PlotSet<T>& plot)
		{
		    typename map< char, PlotSet<T> >::iterator it = plotMap.find(label);

		    if (it == plotMap.end())
                return false;

            it->second = plot;
            return true;
		}

	protected:
		Parser<T>* parser;
		map< char, PlotSet<T> > plotMap;
};
}
#endif
