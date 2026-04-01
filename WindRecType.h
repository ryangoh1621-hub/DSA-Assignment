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
    /** @brief Initialise a WindRecType object of default and non default constructor
    *
    * @return void
    */
    WindRecType();
    WindRecType(const Date& date, const Time&time, const WAST& wast);

    /** @brief Initialise a WindRecType Get and Set Methods
    *
    * @return void
    */
    Date& getDate();
    Time& getTime();
    WAST& getWAST();
    const Date& getDate() const;
    const Time& getTime() const;
    const WAST& getWAST() const;
    void setDate(const Date& date);
    void setTime(const Time& time);
    void setWAST(const WAST& wast);
    //bool operator<(const WindRecType& other) const;
    //bool operator==(const WindRecType& other) const;




private:
    /** @brief creation of WindRecType Attributes
    *
    * @param my_date - to contain an class of date
    * @param my_time - to contain an class of time
    * @param my_wast - to contain an class of wast
    *
    */
    Date my_date;
    Time my_time;
    WAST my_wast;

};

    bool operator==(const WindRecType& lhs, const WindRecType& rhs);
    bool operator<(const WindRecType& lhs, const WindRecType& rhs);
    bool operator>(const WindRecType& lhs, const WindRecType& rhs);


ostream& operator<<(ostream& os, const WindRecType& rec);

#endif // WINDRECTYPE_H_INCLUDED
