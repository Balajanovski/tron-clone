#include "Model.h"

int main() {
    Model model;
    while (!model.isGame_over_flag()) {
        model.loop();
    }
    model.end_screen();
    SDL_Delay(1000);
    return 0;
}