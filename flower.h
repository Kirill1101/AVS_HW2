#ifndef __flower__
#define __flower__

//------------------------------------------------------------------------------
// flower.h - contains a description of the flower
//------------------------------------------------------------------------------

#include "stdio.h"
#include "plant.h"
#include "rnd.h"

class Flower : public Plant {
public:
    enum Type
    {
        HOME,
        GARDEN,
        WILD
    };
    virtual ~Flower() {}
    // Enter flower parameters from file
    virtual void In(FILE* ifst);
    // Random input of flower parameters
    virtual void InRnd();
    // Quotient
    virtual double Quotient();
    // Output of flower parameters
    virtual void Out(FILE* ofst);
private:
    Type type;
    char name[20];
};

#endif

