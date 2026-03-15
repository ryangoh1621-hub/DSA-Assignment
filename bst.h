#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED
#include <iostream>
using namespace std;



template <class DT> // DT = dataType to store any data type
struct Node //creation of a node struct
{
    DT info; //store DT of node
    Node<DT> *left;
    Node<DT> *right;
};

/**
 * @class bst
 * @brief  represents a binary search tree
 *
 * @author Ryan
 * @version 01
 * @date 13/03/2026 Ryan
 *
 * @todo Implemenet of bst node and root
 * @todo Implemenet of bst consturctor and deconstructor
 * @todo Implemenet of bst methods of InOrder,PreOrder, PostOrder
 * @todo Implemenet of bst Insert, Search, Destroy
 *
 * @bug None
 */

template <class DT>
class bst
{

    /** @brief Initialise a bst constructor and deconstructor
    */

public:
    bst();
    ~bst();

    /** @brief Initialise a helper / public method to run aa private method
    */
    void InOrderTraversal() const;
    void PreOrderTraversal() const;
    void PostOrderTraversal() const;

    /** @brief Initialise methods to Insert, Search, Check and Destory
    */
    bool Insert(const DT& data);
    bool InsertRecord(Node<DT>* &node, const DT& data);
    bool Search(const DT& findVal) const;
    bool CheckEmpty()const;
    void DestroyTree();

private:

    /** @brief creation of bst attribute of root pointer
    */
    Node<DT> *m_root;
    //void DeleteNode(const T& deletetarget);

    /** @brief Initialise private methods for computation of node and root
    */
    void InOrder(Node<DT> * node) const;
    void PreOrder(Node<DT> * node) const;
    void PostOrder(Node<DT> * node) const;
    void CopyTree(Node<DT>* &copiedTreeRoot, Node<DT>* &otherTreeRoot);
    void Destroy(Node<DT>* &node);

};
template <class DT>
bst<DT>::bst()
{
    m_root = nullptr; // initilise
}

template <class DT>
bst<DT>::~bst()
{
    Destroy(m_root); //deconstructor
}

template <class DT>
void bst<DT>::InOrderTraversal() const
{
    InOrder(m_root); //helper to call private function
}

template <class DT>
void bst<DT>::PreOrderTraversal() const
{
    PreOrder(m_root); //helper to call private function
}

template <class DT>
void bst<DT>::PostOrderTraversal() const
{
    PostOrder(m_root); //helper to call private function
}

template <class DT>
bool bst<DT>::Insert(const DT& data)
{

    return InsertRecord(m_root, data);

}

template <class DT>
bool bst<DT>::InsertRecord(Node<DT>* &node, const DT& data)
{
    if(node == nullptr)
        {
            node = new Node<DT>; //initilise
            node->info = data; // insert data
            node->left = nullptr; // initilise child
            node->right = nullptr; // initilise child
        }

    if(node->info == data) //check for duplicate
    {
        return false;
    }
    else if(data < node->info) //smaller than, go left
    {
        return InsertRecord(node->left, data); //repeat and add to left
    }
    else //bigger than, go right
    {
        return InsertRecord(node->right, data); //repeat and add to right
    }
}

template <class DT>
bool bst<DT>::Search(const DT& findVal) const
{
    Node<DT>* node = m_root;

    while(node != nullptr)
    {
        if(node->info == findVal) //check node isit match
        {
            return true;
        }
        else if(node->info > findVal) // if bigger
        {
            node = node->left; // save left child node and repeat finding
        }

        else //if smaller
        {
            node = node->right; //save the right child node and repeat finding
        }

    }
    return false;
}

template <class DT>
bool bst<DT>::CheckEmpty() const
{
    if(m_root == nullptr) // check for empty root
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class DT>
void bst<DT>::DestroyTree()
{
    Destroy(m_root); //helper to call private function
}


//-----------Private functions and Methods-------
template <class DT>
void bst<DT>::InOrder(Node<DT> *node) const
{
    if(node != nullptr) //check for null if not move on
    {
        InOrder(node->left); //checking left leaf | Have = run again to see child (recursive) | No = proceed
        cout << node->info << " "; //display node
        InOrder(node->right); //check right leaf | Have = run again to see child (recursive) | No = proceed
    }

}

template <class DT>
void bst<DT>::PreOrder(Node<DT> *node) const
{
    if(node != nullptr) //check for null
    {
        cout << node->info << " "; //display node
        PreOrder(node->left); //checking left leaf | Have = run again to see child (recursive)| No = proceed
        PreOrder(node->right); //check right leaf | Have = run again to see child (recursive)| No = proceed
    }

}

template <class DT>
void bst<DT>::PostOrder(Node<DT> *node) const
{

    if(node != nullptr)
    {
        PostOrder(node->left); //checking left leaf | Have = run again to see child (recursive)| No = proceed
        PostOrder(node->right); //check right leaf | Have = run again to see child (recursive)| No = proceed
        cout << node->info << " "; //display node
    }

}

template <class DT>
void bst<DT>::CopyTree(Node<DT>* &copiedTreeRoot, Node<DT>* &otherTreeRoot)
{
    if(otherTreeRoot == nullptr)
    {
        copiedTreeRoot = nullptr; //initilise
    }
    else
    {
        copiedTreeRoot = new Node<DT>; //create new
        copiedTreeRoot->info = otherTreeRoot->info; //copy data
        CopyTree(copiedTreeRoot->left, otherTreeRoot->left); // repeat for left
        CopyTree(copiedTreeRoot->right, otherTreeRoot->right); // repeat for right
    }
}

template <class DT>
void bst<DT>::Destroy(Node<DT>* &node)
{
    if(node != nullptr)
    {
        Destroy(node->left); //delete left pointer
        Destroy(node->right); // delete right pointer
        delete node; // delete node
        node = nullptr; // set node to null
    }
}

#endif // BST_H_INCLUDED
