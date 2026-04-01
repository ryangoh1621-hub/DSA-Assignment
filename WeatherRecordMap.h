#ifndef WEATHERRECORDMAP_H_INCLUDED
#define WEATHERRECORDMAP_H_INCLUDED

#include "WindRecType.h"
#include "Map.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "additionalFunction.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using std::to_string;

class WeatherRecordMap
{
    public:

    WeatherRecordMap(); // default

    void WRMapInsert(const WindRecType& record);
    void WRMapRemove(const string& key);
    WindRecType WRMapGetRecord (const string& key) const;
    int WRMapTotalRecord() const;

    private:
    Map<string, WindRecType> wind_data;
    string WRkey(const WindRecType& rec) const;

};

ostream& operator<<(ostream& os, const WeatherRecordMap& rec);
istream& operator>>(istream& input, WeatherRecordMap& rec);
#endif // WEATHERRECORDMAP_H_INCLUDED
