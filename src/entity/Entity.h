//
// Created by zakrent on 2/20/18.
//

#ifndef SDL_JUMP_ENTITY_H
#define SDL_JUMP_ENTITY_H


#include "../misc/Vector2.h"
#include "../world/CollisionSystem.h"
#include "EntityState.h"

const double BOUNCE_EFF = 0.8;


class Entity {
protected:
    int numberOfCollisions;
    Vector2 col;
    entityState currentState;
public:
    Vector2 pos;
    Vector2 vel;
    double radius{};

    virtual void updatePhysics();
    virtual void update();
    virtual void render();
    virtual void registerCollision(const CollisionData& data);
    virtual void handleCollisions();

    explicit Entity(const Vector2 &pos) : pos(pos), radius(0.5), numberOfCollisions(0), currentState(entityState::STATE_AIR){}
};

#endif //SDL_JUMP_ENTITY_H
