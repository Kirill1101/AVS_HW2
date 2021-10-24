//------------------------------------------------------------------------------
// shrub.cpp - contains functions for processing shrubs
//------------------------------------------------------------------------------

#include "shrub.h"

//------------------------------------------------------------------------------
Random Shrub::rndMonth(1, 12);

Shrub::Months GetMonth(int n) {
    switch (n) {
    case 1:
        return Shrub::JANUARY;
    case 2:
        return Shrub::FEBRUARY;
    case 3:
        return Shrub::MARCH;
    case 4:
        return Shrub::APRIL;
    case 5:
        return Shrub::MAY;
    case 6:
        return Shrub::JUNE;
    case 7:
        return Shrub::JULY;
    case 8:
        return Shrub::AUGUST;
    case 9:
        return Shrub::SEPTEMBER;
    case 10:
        return Shrub::OCTOBER;
    case 11:
        return Shrub::NOVEMBER;
    case 12:
        return Shrub::DECEMBER;
    }
}

const char* GetMonthStr(int n) {
    switch (n + 1) {
    case 1:
        return "JANUARY";
    case 2:
        return "FEBRUARY";
    case 3:
        return "MARCH";
    case 4:
        return "APRIL";
    case 5:
        return "MAY";
    case 6:
        return "JUNE";
    case 7:
        return "JULY";
    case 8:
        return "AUGUST";
    case 9:
        return "SEPTEMBER";
    case 10:
        return "OCTOBER";
    case 11:
        return "NOVEMBER";
    case 12:
        return "DECEMBER";
    }
}

//------------------------------------------------------------------------------
// Entering bush parameters from a stream
void Shrub::In(FILE* file) {
    int k = 0;
    int j = fscanf(file, "%d%s", &k, name);
    month = GetMonth(k);
}

//------------------------------------------------------------------------------
// Random input of bush parameters
void Shrub::InRnd() {
    char* str = Plant::rnd3.RandomName();
    strcpy(name, str);
    int n = rndMonth.Get();
    month = GetMonth(n);
}

//------------------------------------------------------------------------------
// The quotient of dividing the number of vowels of the name by the number of all letters
double Shrub::Quotient() {
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
// Bush parameters output
void Shrub::Out(FILE* file) {
    const char* str = GetMonthStr(month);
    char month[15];
    strcpy(month, str);
    fprintf(file, "It is Shrub. Month: %s, Name: %s, Quotient of division: %e\n", month, name, Quotient());
}

