#include "Time.h"

Time::Time() // default constructor
{
    m_seconds = 0;
    m_minutes = 0;
    m_hours = 0;
}
Time::Time(int seconds, int minutes, int hours) //non-default consturctor
{
    m_seconds = seconds;
    m_minutes = minutes;
    m_hours = hours;
}
//get set method
int Time::GetSec()const{return m_seconds;}
int Time::GetMin()const{return m_minutes;}
int Time::GetHour()const{return m_hours;}
void Time::SetSec(int sec){ m_seconds = sec;}
void Time::SetMin(int minu){m_minutes = minu;}
void Time::SetHour(int hour){m_hours = hour;}


//input and output stream
ostream & operator <<( ostream & os, const Time & time)
{
    os << "Time: "  << time.GetHour() << ":" << time.GetMin() << ":" << time.GetSec(); // get year
    return os;
}
istream & operator >>( istream & input, Time & time )
{
    // add input code here
        return input;
}
