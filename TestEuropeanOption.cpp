#include "EuropeanOption.h"
#include <iostream>
#include <cstdio>
using namespace std;

template <class Type> class range
{
public:
    Type& func(Type &a, Type &b);
    range(Type a_1, Type b_1): a(a_1), b(b_1)
    {
        return a+b;
    }
private:
    Type a;
    Type b;
};

template <class Type> Type& range<Type>::func(Type &a, Type&b)
{
    return *this +=a+b;
}

int main()
{
    // Call option on a stock
    EuropeanOption callOption;
    cout << "Call option on a stock: " << callOption.Price() << endl;

    EuropeanOption indexOption;
    range<int> r(2,3);

    indexOption.optType = "P";
    indexOption.U = 100.0;
    indexOption.K = 95.0;
    indexOption.T = 0.5;
    indexOption.r = 0.10;
    indexOption.sig = 0.20;
    double q = 0.05;
    indexOption.b = indexOption.r - q;

    cout << "Put option on index: " << indexOption.Price() << endl;

    EuropeanOption futureOption;

    futureOption.optType = "P";
    futureOption.U = 19.0;
    futureOption.K = 19.0;
    futureOption.T = 0.75;
    futureOption.r = 0.10;
    futureOption.sig = 0.28;
    futureOption.b = 0.0;
    cout << "Put option on future: " << futureOption.Price() << endl;
    futureOption.toggle();
    cout << "Call on future: " << futureOption.Price() << endl;
    return 0;
}