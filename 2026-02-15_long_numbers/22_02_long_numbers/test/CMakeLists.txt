# Добавляем локальный GoogleTest
add_subdirectory(googletest)

# Создаем исполняемый файл тестов
add_executable(long_number_tests long_number_tests.cpp)

# Линкуем с библиотекой и GoogleTest
target_link_libraries(long_number_tests 
    long_number 
    gtest
    gtest_main
)

# Включаем обнаружение тестов
include(GoogleTest)
gtest_discover_tests(long_number_tests)