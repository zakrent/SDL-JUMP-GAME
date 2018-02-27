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
            vel.y = -0.08;
        }
        if(inputManager->isInputPressed("Stop")){
            vel.x *= 0.5;
        }
    }
    if(pos.y > 20){
        restart();
    }
}

void Player::restart() {
    pos = startPos;
    vel = Vector2();
    Game::get()->scoreManager->restart();
}
