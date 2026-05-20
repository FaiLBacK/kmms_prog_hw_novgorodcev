#pragma once

#include "game_object.hpp"

class Enemy : public GameObject
{
public:
    Enemy(float xPos, float yPos);
    void update(float dt) override;
    void render(char buffer[MAP_HEIGHT][MAP_WIDTH + 1], float cameraX) const override;
    Bounds getBounds() const override;
    char getType() const override;
    void reverseDirection();

private:
    float xPos;
    float yPos;
    float speed;
    const float width;
    const float height;
};