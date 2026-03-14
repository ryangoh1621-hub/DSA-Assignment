#ifndef TIME_H_INCLUDED
#define TIME_H_INCLUDED
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;
/**
 * @class Time
 * @brief  Represent the Time in hour, min, sec
 *
 * @author Ryan
 * @version 01
 * @date 25/02/2026 Ryan
 *
 * @todo Implemenet of time attributes (completed)
 * @todo Implemenet of time with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (completed)
 *
 * @bug None
 */
class Time
{

public:
    /** @brief Initialise a time object of default and non default constructor
    *
    * @param seconds - the integer value of second
    * @param minutes - the integer value of minutes
    * @param hours - the integer value of hour
    * @return void
    *
    */

    Time();
    Time(int seconds, int minutes, int hours);
    /** @brief Retrieve seconds from m_seconds
     *
     * @return int of m_seconds
     *
     */
    int GetSec()const;

    /** @brief Retrieve minutes from m_minutes
     *
     * @return int of m_minutes
     *
     */
    int GetMin()const;

    /** @brief Retrieve hours from m_hours
     *
     * @return int of hours
     *
     */
    int GetHour()const;

    /** @brief Set seconds
     *
     * @param seconds - set the m_seconds based on the seconds given
     *
     */
    void SetSec(int sec);

    /** @brief Set minutes
     *
     * @param minutes - set the m_minutes based on the minutes given
     *
     */
    void SetMin(int minu);

    /** @brief Set hours
     *
     * @param hours - set the m_hours based on the hours given
     *
     */
    void SetHour(int hour);

private:
    /** @brief creation of time Attributes
    *
    * @param seconds - to contain a integer of the seconds
    * @param minutes - to contain a integer of the minutes
    * @param hours - to contain a integer of the hours
    *
    */
    int m_seconds;
    int m_minutes;
    int m_hours;

};
/** @brief output and input stream operator
*
* @param ostream - process of streaming to prompt
* @param istream - process of reading from an input file
*
*/
ostream & operator <<( ostream & os, const Time & time);
istream & operator >>( istream & input, Time & time );
#endif // TIME_H_INCLUDED
