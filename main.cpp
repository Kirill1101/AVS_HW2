//------------------------------------------------------------------------------
// main.cpp - contains the main function,
// providing easy testing
//------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <ctime> 
#include <cstring>
#include <time.h>

#include "container.h"

void errMessage1() {
    printf("incorrect command line!\n"
        "  Waited:\n"
        "     command -f infile outfile01 outfile02\n"
        "  Or:\n"
        "     command -n number outfile01 outfile02\n");
}


//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    clock_t begin = clock();
    if (argc != 5) {
        errMessage1();
        return 1;
    }

    printf("Start\n");
    Container c;
    FILE* file;

    // Enter all plants.
    if (!strcmp(argv[1], "-f")) {
        file = fopen(argv[2], "rt");
        c.In(file);
        fclose(file);
    } else if (!strcmp(argv[1], "-n")) {
        auto size = atoi(argv[2]);
        if ((size < 1) || (size > 10000)) {
            printf("Incorrect number\n");
            return 3;
        }
        srand(static_cast<unsigned int>(time(0)));
        c.InRnd(size);
    }

    // Output the contents of the container to a file
    file = fopen(argv[3], "wt");
    c.Out(file);
    fclose(file);

    // Output of the container processed by the function
    file = fopen(argv[4], "wt");
    c.Shift();
    c.Out(file);
    printf("Stop\n");
    clock_t end = clock();
    double time_spent = (double)(end - begin) * 1000.0 / CLOCKS_PER_SEC;;
    printf("Program execution time in milliseconds: %f\n", time_spent);
    return 0;
}
