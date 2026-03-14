#include "Result.h"

Result::Result()
{
    //m_unit already initlised
    m_mark = 0;
    //m_date already initlised
}

Result::Result(const Unit & unit, float mark, const Date & date)
{
    m_unit = unit;
    m_mark = mark;
    m_date = date;
}

void Result::GetUnit(Unit & unit) const //return by reference of obj
{
    unit = m_unit; //param = attribute
}

void Result::SetUnit(const Unit & unit)
{
    m_unit = unit; //attribute = param (copy to obj)
}

float Result::GetMark() const
{
    return m_mark;
}
void Result::SetMark(float mark)
{
    m_mark = mark;
}
void Result::GetDate(Date & date) const
{
    date = m_date;
}

void Result::SetDate(const Date & date)
{
    m_date = date;
}

ostream & operator <<(ostream & os, const Result & result)
{
    Unit tempUnit; //create temp storage
    result.GetUnit(tempUnit); // get unit info
    Date tempDate; //create temp storage
    result.GetDate(tempDate); // get date info

    os << tempUnit
       << "  Marks  : " << result.GetMark()
       << tempDate;

    return os;
}

istream & operator >>(istream & input, Result & result)
{

    Unit tempUnit; // temp var to redirect
    Date tempDate; // temp var to redirect
    string tempStr;
    const char DELIMITER = ',';

    input >> tempUnit; //using tempUnit to store obj details from file and pass to input
    getline(input, tempStr, DELIMITER); // get mark from file
    result.SetMark(stoi(tempStr)); //set mark to m_mark
    input >> tempDate; //using tempDate to store obj details from file and pass to input
    result.SetUnit(tempUnit); // update unit details
    result.SetDate(tempDate); // update date details

    return input;
}
