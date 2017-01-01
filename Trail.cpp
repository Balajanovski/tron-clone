//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "Trail.h"

Trail::Trail(Team &nteam, int8_t x, int8_t y) : team(nteam), pos(x, y) {}

Trail::Trail(Team &nteam, Coord npos) : team(nteam), pos(npos) {}