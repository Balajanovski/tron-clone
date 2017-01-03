//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_VIEW_H
#define TRON_VIEW_H

#include "Includes.h"
#include "Field.h"
#include <SDL_ttf.h>
#include <memory>

class View {
public:
    View(Field *field);
    ~View();
    void draw();
    void draw_end_screen(Team Winner);
private:
    void logSDLError(const std::string &msg);
    void render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, int w, int h);
    void render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y);
    SDL_Texture* render_font(const std::string &file, const std::string &msg, SDL_Color color, int font_size);

    SDL_Window *win = nullptr;
    SDL_Renderer *ren = nullptr;
    SDL_Texture *background = nullptr;

    static constexpr SDL_Color COLOR_RED = {255, 0, 0};
    static constexpr SDL_Color COLOR_GREEN = {0, 255, 0};

    Field *field_ptr = nullptr;
};


#endif //TRON_VIEW_H
