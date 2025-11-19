#include <iostream>

#include "array_functions.hpp"
#include "constants.hpp"
#include "input_output.hpp"

void processUserInput() {
    int n;
    std::cout << "Сколько чисел сгенерировать? ";
    std::cin >> n;
    
    if (n <= 0 || n > Constants::MAX_SIZE) {
        std::cout << "Ошибка! Размер должен быть от 1 до " << Constants::MAX_SIZE << std::endl;
        return;
    }
    
    int* numbers = ArrayFunctions::createNumbers(n);
    int* counts = ArrayFunctions::countNumbers(numbers, n);
    int* prefix = ArrayFunctions::makePrefix(counts, Constants::RANGE_SIZE);
    
    int q;
    std::cout << "Сколько запросов? ";
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cout << "Запрос " << i+1 << ". Введите диапазон от 100 до 200: ";
        std::cin >> l >> r;
        
        int result = ArrayFunctions::getCount(prefix, l-Constants::MIN_NUM, r-Constants::MIN_NUM);
        std::cout << "В диапазоне [" << l << "," << r << "] найдено: " << result << " чисел" << std::endl;
    }
    
    ArrayFunctions::freeMemory(numbers, counts, prefix);
}