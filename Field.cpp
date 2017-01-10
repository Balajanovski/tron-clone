//
// Created by JULIA BALAJAN on 31/12/2016.
//

#include "Field.h"

#include <algorithm>

Field::Field() {
    std::fill_n(&matrix[0][0], WIDTH * HEIGHT, NOTHING);
}