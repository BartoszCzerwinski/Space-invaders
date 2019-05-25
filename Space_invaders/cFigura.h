//
// Created by piotr on 27.03.19.
//

#ifndef FREEGLUT_CFIGURA_H
#define FREEGLUT_CFIGURA_H
#include "cFizyka.h"
class cFigura: public cFizyka {
protected:
    //double x_, y_;
public:
    cFigura(double x = 0.0, double y = 0.0);
    virtual void rysuj()=0;
    void przesun(double dx, double dy);
};


#endif //FREEGLUT_CFIGURA_H
