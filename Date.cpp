#include "Date.h"

Date::Date() //Default Constructor
{
    m_day = 0; // initilise to default value of 0
    m_month = 0;
    m_year = 0;
}
Date::Date(int day, int month, int year) //Non-Default Constructor
{
    m_day = day; // initilise to a value
    m_month = month;
    m_year = year;
}

//methods
int Date::GetDay() const // read only | no modification to attrributes
{
    return m_day; //return value of m_day
}

void Date::SetDay(int day)
{
    m_day = day; //set or update value of m_day
}

int Date::GetMonth() const
{
    return m_month; //return value of m_month
}

void Date::SetMonth(int month)
{
    m_month = month; //set or update value of m_month
}

int Date::GetYear() const
{
    return m_year; //return value of m_month
}

void Date::SetYear(int year)
{
    m_year = year; //set or update value of m_month
}

bool Date::operator==(const Date& odate) const
{
    //std::cout << "Equal: " << (m_year == odate.GetYear() && m_month  == odate.GetMonth() && m_day == odate.GetDay()) << std::endl;
    return m_year == odate.GetYear() && m_month  == odate.GetMonth() && m_day == odate.GetDay();
}

bool Date::operator>(const Date& odate) const // compare by year, month and lastly day
{
    if(m_year > odate.GetYear())
    {
        return true;
    }
    else
    {
        if(m_month > odate.GetMonth())
        {
            return true;
        }
        else
        {
            if(m_day > odate.GetDay())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}
bool Date::operator<(const Date& odate) const // compare by year, month and lastly day
{
    if(m_year < odate.GetYear())
    {
        return true;
    }
    else
    {
        if(m_month < odate.GetMonth())
        {
            return true;
        }
        else
        {
            if(m_day < odate.GetDay())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
}

//functions
ostream & operator <<( ostream & os, const Date & date) // to stream out file to output file
{
    os << "Date: " << validateDays(date.GetDay(), date.GetMonth(), date.GetYear()) // validate day thru a function and display result
       << " " << dateConversion(date.GetMonth()) // convert month to a string
       << " " << date.GetYear(); // get year
    return os;
}

istream & operator >>( istream & input, Date & date )
{
    const char DELIMITER = ','; //creation of delimiter for reading ,
    const char DELIMITER2 = '/'; //creation of delimiter for reading /
    string tempStr; // create an temporary storage to read getLine
    getline(input, tempStr, DELIMITER2); // read until see comma
    date.SetDay(stoi(tempStr)); // convert string to int
    getline(input, tempStr, DELIMITER2); // read until see slash
    date.SetMonth(stoi(tempStr)); // convert string to int
    getline(input, tempStr); // read last till invis \n
    date.SetYear(stoi(tempStr));// convert string to int

    return input;
}

string dateConversion(int month)
{
    if(month >= 1 && month <= 12) // check for range
    {
        return Dates[month-1]; // return string of month
    }
    return "0"; // any fake value return 0
}

int validateDays(int day, int month, int year)
{
    if(month == 0) //check value of default
    {
        return 0;
    }

    if((month == 1 || month == 3 || month == 5  || month == 7 || month == 8 || month == 10 || month == 12) == true && day == 31) // validate month with 31 day
    {
        return 31;
    }
    else
    {
        if((month == 2 ||month == 4 || month == 6 ||month == 9 ||month == 11) == true && day >= 31) // validate month with 30 day
        {
            return 30;
        }
        if(month == 2) // validate feb
        {
            if(year%leapYear == 0) // check leap year
            {
                return 29;
            }
            else
            {
                return 28;
            }
        }
        else // if no validation is required
        {
            return day;
        }
    }

    return 0;
}


