#include "Vector.h"
#include <iostream>
#include <string>
#include "Unit.h"

using namespace std;

int main()
{


    vector<int> numbers;
    cout << "Size: " << numbers.size() << endl;

    vector<int> numbers2(7);
    cout << "size" << numbers2.size() << endl;

    Vector<int> numbers3;
    numbers3.Insert(0,0);
    numbers3.Insert(11,1);
    numbers3.Insert(2,2);
    numbers3.Insert(3,3);
    numbers3.Remove(1);
    cout << "Size of numbers: " << numbers3.Size() << endl;
    for(int i = 0; i < numbers3.Size() ; i++)
    {
        cout << numbers3[i] << endl;

    }


    Vector<string> names;
    names.Insert("Jan",0);
    names.Insert("Jan2",1);
    names.Insert("Feb",2);
    names.Insert("Mar",3);
    names.Insert("Apr",4);
    names.Insert("May",5);
    names.Remove(1);

    cout << "Size of names: " << names.Size() << endl;

    for(int i = 0; i < 12; i++)
    {
        cout << "names: " << names[i] << endl;
    }
    cout << "Size of names: " << names.Size() << endl;


    cout << "Update: " << names[2] << endl;
    names[3] = "March";
    cout << "Update 2: " << names[2] << endl;
    cout << "Read: " << names[1] << endl;


    cout << "Vector Copy Test 3 : " << endl;

    Vector<int> points;
    points.Insert(10,0);
    points.Insert(20,1);
    points.Insert(20,2);
    points.Insert(20,3);
    points.Insert(20,4);
    points.Insert(20,5);

    Vector<int> points2 = points;
    Unit unitVec("Data Structure Algo", "ICT283", 3);
    Unit unitVec2("asd", "asd", 1);
    Vector<Unit> myvec;
    myvec.Insert(unitVec,0);
    myvec.Insert(unitVec2,1);
    for(int i = 0; i < 12; i++)
    {
        cout << "Unit: " << myvec[i]<< endl;
    }

    return 0;
}
