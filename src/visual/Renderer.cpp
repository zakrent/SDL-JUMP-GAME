//
// Created by zakrent on 2/19/18.
//

#include <math.h>
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

int Renderer::convertToPixCord(double cord) {
    if(!Game::get()->settingsManager->checkIfSettingExists("upixsize")){
        perror("Failed to get unit pixel size!");
        exit(-1);
    }
    return (int)(cord*Game::get()->settingsManager->getSetting("upixsize"));
}

void Renderer::renderRectangle(Vector2 root, double width, double height) {
    Vector2 screenPos = root - camera;
    SDL_Rect rect{};
    rect.x = convertToPixCord(static_cast<double>(screenPos.x));
    rect.y = convertToPixCord(static_cast<double>(screenPos.y));
    rect.w = convertToPixCord(width);
    rect.h = convertToPixCord(height);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::renderCirlce(Vector2 root, double radius) {
    SDL_Point points[360];
    for(int i = 0; i < 360; i++){
        points[i].x = convertToPixCord((double)root.x);
        points[i].y = convertToPixCord((double)root.y);
        points[i].x += static_cast<int>(cos(i * M_PI / 180)*convertToPixCord(radius));
        points[i].y += static_cast<int>(sin(i * M_PI / 180)*convertToPixCord(radius));
    }
    SDL_RenderDrawLines(renderer, points, 360);
}

