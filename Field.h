//
// Created by JULIA BALAJAN on 31/12/2016.
//

#ifndef TRON_FIELD_H
#define TRON_FIELD_H

#include "Includes.h"

class Field {
public:
    static constexpr int WIDTH = 600;
    static constexpr int HEIGHT = 480;

    Field();
    Objects field_matrix[HEIGHT][WIDTH];
};


#endif //TRON_FIELD_H
