#include <cstdlib>
#include <ctime>

#include "constants.hpp"
#include "array_functions.hpp"

int* ArrayFunctions::countNumbers(int* arr, int n) {
    int* count = new int[Constants::RANGE_SIZE]();
    
    for (int i = 0; i < n; i++) {
        int index = arr[i] - Constants::MIN_NUM;
        if (index >= 0 && index < Constants::RANGE_SIZE) {
            count[index]++;
        }
    }
    return count;
}

int* ArrayFunctions::createNumbers(int n) {
    int* arr = new int[n];
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 100;
    }
    return arr;
}

void ArrayFunctions::freeMemory(int* arr1, int* arr2, int* arr3) {
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

int ArrayFunctions::getCount(int* prefix, int left, int right) {
    if (left < 0) left = 0;
    if (right > Constants::RANGE_SIZE-1) right = Constants::RANGE_SIZE-1;
    if (left > right) return 0;
    
    if (left == 0) {
        return prefix[right];
    } else {
        return prefix[right] - prefix[left-1];
    }
}

int* ArrayFunctions::makePrefix(int* arr, int size) {
    int* prefix = new int[size];
    prefix[0] = arr[0];
    
    for (int i = 1; i < size; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}