//------------------------------------------------------------------------------
// tree.cpp - contains functions for processing trees
//------------------------------------------------------------------------------

#include "tree.h"

//------------------------------------------------------------------------------
Random Tree::rndAge(1, 1000);

//------------------------------------------------------------------------------
// Input tree parameters from stream
void Tree::In(FILE* file) {
    int j = fscanf(file, "%d%s", &age, name);
}

//------------------------------------------------------------------------------
// Random input of tree parameters
void Tree::InRnd() {
    char* str = Plant::rnd3.RandomName();
    strcpy(name, str);
    age = rndAge.Get();
}

//------------------------------------------------------------------------------
// The quotient of dividing the number of vowels of the name by the number of all letters
double Tree::Quotient() {
    char all_gl[12] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y' };
    double gl = 0;
    for (size_t i = 0; i < strlen(name); i++) {
        for (size_t j = 0; j < 12; j++) {
            if (name[i] == all_gl[j]) {
                gl++;
                break;
            }
        }
    }
    return gl / strlen(name);
}

//------------------------------------------------------------------------------
// Output tree parameters
void Tree::Out(FILE* file) {
    fprintf(file, "It is Tree. Age: %d, Name: %s, Quotient of division: %e\n", age, name, Quotient());
}


