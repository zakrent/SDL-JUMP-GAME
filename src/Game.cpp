//
// Created by zakrent on 2/19/18.
//

#include <iostream>
#include "Game.h"
#include "entity/Player.h"

Game* Game::sInstance = nullptr;

void Game::startMainLoop() {
    renderer->createWindow();
    bool running = true;
    const int MIN_UPDATE_TIME = 10;
    int updateStart;

    world->entities.push_back(std::make_unique<Player>(Vector2(0,5)));

    while(running) {
        updateStart = SDL_GetTicks();

	world->shiftMap(world->entities.front()->pos.x);

        world->update();
        collisionSystem->checkForCollisions();
        world->handleCollisions();

        renderer->startRendering();
        std::string infoString = "Current score: "+std::to_string(scoreManager->getCurrentScore())+
                " High score: "+std::to_string(scoreManager->getHighScore());
        renderer->renderString(infoString, Vector2(0,0));
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
    inputManager = new InputManager;
    world = new World;
    renderer = new Renderer;
    collisionSystem = new CollisionSystem;
    scoreManager = new ScoreManager;
}

Game::~Game() {
    SDL_Quit();
}

