#pragma once

#include "level.hpp"
#include "renderer.hpp"

class Game
{
public:
    Game();
    ~Game();
    void run();

private:
    Level level;
    Renderer renderer;
    bool isRunning;
};