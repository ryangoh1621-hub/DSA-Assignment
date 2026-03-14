#include "WAST.h"

WAST::WAST() //default constructor
{
    m_windspeed = 0;
    m_ambientAir = 0;
    m_solarRadiation = 0;
}
WAST::WAST(int windspeed, float ambientAir, int solarRadiation) //non-default constructor
{
    m_windspeed = windspeed;
    m_ambientAir = ambientAir;
    m_solarRadiation = solarRadiation;
}
//Set and Get method
int WAST::GetWindSpeed() const
{
    return m_windspeed;
}
void WAST::SetWindSpeed(int windspeed)
{
    m_windspeed = windspeed;
}
float WAST::GetambientAir() const
{
    return m_ambientAir;
}
void WAST::SetambientAir(float ambientAir)
{
    m_ambientAir = ambientAir;
}
int WAST::GetsolarRadiation() const
{
    return m_solarRadiation;
}
void WAST::SetsolarRadiation(int solarRadiation)
{
    m_solarRadiation = solarRadiation;
}

//input output stream
ostream & operator <<( ostream & os, const WAST & wast)
{
    os << wast.GetWindSpeed() << " | "<< wast.GetambientAir()<< " | " << wast.GetsolarRadiation();
    return os;
}
istream & operator >>( istream & input, WAST & wast )
{
    return input;
}
