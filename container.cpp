//------------------------------------------------------------------------------
// container.cpp - contains container handling functions
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Container constructor
Container::Container() : len{ 0 } { }

//------------------------------------------------------------------------------
// Destructor of the container
Container::~Container() {
    Clear();
}

//------------------------------------------------------------------------------
// Clearing a container of elements (freeing memory)
void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }
    len = 0;
}

//------------------------------------------------------------------------------
// Entering the contents of the container from the specified file.
void Container::In(FILE* file) {
    while (!feof(file)) {
        if ((storage[len] = Plant::StaticIn(file)) != 0) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Random input of container contents
void Container::InRnd(int size) {
    while (len < size) {
        if ((storage[len] = Plant::StaticInRnd()) != nullptr) {
            len++;
        }
    }
}

//------------------------------------------------------------------------------
// Outputting the contents of the container to the specified stream
void Container::Out(FILE* file) {
    fprintf(file, "Container contains %d elements.\n", len);
    for (int i = 0; i < len; i++) {
        fprintf(file, "%d: ", i);
        storage[i]->Out(file);
    }
}

//------------------------------------------------------------------------------
// Moving container elements
void Container::Shift() {
    int counter = 0;
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += storage[i]->Quotient();
        counter++;
    }
    double average = sum / counter;

    int k = len;
    for (int i = 0; i < k; i++) {
        double num = storage[i]->Quotient();
        if (num > average) {
            Plant* pl = storage[i];
            for (int j = i; j < len - 1; j++) {
                storage[j] = storage[j + 1];
            }
            i--;
            k--;
            storage[len - 1] = pl;
        }
    }
}