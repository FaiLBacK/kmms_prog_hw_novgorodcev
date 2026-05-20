#pragma once

class Renderer
{
public:
    void init() const;
    void draw(const char buffer[MAP_HEIGHT][MAP_WIDTH + 1]) const;
    void delay(float ms) const;
    void clearScreen() const;
};