#ifndef ARRAY_FUNCTIONS_HPP
#define ARRAY_FUNCTIONS_HPP

namespace ArrayFunctions {
    int* countNumbers(int* arr, int n);
    int* createNumbers(int n);
    void freeMemory(int* arr1, int* arr2, int* arr3);
    int getCount(int* prefix, int left, int right);
    int* makePrefix(int* arr, int size);
}

#endif