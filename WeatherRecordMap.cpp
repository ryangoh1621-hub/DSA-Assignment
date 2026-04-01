#include "WeatherRecordMap.h"
#include <sstream>

WeatherRecordMap::WeatherRecordMap(){}

void WeatherRecordMap::WRMapInsert(const WindRecType& record)
{
    string key = WRkey(record);
    wind_data.Create(key, record);
}

void WeatherRecordMap::WRMapRemove(const string& key)
{
    wind_data.Delete(key);
}

WindRecType WeatherRecordMap::WRMapGetRecord (const string& key) const
{
    return wind_data[key];
}

int WeatherRecordMap::WRMapTotalRecord() const
{
    return 0;
}


string WeatherRecordMap::WRkey(const WindRecType& rec) const
{
    string key = to_string(rec.getDate().GetDay())
            + "/" + to_string(rec.getDate().GetMonth())
            + "/" + to_string(rec.getDate().GetYear())
            + " " + to_string(rec.getTime().GetHour())
            + ":" + to_string(rec.getTime().GetMin());

            return key;
}

ostream& operator<<(ostream& os, const WeatherRecordMap& rec)
{

}

istream& operator>>(istream& input, WeatherRecordMap& rec)
{

}
