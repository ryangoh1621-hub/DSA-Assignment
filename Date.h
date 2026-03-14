#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;
const int leapYear = 4;
const string Dates[12] = {"January", "February", "March", "April", "May","June","July","August","September", "October", "November", "December"};

/**
 * @class Date
 * @brief  Represent the Date of a unit taken
 *
 * @author Ryan
 * @version 01
 * @date 02/02/2026 Ryan
 *
 * @todo Implemenet of date attributes (completed)
 * @todo Implemenet of date with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (completed)
 *
 * @bug None
 */

class Date
{
public:

    /** @brief Initialise a unit object of default and non default constructor
    *
    * @param day - the integer value of day
    * @param month - the integer value of month
    * @param year - the integer value of year
    * @return void
    *
    */
    Date();
    Date(int day, int month, int year);


    /** @brief Retrieve day from m_day
     *
     * @return int of day
     *
     */
    int GetDay() const;

    /** @brief Set day
     *
     * @param day - set the m_day based on the day given
     *
     */
    void SetDay(int day);

    /** @brief Retrieve month from m_month
     *
     * @return int of month
     *
     */
    int GetMonth() const;

    /** @brief Set month
     *
     * @param month - set the m_month based on the month given
     *
     */
    void SetMonth(int month);

    /** @brief Retrieve year from m_year
     *
     * @return int of year
     *
     */
    int GetYear() const;

    /** @brief Set year
     *
     * @param year - set the m_year based on the year given
     *
     */
    void SetYear(int year);

    bool operator==(const Date& odate) const;
    bool operator>(const Date& odate) const;
    bool operator<(const Date& odate) const;

private:
    /** @brief creation of date Attributes
    *
    * @param day - to contain a integer of the day
    * @param month - to contain a integer of the month
    * @param year - to contain a integer of the year
    *
    */
    int m_day;
    int m_month;
    int m_year;

};

/** @brief output and input stream operator
*
* @param ostream - process of streaming to prompt
* @param istream - process of reading from an input file
*
*/
ostream & operator <<( ostream & os, const Date & date);
istream & operator >>( istream & input, Date & date );

/** @brief convert the integer month to a string name
 *
 * @param month - integer of the month to convert
 * @return string name of the month
 *
 */
string dateConversion(int month);
/** @brief validate the calander date and convert if nessesary
 *
 * @param day - retrive info of day to validate
 * @param month - retrive info of month to validate
 * @param year - retrive info of year to validate
 * @return int of the day
 *
 */
int validateDays(int day, int month, int year);

#endif // DATE_H_INCLUDED
