//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_RENDERER_H
#define SDL_JUMP_RENDERER_H

#include <SDL.h>
#include "../misc/Vector2.h"

class Renderer {
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Vector2 camera;
    void createWindow();
    int convertToPixCord(double cord);
    double convertToWorldCord(int cord);

    void renderRectangle(Vector2 root, double width, double height);
    void renderCirlce(Vector2 root, double radius);

    void startRendering();
    void swapBuffers();

    Renderer();
    ~Renderer();
};


#endif //SDL_JUMP_RENDERER_H
