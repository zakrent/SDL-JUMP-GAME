//
// Created by zakrent on 2/19/18.
//

#include <iostream>
#include "Game.h"

Game* Game::sInstance = nullptr;

void Game::startMainLoop() {
    renderer->createWindow();
    bool running = true;
    const int MIN_UPDATE_TIME = 10;
    int updateStart;

    world->entities.push_back(std::make_unique<Entity>(Vector2(4.5,4)));

    while(running) {
        updateStart = SDL_GetTicks();

        world->update();
        collisionSystem->checkForCollisions();
        world->handleCollisions();

        renderer->startRendering();
        world->render();
        renderer->swapBuffers();

        SDL_Event event{};
        while (SDL_PollEvent(&event) != 0) {
            switch (event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                default:
                    break;
            }
        }

        if (SDL_GetTicks() < updateStart + MIN_UPDATE_TIME) {
            SDL_Delay((updateStart + MIN_UPDATE_TIME) - SDL_GetTicks());
        }
    }
}

Game *Game::get() {
    if(!Game::sInstance) {
        Game::sInstance = new Game;
    }
    return Game::sInstance;
}

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);

    settingsManager = new SettingsManager;
    world = new World;
    renderer = new Renderer;
    collisionSystem = new CollisionSystem;
}

Game::~Game() {
    SDL_Quit();
}

