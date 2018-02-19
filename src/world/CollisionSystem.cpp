//
// Created by zakrent on 2/19/18.
//

#include "CollisionSystem.h"

bool CollisionSystem::checkForAABBCircleCollision(Vector2 AABBRoot, int AABBW, int AABBH, Vector2 CircleRoot,
                                                  double radius) {
    Vector2 directionVector = AABBRoot - CircleRoot;
    directionVector.normalize();
    directionVector *= radius;
    return directionVector.x > AABBRoot.x && directionVector.x < AABBRoot.x+AABBW && directionVector.y < AABBRoot.y && directionVector.y > AABBRoot.y-AABBH;
}
