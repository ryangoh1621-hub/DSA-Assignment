#ifndef ADDITIONALFUNCTION_H_INCLUDED
#define ADDITIONALFUNCTION_H_INCLUDED
#include <iostream>
#include <string>
#include "WeatherRecord.h"
#include <cmath>
using std::string;
using std::ostream;
using std::istream;

float averageWindSpeed(const WeatherRecord& rec);
float averageAmbientAirTemp(const WeatherRecord& rec);
float SDWindSpeed(const WeatherRecord& rec);
float SDambientAirTemp(const WeatherRecord& rec);
float TotalSolarRadiation(const WeatherRecord& rec);

#endif // ADDITIONALFUNCTION_H_INCLUDED
