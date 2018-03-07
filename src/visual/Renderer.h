//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_RENDERER_H
#define SDL_JUMP_RENDERER_H

#include <SDL.h>
#include <string>
#include "../misc/Vector2.h"
#include "TextureWrapper.h"

class Renderer {
    SDL_Window* window;
    SDL_Renderer* renderer;
    TextureWrapper* fontTexture;
    void renderChar(char c, int x, int y);

public:
    Vector2 camera;
    void createWindow();
    int convertToPixCord(double cord);
    double convertToWorldCord(int cord);

    void renderRectangle(Vector2 root, double width, double height);
    void renderCirlce(Vector2 root, double radius);
    void renderTriangle(Vector2 x1, Vector2 x2, Vector2 x3);
    void renderString(std::string s, Vector2 pos);

    void startRendering();
    void swapBuffers();

    Renderer();
    ~Renderer();
};


#endif //SDL_JUMP_RENDERER_H
