#include "WeatherRecord.h"

int main()
{

    WindRecType testRec;

    cout << "Test 1" << endl;
    testRec.my_date = Date(10,10,25);
    testRec.my_time = Time(59,30,22);
    testRec.my_speed = 15.1;

    cout << "My Date: " << testRec.my_date.GetDay() <<"/"<<testRec.my_date.GetMonth() <<"/"<< testRec.my_date.GetYear()  << endl;
    cout << "My Time: " << testRec.my_time.GetHour() <<":"<< testRec.my_time.GetMin() <<":"<< testRec.my_time.GetSec()  << endl;
    cout << "my speed: " << testRec.my_speed << endl;


    WeatherRecord myRec;

    myRec.AddWindRecord(testRec);
    myRec.AddWindRecord(testRec);
    myRec.AddWindRecord(testRec);
    myRec.AddWindRecord(testRec);
    myRec.AddWindRecord(testRec);
    cout << myRec << endl;

    ifstream infile( "MetData-31-3.csv" ); //infile is an object on runtime stack | open file
    if( !infile )
    {
        return -1;
    }
    infile >> myRec;

    return 0;

}
