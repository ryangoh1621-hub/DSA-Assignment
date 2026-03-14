#include "Unit.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Test 1 - default constructor" << endl;
    Unit myUnit;
    cout << myUnit << endl << endl;

    cout << "Test 2 - Non default constructor" << endl;
    Unit myUnit2 ("Data Structure Algo", "ICT283", 3);
    cout << myUnit2 << endl;

    cout << "Test 3 - Set and Get myUnit" << endl;
    myUnit.SetName("Project Management");
    myUnit.SetUnitID("ICT123");
    myUnit.SetCredits(4);
    cout << "**UPDATED myUnit" << endl
         << myUnit << endl;

    return 0;
}
