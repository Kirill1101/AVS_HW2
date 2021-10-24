#ifndef __rnd__
#define __rnd__

#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <string.h>

//------------------------------------------------------------------------------
// rnd.h - contains a random name generator.
//------------------------------------------------------------------------------

class Random {
public:
    Random(int f, int l) {
        if (f <= l) {
            first = f;
            last = l;
        } else {
            first = l;
            last = f;
        }
        // system clock as initializer
        srand(static_cast<unsigned int>(time(0)));
    }
    char* RandomName() {
        int len = rand() % 10 + 3;
        char* name = new char[len] {'\0'};
        char a;
        for (int i = 0; i < len; i++)
        {
            a = rand() % ('z' - 'a' + 1) + 'a';
            name[i] = a;
        }
        name[len - 1] = '\0';
        return name;
    }
    int Get() {
        return rand() % (last - first + 1) + first;
    }
private:
    int first;
    int last;
};
#endif 