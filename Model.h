//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_MODEL_H
#define TRON_MODEL_H

#include "Includes.h"
#include "Player.h"
#include "Trail.h"
#include "Field.h"
#include "Controller.h"

class Model {
public:
    void loop();

    Model();

    bool isGame_over_flag() const;

private:
    Player player_1,
           player_2;

    Field field;

    bool game_over_flag = false;
    Team winner;

    Controller controller;
};


#endif //TRON_MODEL_H
