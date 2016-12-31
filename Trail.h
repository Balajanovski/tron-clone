//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_TRAIL_H
#define TRON_TRAIL_H

#include "Includes.h"

class Trail {
public:
    Team team;

    Coord pos;

    Trail(Team &team, int8_t x, int8_t y);
    Trail(Team &team, Coord pos);
};


#endif //TRON_TRAIL_H
