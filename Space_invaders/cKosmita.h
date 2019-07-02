#pragma once
#ifndef FREEGLUT_CKOSMITA_H
#define FREEGLUT_CKOSMITA_H
#include <GL/freeglut.h>
#include "cFigura.h"
#include"cKula.h"

class cKosmita : public cFigura {
	double a_, b_;
	int do_prawej;
	int do_lewej;
	int do_gory;
	int do_dolu;
	float pozycja_kolumn_x_;
	float pozycja_kolumn_y_;
	int poziom_;
	float kolor_r;
	float kolor_g;
	float kolor_b;
	cKula* pocisk_;
	float kat_obrotu_statuku_;
	int przelacznik;


public:
	cKosmita(double a, double b, double x, double y, float pozycja_kolumn_x, float pozycja_kolumn_y, int poziom_);
	void rysuj();
	void kosmita_lata();
	void kosmita_traci_poziom();
	int get_poziom();
	void ustaw_rozmiar(double a, double b);
	cKula* ognia();
	




};


#endif //FREEGLUT_CPROSTOKAT_H