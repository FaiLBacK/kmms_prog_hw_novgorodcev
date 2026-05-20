#include <cmath>

#include "level.hpp"
#include "player.hpp"

Player::Player(float xPos, float yPos)
    : xPos(xPos)
    , yPos(yPos)
    , verticalSpeed(0.0f)
    , isFlying(true)
    , width(MARIO_WIDTH)
    , height(MARIO_HEIGHT)
{
}

Bounds Player::getBounds() const
{
    Bounds bounds;
    bounds.xPos = xPos;
    bounds.yPos = yPos;
    bounds.width = width;
    bounds.height = height;
    return bounds;
}

char Player::getType() const
{
    return TYPE_MARIO;
}

bool Player::isOnGround() const
{
    return isFlying == false;
}

void Player::jump()
{
    if (isOnGround() == true)
    {
        verticalSpeed = JUMP_POWER;
        isFlying = true;
    }
}

void Player::moveHorizontal(float direction, const Level& level)
{
    const float oldX = xPos;
    xPos += direction;

    const int32_t objectCount = level.getGameObjectCount();
    for (int32_t i = 0; i < objectCount; i++)
    {
        GameObject* other = level.getGameObject(i);
        if (other != nullptr && other != this && other->getType() != TYPE_MARIO)
        {
            const Bounds playerBounds = getBounds();
            const Bounds otherBounds = other->getBounds();

            const bool overlapX = (playerBounds.xPos + playerBounds.width > otherBounds.xPos) &&
                                  (playerBounds.xPos < otherBounds.xPos + otherBounds.width);
            const bool overlapY = (playerBounds.yPos + playerBounds.height > otherBounds.yPos) &&
                                  (playerBounds.yPos < otherBounds.yPos + otherBounds.height);

            if (overlapX == true && overlapY == true)
            {
                xPos = oldX;
                break;
            }
        }
    }
}

void Player::render(char buffer[MAP_HEIGHT][MAP_WIDTH + 1], float cameraX) const
{
    const int32_t drawX = static_cast<int32_t>(std::round(xPos - cameraX));
    const int32_t drawY = static_cast<int32_t>(std::round(yPos));

    const bool isValidX = (drawX >= 0 && drawX < MAP_WIDTH);
    const bool isValidY = (drawY >= 0 && drawY < MAP_HEIGHT);

    if (isValidX == true && isValidY == true && drawY > 1)
    {
        buffer[drawY][drawX] = getType();
    }
}

void Player::update(float dt)
{
    verticalSpeed += GRAVITY * dt;
    yPos += verticalSpeed * dt;

    if (yPos > static_cast<float>(MAP_HEIGHT))
    {
        yPos = MARIO_START_Y;
        verticalSpeed = 0.0f;
    }

    if (yPos >= 20.0f)
    {
        yPos = 20.0f;
        verticalSpeed = 0.0f;
        isFlying = false;
    }
}