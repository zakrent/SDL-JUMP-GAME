//
// Created by zakrent on 2/19/18.
//

#include <entities.h>
#include <iostream>
#include "CollisionSystem.h"
#include "../Game.h"

bool CollisionSystem::checkForAABBCircleCollision(Vector2 AABBRoot, int AABBW, int AABBH, Vector2 CircleRoot,
                                                  double radius) {
    Vector2 AABBCenter = AABBRoot + Vector2(AABBW/2.0, AABBH/2.0);
    Vector2 directionVector = AABBCenter - CircleRoot;
    directionVector.normalize();
    directionVector *= radius;
    directionVector += CircleRoot;
    bool collision = directionVector.x >= AABBRoot.x && directionVector.x <= AABBRoot.x+AABBW && directionVector.y <= AABBRoot.y+AABBH && directionVector.y >= AABBRoot.y;
    return collision;
}

void CollisionSystem::checkForCollisions() {
    std::list<std::unique_ptr<Entity>>* entities = &Game::get()->world->entities;
    std::list<std::vector<Tile>>* tiles = &Game::get()->world->tiles;

    Vector2 mapRoot = Game::get()->world->mapRoot;

    int j = 0;
    for (auto &tile : *tiles) {
        int i = 0;
        for (auto &curTile : tile) {
            if(curTile==Tile::WALL){
                Vector2 AABBRoot = mapRoot + Vector2(j,i);
                for(auto& entity : *entities){
                    if(checkForAABBCircleCollision(AABBRoot, 1, 1, entity->pos, entity->radius)){
                        Vector2 colVec = entity->pos - AABBRoot - Vector2(0.5,0.5);
                        CollisionData colDat = CollisionData{CollisionType::WORLD, colVec, Tile::WALL};
                        entity->registerCollision(colDat);
                    }
                }
            }
            i++;
        }
        j++;
    }
}
