#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED
#define INITIAL_CAPACITY 6
#include <stdexcept> //for out of range
using std::string;
using std::ostream;
using std::istream;
using std::out_of_range; // to be able to throw out of range
/**
 * @class Vector
 * @brief  Represent a template Vector
 *
 * @author Ryan
 * @version 01
 * @date 25/02/2026 Ryan
 *
 * @todo Implemenet of Vector attributes (completed)
 * @todo Implemenet of Vector with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 *
 * @bug None
 */

template <class T>
class Vector
{
public:
    /** @brief Initialise Template Vector object of default constructor, non default constructor,deconstructor
    *
    * @param T*vec - holds different type of Vector
    * @param Capcity - holds int of capacity of vector
    * @param Size - holds current int size when storing value
    * @return void
    *
    */
    Vector();
    Vector(int n);
    ~Vector();

    /** @brief Creation of Copy constructor
     *
     *
     */
    Vector(const Vector<T>& other);

    /** @brief Creation of operator
     *
     *
     */
    Vector<T>& operator=(const Vector<T>& other);

    /** @brief Creation of Read, Create, Update and Delete method
     *
     *
     */
    bool Insert(const T& data, int pos); // create
    bool Remove(int pos); // delete
    const T& operator[](int pos) const; // Read
    T& operator[] (const int& pos); // update

    /** @brief Creation of Get Size
     *
     * @return m_size
     */
    int Size() const;

    /** @brief Creation of Get capacity
     *
     * @return m_capcity
     */
    int GetCapacity() const;

    /** @brief Clear vector & set size back to default
     *
     */
    void Clear();
private:
    /** @brief creation of attributes
    *
    * @param T*vec - holds different type of pointer Vector
    * @param Capcity - holds int of capacity of vector
    * @param Size - holds current int size when storing value
    *
    */
    T * m_vec;
    int m_capacity;
    int m_size;

};

template <class T>
Vector<T>::Vector() // Default constructor
{
    m_size = 0; // Set default value of size
    m_vec = new T[INITIAL_CAPACITY]; // set vector to a initial size of 6
    if(m_vec != nullptr)
    {
        m_capacity = INITIAL_CAPACITY; // set cap at 6
    }
    else
    {
        m_capacity = 0; // default capacity
    }
}

template <class T>
Vector<T>::Vector(int n) //non-default constructor
{

    m_vec = new T[n * 2];
    if(m_vec != nullptr)
    {
        m_capacity = n*2;
        m_size = n;
    }
    else
    {
        m_capacity = 0;
        m_size = 0;
    }

}

template <class T>
Vector<T>::~Vector() //vector deconstructor
{
    if(m_vec != nullptr)
    {
        delete[] m_vec;
        m_vec = nullptr;
    }
}

template <class T>
Vector<T>::Vector(const Vector<T>& other) // copy constructor
{
    //copy over data
    m_capacity = other.m_capacity;
    m_size = other.m_size;

    //allocate new memory e.g. object has it own array
    m_vec = new T[m_capacity];
    for(int i = 0; i < m_size; i++)
    {
        m_vec[i] = other.m_vec[i]; //loop to copy to m_vec
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other) //operator
{
    if(this == &other)
    {
        return *this;
    }
    //delete memory
    delete[] m_vec;

    //copy attributes to main
    m_capacity = other.m_capacity;
    m_size = other.m_size;
    m_vec = new T[m_capacity];

    for(int i = 0; i < m_size; i++)
    {
        m_vec[i] = other.m_vec[i]; //loop to copy to m_vec data
    }
    return *this;

}

template <class T>
bool Vector<T>::Insert(const T& data, int pos) //insert data to vector
{
    if(pos < 0 || pos > m_size) // if pos is out of range or bigger than size
    {
        return false; // return false
    }
    else
    {
        if(m_size > m_capacity/2) //check for possible and resize if size>cap/2
        {
            T* new_Vec = new T[m_capacity*2]; //create new vec
            for(int i = 0; i < m_size; i++)
            {
                new_Vec[i] = m_vec[i]; //Copy data over
            }
            delete[] m_vec; //delete old vec values
            m_vec = new_Vec; // port over new values
            m_capacity = m_capacity*2; //update cap
        }
        else
        {
            //successfuly update data to vector

        }
        for (int i = m_size; i > pos; --i) //movement to shift data downwards
        {
            m_vec[i] = m_vec[i - 1]; //move data down count
        }
        m_vec[pos] = data; // send data to specific position of vector
        m_size++; //increase size by 1
        //if vec is not full
        //shift elements to right from pos
        return true;
    }
}

template <class T>
bool Vector<T>::Remove(int pos) // remove a type of vector
{
    //check position is valid
    if(pos < 0 || pos >= m_size)
    {
        throw out_of_range("position out of range"); //throw if out of range
        return false;
    }
    else
    {
        for(int i = pos; i < m_size - 1; ++i)
        {
            m_vec[i] = m_vec[i+1]; //shift data down
        }
        m_vec[m_size-1] = T{}; //set the most right slot "deleted" back to default value
        --m_size; //update size array
        return true;
    }
}

template <class T>
const T& Vector<T>::operator[](int pos) const // read/view vector object
{
    if(pos < 0 || pos >= m_size)
    {
        throw std::out_of_range("Index out of range");
    }
    return m_vec[pos]; //send back Vector value
}

template <class T>
T& Vector<T>::operator[] (const int& pos) // update vector value
{
    if (pos < 0 || pos >= m_size) //throw if outside range
    {
        throw std::out_of_range("Index out of range");
    }
    return m_vec[pos]; // update value
}

template <class T>
int Vector<T>::Size() const //Get Size of vector
{
    return m_size; // return size value
}
template <class T>
int Vector<T>::GetCapacity() const //Get Capacity of Vector
{
    return m_capacity; // return capacity value
}

template <class T>
void Vector<T>::Clear() //Set Default size
{
    m_size = 0; //set default size if cleared
}

#endif // VECTOR_H_INCLUDED
