//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "View.h"
#include "Cleanup.h"
#include <iostream>

View::View(Field *field) : field_ptr(field) {
    win = SDL_CreateWindow("Tron", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, field->WIDTH, field->HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_BORDERLESS);
    if (win == nullptr) {
        logSDLError("Window Initialisation");
        exit(1);
    }

    ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    if (ren == nullptr) {
        logSDLError("Renderer Initialisation");
        cleanup(win);
        IMG_Quit();
        SDL_Quit();
        exit(1);
    }

    background = IMG_LoadTexture(ren, "background.jpg");
    if (background == nullptr) {
        logSDLError("Texture");
        cleanup(ren, win);
        IMG_Quit();
        SDL_Quit();
        exit(1);
    }

    // Render background texture
    render_texture(ren, background, 0, 0);
}

void View::draw() {
    SDL_Rect draw_dst;
    draw_dst.w = TILESIZE;
    draw_dst.h = TILESIZE;

    for (int y = 0; y < field_ptr->HEIGHT; ++y)
        for (int x = 0; x < field_ptr->WIDTH; ++x) {
            switch(field_ptr->field_matrix[y][x]) {
                case PLAYER_1 :
                case RED_TRAIL :
                    // Set the draw color
                    SDL_SetRenderDrawColor(ren, RED.r, RED.g, RED.b, SDL_ALPHA_OPAQUE);

                    // Set the position to draw
                    draw_dst.x = x;
                    draw_dst.y = y;

                    // Draw
                    SDL_RenderFillRect(ren, &draw_dst);
                    break;
                case PLAYER_2 :
                case GREEN_TRAIL :
                    // Set the draw color
                    SDL_SetRenderDrawColor(ren, GREEN.r, GREEN.g, GREEN.b, SDL_ALPHA_OPAQUE);

                    // Set the position to draw
                    draw_dst.x = x;
                    draw_dst.y = y;

                    // Draw
                    SDL_RenderFillRect(ren, &draw_dst);
                    break;
            }
        }

    SDL_RenderPresent(ren);
}

void View::logSDLError(const std::string &msg) {
    std::cout << msg << " error: " << SDL_GetError() << std::endl;
}

void View::render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y, int w, int h) {
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = w;
    dst.h = h;
    SDL_RenderCopy(ren, tex, nullptr, &dst);
}

void View::render_texture(SDL_Renderer *ren, SDL_Texture *tex, int x, int y) {
    int w,
        h;
    SDL_QueryTexture(tex, nullptr, nullptr, &w, &h);
    render_texture(ren, tex, x, y, w, h);
}
