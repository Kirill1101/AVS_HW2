//------------------------------------------------------------------------------
// shape.cpp - contains procedures related to processing a generic shape
// and create a custom shape
//------------------------------------------------------------------------------

#include "tree.h"
#include "shrub.h"
#include "flower.h"

//------------------------------------------------------------------------------
Random Plant::rnd3(1, 3);

//------------------------------------------------------------------------------
// Entering the parameters of a generalized plant from a file
Plant* Plant::StaticIn(FILE* file) {
    int k = 0;
    int j = fscanf(file, "%d", &k);
    Plant* pl = nullptr;
    switch (k) {
    case 1:
        pl = new Tree;
        break;
    case 2:
        pl = new Shrub;
        break;
    case 3:
        pl = new Flower;
        break;
    }
    pl->In(file);
    return pl;
}



// Random input of a generic plant
Plant* Plant::StaticInRnd() {
    auto k = Plant::rnd3.Get();
    Plant* pl = nullptr;
    switch (k) {
    case 1:
        pl = new Tree;
        break;
    case 2:
        pl = new Shrub;
        break;
    case 3:
        pl = new Flower;
        break;
    }
    pl->InRnd();
    return pl;
}



