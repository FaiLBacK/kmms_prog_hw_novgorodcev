#pragma once
#include "config.hpp"
#include <cmath>

namespace Game {

class Entity {
protected:
    float x, y, width, height, vx, vy;
    bool active;

    Entity(const Entity&) = delete;
    Entity& operator=(const Entity&) = delete;

    void applyPhysics(float dt) {
        vy += Config::GRAVITY * dt;
        vx *= Config::FRICTION;
        x += vx * dt;
        y += vy * dt;
        if (y + height >= Config::GROUND_Y) {
            y = Config::GROUND_Y - height;
            vy = 0;
        }
    }

public:
    Entity(float px, float py, float pw, float ph)
        : x(px), y(py), width(pw), height(ph), vx(0), vy(0), active(true) {}

    virtual ~Entity() = default;

    virtual void update(float dt) = 0;
    virtual void onCollision(Entity& other) = 0;

    float getX() const      { return x; }
    float getY() const      { return y; }
    float getWidth() const  { return width; }
    float getHeight() const { return height; }
    bool  isActive() const  { return active; }
    void  setVelocity(float nvx, float nvy) { vx = nvx; vy = nvy; }
    void  setActive(bool state)             { active = state; }
};

class Mario : public Entity {
private:
    int lives;
    bool isJumping;
public:
    Mario(float x, float y, float w, float h)
        : Entity(x, y, w, h), lives(3), isJumping(false) {}

    void update(float dt) override;
    void onCollision(Entity& other) override;
    void jump();
    int  getLives() const { return lives; }
    bool isJumpingState() const { return isJumping; }
};

class Brick : public Entity {
private:
    int health;
    bool breakable;
public:
    Brick(float x, float y, float w, float h, bool isBreakable = true)
        : Entity(x, y, w, h),
          health(isBreakable ? Config::BRICK_INITIAL_HP : Config::INDESTRUCTIBLE_HP),
          breakable(isBreakable) {}

    void update(float dt) override;
    void onCollision(Entity& other) override;
    void crack();
    int  getHealth() const { return health; }
    bool isBreakable() const { return breakable; }
};

class Coin : public Entity {
private:
    float bobPhase;
public:
    Coin(float x, float y, float w, float h)
        : Entity(x, y, w, h), bobPhase(0.0f) {}

    void update(float dt) override;
    void onCollision(Entity& other) override;
    float getBobOffset() const;
};

}