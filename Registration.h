#ifndef REGISTRATION_H
#define REGISTRATION_H
#include "Result.h"
#include "Vector.h"
#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

const int MAX_RESULTS = 10;

/**
 * @class Registration
 * @brief  Represent a student enrollment
 *
 * @author Ryan
 * @version 01
 * @date 02/02/2026 Ryan
 *
 * @todo Implemenet of registration attributes (completed)
 * @todo Implemenet of registration with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (currently now friend)
 *
 * @bug None
 */
class Registration
{

public:

    /** @brief Initialise a unit object of default
    *
    * @param unit - class unit
    * @param  mark - mark recieve per unit
    *
    * @return void
    *
    */
    Registration();

    /** @brief Retrieve studentID from m_studentId
     *
     * @return long of studentID
     *
     */
    long GetStudentID() const;

    /** @brief Set studentID
     *
     * @param studentID - set the m_studentId based on the studentID given
     *
     */
    void SetStudentID(long studentID);

    /** @brief Retrieve semester from m_semester
     *
     * @return int of semester
     *
     */
    int GetSem() const;

    /** @brief Set semester
     *
     * @param semester - set the m_semester based on the semester given
     *
     */
    void SetSem(int semester);

    /** @brief Retrieve count from m_count
     *
     * @return int of count
     *
     */
    int GetCount() const;

    /** @brief Set count
     *
     * @param count - set the m_count based on the count given
     *
     */
    void SetCount(int count);

    /** @brief Retrieve credits from a unit class
     *
     * @return int of crecdit
     *
     */
    int GetCredits() const;

    /** @brief output and input stream operator
    *
    * @param ostream - process of streaming to prompt
    * @param istream - process of reading from an input file
    *
    */

    void GetResult(const Result & Result, int position);


    friend ostream & operator <<( ostream & os, const Registration & registration);
    friend istream & operator >>( istream & input, Registration & registration );


private:
    /** @brief creation of Registration Attributes
    *
    * @param Result - to contain the class array of max 10 result
    * @param studentId - to contain an long number of the studentID
    * @param semester - to contain an integer of the semester
    * @param count - to contain an interger of the count of each unit taken
    *
    */

    //Vector<Result> m_resultTest[MAX_RESULTS];
    Result m_result[MAX_RESULTS];
    long m_studentId;
    int m_semester;
    int m_count;
};


#endif

