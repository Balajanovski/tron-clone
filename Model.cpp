//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include <iostream>
#include "Model.h"

Model::Model() : player_1(Field::WIDTH / 2 - Field::WIDTH / 4, Field::HEIGHT / 2), player_2(Field::WIDTH / 2 + Field::WIDTH / 4, Field::WIDTH / 2),
                 controller(&player_1, &player_2), view(&field)
{
    field.field_matrix[player_1.pos.y][player_1.pos.x] = PLAYER_1;
    field.field_matrix[player_2.pos.y][player_2.pos.x] = PLAYER_2;

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Unable to initialise SDL: " << std::endl;
        exit(1);
    }

    if ((IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG)) != (IMG_INIT_PNG | IMG_INIT_JPG)) {
        std::cout << "Unable to initialise SDL_img" << std::endl;
        SDL_Quit();
        exit(1);
    }
}


void Model::loop() {
    controller.control();

    Trail player1_new_trail = player_1.tick();
    field.field_matrix[player1_new_trail.pos.y][player1_new_trail.pos.x] = RED_TRAIL;
    if (player_1.pos.x < 0)
        player_1.pos.x = Field::WIDTH - 1;
    else if (player_1.pos.x >= Field::WIDTH)
        player_1.pos.x = 0;
    if (player_1.pos.y < 0)
        player_1.pos.y = Field::HEIGHT - 1;
    else if (player_1.pos.x >= Field::HEIGHT)
        player_1.pos.y = 0;
    field.field_matrix[player_1.pos.y][player_1.pos.x] = PLAYER_1;

    Trail player2_new_trail = player_2.tick();
    field.field_matrix[player2_new_trail.pos.y][player2_new_trail.pos.x] = GREEN_TRAIL;
    if (player_2.pos.x < 0)
        player_2.pos.x = Field::WIDTH - 1;
    else if (player_2.pos.x >= Field::WIDTH)
        player_2.pos.x = 0;
    if (player_2.pos.y < 0)
        player_2.pos.y = Field::HEIGHT - 1;
    else if (player_2.pos.x >= Field::HEIGHT)
        player_2.pos.y = 0;
    field.field_matrix[player_2.pos.y][player_2.pos.x] = PLAYER_2;

    if (field.field_matrix[player_1.pos.y][player_1.pos.x] == RED_TRAIL ||  field.field_matrix[player_1.pos.y][player_1.pos.x] == GREEN_TRAIL) {
        game_over_flag = true;
        winner = GREEN;
        std::cout << "Green wins" << std::endl;
        return;
    }

    if (field.field_matrix[player_2.pos.y][player_2.pos.x] == RED_TRAIL ||  field.field_matrix[player_2.pos.y][player_2.pos.x] == GREEN_TRAIL) {
        game_over_flag = true;
        winner = RED;
        std::cout << "Red wins" << std::endl;
        return;
    }

    current_ticks = SDL_GetTicks();
    int delay = 1000 / max_fps - current_ticks + last_ticks;

    if(delay > 0)
        SDL_Delay(delay);

    view.draw();

    last_ticks = current_ticks;
}

bool Model::isGame_over_flag() const {
    return game_over_flag;
}
