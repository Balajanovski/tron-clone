//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include <iostream>
#include "Model.h"

Model::Model() : player_1(Field::WIDTH / 2 - Field::WIDTH / 4, Field::HEIGHT / 2, RED), player_2(Field::WIDTH / 2 + Field::WIDTH / 4, Field::WIDTH / 2, GREEN),
                 controller(&player_1, &player_2), view(&field)
{
    field.field_matrix[player_1.pos.y][player_1.pos.x] = PLAYER_1;
    field.field_matrix[player_2.pos.y][player_2.pos.x] = PLAYER_2;
}


void Model::loop() {
    controls_current_time = SDL_GetTicks();
    if ((controls_current_time - controls_last_time) > controls_wait_time) {
        controller.control();
        controls_last_time = controls_current_time;
    }

    movement_current_time = SDL_GetTicks();
    if ((movement_current_time - movement_last_time) > movement_wait_time) {
        update_matrix();
        movement_last_time = movement_current_time;
    }

    current_ticks = SDL_GetTicks();
    int delay = 1000 / max_fps - current_ticks + last_ticks;

    if(delay > 0)
        SDL_Delay(delay);

    view.draw();

    last_ticks = current_ticks;
}

void Model::end_screen() {
    view.draw_end_screen(winner);
}

bool Model::isGame_over_flag() const {
    return game_over_flag;
}

void Model::update_matrix() {
    Trail player1_new_trail = player_1.tick();
    field.field_matrix[player1_new_trail.pos.y][player1_new_trail.pos.x] = RED_TRAIL;
    collision_detection(player_1);
    field.field_matrix[player_1.pos.y][player_1.pos.x] = PLAYER_1;

    Trail player2_new_trail = player_2.tick();
    field.field_matrix[player2_new_trail.pos.y][player2_new_trail.pos.x] = GREEN_TRAIL;
    collision_detection(player_2);
    field.field_matrix[player_2.pos.y][player_2.pos.x] = PLAYER_2;
}

void Model::collision_detection(Player &p) {
    Team team = p.getTeam(),
         opponent_team;
    if (team == RED)
        opponent_team = GREEN;
    else if (team == GREEN)
        opponent_team = RED;

    if (field.field_matrix[p.pos.y][p.pos.x] == RED_TRAIL ||  field.field_matrix[p.pos.y][p.pos.x] == GREEN_TRAIL) {
        game_over_flag = true;
        winner = opponent_team;
        return;
    }

    if (p.pos.x < 0)
        p.pos.x = Field::WIDTH - 1;
    else if (p.pos.x >= Field::WIDTH)
        p.pos.x = 0;
    if (p.pos.y < 0)
        p.pos.y = Field::HEIGHT - 1;
    else if (p.pos.y >= Field::HEIGHT)
        p.pos.y = 0;
}

