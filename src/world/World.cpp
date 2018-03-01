//
// Created by zakrent on 2/19/18.
//

#include "World.h"
#include "../visual/Renderer.h"
#include "../Game.h"

World::World() {
    mapRoot = Vector2(0,3);
    generateMap();
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
            i++;
        }
        j++;
    }
}

void World::generateMap() {
    for (int j = 0; j < 50; j++) {
        std::vector<Tile> tempVector;
        for (int i = 0; i < 8; i++) {
            if(i == 7 || (j > 10 && i ==4)){
                tempVector.push_back(Tile::WALL);
            }
            else{
                tempVector.push_back(Tile::AIR);
            }
        }
        tiles.push_back(tempVector);
    }
}

