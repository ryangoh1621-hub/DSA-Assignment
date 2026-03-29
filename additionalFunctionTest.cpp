#include <iostream>
#include "additionalFunction.h"
using namespace std;

int main() {
    vector<double> X = {10, 20, 30, 40, 50};
    vector<double> Y = {12, 24, 33, 45, 55};


    cout << "sum: " << sum(X) << endl;
    cout << "avg: " << average(X) << endl;
    cout << "SD: " << SD(X) << endl;

    double r = sPCC(X, Y);
    cout << "Pearson Correlation Coefficient: " << r << endl;


    vector<double> values = {11, 15, 18, 17, 12, 17};

    double result = MAD(values);
    std::cout << "Mean Absolute Deviation: " << result << std::endl;

    return 0;
    return 0;
}
