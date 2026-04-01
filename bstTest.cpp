#include <iostream>
#include <string>
#include "bst.h"
#include "Date.h"
#include "WindRecType.h"
#include "bstWeatherRecord.h"
#include "additionalFunction.h"
#include "DataSource.h"

using namespace std;
int main()
{


    bst<WindRecType> wrttree;

    wrttree.Insert(WindRecType(Date(10,10,1998),Time(30,10,05), WAST(1,1.2,3)));
    wrttree.Insert(WindRecType(Date(12,10,1998),Time(30,10,05), WAST(1,1.2,3)));
    wrttree.Insert(WindRecType(Date(10,9,1998),Time(30,10,05), WAST(1,1.2,3)));
    wrttree.Insert(WindRecType(Date(5,10,1998),Time(30,10,05), WAST(1,1.2,3)));

    wrttree.InOrderTraversal(bst<WindRecType>::printInfo);



    DataSource mydata;

    ifstream infile1( "data/data_source.txt" );

    if( !infile1 )
    {
        return -1;
    }
    infile1 >> mydata;

    //Creation of weatherRecords.
    //WeatherRecord myRec;
    bstWeatherRecord myRec;
    int choice;
    int inputMonth;
    int inputYear;

    for(int i = 0; i < mydata.getDataSize(); i++)
    {
        string path = "data/"+mydata.getRecord(i);
        cout << path << endl;
        ifstream infile(path);
        infile >> myRec;
        infile.clear();
    }





/*


    bst<Date> bstree;
    bstree.Insert(Date(1,1,2020));
    bstree.Insert(Date(1,3,2020));
    bstree.Insert(Date(1,5,2020));
    bstree.Insert(Date(1,4,2020));
    bstree.Insert(Date(1,2,2020));
    bstree.Insert(Date(1,6,2020));
    cout << "In order: " << endl;

    bstree.InOrderTraversal(bst<Date>::printInfo);
    bstree.PostOrderTraversal(bst<Date>::printInfo);
    bstree.PreOrderTraversal(bst<Date>::printInfo);
    bstree.DestroyTree();
    cout << endl;
    cout << "Key in anything to continue..";
    string line;
    getline(cin, line);


    bst<string> nameTree;
    nameTree.Insert("E");
    nameTree.Insert("C");
    nameTree.Insert("A");
    nameTree.Insert("B");
    nameTree.Insert("F");
    nameTree.Insert("D");
    nameTree.InOrderTraversal(bst<string>::printInfo);
    cout << endl;

    cout << "Key in anything to continue..";
    getline(cin, line);


    bst<int> originalTree;
    bst<int> copyingTree;
    originalTree.Insert(5);
    originalTree.Insert(1);
    originalTree.Insert(4);
    originalTree.Insert(4);
    originalTree.Insert(3);
    originalTree.Insert(8);
    copyingTree.CopyFrom(originalTree);
    cout << "Original: " << endl;
    originalTree.InOrderTraversal(bst<int>::printInfo);
    cout << endl;
    cout << "Copy: " << endl;
    copyingTree.InOrderTraversal(bst<int>::printInfo);
    cout << endl;

    cout << "Key in anything to continue..";

    cout << originalTree.Search(1) << endl;
    */
    return 0;
}
