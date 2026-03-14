#ifndef WEATHERRECORD_H_INCLUDED
#define WEATHERRECORD_H_INCLUDED
//#include "Date.h"
//#include "Time.h"
#include "Vector.h"
//#include "WAST.h"
#include "WindRecType.h"
#include <iostream>
#include <fstream>
#include <sstream>

using std::string;
using std::ostream;
using std::istream;
using std::istringstream; //to be able to use istrngstream getline()
using std::ifstream;
using std::cout;
using std::endl;
using std::cin;
using std::endl;

/**
 * @class WeatherRecord
 * @brief  Represent all information about weather
 *
 * @author Ryan
 * @version 01
 * @date 27/02/2026 Ryan
 *
 * @todo Implemenet of Struct (completed)
 * @todo Implemenet of Vector windlogType wind_data (completed)
 * @todo Implemenet of WeatherRecord with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (completed)
 *
 * @bug None
 */
typedef Vector<WindRecType> WindlogType;

class WeatherRecord
{
public:
    /** @brief Initialise a WeatherRecord object of default and non default constructor
    *
    * @return void
    */
    WeatherRecord();
    WeatherRecord(const WindlogType& windlogType);
    WeatherRecord(const WindRecType & windRecType);

    /** @brief Methods which allow modification of Vector
     *
     */
    void WindRecordInsert(const WindRecType& record);
    void WindRecordRemove(int pos);

    /** @brief Retrieve windRecords
     *
     *
     */
    WindRecType GetWindRecord(int pos) const;

    /** @brief Retrieve Record Count
     *
     * @return int of Vector Size
     *
     */
    int GetTotalRecords() const;

private:
    /** @brief Initialise a Vector Type of wind_data
    *
    *
    */
    WindlogType wind_data;
};


/** @brief output and input stream operator
*
* @param ostream - process of streaming to prompt
* @param istream - process of reading from an input file
*
*/
ostream& operator<<(ostream& os, const WeatherRecord& rec);
istream& operator>>(istream& input, WeatherRecord& rec);
#endif // WEATHERRECORD_H_INCLUDED
