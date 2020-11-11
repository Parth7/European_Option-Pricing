#include"payoff.h"
#include<iostream>
#include<_stdio.h>
using namespace std;

PayoffCall ::PayoffCall(double strike_) : strike(strike_)
{
};
double PayoffCall ::operator()(double spot) const
{
    return max(spot-strike,0);
};

PayoffPut ::PayoffPut(double strike_):strike(strike_)
{
};

double PayoffPut ::operator()(double spot) const
{
    return max(strike-spot,0);
};

Digit ::Digit(double strike_) : strike(strike_)
{
};

double Digit::operator()(double spot) const
{
    return spot>strike ? 1 : 0;
};

void func( PayoffCall& p)
{
    p.strike = 3;
}