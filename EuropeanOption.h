//
// Created by Parth Parakh on 11/11/20.
//

// EurpeanOption.hpp

#include<cstdio>
#include<string>
using namespace std;
class EuropeanOption {
private:
    void init();       // Initialise all default values
    void copy(const EuropeanOption& o2);
    // "Kernel" functions for option calculations
    double CallPrice() const;
    double PutPrice() const;
    double CallDelta() const;
    double PutDelta() const;
public:
// Public member data for convenience only
    double r;
    double sig;
    double K;
    double T;
    double U;
    double b;
    string optType; // Option name (call, put)
public:
// Constructors
EuropeanOption(); // Default call option

EuropeanOption(const string& optionType);     // Create option type

EuropeanOption(const EuropeanOption& option2); // Copy constructor

// Destructor
virtual ~EuropeanOption();

// Assignment operator
EuropeanOption& operator = (const EuropeanOption& option2);
// Functions that calculate option price and (some) sensitivities
double Price() const;
double Delta() const;
// Modifier functions
void toggle();           // Change option type (C/P, P/C)
};
