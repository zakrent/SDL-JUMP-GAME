//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_WORLD_H
#define SDL_JUMP_WORLD_H

#include <list>
#include <SDL_rect.h>
#include "../misc/Vector2.h"

typedef enum tile{
    AIR,
    WALL,
} Tile;

class World {
public:
    std::list<Tile[8]> tiles;
    Vector2 mapRoot;
};

#endif //SDL_JUMP_WORLD_H
