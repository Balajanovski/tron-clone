//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include <iostream>
#include "Model.h"

Model::Model() : player_1(Field::WIDTH / 2 - Field::WIDTH / 4, Field::HEIGHT / 2), player_2(Field::WIDTH / 2 + Field::WIDTH / 4, Field::WIDTH / 2),
                 controller(&player_1, &player_2)
{
    field.field_matrix[player_1.pos.y][player_1.pos.x] = PLAYER_1;
    field.field_matrix[player_2.pos.y][player_2.pos.x] = PLAYER_2;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Unable to initialise SDL: " << SDL_GetError() << std::endl;
        exit(1);
    }

    if ((IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)) != IMG_INIT_PNG | IMG_INIT_JPG) {
        SDL_Quit();
        exit(1);
    }
}

void Model::loop() {
    controller.control();

    Trail player1_new_trail = player_1.tick();
    field.field_matrix[player1_new_trail.pos.y][player1_new_trail.pos.x] = RED_TRAIL;
    field.field_matrix[player_1.pos.y][player_1.pos.x] = PLAYER_1;

    Trail player2_new_trail = player_2.tick();
    field.field_matrix[player2_new_trail.pos.y][player2_new_trail.pos.x] = GREEN_TRAIL;
    field.field_matrix[player_2.pos.y][player_2.pos.x] = PLAYER_2;

    if (player_1.pos.x < 0 || player_1.pos.x >= Field::WIDTH || player_1.pos.y < 0 || player_1.pos.y >= Field::HEIGHT ||
            field.field_matrix[player_1.pos.y][player_1.pos.x] == RED_TRAIL ||  field.field_matrix[player_1.pos.y][player_1.pos.x] == GREEN_TRAIL) {
        game_over_flag = true;
        winner = GREEN;
        return;
    }

    if (player_2.pos.x < 0 || player_2.pos.x >= Field::WIDTH || player_2.pos.y < 0 || player_2.pos.y >= Field::HEIGHT ||
            field.field_matrix[player_2.pos.y][player_2.pos.x] == RED_TRAIL ||  field.field_matrix[player_2.pos.y][player_2.pos.x] == GREEN_TRAIL) {
        game_over_flag = true;
        winner = RED;
        return;
    }
}

bool Model::isGame_over_flag() const {
    return game_over_flag;
}
