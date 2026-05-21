#include <conio.h>
#include <cstring>

#include "constants.hpp"
#include "game.hpp"

Game::Game()
    : isRunning(true)
{
}

Game::~Game()
{
}

void Game::run()
{
    renderer.init();
    level.loadLevel(1);

    while (isRunning == true)
    {
        const int keyState = _kbhit();
        if (keyState != 0)
        {
            const int key = _getch();
            if (key == 27)
            {
                isRunning = false;
            }
        }

        level.updateObjects(1.0f);

        char screenBuffer[MAP_HEIGHT][MAP_WIDTH + 1];
        std::memset(screenBuffer, ' ', sizeof(screenBuffer));
        for (int32_t row = 0; row < MAP_HEIGHT; row++)
        {
            screenBuffer[row][MAP_WIDTH] = '\0';
        }

        level.renderMap(screenBuffer, level.getCameraX());
        renderer.draw(screenBuffer);
        renderer.delay(FRAME_DELAY_MS);
    }
}