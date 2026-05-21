#include <cmath>
#include <cstdlib>
#include <cstring>

#include "constants.hpp"
#include "enemy.hpp"
#include "level.hpp"
#include "player.hpp"

Level::Level()
    : gameObjects(nullptr)
    , objectCount(0)
    , objectCapacity(INITIAL_CAPACITY)
    , cameraX(0.0f)
    , score(0)
    , currentLevelIndex(1)
{
    gameObjects = static_cast<GameObject**>(std::calloc(INITIAL_CAPACITY, sizeof(GameObject*)));
}

Level::~Level()
{
    for (int32_t i = 0; i < objectCount; i++)
    {
        delete gameObjects[i];
    }
    std::free(gameObjects);
}

void Level::addGameObject(GameObject* object)
{
    if (objectCount >= objectCapacity)
    {
        const int32_t newCapacity = objectCapacity * 2;
        GameObject** tempArray = static_cast<GameObject**>(std::realloc(gameObjects, newCapacity * sizeof(GameObject*)));
        if (tempArray != nullptr)
        {
            gameObjects = tempArray;
            objectCapacity = newCapacity;
        }
    }
    gameObjects[objectCount] = object;
    objectCount++;
}

void Level::addScore(int32_t points)
{
    score += points;
}

float Level::getCameraX() const
{
    return cameraX;
}

GameObject* Level::getGameObject(int32_t index) const
{
    return gameObjects[index];
}

int32_t Level::getGameObjectCount() const
{
    return objectCount;
}

int32_t Level::getScore() const
{
    return score;
}

void Level::loadLevel(int32_t levelIndex)
{
    std::system(COLOR_DEFAULT);
    currentLevelIndex = levelIndex;
    score = 0;
    cameraX = 0.0f;

    for (int32_t i = 0; i < objectCount; i++)
    {
        delete gameObjects[i];
    }
    objectCount = 0;

    addGameObject(new Player(MARIO_START_X, MARIO_START_Y));
    addGameObject(new Enemy(25.0f, 10.0f));
    addGameObject(new Enemy(50.0f, 10.0f));
}

void Level::removeGameObject(int32_t index)
{
    if (index >= 0 && index < objectCount)
    {
        delete gameObjects[index];
        gameObjects[index] = gameObjects[objectCount - 1];
        objectCount--;
    }
}

void Level::renderMap(char buffer[MAP_HEIGHT][MAP_WIDTH + 1], float cameraX) const
{
    char scoreText[30];
    std::sprintf(scoreText, "Очки: %d", score);
    const int32_t textLength = static_cast<int32_t>(std::strlen(scoreText));

    for (int32_t i = 0; i < textLength; i++)
    {
        const int32_t targetCol = SCORE_X_OFFSET + i;
        if (targetCol < SCORE_AREA_WIDTH)
        {
            buffer[1][targetCol] = scoreText[i];
        }
    }

    for (int32_t i = 0; i < objectCount; i++)
    {
        gameObjects[i]->render(buffer, cameraX);
    }
}

void Level::resetLevel(int32_t levelIndex)
{
    loadLevel(levelIndex);
}

void Level::updateObjects(float dt)
{
    for (int32_t i = 0; i < objectCount; i++)
    {
        gameObjects[i]->update(dt);
    }
}