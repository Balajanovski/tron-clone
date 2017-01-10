//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "Model.h"

Model::Model() : player_1(Field::WIDTH / 2 - Field::WIDTH / 4, Field::HEIGHT / 2, RED), player_2(Field::WIDTH / 2 + Field::WIDTH / 4, Field::WIDTH / 2, GREEN),
                 controller(this), view(&field)
{
    field.matrix[player_1.pos.y][player_1.pos.x] = PLAYER_1;
    field.matrix[player_2.pos.y][player_2.pos.x] = PLAYER_2;
}

Player &Model::player1() {
	return player_1;
}

Player &Model::player2() {
	return player_2;
}


void Model::loop() {
    controls_current_time = SDL_GetTicks();
    if ((controls_current_time - controls_last_time) > controls_wait_time) {
		controller.handleEvents();
        controls_last_time = controls_current_time;
    }

    movement_current_time = SDL_GetTicks();
    if ((movement_current_time - movement_last_time) > movement_wait_time) {
		updatePlayer(player_1);
		updatePlayer(player_2);
        movement_last_time = movement_current_time;
    }

    current_ticks = SDL_GetTicks();
    int delay = 1000 / max_fps - current_ticks + last_ticks;

    if(delay > 0)
        SDL_Delay(delay);

    view.draw();

    last_ticks = current_ticks;
}

void Model::endGame() {
	if(winner != NONE)
 	   view.draw_end_screen(winner);
}

void Model::quit() {
	game_over_flag = true;
}

bool Model::isGameOver() const {
    return game_over_flag;
}

void Model::updatePlayer(Player &p) {
	Coord trail = p.tick();
    field.matrix[trail.y][trail.x] =
		p.getTeam() == RED ? RED_TRAIL : GREEN_TRAIL;
	
	checkCollision(p);
	
    field.matrix[p.pos.y][p.pos.x] =
		p.getTeam() == RED ? PLAYER_1 : PLAYER_2;
}

void Model::checkCollision(Player &p) {
	Objects cell = field.matrix[p.pos.y][p.pos.x];
    if (cell == RED_TRAIL || cell == GREEN_TRAIL) {
        game_over_flag = true;
		winner = p.getTeam() == RED ? GREEN : RED;
    }
}

