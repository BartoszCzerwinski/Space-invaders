#include "cKula.h"

cKula::cKula(double a, double b, double x, double y, double kat,float kat_grawitacji,int ID,float predkosc) : cFigura(x, y), a_(a), b_(b) {
	ustaw_geometria(x, y, -a / 2, -b / 2, a / 2, b / 2);
	this->kat_ = kat;
	this->kat_grawitacji_ = kat_grawitacji;
	this->ID_ = ID;
	this->predkosc_ = predkosc;
	ustaw_predkosc(predkosc_, kat_);
	ustaw_fizyka(9.81*1E-6, kat_grawitacji_);
}

void cKula::ustaw_predkosc_belka()
{
	ustaw_predkosc(predkosc_, -kat_);
}

int cKula::get_ID()
{
	return ID_;
}

float cKula::get_polozenie_y()
{
	return y_;
}


void cKula::rysuj() {


	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
	{
		glVertex3d(-a_ / 2, b_ / 2, 0);
		glVertex3d(a_ / 2, b_ / 2, 0);
		glVertex3d(a_ / 2, -b_ / 2, 0);
		glVertex3d(-a_ / 2, -b_ / 2, 0);
	}
	glEnd();
	glPopMatrix();
}