//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "Trail.h"

Trail::Trail(Team &team, int8_t x, int8_t y) : Trail::team(team), pos(x, y) {}

Trail::Trail(Team &team, Coord pos) : Trail::team(team), Trail::pos(pos) {}