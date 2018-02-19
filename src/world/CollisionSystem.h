//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_COLLISIONSYSTEM_H
#define SDL_JUMP_COLLISIONSYSTEM_H


#include "../misc/Vector2.h"

class CollisionSystem {
    bool checkForAABBCircleCollision(Vector2 AABBRoot, int AABBW, int AABBH, Vector2 CircleRootPos, double radius);
};


#endif //SDL_JUMP_COLLISIONSYSTEM_H
