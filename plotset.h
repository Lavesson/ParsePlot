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

#ifndef _PLOTSET_H_
#define _PLOTSET_H_

namespace ParsePlot {

/**
 * @file plotset.h
 * @brief Contains the class PlotSet, which is used by the plotter
 *
 * @class PlotSet
 * @brief Keeps information about an independent axis state in the plotter
 * @author Eric Lavesson
 * @date 2011-02-05
 * @version 1.0.0-a
 */
template <typename T>
class PlotSet
{
	public:
        /**
		 * @fn PlotSet()
		 * @brief Constructor
		 *
		 * This constructor uses no default values. Use the Set-functions to set values */
        PlotSet() {}

        /**
		 * @fn PlotSet(T aMin, T aMax, T aStep)
		 * @brief Constructor
		 * @arg @c aMin Initial minimal axis value
		 * @arg @c aMax Initial maximal axis value
		 * @arg @c aStep Initial fixed sweep step */
		PlotSet(T aMin, T aMax, T aStep)
			: min(aMin), max(aMax), step(aStep) {}

        /**
		 * @fn GetMin()
		 * @brief Get minimal axis value
		 * @return Return the minimal axis value */
		T GetMin() { return min; }

		/**
		 * @fn GetMax()
		 * @brief Get maximal axis value
		 * @return Return the maximal axis value */
		T GetMax() { return max; }

		/**
		 * @fn GetStep()
		 * @brief Get fixed step value
		 * @return Return the fixed step value */
		T GetStep() { return step; }

        /**
		 * @fn SetMin(T aMin)
		 * @brief Set the minimal axis value
		 * @arg @c aMin New minimal axis value */
		void SetMin(T aMin) { min = aMin; }

        /**
		 * @fn SetMax(T aMax)
		 * @brief Set the maximal axis value
		 * @arg @c aMax New maximal axis value */
		void SetMax(T aMax) { max = aMax; }

        /**
		 * @fn SetStep(T aStep)
		 * @brief Set the step value
		 * @arg @c aStep New step value */
		void SetStep(T aStep) { step = aStep; }

	private:
		T min;
		T max;
		T step;
};

}

#endif
