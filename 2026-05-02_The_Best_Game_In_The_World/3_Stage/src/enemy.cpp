#include <cmath>

#include "constants.hpp"
#include "enemy.hpp"

Enemy::Enemy(float xPos, float yPos)
    : xPos(xPos)
    , yPos(yPos)
    , speed(ENEMY_SPEED)
    , width(ENEMY_WIDTH)
    , height(ENEMY_HEIGHT)
{
}

Bounds Enemy::getBounds() const
{
    Bounds bounds;
    bounds.xPos = xPos;
    bounds.yPos = yPos;
    bounds.width = width;
    bounds.height = height;
    return bounds;
}

char Enemy::getType() const
{
    return TYPE_ENEMY;
}

void Enemy::reverseDirection()
{
    speed = -speed;
}

void Enemy::render(char buffer[MAP_HEIGHT][MAP_WIDTH + 1], float cameraX) const
{
    const int32_t drawX = static_cast<int32_t>(std::round(xPos - cameraX));
    const int32_t drawY = static_cast<int32_t>(std::round(yPos));
    const int32_t objW = static_cast<int32_t>(std::round(width));
    const int32_t objH = static_cast<int32_t>(std::round(height));

    for (int32_t col = drawX; col < (drawX + objW); col++)
    {
        for (int32_t row = drawY; row < (drawY + objH); row++)
        {
            const bool isValidX = (col >= 0 && col < MAP_WIDTH);
            const bool isValidY = (row >= 0 && row < MAP_HEIGHT);

            if (isValidX == true && isValidY == true && row > 1)
            {
                buffer[row][col] = getType();
            }
        }
    }
}

void Enemy::update(float dt)
{
    xPos += speed * dt;

    const bool hitLeftBorder = (xPos < 0.0f);
    const bool hitRightBorder = (xPos > static_cast<float>(MAP_WIDTH) * 2.0f);

    if (hitLeftBorder == true || hitRightBorder == true)
    {
        reverseDirection();
    }
}