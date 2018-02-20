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
    while(running) {
        updateStart = SDL_GetTicks();

        world->update();

        renderer->startRendering();
        world->render();
        renderer->renderCirlce(Vector2(4,4), 0.5);
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
}

Game::~Game() {
    SDL_Quit();
}

