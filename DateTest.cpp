#include "Date.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Test 1 - default constructor" << endl;
    Date myDate;
    cout << myDate << endl;

    cout << "Test 2 - Non default constructor" << endl;
    Date myDate2(30,2,2028);
    cout << myDate2 << endl;


    cout << "Test 3 - Set and Get date" << endl;
    myDate.SetDay(19);
    myDate.SetMonth(10);
    myDate.SetYear(1998);
    cout << "**UPDATED Date" << endl<< myDate << endl;

    return 0;
}
