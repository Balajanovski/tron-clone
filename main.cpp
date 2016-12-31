#include "Model.h"

int main() {
    Model model;
    while (model.isGame_over_flag())
        model.loop();
    return 0;
}