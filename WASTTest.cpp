#include "WAST.h"  // Registration class declaration/interface
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    cout << "Test 1" << endl;


    ifstream infile( "MetData-31-3.csv" ); //infile is an object on runtime stack | open file
    if( !infile )
    {
        return -1;
    }
    WAST myWast; //create obj
    infile >> myWast; //read from file to obj

    ifstream infile2( "MetData_Mar01-2014-Mar01-2015-ALL.csv" ); //infile is an object on runtime stack | open file
    if( !infile )
    {
        return -1;
    }
    WAST myWast2; //create obj
    infile2 >> myWast2; //read from file to obj
    //ofstream ofile( "routput.txt" ); //output file
    //ofile << RegistrationObj //ofile to save information to |output file
    //<< "Number of unit = " << RegistrationObj.GetCount() << '\n'
    //<< "Total credits     = " << RegistrationObj.GetCredits() << '\n';




    return 0;
}
