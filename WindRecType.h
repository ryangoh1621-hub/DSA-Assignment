#ifndef WINDRECTYPE_H_INCLUDED
#define WINDRECTYPE_H_INCLUDED
#include "Date.h"
#include "Time.h"
#include "WAST.h"
/**
 * @class WindRecType
 * @brief  Represent the windRecType
 *
 * @author Ryan
 * @version 01
 * @date 1/03/2026 Ryan
 *
 * @todo Implemenet of class attributes (completed)
 * @todo Implemenet of with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 *
 * @bug None
 */
class WindRecType
{

public:
    WindRecType();
    WindRecType(const Date& date, const Time&time, const WAST& wast);

    //Get and Set
    Date& getDate();
    Time& getTime();
    WAST& getWAST();
    const Date& getDate() const;
    const Time& getTime() const;
    const WAST& getWAST() const;
    void setDate(const Date& date);
    void setTime(const Time& time);
    void setWAST(const WAST& wast);


private:
    Date my_date;
    Time my_time;
    WAST my_wast;

};


#endif // WINDRECTYPE_H_INCLUDED
