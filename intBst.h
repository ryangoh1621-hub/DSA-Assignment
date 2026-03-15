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
    void Search(const int value);

    void Destroy(Node*& Node); //ok

private:
    Node *m_root; //creation of Node pointer of m_root
    void InOrder(Node* node) const; //For private //ok
    void PreOrder(Node* node) const; //ok
    void PostOrder(Node* node) const; //ok
    void Delete(const int value);
};

intBst::intBst() //constructor
{
    m_root = nullptr;
}
~intBst::intBst() //deconstructor
{
    Destroy(m_root);
}
void intBst::Destroy(Node*& Node) //destroy all componenet of struct
{
        if(node != nullptr)
    {
        Destroy(node->left);
        Destroy(node->right);
        delete node;
        node = nullptr;
    }
}
void intBst::InOrderTraversal() const{InOrder(m_root);} //trigger private InOrder
void intBst::PreOrderTraversal() const{PreOrder(m_root);} //trigger private InOrder
void intBst::PostOrderTraversal() const{PostOrder(m_root);} //trigger private InOrder
void intBst::InOrder(Node* node) const
{
    if(node != nullptr) //if data is found
    {
        InOrder(node->left); //check left child (recursive, to check child from that particular node)
        cout<< node->info<< " "; //display current node
        InOrder(node->right); // check right child (recursive, to check child from that particular node)
    }
}
void intBst::PreOrder(Node* node) const
{
    if(node != nullptr)
    {

        if(node->left);
        cout<< node->info<< " ";
        PreOrder(node->left);
        PreOrder(node->right);
    }

}
void intBst::PostOrder(Node* node) const
{
    if(node != nullptr)
    {
        PostOrder(node->left);
        PostOrder(node->right);
        cout<< node->info<< " ";
    }
}

    void Insert(const int value)
    {

    }
    void Search(const int value)
    {

    }

#endif // INTBST_H_INCLUDED
