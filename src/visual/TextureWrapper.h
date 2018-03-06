//
// Created by zakrent on 3/6/18.
//

#ifndef SDL_JUMP_TEXTUREWRAPPER_H
#define SDL_JUMP_TEXTUREWRAPPER_H

#include <SDL.h>

class TextureWrapper {
private:
    SDL_Texture *texturePointer;
public:
    SDL_Texture *getTexturePointer();
    void loadFromFile(SDL_Renderer *renderer, char *filePath);
public:
    TextureWrapper();
    TextureWrapper(SDL_Renderer *renderer, char *filePath);
    ~TextureWrapper();

};


#endif //SDL_JUMP_TEXTUREWRAPPER_H
