//
// Created by zakrent on 2/20/18.
//

#include <cmath>
#include "Entity.h"
#include "../Game.h"

void Entity::render() {
    Game::get()->renderer->renderCirlce(pos, radius);
}

void Entity::registerCollision(const CollisionData& data) {
    numberOfCollisions++;
    col += data.collisionVector;
}

void Entity::updatePhysics() {
    vel += Vector2(0, 0.0015);
    if(currentState == entityState::STATE_GROUND){
        vel *= 0.9;
    }
    pos+=vel;
}

void Entity::update() {
    updatePhysics();
}

void Entity::handleCollisions() {
    if(!(col == Vector2())) {
        if(currentState == entityState::STATE_AIR){
            currentState = entityState::STATE_GROUND;
        }
        col *= 1.0/numberOfCollisions;
        double colAngle = asin(static_cast<double>(col.y / col.length())) * 180 / M_PI;
        if(colAngle < 0){
            colAngle += 360;
        }
        Vector2 intersectionVec = Vector2();
        if ((colAngle >= 35 && colAngle <= 145) || (colAngle > 215 && colAngle < 325)) {
            vel.y *= -1*BOUNCE_EFF;
            intersectionVec.y = -0.5-col.y-radius;
        } else {
            vel.x *= -1*BOUNCE_EFF;
            intersectionVec.x = -0.5-col.x-radius;
        }
        if(vel.length() < 0.012){
            vel = Vector2();
        }
        pos += intersectionVec;
    }
    else if(currentState == entityState::STATE_GROUND){
        currentState = entityState::STATE_AIR;
    }
    numberOfCollisions = 0;
    col = Vector2();
}
