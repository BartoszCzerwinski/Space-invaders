#pragma once
#ifndef FREEGLUT_CBELKA_H
#define FREEGLUT_CBELKA_H
#include <GL/freeglut.h>
#include "cFigura.h"

class cBelka : public cFigura {
	double a_, b_;

public:
	cBelka(double a, double b, double x, double y);
	void rysuj();
	void ustaw_rozmiar(double a, double b);

};


#endif //FREEGLUT_CPROSTOKAT_H