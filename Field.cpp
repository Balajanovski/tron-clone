//
// Created by JULIA BALAJAN on 31/12/2016.
//

#include "Field.h"
#include <cstring>

Field::Field() {
    std::memset(field_matrix, NOTHING, sizeof(field_matrix[0][0]) * HEIGHT * WIDTH);
}