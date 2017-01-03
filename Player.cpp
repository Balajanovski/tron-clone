//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "Player.h"

Player::Player(Coord npos, Team nteam) : team(nteam), pos(npos) {}

Player::Player(int x, int y, Team nteam) : team(nteam) {
    pos = Coord(x, y);
}

void Player::changeDirection(Dir newDir) {
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
    return new_trail;
}

Team Player::getTeam() const {
    return team;
}
