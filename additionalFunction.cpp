#include "additionalFunction.h"

double sPCC(const Vector<double>& x, const Vector<double>& y)
{
    if(x.Size() == y.Size())
    {
        double yMean = 0; //
        double xMean = 0;
        double numerator= 0;
        double Xdenom = 0;
        double Ydenom = 0;

        //getting mean of vector x and vector y
        for(int i = 0; i < x.Size(); i++)
        {
            xMean = xMean + x[i];
            yMean = yMean + y[i];

        }
        xMean = xMean / x.Size();
        yMean = yMean / y.Size();

        //compute deviation and sum
        for(int i =0; i < x.Size(); i++)
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

double MAD(const Vector<double>& data)
{
    double sumAd = 0;
    double mean = 0;

    for (int i = 0; i < data.Size(); i++) //calculate mean
    {
        mean = mean + data[i];
    }
    mean = mean / data.Size();


    for (int i = 0; i < data.Size(); i++)
    {
        sumAd = sumAd + fabs(data[i] - mean);
    }

    return sumAd / data.Size();
}


double average(const Vector<double>& data)
{
    return sum(data) / data.Size();
}

double sum(const Vector<double>& data)
{
    double sum = 0;
    for(int i =0; i < data.Size(); i++)
    {
        sum = sum + data[i];
    }
    return sum;
}

double SD(const Vector<double>& data)
{
    double mean = average(data);
    double varianceSum = 0;
    double currDiff = 0;
    double variance = 0;

    for (int i = 0; i < data.Size(); i++)
    {
        currDiff = data[i] - mean;
        varianceSum = varianceSum + (currDiff * currDiff);
    }

    variance = varianceSum / data.Size(); // population SD
    return sqrt(variance);
}


double roundUpDec(double data)
{
    return round(data * 10) / 10.0;
}

