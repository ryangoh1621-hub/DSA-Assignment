#include "registration.h"  // Registration class declaration/interface
#include <iostream>
#include <fstream>

using namespace std;  // check textbook for details of the namespace concept

int main()
{

    ifstream infile( "rinput.txt" ); //infile is an object on runtime stack | open file
    if( !infile )
    {
        return -1;
    }
    Registration RegistrationObj; //create obj
    infile >> RegistrationObj; //read from file to obj

    ofstream ofile( "routput.txt" ); //output file

    ofile << RegistrationObj //ofile to save information to |output file
          << "Number of unit = " << RegistrationObj.GetCount() << '\n'
          << "Total credits     = " << RegistrationObj.GetCredits() << '\n';


    return 0;
}
