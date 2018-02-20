//
// Created by zakrent on 2/20/18.
//

#include "Entity.h"
#include "../Game.h"

void Entity::render() {
    Game::get()->renderer->renderCirlce(pos, radius);
}

void Entity::handleCollision(CollisionData data) {}
