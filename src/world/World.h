//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_WORLD_H
#define SDL_JUMP_WORLD_H

#include <list>
#include <SDL_rect.h>
#include <vector>
#include <memory>
#include "../misc/Vector2.h"
#include "../entity/Entity.h"
#include "Tile.h"

class World {
public:
    std::list<std::unique_ptr<Entity>> entities;
    std::list<std::vector<Tile>> tiles;
    Vector2 mapRoot;

    void update();
    void handleCollisions();

    void render();
    void generateMap();

    World();
};

#endif //SDL_JUMP_WORLD_H
