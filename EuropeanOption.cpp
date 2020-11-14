//
// Created by Parth Parakh on 11/11/20.
//

#include "EuropeanOption.h" // Declarations of functions
#include <cmath> // For mathematical functions, e.g. exp()
#include<string>
using namespace std;
// Kernel Functions
double EuropeanOption::CallPrice() const
{
    double tmp = sig*sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;
    return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));
}

double EuropeanOption::PutPrice() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;
    return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));
}

double EuropeanOption::CallDelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * N(d1);
}

double EuropeanOption::PutDelta() const
{
    double tmp = sig * sqrt(T);
    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    return exp((b-r)*T) * (N(d1) - 1.0);
}

void EuropeanOption::init()
{ // Initialise all default values
// Default values r = 0.08;
    sig = 0.30;
    K = 65.0;
    T = 0.25;
    U = 60.0; // U == stock in this case
    b = r; // Black and Scholes stock option model (1973) optType = "C"; // European Call Option (the default type)
}

void EuropeanOption::copy(const EuropeanOption& o2)
{
    r = o2.r;
    sig = o2.sig;
    K = o2.K;
    T = o2.T;
    U = o2.U;
    b = o2.b;
    optType = o2.optType;
}

EuropeanOption::EuropeanOption()
{
    init();
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{
    copy(o2);
}

EuropeanOption::EuropeanOption(const string& optionType)
{
    init();
    optType = optionType;
    if (optType == "c") optType = "C";
}

EuropeanOption:: ~EuropeanOption()
{
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& opt2)
{ // Assignment operator (deep copy)
    if (this == &opt2) return *this;
    copy (opt2);
    return *this;
}

double EuropeanOption::Price() const
{
    if (optType == "C")
    {
        return CallPrice();
    }
    else
    {
        return PutPrice();
    }
}

double EuropeanOption::Delta() const
{
    if (optType == "C")
        return CallDelta();
    else
        return PutDelta();
}

void EuropeanOption::toggle()
{
    if (optType == "C") optType = "P";
    else
        optType = "C";
}







