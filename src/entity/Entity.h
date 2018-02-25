//
// Created by zakrent on 2/20/18.
//

#ifndef SDL_JUMP_ENTITY_H
#define SDL_JUMP_ENTITY_H


#include "../misc/Vector2.h"
#include "../world/CollisionSystem.h"

const double BOUNCE_EFF = 0.8;

class Entity {
    int numberOfCollisions;
    Vector2 col;
public:
    Vector2 pos;
    Vector2 vel;
    double radius{};

    virtual void update();
    virtual void render();
    virtual void registerCollision(const CollisionData& data);
    virtual void handleCollisions();

    Entity() = default;
    explicit Entity(const Vector2 &pos) : pos(pos), radius(0.5) {vel.x = 0.005;}
};

#endif //SDL_JUMP_ENTITY_H
