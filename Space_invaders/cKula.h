#pragma once
#pragma once

#ifndef FREEGLUT_CKULA_H
#define FREEGLUT_CKULA_H
#include <GL/freeglut.h>
#include "cFigura.h"

class cKula : public cFigura {
	double a_, b_;
	double kat_;


public:
	cKula(double a, double b, double x, double y, double kat);
	void rysuj();
	void ustaw_rozmiar(double a, double b);
	float get_polozenie_y();

};


#endif //FREEGLUT_CPROSTOKAT_H