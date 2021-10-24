#ifndef __tree__
#define __tree__
//------------------------------------------------------------------------------
// tree.h - contains a description of the tree
//------------------------------------------------------------------------------

#include "stdio.h"
#include "plant.h"
#include "rnd.h"

class Tree : public Plant {
public:
    virtual ~Tree() {}
    // Input tree parameters from file
    virtual void In(FILE* file);
    // Random input of tree parameters
    virtual void InRnd();
    // Private
    virtual double Quotient();
    // Output tree parameters
    virtual void Out(FILE* file);
private:
    static Random rndAge;
    int age;
    char name[20];
};

#endif
