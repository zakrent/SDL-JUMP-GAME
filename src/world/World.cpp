//
// Created by zakrent on 2/19/18.
//

#include <iostream>
#include "World.h"
#include "../visual/Renderer.h"
#include "../Game.h"

World::World() {
    seed = 240;
    mapRoot = Vector2(-25,3);
    generateMap();
}

int World::getBlockSeed(int blockId){
    return abs((blockId*1299811*seed)%1000);
}

std::vector<Tile> World::generateColumn(int x){
    std::vector<Tile> retVec;
    int columnId = x/4;
    int blockId = abs(x)%4;
    int blockSeed = getBlockSeed(columnId);
    bool hole = blockSeed < 400  && (blockId == 2 || blockId == 1);
    bool spikes = (blockSeed > 400 && blockSeed < 800) && !hole && blockId != 0;
    bool upperLevel = blockSeed < 800 && blockSeed > 350 && 0x8&blockSeed;
    bool upperSpikes = upperLevel && (blockSeed < 400 || blockSeed > 750);

    for (int i = 0; i < 8; i++) {
        if((i == 7 && !hole) || (upperLevel && i == 4)){
            retVec.push_back(Tile::WALL);
        }
        else if(spikes && i==6){
            retVec.push_back(Tile::SPIKE);
        }
        else{
            retVec.push_back(Tile::AIR);
        }
    }
    return retVec;
}

void World::shiftMap(int centerX){
    Vector2 newRoot = Vector2(centerX-25, 3);
    int deltaX = newRoot.x - mapRoot.x;
    for(int i = 0; i < abs(deltaX); i++){
        if(deltaX > 0) {
            tiles.pop_front();
            tiles.push_back(generateColumn(mapRoot.x+25+i));
        }
        else{
            tiles.pop_back();
            tiles.push_front(generateColumn(mapRoot.x-26-i));
        }
    }
    mapRoot = newRoot;
}

void World::update() {
    for(std::unique_ptr<Entity>& entity : entities){
        entity->update();
    }
}

void World::handleCollisions() {
    for(std::unique_ptr<Entity>& entity : entities){
        entity->handleCollisions();
    }
}

void World::render() {

    for(std::unique_ptr<Entity>& entity : entities) {
        entity->render();
    }

    Renderer* renderer = Game::get()->renderer;
    int j = 0;
    for (auto &tile : tiles) {
        int i = 0;
        for (auto &curTile : tile) {
            if(curTile==Tile::WALL){
                renderer->renderRectangle(mapRoot+Vector2(j,i), 1, 1);
            }
            else if(curTile==Tile::SPIKE){
                renderer->renderTriangle(mapRoot+Vector2(j,i+1), mapRoot+Vector2(j+1,i+1), mapRoot+Vector2(j+0.5,i));
            }
            i++;
        }
        j++;
    }
}

void World::generateMap() {
    for (int j = -25; j < 25; j++) {
        tiles.push_back(generateColumn(mapRoot.x+j));
    }
}

