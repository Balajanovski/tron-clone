//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_VIEW_H
#define TRON_VIEW_H

#include "Includes.h"
#include "Field.h"

class View {
public:
    View(Field &field);
private:
    void logSDLError(const std::string &msg);
    void render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, int w, int h);
    void render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y);

    SDL_Window *win = nullptr;
    SDL_Renderer *ren = nullptr;
    SDL_Texture *background = nullptr;
};


#endif //TRON_VIEW_H
