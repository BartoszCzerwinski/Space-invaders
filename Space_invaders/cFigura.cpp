//
// Created by piotr on 27.03.19.
//

#include "cFigura.h"

cFigura::cFigura(double x, double y):cFizyka() {

}

void cFigura::przesun(double dx, double dy) {
    x_ += dx;
    y_ += dy;

}
