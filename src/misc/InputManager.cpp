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
}
