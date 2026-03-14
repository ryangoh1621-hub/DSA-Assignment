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
