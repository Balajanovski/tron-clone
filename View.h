//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_VIEW_H
#define TRON_VIEW_H

#include "Includes.h"
#include "Field.h"
#include <memory>

class View {
public:
    View(Field *field);
    void draw();
private:
    void logSDLError(const std::string &msg);
    void render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, int w, int h);
    void render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y);

    SDL_Window *win = nullptr;
    SDL_Renderer *ren = nullptr;
    SDL_Texture *background = nullptr;

    static constexpr SDL_Color RED = {255, 0, 0};
    static constexpr SDL_Color GREEN = {0, 255, 0};
    static constexpr int8_t TILESIZE = 1;

    std::shared_ptr<Field> field_ptr;
};


#endif //TRON_VIEW_H
