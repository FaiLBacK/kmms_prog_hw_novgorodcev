#include "input_output.hpp"
#include "array_functions.hpp"
#include "constants.hpp"
#include <iostream>

void processUserInput() {
    int n;
    std::cout << "Сколько чисел сгенерировать? ";
    std::cin >> n;
    
    if (n <= 0 || n > MAX_SIZE) {
        std::cout << "Ошибка! Размер должен быть от 1 до " << MAX_SIZE << std::endl;
        return;
    }
    
    int* numbers = createNumbers(n);
    int* counts = countNumbers(numbers, n);
    int* prefix = makePrefix(counts, RANGE_SIZE);
    
    int q;
    std::cout << "Сколько запросов? ";
    std::cin >> q;
    
    for (int i = 0; i < q; i++) {
        int l, r;
        std::cout << "Запрос " << i+1 << ". Введите диапазон от 100 до 200: ";
        std::cin >> l >> r;
        
        int result = getCount(prefix, l-MIN_NUM, r-MIN_NUM);
        std::cout << "В диапазоне [" << l << "," << r << "] найдено: " << result << " чисел" << std::endl;
    }
    
    freeMemory(numbers, counts, prefix);
}