#pragma once

#include "constants.hpp"
#include "game_object.hpp"

class Level;

class Player : public GameObject
{
public:
    explicit Player(float xPos, float yPos);
    void update(float dt) override;
    void render(char buffer[MAP_HEIGHT][MAP_WIDTH + 1], float cameraX) const override;
    Bounds getBounds() const override;
    char getType() const override;
    void jump();
    bool isOnGround() const;
    void moveHorizontal(float direction, const Level& level);

private:
    float xPos;
    float yPos;
    float verticalSpeed;
    bool isFlying;
    const float width;
    const float height;
};