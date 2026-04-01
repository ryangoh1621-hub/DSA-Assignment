#include "WindRecType.h"
WindRecType::WindRecType() = default;
WindRecType::WindRecType(const Date& date, const Time& time, const WAST& wast) : my_date(date), my_time(time), my_wast(wast) {}


// Get and Set
Date& WindRecType::getDate() // for modification
{
    return my_date;
}
Time& WindRecType::getTime()
{
    return my_time;
}
WAST& WindRecType::getWAST()
{
    return my_wast;
}

const Date& WindRecType::getDate() const // for non-modification
{
    return my_date;
}
const Time& WindRecType::getTime() const
{
    return my_time;
}
const WAST& WindRecType::getWAST() const
{
    return my_wast;
}
void WindRecType::setDate(const Date& date)
{
    my_date = date;
}
void WindRecType::setTime(const Time& time)
{
    my_time = time;
}
void WindRecType::setWAST(const WAST& wast)
{
    my_wast = wast;
}
/*
bool WindRecType::operator<(const WindRecType& other) const
{
    if (my_date < other.my_date) return true;
    if (my_date > other.my_date) return false;

    return my_time < other.my_time;
}

bool WindRecType::operator==(const WindRecType& other) const
{
    return (my_date == other.my_date &&
            my_time == other.my_time);
}*/

    bool operator==(const WindRecType& lhs, const WindRecType& rhs)
    {
            return lhs.getDate() == rhs.getDate() &&
           lhs.getTime() == rhs.getTime();
    }
    bool operator<(const WindRecType& lhs, const WindRecType& rhs)
    {
            if (lhs.getDate() == rhs.getDate()) {
        return lhs.getTime() < rhs.getTime();
    }
    return lhs.getDate() < rhs.getDate();
    }
    bool operator>(const WindRecType& lhs, const WindRecType& rhs)
    {
            if (lhs.getDate() == rhs.getDate()) {
        return lhs.getTime() > rhs.getTime();
    }
    return lhs.getDate() > rhs.getDate();
    }


ostream& operator<<(ostream& os, const WindRecType& rec)
{
    os << rec.getDate().GetDay() << " "
       << rec.getDate().GetMonth() << " "
       << rec.getDate().GetYear() << " "

       << rec.getTime().GetHour() << ":"
       << rec.getTime().GetMin() << ":"
       << rec.getTime().GetSec() << " "

       << rec.getWAST().GetWindSpeed() << " "
       << rec.getWAST().GetambientAir() << " "
       << rec.getWAST().GetsolarRadiation();

    return os;
}
