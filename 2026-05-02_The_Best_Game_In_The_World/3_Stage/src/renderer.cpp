#include <cstdio>
#include <windows.h>

#include "renderer.hpp"

void Renderer::clearScreen() const
{
    std::system("cls");
}

void Renderer::delay(float ms) const
{
    Sleep(static_cast<DWORD>(ms));
}

void Renderer::draw(const char buffer[MAP_HEIGHT][MAP_WIDTH + 1]) const
{
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    for (int32_t row = 0; row < MAP_HEIGHT; row++)
    {
        std::printf("%s\n", buffer[row]);
    }
}

void Renderer::init() const
{
    std::system("title Mario OOP Refactored");
}