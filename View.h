//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_VIEW_H
#define TRON_VIEW_H

#include "Includes.h"
#include "Cleanup.h"

class Field;

class View : private SdlHandle, ImgHandle, TtfHandle {
public:
    View(Field *field);
	
    void draw();
    void draw_end_screen(Team Winner);
	
private:
	SdlWinPtr win;
    SdlRenPtr ren;
    SdlTexPtr background;

    static constexpr SDL_Color COLOR_RED = {255, 0, 0};
    static constexpr SDL_Color COLOR_GREEN = {0, 255, 0};

    Field *field = nullptr;
};


#endif //TRON_VIEW_H
