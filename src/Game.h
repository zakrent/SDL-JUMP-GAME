//
// Created by zakrent on 2/19/18.
//

#ifndef SDL_JUMP_GAME_H
#define SDL_JUMP_GAME_H

#include <SDL.h>
#include "misc/SettingsManager.h"
#include "visual/Renderer.h"

class Game {
    static Game* sInstance;
    Game();
    ~Game();
public:
    SettingsManager* settingsManager;
    Renderer* renderer;

    void startMainLoop();
    static Game* get();
};


#endif //SDL_JUMP_GAME_H