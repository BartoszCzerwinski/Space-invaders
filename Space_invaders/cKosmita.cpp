

#include "cKosmita.h"

cKosmita::cKosmita(double a, double b, double x, double y, float pozycja_kolumn_x, float pozycja_kolumn_y, int poziom) : cFigura(x, y), a_(a), b_(b) {
	ustaw_geometria(x, y, -a / 2, -b / 2, a / 2, b / 2);
	this->pozycja_kolumn_x_ = pozycja_kolumn_x;
	this->pozycja_kolumn_y_ = pozycja_kolumn_y;
	do_prawej = 1;
	do_lewej = 0;
	do_gory = 1;
	do_dolu = 0;
	this->poziom_ = poziom;
	this->kat_obrotu_kosmity_ = 0;
}

cKula* cKosmita::ognia()
{
	return pocisk_ = new cKula(0.1, 0.1, x_, y_-0.3 , -90,-90,0,0.001);
}

void cKosmita::obracaj_kosmite()
{
	kat_obrotu_kosmity_ +=5;
	
}

int cKosmita::get_poziom()
{
	return poziom_;
}

void cKosmita::kosmita_traci_poziom()
{
	poziom_ = poziom_ - 1;
}

void cKosmita::kosmita_lata()
{
	if ((do_prawej == 1) && x_ <= 1.909 + pozycja_kolumn_x_)
	{
		x_ += 0.02;
		if (x_ >= 1.909 + pozycja_kolumn_x_)
		{
			do_prawej = 0;
			do_lewej = 1;
		}
	}

	if ((do_lewej == 1) && x_ >= -1.909 + pozycja_kolumn_x_)
	{
		x_ -= 0.02;
		if (x_ <= -1.909 + pozycja_kolumn_x_)
		{
			do_prawej = 1;
			do_lewej = 0;
		}
	}

	if ((do_gory == 1) && y_ <= 1.5 + pozycja_kolumn_y_)
	{
		y_ += 0.02;
		if (y_ >= 1.5 + pozycja_kolumn_y_)
		{
			do_gory = 0;
			do_dolu = 1;
		}
	}
	if ((do_dolu == 1) && y_ >= -1 + pozycja_kolumn_y_)
	{
		y_ -= 0.02;
		if (y_ <= -1 + pozycja_kolumn_y_)
		{
			do_gory = 1;
			do_dolu = 0;
		}
	}


}


void cKosmita::rysuj() {

	if (poziom_ == 1)
	{
		kolor_r = 0.0;
		kolor_g = 0.2;
		kolor_b = 0.0;
	}
	if (poziom_ == 2)
	{
		kolor_r = 0.0;
		kolor_g = 0.6;
		kolor_b = 0.0;
	}
	if (poziom_ == 3)
	{
		kolor_r = 0.0;
		kolor_g = 1.0;
		kolor_b = 0.0;
	}

	/// PASEK

	glPushMatrix();


	glTranslated(x_, y_, 0.0);
	glRotated(kat_obrotu_kosmity_, 1.0, 0.0, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(1, 1, 1 );

	glBegin(GL_POLYGON);
	{
		glVertex3d(-a_ / 2, 0.01, 0);
		glVertex3d(a_ / 2, 0.01, 0);
		glVertex3d(a_ / 2, -0.01, 0);
		glVertex3d(-a_ / 2, -0.01, 0);
	
	}


	glEnd();
	glPopMatrix();

	/// OBRYS

	glPushMatrix();


	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(kolor_r, kolor_g, kolor_b);

	glBegin(GL_POLYGON);
	for (float kat = 0;kat < 360;kat += 10)
	{
		GLfloat x, y;
		x = a_ / 2 * cos(kat / 180 * 3.14);
		y = b_ / 2 * sin(kat / 180 * 3.14);
		glVertex2f(x, y);
	}

	glEnd();
	glPopMatrix();

	/// KOPU£KA

	glPushMatrix();


	glTranslated(x_, y_, 0.0);
	glRotated(0, 1.0, 0.0, 0.0);
	glRotated(0, 0.0, 1.0, 0.0);
	glRotated(0, 0.0, 0.0, 1.0);

	glColor3d(kolor_r, kolor_g, kolor_b);


	glBegin(GL_POLYGON);
	for (float kat = 0;kat < 360;kat += 10)
	{
		GLfloat x, y;
		x = a_ / 6 * cos(kat / 180 * 3.14);
		y = b_ / 6 * sin(kat / 180 * 3.14);
		glVertex2f(x, y+0.25);
	}

	glEnd();
	glPopMatrix();
}