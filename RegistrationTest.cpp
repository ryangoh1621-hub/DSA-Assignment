#include "Registration.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Test 1 - default constructor" << endl;
    Registration myRegistration;
    cout << myRegistration << endl;

    cout << "Test 2 - get and set method" << endl;
    myRegistration.SetStudentID(12345);
    myRegistration.SetSem(2);
    myRegistration.SetCount(1);
    cout << myRegistration << endl;

    return 0;
}
