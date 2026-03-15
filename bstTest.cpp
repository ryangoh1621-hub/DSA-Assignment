#include <iostream>
#include <string>
#include "bst.h"
#include "Date.h"

using namespace std;
int main()
{
    bst<Date> bstree;
    bstree.Insert(Date(1,1,2020));
    bstree.Insert(Date(1,3,2020));
    bstree.Insert(Date(1,5,2020));
    bstree.Insert(Date(1,4,2020));
    bstree.Insert(Date(1,2,2020));
    bstree.Insert(Date(1,6,2020));
    cout << "In order: " << endl;
    //bstree.InOrderTraversal();
    //bstree.PostOrderTraversal();
    bstree.InOrderTraversal();
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
    nameTree.InOrderTraversal();
    cout << endl;

    cout << "Key in anything to continue..";
    getline(cin, line);


    bst<int> numberTrree;
    numberTrree.Insert(5);
    numberTrree.Insert(1);
    numberTrree.Insert(4);
    numberTrree.Insert(3);
    numberTrree.Insert(8);
    numberTrree.PostOrderTraversal();
     cout << endl;

    cout << "Key in anything to continue..";
    getline(cin, line);

    cout << numberTrree.Search(1) << endl;
    return 0;
}
