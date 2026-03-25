#include "intBst.h"

intBst::intBst() //constructor
{
    m_root = nullptr;
}
intBst::~intBst() //deconstructor
{
    Destroy(m_root);
}
void intBst::Destroy(Node*& Node) //destroy all componenet of struct
{
        if(Node != nullptr)
    {
        Destroy(Node->left);
        Destroy(Node->right);
        delete Node;
        Node = nullptr;
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
        cout<< node->data<< " "; //display current node
        InOrder(node->right); // check right child (recursive, to check child from that particular node)
    }
}
void intBst::PreOrder(Node* node) const
{
    if(node != nullptr)
    {
        cout<< node->data<< " ";
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
        cout<< node->data<< " ";
    }
}

    void intBst::Insert(const int value)
    {
        InsertRecord(m_root, value);
    }

    void intBst::InsertRecord(Node* &Node, int val)
    {
        if(Node == nullptr)
            {
                Node = new struct Node;
                Node->data = val;
                Node->left = nullptr;
                Node->right = nullptr;
                return;
            }
            if(val < Node->data)
                {
                    InsertRecord(Node->left, val);
                }
            else
                {
                    InsertRecord(Node->right, val);
                }
    }
    void intBst::Search(const int value)
    {

    }
