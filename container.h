#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - contains the data type,
// representing the simplest container
//------------------------------------------------------------------------------

#include "plant.h"

class Container {
public:
    Container();
    ~Container();
    // Inject the contents of the container from the specified stream
    void In(FILE* file);
    // Randomly enter the contents of the container
    void InRnd(int size);
    // Output the contents of the container to the specified stream
    void Out(FILE* file);
    // Move container elements
    void Shift();
private:
    void Clear();
    int len;
    Plant* storage[10000];
};

#endif