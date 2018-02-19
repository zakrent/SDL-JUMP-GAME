//
// Created by zakrent on 2/19/18.
//

#include "Renderer.h"
#include "../Game.h"

Renderer::Renderer() {
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void Renderer::createWindow() {
    Game* game = Game::get();

    if(!game->settingsManager->checkIfSettingExists("resx") || !game->settingsManager->checkIfSettingExists("resy")){
        perror("Failed to load resolution settings!\n");
        exit(-1);
    }

    int resX = game->settingsManager->getSetting("resx");
    int resY = game->settingsManager->getSetting("resy");

    if(SDL_CreateWindowAndRenderer(resX, resY, NULL, &window, &renderer) < 0){
        perror("Failed to create window!\n");
        exit(-1);
    }
}

void Renderer::startRendering() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void Renderer::swapBuffers() {
    SDL_RenderPresent(renderer);
}
