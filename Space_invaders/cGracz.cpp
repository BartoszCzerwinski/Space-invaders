

//
// Created by piotr on 27.03.19.
//

#include "cGracz.h"
#include"cKula.h"

cGracz::cGracz(double a, double b, double x, double y, int zycia) : cFigura(x, y), a_(a), b_(b) {
	this->zycia_ = zycia;
	this->magazynek_ = 3;
	ustaw_geometria(x, y, -0.477, -2.4, 0.477, -1.9);
	ilosc_punktow_ = 0;
}


void cGracz::wyswietlanie_statystyk(float x, float y, float z, const char *string)
{
	glRasterPos3f(x, y, z);

	for (const char* c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *c); // Updates the position
	}
}

int cGracz::get_punkty()
{
	return ilosc_punktow_;
}

void cGracz::zliczaj_punkty()
{
	ilosc_punktow_ = ilosc_punktow_ + 10;
}

int cGracz::get_zycia()
{
	return zycia_;
}

void cGracz::zmniejsz_zycia()
{
	zycia_--;
}


cKula* cGracz::ognia()
{
	return pocisk_ = new cKula(0.1, 0.1, x_, y_ - 1.8, 90,90,1,0.001);
}

void cGracz::rysuj() {

	//pozioma belka duza ===============

	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.477, -2.3, 0);
		glVertex3d(0.477, -2.3, 0);
		glVertex3d(0.477, -2.4, 0);
		glVertex3d(-0.477, -2.4, 0);
	}
	glEnd();
	glPopMatrix();

	//pionowa belka  ==================

	glPushMatrix();

	glTranslated(x_, y_ , 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.0954, -1.9, 0);
		glVertex3d(0.0954, -1.9, 0);
		glVertex3d(0.0954, -2.4, 0);
		glVertex3d(-0.0954, -2.4, 0);
	}
	glEnd();
	glPopMatrix();

	//pozioma mala belka

	glPushMatrix();

	glTranslated(x_, y_ , 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-0.2862, -2.1, 0);
		glVertex3d(0.2862, -2.1, 0);
		glVertex3d(0.2862, -2.2, 0);
		glVertex3d(-0.2862, -2.2, 0);
	}
	glEnd();
	glPopMatrix();

}