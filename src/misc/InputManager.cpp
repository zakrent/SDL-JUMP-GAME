//
// Created by zakrent on 2/20/18.
//

#include "InputManager.h"
#include "FileParser.h"

void InputManager::registerInput(std::string name, SDL_Scancode scancode) {
    inputs[name] = scancode;
}

bool InputManager::isInputPressed(std::string input) {
    return state[inputs[input]];
}

InputManager::InputManager() {
    state = SDL_GetKeyboardState(NULL);
    loadFromFile();
}

void InputManager::loadFromFile() {
    std::string filename = "controls.dat";
    FileParser fileParser(filename);
    for(const auto &element : fileParser.data){
        registerInput(element.first, SDL_GetScancodeFromName(element.second.c_str()));
    }
}
