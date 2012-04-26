#include <map>
#include <vector>
#include "parser.h"
#include "plotter.h"
#include "realplotter2d.h"
#include "realparser.h"

#include <iostream>

// Temp
#include "scanner.h"
#include "defaultscanner.h"
#include "stringmodifier.h"

using std::cout;
using std::endl;
using std::map;
using std::vector;

using namespace ParsePlot;

int main()
{
    /*RealPlotter2D::ResultMap m;

    Parser<double> *parse = new RealParser();
    Plotter<double> *plot = new RealPlotter2D(parse);

    plot->Plot(m, "x^2+4x");

    delete parse;
    delete plot;*/

    Scanner *s = new DefaultScanner();
    s->Scan("20.94588+45*(35-2)*3");

    cout << "TOKENS:" << endl;
    cout << "-------" << endl << endl;

    while (s->HasNext())
    {
        cout << "TOKEN: " << s->Next()->GetValue() << endl;
    }

    delete s;
    return 0;
}
