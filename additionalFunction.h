#ifndef ADDITIONALFUNCTION_H_INCLUDED
#define ADDITIONALFUNCTION_H_INCLUDED
#include <iostream>
#include <string>
#include "WeatherRecord.h"
#include <cmath>
#include <vector>
#include <stdexcept>

using std::string;
using std::ostream;
using std::istream;
using std::invalid_argument;
using std::isnan;

double average(const Vector<double>& data);
double sum(const Vector<double>& data);
double SD(const Vector<double>& data);
double roundUpDec(double data);

double sPCC(const Vector<double>& x, const Vector<double>& y);
double MAD(const Vector<double>& data);


#endif // ADDITIONALFUNCTION_H_INCLUDED
