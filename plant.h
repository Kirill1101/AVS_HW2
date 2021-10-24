#ifndef __plant__
#define __plant__

//------------------------------------------------------------------------------
// plant.h - contains a description of the generalizing plant
//------------------------------------------------------------------------------

#include "rnd.h"

class Plant {
protected:
    static Random rnd3;
public:
    virtual ~Plant() {};
    // Enter a generic figure
    static Plant* StaticIn(FILE* file);
    // Enter a generic figure
    virtual void In(FILE* file) = 0;
    // Случайный ввод обобщенной фигуры
    static Plant* StaticInRnd();
    // Random input of a generic figure
    virtual void InRnd() = 0;
    // Quotient
    virtual double Quotient() = 0;
    // Display the generalized figure
    virtual void Out(FILE* file) = 0;
};
#endif
