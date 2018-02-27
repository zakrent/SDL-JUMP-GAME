//
// Created by zakrent on 2/27/18.
//

#ifndef SDL_JUMP_PLAYER_H
#define SDL_JUMP_PLAYER_H

#include "Entity.h"

class Player : public Entity {
public:
    void update() override;

    Player() = default;
    explicit Player(const Vector2 &pos) : Entity(pos) {}
};


#endif //SDL_JUMP_PLAYER_H
