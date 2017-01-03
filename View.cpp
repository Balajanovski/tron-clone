//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "View.h"
#include "Cleanup.h"
#include <iostream>

View::View(Field *field) : field_ptr(field) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Unable to initialise SDL: " << std::endl;
        exit(1);
    }

    if ((IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)) != (IMG_INIT_PNG | IMG_INIT_JPG)) {
        std::cout << "Unable to initialise SDL_img" << std::endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() == -1) {
        std::cout << "Unable to initialise SDL_ttf" << std::endl;
        IMG_Quit();
        SDL_Quit();
        exit(1);
    }

    win = SDL_CreateWindow("Tron", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, field->SCREEN_WIDTH, field->SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
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

    background = IMG_LoadTexture(ren, "Resources/background.jpg");
    if (background == nullptr) {
        logSDLError("Texture");
        cleanup(ren, win);
        IMG_Quit();
        SDL_Quit();
        exit(1);
    }
}

View::~View() {
    cleanup(ren, win, background);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

void View::draw() {
    // Render background texture
    render_texture(ren, background, 0, 0);

    SDL_Rect draw_dst;
    draw_dst.w = Field::TILESIZE;
    draw_dst.h = Field::TILESIZE;

    for (int y = 0; y < field_ptr->HEIGHT; ++y)
        for (int x = 0; x < field_ptr->WIDTH; ++x) {
            switch(field_ptr->field_matrix[y][x]) {
                case PLAYER_1 :
                case RED_TRAIL :
                    // Set the draw color
                    SDL_SetRenderDrawColor(ren, COLOR_RED.r, COLOR_RED.g, COLOR_RED.b, SDL_ALPHA_OPAQUE);

                    // Set the position to draw
                    draw_dst.x = x * Field::TILESIZE;
                    draw_dst.y = y * Field::TILESIZE;

                    // Draw
                    SDL_RenderFillRect(ren, &draw_dst);
                    break;
                case PLAYER_2 :
                case GREEN_TRAIL :
                    // Set the draw color
                    SDL_SetRenderDrawColor(ren, COLOR_GREEN.r, COLOR_GREEN.g, COLOR_GREEN.b, SDL_ALPHA_OPAQUE);

                    // Set the position to draw
                    draw_dst.x = x * Field::TILESIZE;
                    draw_dst.y = y * Field::TILESIZE;

                    // Draw
                    SDL_RenderFillRect(ren, &draw_dst);
                    break;
                case NOTHING :
                    break;
            }
        }

    SDL_RenderPresent(ren);
}

void View::draw_end_screen(Team winner) {
    std::string winner_text;
    SDL_Color winner_color;

    if (winner == RED) {
        winner_text = "Red Won";
        winner_color = {255, 0, 0};
    }
    else if (winner == GREEN) {
        winner_text = "Green Won";
        winner_color = {0, 255, 0};
    }
    else {
        winner_text = "I AM ERROR";
        winner_color = {255, 255, 255};
    }

    SDL_Texture *winner_texture = render_font("Resources/Pixelated.ttf", winner_text.c_str(), winner_color, 50);
    if (winner_texture == nullptr)
        exit(1);
    int w,
        h;
    SDL_QueryTexture(winner_texture, nullptr, nullptr, &w, &h);

    SDL_Rect dst;
    dst.x = Field::WIDTH / 2 + w / 2;
    dst.y = Field::HEIGHT / 2 + h / 2;
    dst.w = w;
    dst.h = h;

    SDL_RenderCopy(ren, winner_texture, nullptr, &dst);
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

SDL_Texture* View::render_font(const std::string &file, const std::string &msg, SDL_Color color, int font_size) {
    TTF_Font *font = TTF_OpenFont(file.c_str(), font_size);
    if (font == nullptr) {
        logSDLError("TTF Open Font");
        return nullptr;
    }

    SDL_Surface *temp_surface = TTF_RenderText_Blended(font, msg.c_str(), color);
    if (temp_surface == nullptr) {
        logSDLError("TTF Render Font");
        return nullptr;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(ren, temp_surface);
    if (tex == nullptr)
        logSDLError("Create Texture");

    TTF_CloseFont(font);
    SDL_FreeSurface(temp_surface);
    return tex;
}