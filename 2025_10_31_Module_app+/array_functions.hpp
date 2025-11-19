#ifndef ARRAY_FUNCTIONS_HPP
#define ARRAY_FUNCTIONS_HPP

namespace NumberProcessor {
    int* countNumbers(const int* arr, int n);
    int* createNumbers(int n);
    void freeMemory(int* arr1, int* arr2, int* arr3);
    int getCount(const int* prefix, int left, int right);
    int* makePrefix(const int* arr, int size);
}

#endif