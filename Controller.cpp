//
// Created by JULIA BALAJAN on 30/12/2016.
//

#include "Controller.h"

Controller::Controller(Player *p1, Player *p2) : p1_pointer(p1), p2_pointer(p2) {}

void Controller::control() {
    SDL_PollEvent(&current_event);
    if (current_event.type == SDL_KEYDOWN) {
        switch(current_event.key.keysym.sym) {
            case SDLK_LEFT :
                switch (p1_pointer->getDirection()) {
                    case UP :
                        p1_pointer->changeDirection(LEFT);
                        break;
                    case DOWN :
                        p1_pointer->changeDirection(RIGHT);
                        break;
                    case LEFT :
                        p1_pointer->changeDirection(DOWN);
                        break;
                    case RIGHT :
                        p1_pointer->changeDirection(UP);
                        break;
                }
                break;
            case SDLK_RIGHT :
                switch (p1_pointer->getDirection()) {
                    case UP :
                        p1_pointer->changeDirection(RIGHT);
                        break;
                    case DOWN :
                        p1_pointer->changeDirection(LEFT);
                        break;
                    case LEFT :
                        p1_pointer->changeDirection(UP);
                        break;
                    case RIGHT :
                        p1_pointer->changeDirection(DOWN);
                        break;
                }
                break;
            case SDLK_a :
                switch (p2_pointer->getDirection()) {
                    case UP :
                        p2_pointer->changeDirection(LEFT);
                        break;
                    case DOWN :
                        p2_pointer->changeDirection(RIGHT);
                        break;
                    case LEFT :
                        p2_pointer->changeDirection(DOWN);
                        break;
                    case RIGHT :
                        p2_pointer->changeDirection(UP);
                        break;
                }
                break;
            case SDLK_d :
                switch (p1_pointer->getDirection()) {
                    case UP :
                        p2_pointer->changeDirection(RIGHT);
                        break;
                    case DOWN :
                        p2_pointer->changeDirection(LEFT);
                        break;
                    case LEFT :
                        p2_pointer->changeDirection(UP);
                        break;
                    case RIGHT :
                        p2_pointer->changeDirection(DOWN);
                        break;
                }
                break;
        }
    }
    else if (current_event.type == SDL_QUIT)
        exit(0);
}
