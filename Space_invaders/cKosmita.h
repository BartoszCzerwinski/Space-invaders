#pragma once
#ifndef FREEGLUT_CKOSMITA_H
#define FREEGLUT_CKOSMITA_H
#include <GL/freeglut.h>
#include "cFigura.h"

class cKosmita : public cFigura {
	double a_, b_;
	int do_prawej;
	int do_lewej;
	int do_gory;
	int do_dolu;
	float pozycja_kolumn_x_;
	float pozycja_kolumn_y_;

public:
	cKosmita(double a, double b, double x, double y,float pozycja_kolumn_x,float pozycja_kolumn_y);
	void rysuj();
	void kosmita_lata();
	void ustaw_rozmiar(double a, double b);

};


#endif //FREEGLUT_CPROSTOKAT_H