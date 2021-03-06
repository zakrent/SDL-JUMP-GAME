//
// Created by zakrent on 2/20/18.
//

#ifndef SDL_JUMP_INPUTMANAGER_H
#define SDL_JUMP_INPUTMANAGER_H

#include <string>
#include <map>
#include <SDL.h>

class InputManager {
    std::map<std::string, SDL_Scancode> inputs;
    const Uint8* state;
public:
    void loadFromFile();
    bool isInputPressed(std::string input);
    void registerInput(std::string name, SDL_Scancode scancode);

    InputManager();
};


#endif //SDL_JUMP_INPUTMANAGER_H
