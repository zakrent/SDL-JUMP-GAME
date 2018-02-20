//
// Created by zakrent on 2/20/18.
//

#ifndef SDL_JUMP_ENTITY_H
#define SDL_JUMP_ENTITY_H


#include "../misc/Vector2.h"
#include "../world/CollisionSystem.h"

class Entity {
public:
    Vector2 pos;
    Vector2 vel;
    double radius;

    virtual void update() = 0;
    virtual void render();
    virtual void handleCollision(CollisionData data);

};

#endif //SDL_JUMP_ENTITY_H
