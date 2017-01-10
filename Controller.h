//
// Created by JULIA BALAJAN on 30/12/2016.
//

#ifndef TRON_CONTROLLER_H
#define TRON_CONTROLLER_H

#include "Includes.h"

class Model;

class Controller {
public:
    void handleEvents();

    Controller(Model *model);
	
private:
	Model *model;
};


#endif //TRON_CONTROLLER_H
