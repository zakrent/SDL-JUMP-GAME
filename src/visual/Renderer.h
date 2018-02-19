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
    SDL_Rect camera;

public:
    void createWindow();

    void startRendering();
    void swapBuffers();

    Renderer();
    ~Renderer();
};


#endif //SDL_JUMP_RENDERER_H
