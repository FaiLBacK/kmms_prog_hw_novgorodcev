#pragma once

#include "game_object.hpp"

class Level
{
public:
    Level();
    ~Level();
    void loadLevel(int32_t levelIndex);
    void updateObjects(float dt);
    void renderMap(char buffer[MAP_HEIGHT][MAP_WIDTH + 1], float cameraX) const;
    void addGameObject(GameObject* object);
    void removeGameObject(int32_t index);
    GameObject* getGameObject(int32_t index) const;
    int32_t getGameObjectCount() const;
    float getCameraX() const;
    int32_t getScore() const;
    void addScore(int32_t points);
    void resetLevel(int32_t levelIndex);

private:
    GameObject** gameObjects;
    int32_t objectCount;
    int32_t objectCapacity;
    float cameraX;
    int32_t score;
    int32_t currentLevelIndex;
};