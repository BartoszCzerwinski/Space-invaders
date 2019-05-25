

#include "cKosmita.h"

cKosmita::cKosmita(double a, double b, double x, double y,float pozycja_kolumn_x,float pozycja_kolumn_y) : cFigura(x, y), a_(a), b_(b) {
	ustaw_geometria(x, y, -a / 2, -b / 2, a / 2, b / 2);
	this->pozycja_kolumn_x_ = pozycja_kolumn_x;
	this->pozycja_kolumn_y_ = pozycja_kolumn_y;
	do_prawej = 1;
	do_lewej = 0;
	do_gory = 1;
	do_dolu = 0;
}

void cKosmita::kosmita_lata()
{
	if ((do_prawej == 1) && x_ <= 1.909+pozycja_kolumn_x_)
	{
		x_ += 0.02;
		if (x_>= 1.909+pozycja_kolumn_x_)
		{
			do_prawej = 0;
			do_lewej = 1;
		}
	}

	if ((do_lewej == 1) && x_ >= -1.909+pozycja_kolumn_x_)
	{
		x_ -= 0.02;
		if (x_ <= -1.909+pozycja_kolumn_x_)
		{
			do_prawej = 1;
			do_lewej = 0;
		}
	}

	if ((do_gory == 1) && y_ <= 1.5+pozycja_kolumn_y_)
	{
		y_ += 0.02;
		if (y_ >= 1.5+pozycja_kolumn_y_)
		{
			do_gory = 0;
			do_dolu = 1;
		}
	}
	if ((do_dolu == 1) && y_ >= -1+pozycja_kolumn_y_)
	{
		y_ -= 0.02;
		if (y_ <= -1+pozycja_kolumn_y_)
		{
			do_gory = 1;
			do_dolu = 0;
		}
	}


}


void cKosmita::rysuj() {
	glPushMatrix();

	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(0.0, 1.0, 0.0);

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
