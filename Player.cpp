//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "Player.h"
#include "Trail.h"

Player::Player(Coord pos) : Player::pos(pos) {}

Player::Player(int x, int y) {
    Player::pos = Coord(x, y);
}

inline void Player::changeDirection(Dir newDir) {
    direction = newDir;
}

Dir Player::getDirection() const {
    return direction;
}

Trail Player::tick() {
    Trail new_trail(team, pos);
    switch(direction) {
        case UP :
            --pos.y;
            break;
        case DOWN :
            ++pos.y;
            break;
        case LEFT :
            --pos.x;
            break;
        case RIGHT :
            ++pos.x;
            break;
    }
}