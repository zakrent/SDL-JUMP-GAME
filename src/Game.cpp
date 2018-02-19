//
// Created by zakrent on 2/19/18.
//

#include <iostream>
#include "Game.h"

Game* Game::sInstance = nullptr;

void Game::startMainLoop() {
    renderer->createWindow();
    bool running = true;
    while(running) {

        renderer->startRendering();
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
    renderer = new Renderer;
}

Game::~Game() {
    SDL_Quit();
}

