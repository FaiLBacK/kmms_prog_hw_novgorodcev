#include <iostream>
#include <locale>

#include "constants.hpp"
#include "game.hpp"

int main()
{
    std::setlocale(LC_ALL, "Russian");

    std::cout << "Запуск игры..." << std::endl;
    Game game;
    game.run();

    std::cout << "Игра завершена. Спасибо за игру!" << std::endl;
    return 0;
}