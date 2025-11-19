#include <iostream>

#include "array_functions.hpp"
#include "constants.hpp"
#include "input_output.hpp"

void processUserInput() {
    int inputN;
    std::cout << "Сколько чисел сгенерировать? ";
    std::cin >> inputN;
    
    const int n = inputN;
    
    if (n <= 0 || n > NumberProcessor::MAX_SIZE) {
        std::cout << "Ошибка! Размер должен быть от 1 до " << NumberProcessor::MAX_SIZE << std::endl;
        return;
    }
    
    int* numbers = NumberProcessor::createNumbers(n);
    int* counts = NumberProcessor::countNumbers(numbers, n);
    int* prefix = NumberProcessor::makePrefix(counts, NumberProcessor::RANGE_SIZE);
    
    int inputQ;
    std::cout << "Сколько запросов? ";
    std::cin >> inputQ;
    
    const int q = inputQ;
    
    for (int i = 0; i < q; i++) {
        int inputL, inputR;
        std::cout << "Запрос " << i+1 << ". Введите диапазон от 100 до 200: ";
        std::cin >> inputL >> inputR;
        
        const int l = inputL;
        const int r = inputR;
        const int result = NumberProcessor::getCount(prefix, l-NumberProcessor::MIN_NUM, r-NumberProcessor::MIN_NUM);
        
        std::cout << "В диапазоне [" << l << "," << r << "] найдено: " << result << " чисел" << std::endl;
    }
    
    NumberProcessor::freeMemory(numbers, counts, prefix);
}