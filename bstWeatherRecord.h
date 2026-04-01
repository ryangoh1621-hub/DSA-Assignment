#ifndef BSTWEATHERRECORD_H_INCLUDED
#define BSTWEATHERRECORD_H_INCLUDED
#include "bst.h"
#include "WindRecType.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "additionalFunction.h"

class bstWeatherRecord
{

public:
    bstWeatherRecord();
    void WindRecordInsert(const WindRecType& record);
    bool WindRecordSearch(const WindRecType& record) const;
    void DisplayAll() const;

    private:
    bst<WindRecType> wind_data;   // now using BST instead of Vector
};

ostream& operator<<(ostream& os, const bstWeatherRecord& rec);
istream& operator>>(istream& input, bstWeatherRecord& rec);





#endif // BSTWEATHERRECORD_H_INCLUDED
