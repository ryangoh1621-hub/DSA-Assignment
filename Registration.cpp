#include "Registration.h"

Registration::Registration() // create default constructor
{
    m_count = 0; // initilise with default value
    m_studentId = 0;
    m_semester = 0;
}

//methods
long Registration::GetStudentID() const // read only | no modification to attrributes || method to call student ID
{
    return m_studentId; // return studentID
}
void Registration::SetStudentID(long studentID)
{
    m_studentId = studentID;
}

int Registration::GetSem() const // read only | no modification to attrributes || method to call student ID
{
    return m_semester;// return semester
}
void Registration::SetSem(int semester)
{
    m_semester = semester;
}

int Registration::GetCount() const // read only | no modification to attrributes || method to call student ID
{
    return m_count; // return count
}
void Registration::SetCount(int count)
{
    m_count = count;
}

int Registration::GetCredits() const // read only | no modification to attrributes || method to call student ID
{
    int sum = 0;
    Unit tempUnit;

    for(int i = 0; i < m_count; i++)
    {
        m_result[i].GetUnit(tempUnit);
        sum += tempUnit.GetCredits();
    }
    return sum;
}

istream & operator >>( istream & input, Registration & registration )
{
    const char DELIMITER = ',';
    string tempStr; // read using getLine
    getline(input, tempStr, DELIMITER); // read until see comma
    registration.SetStudentID(stol(tempStr)); // convert string to long
    getline(input, tempStr, DELIMITER); // read until see comma
    registration.SetSem(stoi(tempStr)); // convert int to string
    getline(input, tempStr); // read last and invis \n
    registration.SetCount(stoi(tempStr));

    for(int i = 0; i < registration.GetCount(); i++)
    {
        input >> registration.m_result[i];
    }

    return input;
}


ostream & operator <<( ostream & os, const Registration & registration )
{
    os << "Student ID: " << registration.GetStudentID() << '\n'
       << "Semester:   " << registration.GetSem() << '\n'
       << "count:   " << registration.GetCount() << '\n';
    for(int i = 0; i < registration.GetCount(); i++)
    {
        os << registration.m_result[i] << '\n';
    }

    return os;
}
