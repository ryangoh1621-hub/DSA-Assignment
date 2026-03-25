#include "additionalFunction.h"
/*
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


*/


double sPCC(const vector<double>& x, const vector<double>& y)
{
    if(x.size() == y.size())
    {
        double yMean = 0; //
        double xMean = 0;
        double numerator= 0;
        double Xdenom = 0;
        double Ydenom = 0;

        //getting mean of vector x and vector y
        for(int i = 0; i < x.size(); i++)
        {
            xMean = xMean + x[i];
            yMean = yMean + y[i];

        }
        xMean = xMean / x.size();
        yMean = yMean / y.size();

        //compute deviation and sum
        for(int i =0; i < x.size(); i++)
        {
            double dx = x[i] - xMean;
            double dy = y[i] - yMean;
            numerator += dx * dy;
            Xdenom += dx * dx;
            Ydenom += dy * dy;
        }

        return numerator / (sqrt(Xdenom) * sqrt(Ydenom));
    }
    else
    {
        throw invalid_argument("Error, both vector must be in equal length");
    }
}

double MAD(const vector<double>& data)
{
    double sumAd = 0;
    double mean = 0;

    for (int i = 0; i < data.size(); i++) //calculate mean
    {
        mean = mean + data[i];
    }
    mean = mean / data.size();


for (int i = 0; i < data.size(); i++) {
    sumAd = sumAd + fabs(data[i] - mean);
}

    return sumAd / data.size();
}
