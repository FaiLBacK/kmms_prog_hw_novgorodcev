#pragma once

#include "bounds.hpp"
#include "constants.hpp"

class GameObject
{
public:
    virtual ~GameObject() = default;
    virtual void update(float dt) = 0;
    virtual void render(char buffer[MAP_HEIGHT][MAP_WIDTH + 1], float cameraX) const = 0;
    virtual Bounds getBounds() const = 0;
    virtual char getType() const = 0;
};