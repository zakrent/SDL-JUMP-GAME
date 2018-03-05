//
// Created by zakrent on 2/27/18.
//

#include "Player.h"
#include "../misc/InputManager.h"
#include "../Game.h"
#include "EntityState.h"

void Player::update() {
    updatePhysics();
    Game::get()->renderer->camera.x=pos.x;
    Game::get()->scoreManager->registerScore(static_cast<double>(pos.x));
    if(currentState == entityState::STATE_GROUND){
        InputManager* inputManager = Game::get()->inputManager;
        if(inputManager->isInputPressed("Right")){
            vel.x = 0.045;
        }
        if(inputManager->isInputPressed("Left")){
            vel.x = -0.045;
        }
        if(inputManager->isInputPressed("Jump")){
            vel.y = -0.10;
        }
        if(inputManager->isInputPressed("Stop")){
            vel.y = 0;
        }
    }
    if(pos.y > 20){
        restart();
    }
}

void Player::restart() {
    pos = startPos;
    vel = Vector2();
    currentState = entityState::STATE_AIR;
    Game::get()->scoreManager->restart();
}

void Player::registerCollision(const CollisionData &data) {
    if(data.type == CollisionType::WORLD && data.tileType == Tile::SPIKE){
        restart();
    }
    Entity::registerCollision(data);
}
