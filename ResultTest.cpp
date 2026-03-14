#include "Result.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Test 1 - default constructor" << endl;
    Result myR;
    cout << myR << endl;

    cout << "Test 2 - non default constructor" << endl;
    Unit rUnit ("Math", "ICT900", 3);
    Date rDate (10,4,25);
    Result myR2(rUnit, 87, rDate);
    cout << myR2 << endl;

    cout << "Test 3 - Set and Get Result" << endl;
    Unit tempUnit("A Math", "ICT901", 4);
    myR.SetUnit(tempUnit);
    myR.SetMark(90);
    Date tempDate(10,4,25);
    myR.SetDate(tempDate);
    cout << "**UPDATED myR" << endl
         << myR << endl;

    return 0;
}
