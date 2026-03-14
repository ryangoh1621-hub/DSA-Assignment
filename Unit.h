#ifndef UNIT_H
#define UNIT_H
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

/**
 * @class Unit
 * @brief  Represent a description of a unit
 *
 * @author Ryan
 * @version 01
 * @date 02/02/2026 Ryan
 *
 * @todo Implemenet of unit attributes (completed)
 * @todo Implemenet of unit with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (completed)
 *
 * @bug None
 */
class Unit
{

public:

    /** @brief Initialise a unit object of default and non default constructor
    *
    * @param names - name of a unit
    * @param unitID - unit code
    * @param credits - amount of credit per unit
    * @return void
    *
    */
    Unit();
    Unit(const string & names, const string & unitID, int credits);

    /** @brief Retrieve name from m_names
     *
     * @return String of name of unit
     *
     */
    string GetName() const;

    /** @brief Set unit name
     *
     * @param names - set the m_name based on the name given
     *
     */
    void SetName(const string & names);

    /** @brief Retrieve unitID from m_unitID
     *
     * @return String of unitID
     *
     */
    string GetUnitID() const;

    /** @brief Set unitID
     *
     * @param unitID - set the m_unitID based on the unitID given
     *
     */
    void SetUnitID(const string & unitID);

    /** @brief Retrieve credits from m_credit
     *
     * @return int of crecdit
     *
     */
    int GetCredits() const;

    /** @brief Set credits
     *
     * @param credits - set the m_credits based on the credits given
     *
     */
    void SetCredits( int credits );

private:
    /** @brief creation of unit Attributes
    *
    * @param names - to contain a string of the unit name
    * @param unitID - to contain a string of the unit code
    * @param credits - to contain a single integer of the unit credits
    *
    */
    string m_names;
    string m_unitID;
    int  m_credits;
};

//------- function ------- //
/** @brief output and input stream operator
*
* @param ostream - process of streaming to prompt
* @param istream - process of reading from an input file
*
*/
ostream & operator <<( ostream & os, const Unit & unit );
istream & operator >>( istream & input, Unit & unit );

#endif
