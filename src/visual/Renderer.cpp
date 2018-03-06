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
    fontTexture = new TextureWrapper(renderer, const_cast<char *>("textures/font.bmp"));
}

void Renderer::startRendering() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    if(!Game::get()->settingsManager->checkIfSettingExists("resx")){
        perror("Failed to get screen res settings\n");
        exit(-1);
    }
    camera.x -= convertToWorldCord(Game::get()->settingsManager->getSetting("resx"))/2;
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

double Renderer::convertToWorldCord(int cord) {
    if(!Game::get()->settingsManager->checkIfSettingExists("upixsize")){
        perror("Failed to get unit pixel size!");
        exit(-1);
    }
    return (1.0*cord/Game::get()->settingsManager->getSetting("upixsize"));
}

void Renderer::renderRectangle(Vector2 root, double width, double height) {
    Vector2 screenPos = root - camera;
    SDL_Rect rect{};
    rect.x = convertToPixCord(static_cast<double>(screenPos.x));
    rect.y = convertToPixCord(static_cast<double>(screenPos.y));
    rect.w = convertToPixCord(width);
    rect.h = convertToPixCord(height);

    if((int)root.x % 2 == 0)
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    else
        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

void Renderer::renderCirlce(Vector2 root, double radius) {
    Vector2 screenPos = root- camera;
    SDL_Point points[360];
    for(int i = 0; i < 360; i++){
        points[i].x = convertToPixCord((double)screenPos.x);
        points[i].y = convertToPixCord((double)screenPos.y);
        points[i].x += static_cast<int>(cos(i * M_PI / 180)*convertToPixCord(radius));
        points[i].y += static_cast<int>(sin(i * M_PI / 180)*convertToPixCord(radius));
    }
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLines(renderer, points, 360);
}

void Renderer::renderTriangle(Vector2 x1, Vector2 x2, Vector2 x3) {
    SDL_Point points[4];
    x1 -= camera;
    x2 -= camera;
    x3 -= camera;
    points[0] = SDL_Point{convertToPixCord(static_cast<double>(x1.x)), convertToPixCord(static_cast<double>(x1.y))};
    points[1] = SDL_Point{convertToPixCord(static_cast<double>(x2.x)), convertToPixCord(static_cast<double>(x2.y))};
    points[2] = SDL_Point{convertToPixCord(static_cast<double>(x3.x)), convertToPixCord(static_cast<double>(x3.y))};
    points[3] = points[0];
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLines(renderer, points, 4);
}

void Renderer::renderChar(char c, Vector2 pos, int offset=0) {
    if(c < 'a') {
        c -= 1;
    }
    int xFontPos = ((c%16))*32;
    int yFontPos = (c/16)*32;
    SDL_Rect srcrect{xFontPos, yFontPos, 32, 32};
    SDL_Rect dstrect{convertToPixCord((double)pos.x)+offset*16,
                     convertToPixCord((double)pos.y), 16, 16};
    SDL_RenderCopyEx(renderer, fontTexture->getTexturePointer(), &srcrect,
                     &dstrect, 0, nullptr, SDL_FLIP_NONE);
}

void Renderer::renderString(std::string s, Vector2 pos) {
    int i = 0;
    for(auto c : s){
        renderChar(c, pos, i);
        i++;
    }
}

