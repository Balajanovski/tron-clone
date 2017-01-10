#include "Model.h"

#include <SDL2/SDL_timer.h>

int main() {
    Model model;
    while (!model.isGameOver()) {
        model.loop();
    }
    model.endGame();
    SDL_Delay(1000);
    return 0;
}