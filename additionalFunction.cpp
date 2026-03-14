#include "additionalFunction.h"

float averageWindSpeed(const WeatherRecord& rec)
{
    float avg = 0;
    float sum = 0;
    for (int i = 0; i < rec.GetTotalRecords(); ++i)
    {
        sum = sum + rec.GetWindRecord(i).getWAST().GetWindSpeed();
    }
    avg = sum / rec.GetTotalRecords();
    return avg;
}

float averageAmbientAirTemp(const WeatherRecord& rec)
{
    float avg = 0;
    float sum = 0;
    for (int i = 0; i < rec.GetTotalRecords(); ++i)
    {
        sum = sum + rec.GetWindRecord(i).getWAST().GetambientAir();

    }
    avg = sum / rec.GetTotalRecords();

    return avg;
}

float SDWindSpeed(const WeatherRecord& rec)
{
    float avg = averageWindSpeed(rec); // call average of windspeed
    float sumOfDeviation = 0;
    float variance = 0;
    float deviation = 0;
    int totalcount = rec.GetTotalRecords();

    for (int i = 0; i < totalcount; ++i)
    {
        // calculate deviation by per line value minus average
         deviation = rec.GetWindRecord(i).getWAST().GetWindSpeed() - avg;

        // get sum of deviation formula (deviation * deviation)
    sumOfDeviation = sumOfDeviation + (deviation * deviation);
    }

    // calculating variance
    variance = sumOfDeviation / totalcount;

    return sqrt(variance); //using cmath formula to get sqareroot varience

}

float SDambientAirTemp(const WeatherRecord& rec)
{
    float avg = averageAmbientAirTemp(rec); // call average of windspeed
    float sumOfDeviation = 0;
    float variance = 0;
        float deviation = 0;
    int totalcount = rec.GetTotalRecords();

    for (int i = 0; i < totalcount; ++i)
    {
        // calculate deviation by per line value minus average
        deviation = rec.GetWindRecord(i).getWAST().GetambientAir() - avg;

        // get sum of deviation formula (deviation * deviation)
       sumOfDeviation = sumOfDeviation + (deviation * deviation);
    }

    // calculating variance
    variance = sumOfDeviation / totalcount;

    return sqrt(variance); //using cmath formula to get sqareroot varience
}
float TotalSolarRadiation(const WeatherRecord& rec)
{
    float sum = 0;
    for (int i = 0; i < rec.GetTotalRecords(); ++i)
    {
        sum = sum + rec.GetWindRecord(i).getWAST().GetsolarRadiation();
    }
    return sum;
}

