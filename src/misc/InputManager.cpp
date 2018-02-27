//
// Created by zakrent on 2/20/18.
//

#include "InputManager.h"

void InputManager::registerInput(std::string name, SDL_Scancode scancode) {
    inputs[name] = scancode;
}

bool InputManager::isInputPressed(std::string input) {
    return state[inputs[input]];
}

InputManager::InputManager() {
    state = SDL_GetKeyboardState(NULL);
    registerInput("Jump", SDL_SCANCODE_W);
    registerInput("Right", SDL_SCANCODE_D);
    registerInput("Left", SDL_SCANCODE_A);
    registerInput("Stop", SDL_SCANCODE_S);
}
