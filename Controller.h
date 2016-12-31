//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_CONTROLLER_H
#define TRON_CONTROLLER_H

#include "Includes.h"
#include "Player.h"

class Controller {
public:
    void control();

    Controller(Player *p1, Player *p2);
private:
    SDL_Event current_event;

    Player *p1_pointer,
           *p2_pointer;
};


#endif //TRON_CONTROLLER_H
