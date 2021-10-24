//------------------------------------------------------------------------------
// flower.cpp - contains functions for processing flowers
//------------------------------------------------------------------------------

#include "flower.h"

// Type selection
Flower::Type GetType(int n) {
    switch (n) {
    case 1:
        return Flower::HOME;
    case 2:
        return Flower::GARDEN;
    case 3:
        return Flower::WILD;
    }
}

const char* GetTypeStr(int n) {
    switch (n + 1) {
    case 1:
        return "HOME";
    case 2:
        return "GARDEN";
    case 3:
        return "WILD";
    }
}

//------------------------------------------------------------------------------
// Input the parameters of the flower from the stream
void Flower::In(FILE* file) {
    int k = 0;
    int j = fscanf(file, "%d%s", &k, name);
    type = GetType(k);
}

//------------------------------------------------------------------------------
// Random input of flower parameters
void Flower::InRnd() {
    char* str = Plant::rnd3.RandomName();
    strcpy(name, str);
    int n = Plant::rnd3.Get();
    type = GetType(n);
}

//------------------------------------------------------------------------------
// The quotient of dividing the number of vowels of the name by the number of all letters
double Flower::Quotient() {
    char all_gl[12] = { 'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y' };
    double gl = 0;
    for (size_t  i = 0; i < strlen(name); i++) {
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
// Display the parameters of the flower
void Flower::Out(FILE* file) {
    const char* str = GetTypeStr(type);
    char type[10];
    strcpy(type, str);
    fprintf(file, "It is Flower. Type: %s, Name: %s, Quotient of division: %e\n", type, name, Quotient());
}