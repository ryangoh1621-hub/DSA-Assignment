#ifndef WAST_H_INCLUDED
#define WAST_H_INCLUDED
#include <string>
#include <iostream>

using std::string;
using std::ostream;
using std::istream;

/**
 * @class WAST
 * @brief  Represent all information about wind
 *
 * @author Ryan
 * @version 01
 * @date 26/02/2026 Ryan
 *
 * @todo Implemenet of unit attributes (completed)
 * @todo Implemenet of unit with constructors (completed)
 * @todo Implemenet get() Set() method (completed)
 * @todo Implemenet input and output stream (completed)
 *
 * @bug None
 */

class WAST
{
public:
    /** @brief Initialise a time object of default and non default constructor
    *
    * @param windspeed - the integer value of windspeed
    * @param ambientAir - the float value of ambientAir
    * @param solarRadiation - the integer value of solarRadiation
    * @return void
    *
    */
    WAST();
    WAST(int windspeed, float ambientAir, int solarRadiation);

    /** @brief Retrieve windspeed from m_windspeed
     *
     * @return integer of windspeed of WAST
     *
     */
    int GetWindSpeed() const;

    /** @brief Set windpseed
     *
     * @param windspeed- set the m_windspeed based on the speed given
     *
     */
    void SetWindSpeed(int windspeed);

    /** @brief Retrieve ambientAir from m_ambientAir
     *
     * @return float of ambientAir of WAST
     *
     */
    float GetambientAir() const;

    /** @brief Set ambientAir
     *
     * @param ambientAir - set the m_ambientAir based on the ambientAir given
     *
     */
    void SetambientAir(float ambientAir);

    /** @brief Retrieve solarRadiation from m_solarRadiation
     *
     * @return integer of solarRadiation of WAST
     *
     */
    int GetsolarRadiation() const;

    /** @brief Set solarRadiation
     *
     * @param solarRadiation - set the m_solarRadiation based on the solarRadiation given
     *
     */
    void SetsolarRadiation(int solarRadiation);

private:

    /** @brief creation of WAST Attributes
    *
    * @param windspeed - to contain an interger of windspeed
    * @param ambientAir - to contain an float of ambientAir
    * @param solarRadiation - to contain an interger of solarRadiation
    *
    */
    int m_windspeed;
    float m_ambientAir;
    int m_solarRadiation;

};

/** @brief output and input stream operator
*
* @param ostream - process of streaming to prompt
* @param istream - process of reading from an input file
*
*/
ostream & operator <<( ostream & os, const WAST & wast);
istream & operator >>( istream & input, WAST & wast );

#endif // WAST_H_INCLUDED
