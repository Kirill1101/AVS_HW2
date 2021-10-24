#ifndef __shrub__
#define __shrub__
//------------------------------------------------------------------------------
// strub.h - contains a description of the bush
//------------------------------------------------------------------------------

#include "stdio.h"
#include "plant.h"
#include "rnd.h"

class Shrub : public Plant {
public:
    virtual ~Shrub() {}
    // Enter bush parameters from file
    virtual void In(FILE* file);
    // Random input of bush parameters
    virtual void InRnd();
    // Quotient
    virtual double Quotient();
    // Display the parameters of the bush
    virtual void Out(FILE* file);
    enum Months
    {
        JANUARY,
        FEBRUARY,
        MARCH,
        APRIL,
        MAY,
        JUNE,
        JULY,
        AUGUST,
        SEPTEMBER,
        OCTOBER,
        NOVEMBER,
        DECEMBER
    };
private:
    static Random rndMonth;
    Months month;
    char name[20];
};

#endif
