#include "Time.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Test 1 - default constructor" << endl;
    Time mytime;
    cout << mytime << endl;

    cout << "Test 2 - Non default constructor" << endl;
    Time mytime2(0,9,17);
    cout << mytime2 << endl;

    cout << "Test 3 - Set and Get time" << endl;
    mytime.SetSec(10);
    mytime.SetMin(30);
    mytime.SetHour(20);
    cout << "**UPDATED Time" << endl<< mytime << endl;
    return 0;
}
