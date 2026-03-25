#include <iostream>
#include <string>
#include "intBst.h"


using namespace std;
int main()
{


    intBst NumTree;
    NumTree.Insert(5);
    NumTree.Insert(1);
    NumTree.Insert(4);
    NumTree.Insert(3);
    NumTree.Insert(8);
    NumTree.InOrderTraversal();
    cout << endl;
    NumTree.PreOrderTraversal();
    cout << endl;
    NumTree.PostOrderTraversal();
    cout << endl;

    return 0;
}
