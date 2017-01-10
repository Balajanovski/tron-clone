//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "Player.h"
#include "Field.h"

Player::Player(int x, int y, Team nteam) : team(nteam), pos(x, y) {}

void Player::changeDirection(Dir newDir) {
    direction = newDir;
}

Dir Player::getDirection() const {
    return direction;
}

void Player::turnLeft() {
	switch (getDirection()) {
	case UP:	changeDirection(LEFT); break;
	case DOWN:	changeDirection(RIGHT); break;
	case LEFT:	changeDirection(DOWN); break;
	case RIGHT:	changeDirection(UP); break;
	}
}

void Player::turnRight() {
	switch (getDirection()) {
	case UP:	changeDirection(RIGHT); break;
	case DOWN:	changeDirection(LEFT); break;
	case LEFT:	changeDirection(UP); break;
	case RIGHT:	changeDirection(DOWN); break;
	}
}

Coord Player::tick() {
	Coord new_trail = pos;
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
	
	if (pos.x < 0)
		pos.x = Field::WIDTH - 1;
	else if (pos.x >= Field::WIDTH)
		pos.x = 0;
	if (pos.y < 0)
		pos.y = Field::HEIGHT - 1;
	else if (pos.y >= Field::HEIGHT)
		pos.y = 0;
	
    return new_trail;
}

Team Player::getTeam() const {
    return team;
}
