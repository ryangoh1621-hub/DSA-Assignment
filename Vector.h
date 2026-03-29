#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#include <stdexcept> //for out of range
#include <vector>
using std::string;
using std::ostream;
using std::istream;
using std::out_of_range; // to be able to throw out of range
using std::vector;

template <class T>
class Vector
{
public:


    Vector(){}; //no implementation required
    Vector(int n);
    ~Vector(){}; // no implementation required

    //Vector(const Vector<T>& other); //copy consturctor
    //Vector<T>& operator=(const Vector<T>& other); // copy assignment operator

    bool Insert(const T& data, int pos); // create
    bool Remove(int pos); // delete
    const T& operator[](int pos) const; // Read
    T& operator[] (const int& pos); // update

    int Size() const;



private:
    vector<T> m_vec;
};

template <class T>
Vector<T>::Vector(int n) //non-default constructor
{
    if(n >= 0) // of valid size
        {
            m_vec.resize(n);
        }

}

/*
template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) //operator
{
    if (this != &other) {
        m_vec = other.m_vec;
    }
    return *this;

}*/

template <class T>
bool Vector<T>::Insert(const T& data, int pos) //insert data to vector
{
   if(pos < 0 || pos > Size())
    {
        return false;
    }
   else if (pos == Size())
    {
        m_vec.push_back(data);
    }
   else
    {
        m_vec.insert(m_vec.begin() + pos, data);
    }
   return true;
}

template <class T>
bool Vector<T>::Remove(int pos) // remove a type of vector
{
    if (pos < 0 || pos >= Size()) {
        return false;
    }
    m_vec.erase(m_vec.begin() + pos);
    return true;
}

template <class T>
const T& Vector<T>::operator[](int pos) const // read/view vector object
{
    if(pos < 0 || pos >= m_vec.size())
    {
        throw std::out_of_range("Index out of range");
    }
    return m_vec[pos]; //send back Vector value

}

template <class T>
T& Vector<T>::operator[] (const int& pos) // update vector value
{

    if (pos < 0 || pos >= m_vec.size()) //throw if outside range
    {
        throw std::out_of_range("Index out of range");
    }
    return m_vec[pos]; // update value

}

template <class T>
int Vector<T>::Size() const //Get Size of vector
{
    return m_vec.size(); // return size value
}

#endif // VECTOR_H_INCLUDED
