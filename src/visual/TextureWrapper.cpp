//
// Created by zakrent on 3/6/18.
//

#include "TextureWrapper.h"

TextureWrapper::TextureWrapper() {
    texturePointer = nullptr;
}
TextureWrapper::TextureWrapper(SDL_Renderer *renderer, char* filePath) {
    texturePointer = nullptr;
    loadFromFile(renderer, filePath);
}

TextureWrapper::~TextureWrapper() {
    if(texturePointer){
        SDL_DestroyTexture(texturePointer);
    }
}

void TextureWrapper::loadFromFile(SDL_Renderer *renderer, char* filePath) {
    SDL_Surface* tempSurface = nullptr;
    tempSurface = SDL_LoadBMP(filePath);
    texturePointer = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    tempSurface = nullptr;
}

SDL_Texture *TextureWrapper::getTexturePointer() {
    return texturePointer;
}

