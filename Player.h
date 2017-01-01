//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_PLAYER_H
#define TRON_PLAYER_H

#include "Includes.h"
#include "Trail.h"

class Player {
public:
    void changeDirection(Dir new_dir);
    Dir getDirection() const;
    Trail tick();

    Player() = default;
    Player(Coord pos);
    Player(int x, int y);

    Coord pos;
private:
    Dir direction = UP;
    Team team;
};


#endif //TRON_PLAYER_H
