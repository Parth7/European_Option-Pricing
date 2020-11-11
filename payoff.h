//
// Created by Parth Parakh on 30/10/20.
//

#ifndef PAYOFF1_H
#define PAYOFF1_H
class Payoff
{
public :
    Payoff (){};
    virtual double operator()(double spot) =0;
    virtual ~Payoff(){}
private:
};

class PayoffCall : public Payoff
{
public:
    PayoffCall(double strike_);
    virtual double operator()(double spot) const;
    virtual ~PayoffCall(){}
    friend void func(PayoffCall& P);
private :
    double strike;
};

class PayoffPut : public Payoff
{
public:
    PayoffPut( double strike_);
    virtual double operator()(double spot) const;
    virtual ~PayoffPut(){}
private :
    double strike;
};

class Digit : public Payoff
{
public:
    Digit(double strike_);
    virtual double operator()(double spot) const;
    virtual ~Digit(){}
private :
    double strike;
};
#endif
