//
// Created by JULIA BALAJAN on 31/12/2016.
//

#ifndef TRON_COORD_H
#define TRON_COORD_H

#include <SDL_config_macos.h>

struct Coord {
    int8_t x,
           y;
    Coord(int x, int y) : Coord::x(x), Coord::y(y) {}
    Coord() = default;
};

#endif //TRON_COORD_H
