#include "Unit.h"

Unit::Unit() // default constructor - initlised to empty string
{
  m_names = "";
  m_unitID = "";
  m_credits = 0;
}

Unit::Unit(const string & names, const string & unitID, int credits) // non-default
{
  m_names = names;
  m_unitID = unitID;
  m_credits = credits;

}

string Unit::GetName() const //
{
    return m_names;
}

void Unit::SetName(const string & names)
{
    m_names = names;
}


string Unit::GetUnitID() const
{
    return m_unitID;
}

void Unit::SetUnitID(const string & unitID)
{
    m_unitID = unitID;
}


int Unit::GetCredits() const //get set method
{
  return m_credits;
}

void Unit::SetCredits( int credits )
{
  m_credits = credits;
}

istream & operator >>(istream & input, Unit & unit)
{
    const char DELIMITER = ',';
    string tempStr; // read using getLine
    getline(input, tempStr, DELIMITER); // read until see comma
    unit.SetName(tempStr);
    getline(input, tempStr, DELIMITER); // read until see comma
    unit.SetUnitID(tempStr);
    getline(input, tempStr, DELIMITER); // read until see comma
    unit.SetCredits(stoi(tempStr)); // change to int then set ID STOL = string to int

  return input;
}

ostream & operator <<( ostream & os, const Unit & unit )
{
  os << "  Unit: " << unit.GetName() << '\n' //call by getter
     << "  Section: " << unit.GetUnitID() << '\n' //call by getter
     << "  Credits: " << unit.GetCredits() << '\n'; //call by getter

  return os;
}
