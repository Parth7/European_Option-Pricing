//
// Created by Parth Parakh on 29/10/20.
//

#include "random1.h"
#include <cstdlib>

using namespace std;

double GetOneGaussianBySummation()
{
    double result=0;
    for (unsigned long j=0; j < 12; j++)
        result += rand()/static_cast<double>(RAND_MAX);
    result -= 6.0;
    return result;
}


double GetOneGaussianByBoxMuller()
{
    double result;
    double x;
    double y;
    double sizeSquared;
    while(sizeSquared >= 1.0)
    {
        x = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        y = 2.0 * rand() / static_cast<double>(RAND_MAX) - 1;
        sizeSquared = x * x + y * y;
    }
}