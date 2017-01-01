//
// Created by JULIA BALAJAN on 31/12/2016.
//

#ifndef TRON_COORD_H
#define TRON_COORD_H

#include <SDL_config_macos.h>

struct Coord {
    int x,
        y;
    Coord(int nx, int ny) : x(nx), y(ny) {}
    Coord() = default;
};

#endif //TRON_COORD_H
