#ifndef ARRAY_FUNCTIONS_HPP
#define ARRAY_FUNCTIONS_HPP

int* createNumbers(int n);
int* countNumbers(int* arr, int n);
int* makePrefix(int* arr, int size);
int getCount(int* prefix, int left, int right);
void freeMemory(int* arr1, int* arr2, int* arr3);

#endif