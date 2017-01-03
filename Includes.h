//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_INCLUDES_H
#define TRON_INCLUDES_H

#include <string>
#include <SDL2/SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Coord.h"

enum Dir {UP = 0, DOWN, LEFT, RIGHT};
enum Team {RED = 0, GREEN = 1};
enum Objects {NOTHING = 0, RED_TRAIL, PLAYER_1, GREEN_TRAIL, PLAYER_2};

#endif //TRON_INCLUDES_H
