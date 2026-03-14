#ifndef RESULT_H_INCLUDED
#define RESULT_H_INCLUDED
#include "Unit.h"
#include "Date.h"
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

/**
 * @class Result
 * @brief  Represent a result of the unit taken
 *
 * @author Ryan
 * @version 01
 * @date 02/02/2026 Ryan
 *
 * @todo Implemenet of result attributes (completed)
 * @todo implmenet of Date class to attribute
 * @todo Implemenet of result with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (completed)

 *
 * @bug None
 */

class Result
{

public:

    /** @brief Initialise a result object of default and non default constructor
    *
    * @param unit - class unit
    * @param  mark - mark recieve per unit
    * @param  date - class date
    *
    * @return void
    *
    */
    Result();
    Result(const Unit & unit, float mark, const Date & date);

    /** @brief Retrieve unit class from m_unit
     *
     * @return unit object details
     *
     */
    void GetUnit(Unit & unit) const;

    /** @brief Set unit object
     *
     * @param unit - from unit class
     *
     */
    void SetUnit(const Unit & unit);

    /** @brief Retrieve mark from m_mark
     *
     * @return float of mark
     *
     */
    float GetMark() const;

    /** @brief Set mark
     *
     * @param mark - set the m_mark based on the mark given
     *
     */
    void SetMark(float mark);

    /** @brief Retrieve date class from m_date
     *
     * @return date object details
     *
     */
    void GetDate(Date & date) const;

    /** @brief Set date object
     *
     * @param date - from date obj
     *
     */
    void SetDate(const Date & date);

private:

    /** @brief creation of Result Attributes
    *
    * @param Unit - to contain the class of unit
    * @param marks - to contain an float of the marks
    * @param date - to contain an class of date
    *
    */
    Unit m_unit;
    float m_mark;
    Date m_date;
};

/** @brief output and input stream operator
*
* @param ostream - process of streaming to prompt
* @param istream - process of reading from an input file
*
*/
ostream & operator <<(ostream & os, const Result & result);
istream & operator >>(istream & input, Result & result);

#endif // RESULT_H_INCLUDED
