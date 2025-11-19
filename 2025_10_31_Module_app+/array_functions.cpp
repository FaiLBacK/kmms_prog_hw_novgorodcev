#include <cstdlib>
#include <ctime>

#include "constants.hpp"
#include "array_functions.hpp"

int* NumberProcessor::countNumbers(const int* arr, int n) {
    int* count = new int[NumberProcessor::RANGE_SIZE]();
    
    for (int i = 0; i < n; i++) {
        const int index = arr[i] - NumberProcessor::MIN_NUM;
        if (index >= 0 && index < NumberProcessor::RANGE_SIZE) {
            count[index]++;
        }
    }
    return count;
}

int* NumberProcessor::createNumbers(int n) {
    int* arr = new int[n];
    srand(time(0));
    
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 100;
    }
    return arr;
}

void NumberProcessor::freeMemory(int* arr1, int* arr2, int* arr3) {
    delete[] arr1;
    delete[] arr2;
    delete[] arr3;
}

int NumberProcessor::getCount(const int* prefix, int left, int right) {
    int adjustedLeft = left;
    int adjustedRight = right;
    
    if (adjustedLeft < 0) adjustedLeft = 0;
    if (adjustedRight > NumberProcessor::RANGE_SIZE-1) adjustedRight = NumberProcessor::RANGE_SIZE-1;
    if (adjustedLeft > adjustedRight) return 0;
    
    if (adjustedLeft == 0) {
        return prefix[adjustedRight];
    } else {
        return prefix[adjustedRight] - prefix[adjustedLeft-1];
    }
}

int* NumberProcessor::makePrefix(const int* arr, int size) {
    int* prefix = new int[size];
    prefix[0] = arr[0];
    
    for (int i = 1; i < size; i++) {
        prefix[i] = prefix[i-1] + arr[i];
    }
    return prefix;
}
