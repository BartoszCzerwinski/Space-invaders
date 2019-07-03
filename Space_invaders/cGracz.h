
//
// Created by piotr on 27.03.19.
// 

#ifndef FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CPROSTOKAT_H
#define FREEGLUT_CNOBEK_H
#define GLUT_BITMAP_8_BY_13
#define GLUT_BITMAP_9_BY_15
#define GLUT_BITMAP_TIMES_ROMAN_10
#define GLUT_BITMAP_TIMES_ROMAN_24
#define GLUT_BITMAP_HELVETICA_10
#define GLUT_BITMAP_HELVETICA_12
#define GLUT_BITMAP_HELVETICA_18
#include <GL/freeglut.h>
#include "cFigura.h"
#include"cKula.h"


class cGracz : public cFigura {
	double a_, b_;
	cKula* pocisk_;
	int zycia_;
	int ilosc_punktow_;
	int magazynek_;
	


public:
	cGracz(double a, double b, double x, double y, int zycia);
	void rysuj();
	void ustaw_rozmiar(double a, double b);
	cKula* ognia();
	void zmniejsz_zycia();
	int get_zycia();
	void wyswietlanie_statystyk(float x, float y, float z, const char *string);
	void zliczaj_punkty();
	int get_punkty();


};


#endif //FREEGLUT_CPROSTOKAT_H