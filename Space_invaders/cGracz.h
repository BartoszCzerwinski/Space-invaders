//
// Created by piotr on 27.03.19.
// 

#ifndef FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CPROSTOKAT_H
#include <GL/freeglut.h>
#include "cFigura.h"
#include"cKula.h"

class cGracz : public cFigura{
double a_,b_;
cKula* pocisk_;
int zycia_;
int ilosc_punktow_;


public:
    cGracz(double a, double b, double x, double y,int zycia);
    void rysuj();
    void ustaw_rozmiar(double a, double b);
	cKula* ognia();

};


#endif //FREEGLUT_CPROSTOKAT_H
