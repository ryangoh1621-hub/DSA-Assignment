#ifndef INTBST_H_INCLUDED
#define INTBST_H_INCLUDED
#include <iostream>
using namespace std;

struct Node //creation of a node struct
{
    int data; //store DT of node
    Node *left;
    Node *right;
};
class intBst
{

public:

    intBst(); //ok
    ~intBst(); //ok

    void InOrderTraversal() const; //ok
    void PreOrderTraversal() const; //ok
    void PostOrderTraversal() const; //ok


    void Insert(const int value);
    void InsertRecord(Node* &Node, int val);
    void Search(const int value);

    void Destroy(Node*& Node); //ok

private:
    Node *m_root; //creation of Node pointer of m_root
    void InOrder(Node* node) const; //For private //ok
    void PreOrder(Node* node) const; //ok
    void PostOrder(Node* node) const; //ok
    void Delete(const int value);
};

#endif // INTBST_H_INCLUDED
